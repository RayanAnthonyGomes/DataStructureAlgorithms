# 🌈 Recursion

### 🔁 *Breaking Problems into Smaller Pieces*

---

## 🚀 What is a Function?

A **function** is a reusable block of code:

✔️ Performs a specific task
✔️ Can take input (parameters)
✔️ Can return output

💡 Helps break complex problems into smaller parts

---

# 🔁 What is Recursion?

**Recursion** = when a function calls itself

👉 Used to solve problems that can be divided into **smaller similar subproblems**

---

# ⚠️ Infinite Recursion (Danger 💀)

```cpp
#include <iostream>
using namespace std;

void infiniteRecursion() {
    cout << "Calling function" << endl;
    infiniteRecursion(); // ❌ No stopping condition
}
```

❗ This runs forever → causes **stack overflow**

---

# 🛑 Base Case (MOST IMPORTANT)

👉 A **base case** is the condition that stops recursion

✔️ Prevents infinite calls
✔️ Defines simplest version of problem

---

# 📚 Recursive Stack (Behind the Scenes)

Every recursive call uses **stack memory**

🧠 Think like this:

```id="stack1"
main()
 └── f(5)
      └── f(4)
           └── f(3)
                └── f(2)
                     └── f(1)
```

👉 Each call waits until base case is reached

---

# 🔄 Program Flow

1. Function calls itself
2. Stack keeps growing 📈
3. Base case reached
4. Stack starts **unwinding** 📉

---

# 🧠 Types of Recursion

---

## 🔵 1. Head Recursion

👉 Recursive call happens **first**

```cpp
#include <iostream>
using namespace std;

void headRecursion(int n) {
    if (n > 0) {
        headRecursion(n - 1);
        cout << n << " ";
    }
}
```

### 📌 Output:

```id="hrec"
1 2 3 4 5
```

👉 Work happens **after recursion**

---

## 🔴 2. Tail Recursion

👉 Recursive call happens **last**

```cpp
#include <iostream>
using namespace std;

void tailRecursion(int n) {
    if (n == 0) return;

    cout << n << " ";
    tailRecursion(n - 1);
}
```

### 📌 Output:

```id="trec"
5 4 3 2 1
```

👉 Work happens **before recursion**

---

# ⚠️ Stack Overflow

❗ Happens when:

* No base case
* Too many recursive calls

👉 System runs out of memory → program crashes 💀

---

# 🌳 Recursion Tree

Visual representation of recursion:

```id="tree1"
f(3)
├── f(2)
│   ├── f(1)
│   │   └── f(0)
```

👉 Helps understand:

* Call flow
* Subproblems

---

# ⏱️ Time Complexity

👉 Depends on number of calls

* Single recursion → **O(n)**
* Multiple calls → can be higher

---

# 💾 Space Complexity

👉 Based on recursion depth

* Depth = n → **O(n)** space

---

# 🧠 Key Takeaways

✔️ Recursion = function calling itself
✔️ Base case is **mandatory**
✔️ Uses stack memory
✔️ Powerful but must be used carefully

---

# 🧪 Practice Problems

🔥 Try these:

* 🔢 Factorial
* 🔁 Fibonacci
* 🔄 Reverse Array
* 🔤 Reverse String
* 🧩 Subsequence generation

---

# 🎯 Conclusion

Recursion is:

* 🧠 Elegant
* ⚡ Powerful
* 🔥 Core concept in DSA

---

