# Ex02 — PmergeMe — Complete Explanation

---

## 1. The Problem — What Do They Want?

The subject says:

> You must create a program that sorts a **positive integer sequence** using the **merge-insert sort algorithm** (Ford-Johnson algorithm).

So at its core, this is a **sorting** exercise. But NOT with bubble sort, NOT with quicksort, NOT with merge sort. You must use a very specific, obscure algorithm invented in 1959 by two mathematicians named **Lester Ford** and **Selmer Johnson**.

### What makes this exercise special?

The subject adds three extra constraints:

1. **Two different containers** — You must implement the same sorting algorithm using two different C++ containers (`std::vector` and `std::deque` in our case), and compare their performance.

2. **At least 3000 elements** — The program must handle large inputs.

3. **Time measurement** — You must display how long each container took to sort, in microseconds.

### The output format

```
Before: 3 5 9 7 4
After:  3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00031 us
Time to process a range of 5 elements with std::deque  : 0.00014 us
```

---

## 2. The Challenge — Why Is This Hard?

### Why not just use `std::sort`?

Because the subject explicitly says to use the **Ford-Johnson** algorithm. Any evaluator who knows the algorithm will check that your code follows the correct steps:
- Pairing
- Recursive sorting of winners
- Jacobsthal-ordered insertion

### Why Ford-Johnson specifically?

Ford-Johnson is famous in computer science because it produces the **absolute minimum number of comparisons** needed to sort a sequence. While `std::sort` (quicksort) might do `N × log(N)` comparisons on average, Ford-Johnson can often do fewer.

The trade-off? It uses **more memory** and is **harder to implement**. The subject is testing whether you can implement a complex, mathematically precise algorithm — not just call a library function.

### Why two containers?

The subject wants you to understand that the **same algorithm** behaves differently depending on the **data structure** it runs on:
- `std::vector` stores elements in **one continuous block** of memory → fast random access, but slow insertion in the middle.
- `std::deque` stores elements in **multiple blocks** → slightly slower random access, but faster insertion at the front.

---

## 3. Key Concepts

### 3.1 What is "Merge-Insertion Sort" (Ford-Johnson)?

It's a sorting algorithm built on a simple observation:

> **If you've already done some comparisons, don't waste them. Use every piece of information you've learned to minimize future comparisons.**

The algorithm has 5 phases:

```
Phase 1: PAIR      → Group elements into pairs and compare each pair
Phase 2: RECURSE   → Recursively sort the "winners" (larger elements)
Phase 3: FREE INSERT → Insert the smallest loser at the front for free
Phase 4: JACOBSTHAL → Insert remaining losers using binary search, 
                      in a mathematically optimal order
Phase 5: STRAGGLER → Insert the leftover element (if odd count)
```

### 3.2 What is a "Pair"?

We take the input array and group consecutive elements into pairs of two:

```
Input:  [13, 2, 8, 5, 9, 1]

Pairs:  (13, 2)  (8, 5)  (9, 1)
```

For each pair, we compare the two numbers. The **larger** one becomes the "winner", and the **smaller** one becomes the "pend" (pending insertion):

```
Winners (largers):  [13, 8, 9]
Losers  (pend):     [2,  5, 1]
```

> [!IMPORTANT]  
> Each winner remembers which loser it beat. This pairing is critical later.

### 3.3 What is the "Main Chain"?

After recursively sorting the winners, they form a sorted sequence called the **main chain**:

```
mainChain = [8, 9, 13]    ← the winners, now sorted
pend      = [5, 1, 2]     ← the losers, reordered to match their winners
```

The pairing is now:
- `8` beat `5` (so `5 < 8`)
- `9` beat `1` (so `1 < 9`)
- `13` beat `2` (so `2 < 13`)

### 3.4 What is the "Free Insert"?

Look at `pend[0]` which is `5`. We know `5 < 8`, and `8` is the **smallest** number in the entire `mainChain`. Therefore:

> `5` is guaranteed to be smaller than everything in `mainChain`!

We can shove it to the very front **without any comparisons at all**:

```
mainChain = [5, 8, 9, 13]    ← 5 inserted for FREE
```

### 3.5 What are Jacobsthal Numbers?

The remaining pend elements (`1` and `2`) need to be inserted into the main chain using binary search. But the **order** in which we insert them matters!

The Jacobsthal sequence is: **0, 1, 1, 3, 5, 11, 21, 43, 85, ...**

Formula: `J(n) = J(n-1) + 2 × J(n-2)`

This sequence generates the **optimal insertion order**. Instead of inserting pend elements left to right (1, 2, 3, 4, 5...), we insert them in groups that go backwards:

```
Normal order:     b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b11 ...
Jacobsthal order: b1, b3, b2, b5, b4, b11, b10, b9, b8, b7, b6 ...
```

### Why backwards? 

When you insert `b3` before `b2`, the main chain is shorter during `b3`'s binary search, meaning fewer comparisons. By the time you insert `b2`, you've already narrowed down where it can possibly be. This mathematical trick saves 1-2 comparisons per group, which adds up for large inputs.

### 3.6 What is the "Straggler"?

If the input has an **odd** number of elements, the last element has no partner. It becomes the "straggler" and is simply inserted at the very end using binary search after everything else is sorted.

```
Input: [13, 2, 8, 5, 9]   ← 5 elements (odd!)
Pairs: (13,2), (8,5)      ← only 2 pairs
Straggler: 9              ← this guy waits until the end
```

### 3.7 What is `std::lower_bound`?

This is the **binary search** function from C++'s `<algorithm>` library. Given a sorted array and a value, it returns an iterator pointing to the first element that is **≥** the value. This tells us exactly where to insert the value to keep the array sorted.

```cpp
// mainChain = [5, 8, 9, 13]
// We want to insert 2
std::lower_bound(mainChain.begin(), mainChain.end(), 2);
// Returns iterator pointing to 5 (first element ≥ 2)
// We insert 2 before 5 → [2, 5, 8, 9, 13]
```

---

## 4. Full Visual Walkthrough

Let's trace the entire algorithm with: **`[13, 2, 8, 5, 9, 1]`**

### Phase 1: Pair and Compare

```
Input: [13, 2, 8, 5, 9, 1]    (6 elements, even → no straggler)

Pair (13, 2):  13 > 2  → winner: 13, loser: 2
Pair (8, 5):   8 > 5   → winner: 8,  loser: 5
Pair (9, 1):   9 > 1   → winner: 9,  loser: 1

Winners (largers): [13, 8, 9]
Losers  (pend):    [2,  5, 1]
```

### Phase 2: Recursively Sort Winners

We now call the same algorithm on `[13, 8, 9]`:

```
  ┌─── Recursive call on [13, 8, 9] ───────────────────┐
  │                                                      │
  │  3 elements → straggler = 9                          │
  │  Pair (13, 8): winner=13, loser=8                    │
  │  largers = [13]                                      │
  │                                                      │
  │  Recursive call on [13] → size 1, return immediately │
  │                                                      │
  │  mainChain = [13]                                    │
  │  pend = [8]                                          │
  │  Insert pend[0]=8 at front → mainChain = [8, 13]     │
  │  No more pend to insert                              │
  │  Insert straggler 9 via binary search                │
  │  lower_bound finds position between 8 and 13         │
  │  mainChain = [8, 9, 13]                              │
  │                                                      │
  │  Return [8, 9, 13] ✓                                 │
  └──────────────────────────────────────────────────────┘
```

### Phase 3: Recover Pairings

Now `largers = [8, 9, 13]` (sorted). We need to find each winner's original loser:

```
Original pairs:  (13, 2), (8, 5), (9, 1)

8's loser  → search pool, find (8, 5)  → pend gets 5
9's loser  → search pool, find (9, 1)  → pend gets 1
13's loser → search pool, find (13, 2) → pend gets 2

mainChain = [8, 9, 13]
pend      = [5, 1, 2]
```

### Phase 4: Free Insert

`pend[0] = 5`. We know `5 < 8` (from the original comparison). Since `8` is the smallest in `mainChain`, `5` goes to the front for free:

```
mainChain = [5, 8, 9, 13]
```

### Phase 5: Jacobsthal Insertion

Remaining pend: `[1, 2]` at indices 1 and 2.

Jacobsthal order for 3 elements: `[0, 2, 1]`
- Index 0: skip (already inserted)
- Index 2: insert `pend[2]` = **2**
- Index 1: insert `pend[1]` = **1**

**Insert 2:**
```
lower_bound([5, 8, 9, 13], 2) → points to 5
Insert before 5:
mainChain = [2, 5, 8, 9, 13]
```

**Insert 1:**
```
lower_bound([2, 5, 8, 9, 13], 1) → points to 2
Insert before 2:
mainChain = [1, 2, 5, 8, 9, 13]
```

### Final Result

```
[1, 2, 5, 8, 9, 13] ✓ Sorted!
```

---

## 5. Implementation Details (Code Walkthrough)

### 5.1 [PmergeMe.hpp](file:///home/aysadeq/Desktop/Cpp-Module/Cpp-09/ex02/PmergeMe.hpp)

```cpp
class PmergeMe {
private:
    std::vector<int>    _vec;     // Copy of input for vector sort
    std::deque<int>     _deq;     // Copy of input for deque sort

    std::vector<size_t> _jacobsthalOrder(size_t n);  // Generate insertion order
    void                _sortVector(std::vector<int>& arr);  // Ford-Johnson for vector
    void                _sortDeque(std::deque<int>& arr);    // Ford-Johnson for deque

public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void run(int argc, char **argv);  // Parse, sort, display
};
```

Key design decisions:
- **Two separate sort functions** — The subject says "avoid using a generic function", so we duplicate the algorithm for each container instead of using templates.
- **`_jacobsthalOrder`** is shared — It just generates a sequence of indices, not actual sorting logic.

---

### 5.2 [_jacobsthalOrder()](file:///home/aysadeq/Desktop/Cpp-Module/Cpp-09/ex02/PmergeMe.cpp#L30-L53) — The Insertion Order Generator

```cpp
std::vector<size_t> PmergeMe::_jacobsthalOrder(size_t n) {
    std::vector<size_t> order;
    if (n == 0) return order;

    order.push_back(0);          // b1 is always first
    if (n == 1) return order;

    size_t prev2 = 0;            // J(0) = 0
    size_t prev1 = 1;            // J(1) = 1

    while (true) {
        size_t jk = prev1 + 2 * prev2;   // Next Jacobsthal number
        size_t start = jk < n ? jk : n;   // Don't go past the array

        for (size_t i = start; i > prev1; i--)  // Count backwards!
            order.push_back(i - 1);              // Convert to 0-indexed

        if (jk >= n) break;       // We've covered all elements
        prev2 = prev1;
        prev1 = jk;
    }

    return order;
}
```

Example output for `n = 6`: `[0, 2, 1, 4, 3, 5]`

This means: insert `pend[0]` first, then `pend[2]`, then `pend[1]`, then `pend[4]`, then `pend[3]`, then `pend[5]`.

---

### 5.3 [_sortVector()](file:///home/aysadeq/Desktop/Cpp-Module/Cpp-09/ex02/PmergeMe.cpp#L58-L120) — The Ford-Johnson Algorithm

#### Step 1: Base case & straggler (lines 59-65)
```cpp
if (arr.size() <= 1) return;       // Nothing to sort

bool hasStraggler = arr.size() % 2 != 0;
int straggler = 0;
if (hasStraggler)
    straggler = arr.back();         // Save the odd one out
```

#### Step 2: Create pairs (lines 68-74)
```cpp
std::vector<std::pair<int, int> > pairs;
for (size_t i = 0; i + 1 < arr.size(); i += 2) {
    if (arr[i] >= arr[i + 1])
        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));  // (larger, smaller)
    else
        pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
}
```
Each pair is stored as `(winner, loser)`. The `>=` comparison ensures the larger one is always `.first`.

#### Step 3: Recursive sort (lines 77-82)
```cpp
std::vector<int> largers;
for (size_t i = 0; i < pairs.size(); i++)
    largers.push_back(pairs[i].first);

std::vector<std::pair<int, int> > pool = pairs;  // Save pairs for later
_sortVector(largers);                             // RECURSE!
```
We extract just the winners and sort them recursively. We save a copy of the original pairs (`pool`) so we can look up pairings after the sort scrambles the order.

#### Step 4: Recover pairings (lines 85-97)
```cpp
std::vector<int> mainChain;
std::vector<int> pend;

for (size_t i = 0; i < largers.size(); i++) {
    mainChain.push_back(largers[i]);
    for (size_t j = 0; j < pool.size(); j++) {
        if (pool[j].first == largers[i]) {       // Find this winner's loser
            pend.push_back(pool[j].second);
            pool.erase(pool.begin() + j);        // Remove so we don't reuse
            break;
        }
    }
}
```
For each sorted winner, we search the pool to find which loser was originally paired with it.

#### Step 5: Free insert (line 100)
```cpp
mainChain.insert(mainChain.begin(), pend[0]);
```
`pend[0]` is the loser of the smallest winner. It's guaranteed smaller than everything → goes to the front for free.

#### Step 6: Jacobsthal insertion (lines 103-110)
```cpp
std::vector<size_t> order = _jacobsthalOrder(pend.size());
for (size_t i = 0; i < order.size(); i++) {
    if (order[i] == 0 || order[i] >= pend.size()) continue;  // Skip b1 and out-of-bounds
    int val = pend[order[i]];
    std::vector<int>::iterator pos =
        std::lower_bound(mainChain.begin(), mainChain.end(), val);  // Binary search
    mainChain.insert(pos, val);
}
```

#### Step 7: Straggler (lines 113-117)
```cpp
if (hasStraggler) {
    std::vector<int>::iterator pos =
        std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
    mainChain.insert(pos, straggler);
}
```

#### Step 8: Return result (line 119)
```cpp
arr = mainChain;
```

---

### 5.4 [_sortDeque()](file:///home/aysadeq/Desktop/Cpp-Module/Cpp-09/ex02/PmergeMe.cpp#L125-L180)

This is **identical logic** to `_sortVector` but uses `std::deque` instead. The only visible difference is line 162:

```cpp
mainChain.push_front(pend[0]);   // deque has push_front (vector doesn't)
```

---

### 5.5 [run()](file:///home/aysadeq/Desktop/Cpp-Module/Cpp-09/ex02/PmergeMe.cpp#L184-L228) — The Orchestrator

1. **Parse arguments** (lines 186-197) — Uses `strtol` to safely convert strings to integers, rejecting negatives and overflow.
2. **Print "Before"** (lines 200-203)
3. **Sort & time both containers** (lines 206-212) — Uses `clock()` to measure CPU time.
4. **Print "After"** (lines 215-218)
5. **Print times** (lines 221-227) — Converts clock ticks to microseconds.

---

### 5.6 [main.cpp](file:///home/aysadeq/Desktop/Cpp-Module/Cpp-09/ex02/main.cpp)

```cpp
int main(int argc, char **argv) {
    if (argc < 2) {                      // No arguments
        std::cerr << "Error" << std::endl;
        return 1;
    }
    try {
        PmergeMe sorter;
        sorter.run(argc, argv);          // Do everything
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;  // Errors to stderr
        return 1;
    }
    return 0;
}
```

---

## 6. Quick Summary for Evaluation Defense

If an evaluator asks "explain your algorithm", say:

1. **"I pair consecutive elements and compare each pair"** — This gives me winners and losers.
2. **"I recursively sort the winners"** — This builds my sorted main chain.
3. **"I insert the first loser at the front for free"** — Because it's smaller than the smallest winner.
4. **"I insert the remaining losers using binary search in Jacobsthal order"** — Jacobsthal minimizes the number of comparisons by keeping the search area small.
5. **"If there was an odd element, I insert it last"** — The straggler.
6. **"I do this separately for vector and deque to compare performance"** — As required by the subject.
