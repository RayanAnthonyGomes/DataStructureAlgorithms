
# 🔁 Parameterized Recursion
    
## 📖 What is Parameterized Recursion?

Parameterized recursion is a recursive approach where **all necessary data is passed as parameters** instead of relying on global variables.

### ✅ Advantages
- Better control over recursion flow
- Cleaner and more readable code
- No dependency on global variables

---

## 🧩 Example 1: Print Value X, N Times

### 📝 Problem
Print a value `X`, exactly `N` times using recursion.

### 💡 Code (C++)
```cpp
#include <bits/stdc++.h>
using namespace std;

void printXNTimes(int x, int n) {
    if (n == 0) return;     // Base case
    cout << x << " ";
    printXNTimes(x, n - 1);
}

int main() {
    printXNTimes(4, 5);
}
````

### ⚙️ Explanation

Each recursive call prints `x` and reduces `n` until it reaches 0.

---

## 🔢 Example 2: Print Numbers from 1 to N

### 🧠 Head Recursion (Work After Call)

```cpp
void print1ToN(int n) {
    if (n == 0) return;
    print1ToN(n - 1);
    cout << n << " ";
}
```

👉 Output: `1 2 3 4 5`

---

### ⚡ Tail Recursion (Work Before Call)

```cpp
void print1ToN(int i, int n) {
    if (i > n) return;
    cout << i << " ";
    print1ToN(i + 1, n);
}
```

👉 Output: `1 2 3 4 5`

---

## 🔽 Example 3: Print Numbers from N to 1

### ⚡ Tail Recursion

```cpp
void printNto1(int n) {
    if (n == 0) return;
    cout << n << " ";
    printNto1(n - 1);
}
```

👉 Output: `5 4 3 2 1`

---

### 🧠 Head Recursion

```cpp
void printNto1(int i, int n) {
    if (i > n) return;
    printNto1(i + 1, n);
    cout << i << " ";
}
```

👉 Output: `5 4 3 2 1`

---

## ⚖️ Head vs Tail Recursion

| Feature      | Head Recursion       | Tail Recursion                  |
| ------------ | -------------------- | ------------------------------- |
| Execution    | After recursive call | Before recursive call           |
| Optimization | Harder               | Easier (Tail Call Optimization) |
| Use Case     | Trees, Backtracking  | Loop-like problems              |

---

## ⏱️ Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(n) (due to recursion stack)

---

## 🧠 Key Takeaways

* Always define a **base case**
* Use parameters to control recursion flow
* Tail recursion can often be converted into loops

```

---

