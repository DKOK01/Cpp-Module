# CPP Module 09 — Full Review & Evaluation Prep

## Code Review Summary

### 🔧 Bugs Fixed During Review

| # | Issue | File | Fix |
|---|---|---|---|
| 1 | `std::strtof` is **C99/C++11**, not available in strict C++98 | ex00/BitcoinExchange.cpp | Replaced with `std::strtod` + `static_cast<float>` |
| 2 | `<stdexcept>` not included — `std::runtime_error` might not compile on strict compilers | All 3 headers | Added `# include <stdexcept>` |

### ✅ Readiness Checklist

#### Ex00 — Bitcoin Exchange
| Criteria | Status | Notes |
|---|---|---|
| Compiles with `-Wall -Wextra -Werror -std=c++98` | ✅ | After strtof fix |
| Program name is `btc` | ✅ | Makefile: `NAME = btc` |
| Takes a file as argument | ✅ | `av[1]` |
| Uses at least one container | ✅ | `std::map<std::string, float>` |
| Handles `date \| value` format | ✅ | Splits on `" \| "` |
| Valid date format `Year-Month-Day` | ✅ | Full validation incl. leap year |
| Value must be float/int between 0 and 1000 | ✅ | Checked after parsing |
| Uses closest lower date if exact date not found | ✅ | `upper_bound` + decrement |
| Error handling with appropriate messages | ✅ | All 4 error types covered |
| Orthodox Canonical Form | ✅ | All 4 members |
| Files: Makefile, main.cpp, BitcoinExchange.{cpp,hpp} | ✅ | All present |

#### Ex01 — RPN
| Criteria | Status | Notes |
|---|---|---|
| Program name is `RPN` | ✅ | Makefile: `NAME = RPN` |
| Takes RPN expression as argument | ✅ | `av[1]` |
| Numbers always less than 10 (single digit) | ✅ | `token.length() != 1` check |
| Handles `+ - / *` | ✅ | All four operators |
| Error on invalid input | ✅ | Brackets, multi-digit, letters → Error |
| Error on stderr | ✅ | `std::cerr` |
| Uses at least one container | ✅ | `std::stack<long>` |
| Container NOT used in ex00 | ✅ | stack ≠ map |
| Orthodox Canonical Form | ✅ | All 4 members |
| Division by zero handled | ✅ | Throws in `applyOp` |

#### Ex02 — PmergeMe
| Criteria | Status | Notes |
|---|---|---|
| Program name is `PmergeMe` | ✅ | Makefile: `NAME = PmergeMe` |
| Uses merge-insert sort (Ford-Johnson) | ✅ | Pairs, recursive sort, Jacobsthal insertion |
| Uses at least TWO different containers | ✅ | `std::vector` + `std::deque` |
| Containers NOT used in ex00/ex01 | ✅ | vector/deque ≠ map/stack |
| Handles 3000+ integers | ✅ | Recursion depth ~12, no stack overflow |
| Displays unsorted sequence | ✅ | `Before:` line |
| Displays sorted sequence | ✅ | `After:` line |
| Displays time for each container | ✅ | Two timing lines with `clock()` |
| Error handling for bad input | ✅ | Non-digits, negatives, zero, overflow |
| Orthodox Canonical Form | ✅ | All 4 members |
| Separate implementation per container | ✅ | `sortVec` and `sortDeq` are independent |

### ⚠️ Things to Clean Before Pushing

> [!WARNING]
> Remove these extra files from the exercise directories before pushing:

```bash
# Remove explanation markdown files (not required for submission)
rm -f /home/azedine/Desktop/CPP-Module/CPP_09/ex00/ex00_explanation.md
rm -f /home/azedine/Desktop/CPP-Module/CPP_09/ex01/ex01_explanation.md
# Remove old analysis files
rm -f /home/azedine/Desktop/CPP-Module/CPP_09/ex00/cpp09_analysis.md
rm -f /home/azedine/Desktop/CPP-Module/CPP_09/ex00/scratchpad_7jian28v.md
```

The `input.txt` and `cpp_09/data.csv` in ex00 **should** stay — the evaluator needs both to test.

---

## Deep-Dive Evaluation Q&A

> [!IMPORTANT]
> Evaluators ask "under the hood" questions. Below is every concept you need to explain fluently.

---

### 🗂 General: STL Containers

**Q: What is the STL?**
The **Standard Template Library** — a collection of template classes and functions in C++ that provides containers (data structures), iterators (traversal), and algorithms (sorting, searching). It's "template" because every container works with any type: `std::vector<int>`, `std::vector<std::string>`, etc.

**Q: What are the main categories of STL containers?**

| Category | Examples | Key Feature |
|---|---|---|
| **Sequence** | `vector`, `deque`, `list` | Elements stored in insertion order |
| **Associative** | `map`, `set`, `multimap`, `multiset` | Elements sorted by key, tree-based (O(log n) lookup) |
| **Adapters** | `stack`, `queue`, `priority_queue` | Restricted interface on top of a sequence container |

**Q: What's the difference between a container and a container adapter?**
A **container** owns and manages its memory directly (e.g., `vector` manages a dynamic array). An **adapter** wraps another container and restricts its interface. For example, `std::stack` by default wraps a `std::deque` but only exposes `push()`, `pop()`, and `top()` — you can't access the middle elements.

---

### 🗺️ Ex00: `std::map` Under the Hood

**Q: What is `std::map` and how is it implemented?**
`std::map<K,V>` stores key-value pairs sorted by key. Internally it's a **red-black tree** (a self-balancing binary search tree). This gives:
- **Lookup**: O(log n)
- **Insert**: O(log n)
- **Iteration**: O(n) in sorted order
- Keys are **unique** (use `std::multimap` for duplicate keys)

**Q: Why did you choose `std::map` for the Bitcoin exercise?**
Two reasons:
1. Keys (dates as `YYYY-MM-DD` strings) are **automatically sorted** chronologically because lexicographic order equals chronological order for this date format
2. `upper_bound()` provides O(log n) lookup for "closest earlier date" — exactly what the subject requires

**Q: Explain `upper_bound` vs `lower_bound`.**

```cpp
// Given a sorted map: {1, 3, 5, 7, 9}
lower_bound(5)  → iterator to 5  (first element >= 5)
upper_bound(5)  → iterator to 7  (first element >  5)
lower_bound(6)  → iterator to 7  (first element >= 6)
upper_bound(6)  → iterator to 7  (first element >  6)
```

In our code, `upper_bound(date)` finds the first entry **after** our date. Decrementing gives the last entry **at or before** our date — which is the closest earlier date.

**Q: What's the difference between `map[]` and `map.find()`?**
- `map[key]` — creates the entry with a default value if it doesn't exist (dangerous for read-only access)
- `map.find(key)` — returns an iterator; returns `map.end()` if not found (safe)

**Q: Why do you use `.c_str()` when opening files?**
In C++98, `std::ifstream` constructor takes a `const char*`, not `std::string`. `.c_str()` converts a `std::string` to a null-terminated C-style string.

**Q: What is `std::strtod` and why not `std::stof`?**
`std::stof` is C++11. `std::strtod` is a C89 function that converts a string to `double`. It takes a pointer-to-pointer (`char**`) that tells you where parsing stopped — useful for detecting trailing garbage. We cast the result to `float`.

---

### 📚 Ex01: `std::stack` Under the Hood

**Q: What is `std::stack` and how does it work internally?**
`std::stack` is a **container adapter** that enforces LIFO (Last In, First Out) access. By default it wraps a `std::deque`, but you can specify any sequence container:
```cpp
std::stack<int>                     // uses deque internally
std::stack<int, std::vector<int>>   // uses vector internally
```
It only exposes:
- `push(val)` — add to top
- `pop()` — remove from top (returns void!)
- `top()` — peek at top (returns reference)
- `size()` / `empty()`

**Q: Why is `std::stack` the right choice for RPN?**
RPN evaluation is the **textbook use case** for a stack. The algorithm naturally pushes operands and pops them when operators appear. The LIFO order ensures the most recent operands are used first, which matches how postfix notation works.

**Q: Explain the pop order for subtraction and division.**
```
Expression: "3 1 -"
Stack after pushes: [3, 1]  (1 is on top)
Pop 1 → right operand
Pop 3 → left operand
Compute: 3 - 1 = 2  ✅ (not 1 - 3)
```
The **first pop** gives the **right** operand, the **second pop** gives the **left** operand. Swapping them gives wrong results for non-commutative operations (subtraction, division).

**Q: Why use `long` instead of `int` on the stack?**
Input numbers are single digits (0-9), but **intermediate results** can exceed `int` range. For example, repeated multiplications. `long` provides at least 64 bits on most systems, preventing overflow.

**Q: What does `token[0] - '0'` do?**
It converts an ASCII character to its numeric value. In ASCII, digits are consecutive: `'0'=48, '1'=49, ..., '9'=57`. So `'5' - '0' = 53 - 48 = 5`.

**Q: Why use `std::istringstream` to tokenize?**
The `>>` operator on streams **automatically skips whitespace** and reads the next token. This is cleaner than manually splitting the string and handles multiple spaces, tabs, etc.

---

### 🔀 Ex02: Ford-Johnson & Containers Under the Hood

**Q: Explain the Ford-Johnson algorithm step by step.**
1. **Pair** adjacent elements and compare — each pair has a winner (larger) and loser (smaller). Cost: n/2 comparisons
2. **Recursively sort** the winners using the same algorithm
3. **Build main chain**: place b1 (first loser) at front, then all sorted winners → `[b1, a1, a2, ...]`
4. **Insert remaining losers** (pend elements) into the main chain using binary search, following **Jacobsthal order** to minimize comparisons
5. **Insert straggler** (unpaired element from odd-length input)

**Q: Why does Ford-Johnson minimize comparisons?**
It uses the **optimal** number of binary search comparisons for insertion. By using Jacobsthal numbers to determine insertion order, each pend element is inserted when the search space is at its **power-of-2 boundary**, making each binary search use the minimum number of comparisons.

**Q: What are Jacobsthal numbers and why do they matter?**
`J(n) = J(n-1) + 2*J(n-2)`, giving: 0, 1, 1, 3, 5, 11, 21, 43, ...

They determine the **insertion order** of pend elements. Within each group (between consecutive Jacobsthal numbers), elements are inserted from right to left. This ensures that when we binary-search for the insertion point, the search range never exceeds a power of 2 — which is the ideal case for binary search (each comparison eliminates exactly half the range).

**Q: Why does b1 go at the beginning of the main chain?**
b1 is the loser of the first pair, so b1 < a1. And a1 is the smallest winner (sorted). Since b1 < a1 < a2 < ... < ak, b1 is guaranteed to be smaller than everything else. It goes at position 0 unconditionally, without needing a comparison.

**Q: What's a straggler?**
When the input has an **odd** number of elements, one element has no pair. It's saved and inserted via binary search at the very end, after all pend elements are placed.

**Q: Explain the pair reconnection after recursion.**
After recursively sorting the winners, their order changes but we lose track of which loser belongs to which winner. The `used[]` flag approach rescans the original pairs:
```cpp
for each sorted winner:
    find the first unused original pair with matching winner
    mark it as used
```
This correctly handles **duplicates** — two winners with the same value get matched to different original pairs.

**Q: What is `std::lower_bound` and how does it work?**
It performs a **binary search** on a sorted range and returns an iterator to the first element **≥** the target value. Complexity: O(log n) for random-access iterators (vector/deque), O(n) for bidirectional iterators (list).
```cpp
// sorted: [1, 3, 5, 7, 9]
lower_bound(begin, end, 5)  → iterator to 5
lower_bound(begin, end, 6)  → iterator to 7
lower_bound(begin, end, 0)  → iterator to 1  (beginning)
lower_bound(begin, end, 10) → end iterator
```

**Q: What's the difference between `std::vector` and `std::deque`?**

| Feature | `std::vector` | `std::deque` |
|---|---|---|
| Memory layout | Single **contiguous** block | Multiple **chunks** |
| Cache performance | **Excellent** (locality) | **Good** (chunked) |
| Random access | O(1) | O(1) |
| Push back | Amortized O(1) | Amortized O(1) |
| Push front | O(n) ❌ | O(1) ✅ |
| Insert middle | O(n) | O(n) |
| Iterator invalidation | On reallocation | On insert at front/back |

For sorting, `std::vector` is usually **faster** due to contiguous memory (better CPU cache utilization).

**Q: Why not use a generic/template function for both containers?**
The subject specifically says: *"It is strongly advised to implement your algorithm for each container and thus to avoid using a generic function."* Using templates would technically work but goes against the exercise's intent of demonstrating you understand both containers independently.

**Q: How do you measure time? Could `clock()` give 0?**
`clock()` measures **CPU time** in ticks. We divide by `CLOCKS_PER_SEC` to get seconds, then multiply by 1,000,000 for microseconds. For very small inputs (like 5 elements), the sort is so fast that `clock()` might return 0 ticks — this is normal and expected.

---

### 🏗️ Orthodox Canonical Form (All Exercises)

**Q: What is the Orthodox Canonical Form?**
A design rule requiring every class to implement these four members:

| Member | Purpose |
|---|---|
| **Default constructor** | Creates an object with default state |
| **Copy constructor** | Creates a new object as a copy of another |
| **Copy assignment operator** | Assigns one object's state to another |
| **Destructor** | Cleans up when the object is destroyed |

**Q: Why is the self-assignment check needed in operator=?**
```cpp
if (this != &other) // prevents: obj = obj;
```
Without it, `obj = obj` would first destroy `obj`'s data, then try to copy from the destroyed data → **undefined behavior**. The address comparison (`this != &other`) is O(1).

**Q: Why return `*this` from operator=?**
To support **chaining**: `a = b = c`. The assignment operator returns a reference to the left-hand object, so `b = c` returns `b`, and then `a = b` works.

**Q: Why use initializer lists in the copy constructor?**
```cpp
BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}
```
The initializer list constructs `_rates` directly with the right data. Without it, `_rates` would first be default-constructed (empty map), then overwritten in the body — **two operations** instead of one.

---

### 🔒 Include Guards

**Q: Why `#pragma once` instead of `#ifndef`/`#define`?**
Both prevent double-inclusion. `#pragma once` is shorter and less error-prone (no risk of misspelling the macro name). It's supported by all modern compilers (GCC, Clang, MSVC). Some 42 evaluators prefer traditional guards — both are accepted.

---

### 📋 Container Usage Summary

| Exercise | Container Used | Forbidden After |
|---|---|---|
| ex00 | `std::map` | ❌ ex01, ex02 |
| ex01 | `std::stack` | ❌ ex02 |
| ex02 | `std::vector` + `std::deque` | — |

No container conflicts. ✅
