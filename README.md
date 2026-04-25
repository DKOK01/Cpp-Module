<h1 align="center">
    📖 C++ Modules
</h1>

<p align="center">
    <b><i>42 School C++ Piscine - From basics to advanced OOP & STL</i></b><br>
</p>

<p align="center">
    <img src="https://img.shields.io/badge/42-aysadeq-000000?style=for-the-badge&logo=42&logoColor=white" />
    <img src="https://img.shields.io/badge/C++-98-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
    <img src="https://img.shields.io/badge/Modules-10%2F10-success?style=for-the-badge" />
</p>

<p align="center">
    <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/DKOK01/Cpp-Module?color=lightblue" />
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/DKOK01/Cpp-Module?color=blue" />
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/DKOK01/Cpp-Module?color=green" />
</p>

---

## 🗂️ About

The **C++ Modules** are a series of 10 projects at **42 School** designed to introduce Object-Oriented Programming through the C++ language. Starting from basic syntax, these modules progressively cover:

- Classes, member functions, and encapsulation
- Memory allocation (stack vs heap)
- References, pointers, and polymorphism
- Operator overloading and Orthodox Canonical Form
- Inheritance, abstract classes, and interfaces
- Exception handling and type casting
- Templates and generic programming
- STL Containers, iterators, and algorithms

> ⚠️ **Note:** All code follows the **C++98 standard** as required by 42.

---

## 📊 Progress

| Module | Topics | Status |
|:------:|:-------|:------:|
| [CPP00](./Cpp-00) | Namespaces, classes, member functions, stdio streams | ✅ |
| [CPP01](./Cpp-01) | Memory allocation, pointers to members, references | ✅ |
| [CPP02](./Cpp-02) | Ad-hoc polymorphism, operator overloading, canonical form | ✅ |
| [CPP03](./Cpp-03) | Inheritance | ✅ |
| [CPP04](./Cpp-04) | Subtype polymorphism, abstract classes, interfaces | ✅ |
| [CPP05](./Cpp-05) | Exceptions, try/catch, custom exception classes | ✅ |
| [CPP06](./Cpp-06) | C++ type casting (static, dynamic, reinterpret) | ✅ |
| [CPP07](./Cpp-07) | Function and class templates | ✅ |
| [CPP08](./Cpp-08) | STL Containers, iterators, algorithms | ✅ |
| [CPP09](./Cpp-09) | STL real-world applications (exchange, RPN, sorting) | ✅ |

---

## 🛠️ How to Use

```bash
# Clone the repository
git clone https://github.com/DKOK01/Cpp-Module.git
cd Cpp-Module

# Navigate to any exercise
cd Cpp-09/ex02

# Compile
make

# Run
./PmergeMe 3 5 9 7 4
```

---

## 📝 Module Details

<details>
<summary><b>CPP00 - Basics</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | Megaphone - String to uppercase |
| ex01 | PhoneBook - Contact management with classes |
| ex02 | Account - Recreating a lost implementation from logs |

**Key concepts:** `std::string`, `std::cin`, `std::cout`, class basics, static members
</details>

<details>
<summary><b>CPP01 - Memory & References</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | Zombie class with stack allocation |
| ex01 | Zombie horde with heap allocation |
| ex02 | Pointers vs references demo |
| ex03 | Weapon class with references |
| ex04 | File content replacement |
| ex05 | Harl - Pointers to member functions |
| ex06 | Harl filter - Switch statements |

**Key concepts:** `new`, `delete`, references, file streams, switch
</details>

<details>
<summary><b>CPP02 - Orthodox Canonical Form</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | Fixed-point class (OCF) |
| ex01 | Constructors and type conversion |
| ex02 | Operator overloading |

**Key concepts:** Copy constructor, assignment operator, operator overloading
</details>

<details>
<summary><b>CPP03 - Inheritance</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | ClapTrap base class |
| ex01 | ScavTrap inheritance |
| ex02 | FragTrap inheritance |
| ex03 | DiamondTrap - Multiple inheritance |

**Key concepts:** Inheritance, virtual functions, diamond problem
</details>

<details>
<summary><b>CPP04 - Polymorphism</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | Animal hierarchy with virtual functions |
| ex01 | Deep copy with Brain class |
| ex02 | Abstract classes |

**Key concepts:** Virtual functions, pure virtual, abstract classes
</details>

<details>
<summary><b>CPP05 - Exceptions</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | Bureaucrat class with grade range exceptions |
| ex01 | Form class with signing requirements |
| ex02 | Concrete forms (ShrubberyCreation, RobotomyRequest, PresidentialPardon) |
| ex03 | Intern class - Factory pattern for form creation |

**Key concepts:** `try`, `catch`, `throw`, custom exception classes, inheritance-based exceptions
</details>

<details>
<summary><b>CPP06 - C++ Casts</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | ScalarConverter - Convert literals between char, int, float, double |
| ex01 | Serializer - Pointer to uintptr_t serialization/deserialization |
| ex02 | Base identification - Dynamic type identification without RTTI |

**Key concepts:** `static_cast`, `dynamic_cast`, `reinterpret_cast`, type promotion, literal detection
</details>

<details>
<summary><b>CPP07 - Templates</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | `swap`, `min`, `max` function templates |
| ex01 | `iter` - Apply a function to every element of an array |
| ex02 | Array class template with bounds checking |

**Key concepts:** Function templates, class templates, template specialization, `operator[]`
</details>

<details>
<summary><b>CPP08 - STL Containers & Algorithms</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | `easyfind` - Search for an integer in any container |
| ex01 | Span - Store N integers and find shortest/longest span |
| ex02 | MutantStack - A stack with iterators |

**Key concepts:** `std::vector`, `std::list`, `std::stack`, iterators, `std::find`, `std::sort`
</details>

<details>
<summary><b>CPP09 - STL Applications</b></summary>

| Exercise | Description |
|----------|-------------|
| ex00 | BitcoinExchange - Calculate BTC values from a CSV database using `std::map` |
| ex01 | RPN - Reverse Polish Notation calculator using `std::stack` |
| ex02 | PmergeMe - Ford-Johnson merge-insertion sort with `std::vector` & `std::deque` |

**Key concepts:** `std::map`, `std::stack`, `std::deque`, `std::lower_bound`, algorithm benchmarking, Jacobsthal numbers
</details>

---

## 🔧 Compilation Flags

```makefile
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
```

---

## 👤 Author

| [<img src="https://github.com/DKOK01.png" width="100px;"/><br /><sub><b>Ayman Sadeq</b></sub>](https://github.com/DKOK01) |
| :---: |

<p align="center">
    <a href="https://profile.intra.42.fr/users/aysadeq">42 Intra</a> •
    <a href="https://www.linkedin.com/in/ayman-sadeq-95b8aa322/">LinkedIn</a>
</p>

---

<p align="center">
    <i>If this helped you, consider giving a ⭐!</i>
</p>
