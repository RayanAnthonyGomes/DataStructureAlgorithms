# 🌈 C++ Basics

### ⚡ *The Language of Speed*

---

## 🚀 Welcome to the Coding World!

**C++ (CPP)** is a powerful, general-purpose programming language used in:

* 🖥️ System Development
* 🧠 Competitive Programming
* 🛠️ Software Engineering

This guide builds your **strong foundation** in C++.

---

# 🦴 1. Basic Skeleton

Every C++ program has a structure:

```cpp
#include <iostream>
using namespace std;

int main() {
    // Your code here
    return 0;
}
```

### 🔍 Explanation:

* 📥 `#include <iostream>` → Input/Output tools
* 📦 `using namespace std;` → Avoid writing `std::`
* 🚦 `main()` → Entry point of program
* 🧱 `{}` → Code block
* ✅ `return 0;` → Program finished successfully

---

# 📦 2. Data Types

Think of variables as containers 🧃

| Type      | Use              | Example |
| --------- | ---------------- | ------- |
| 🔢 int    | Whole numbers    | 5, -10  |
| 🌊 float  | Decimal numbers  | 3.14    |
| 🔤 char   | Single character | 'A'     |
| ✅ bool    | True/False       | true    |
| 📝 string | Text             | "Hello" |

```cpp
int age = 25;
float height = 5.9;
char grade = 'A';
bool isStudent = true;
string name = "Rahul";
```

---

# 🔄 3. Input / Output

### 🗣️ Talking to Computer

```cpp
int age;

cout << "Enter your age: ";
cin >> age;

cout << "Your age is: " << age;
```

### 🎯 Trick:

* `cout <<` → Output ➡️
* `cin >>` → Input ⬅️

---

# 🤔 4. If-Else (Decision Making)

```cpp
int money = 500;

if (money >= 1000) {
    cout << "I will buy a pizza";
} else {
    cout << "I will buy a burger";
}
```

👉 Like real life:

> If condition → do this
> Else → do that

---

# 🔁 5. For Loop (Repetition)

```cpp
for (int i = 1; i <= 5; i++) {
    cout << "Hello" << endl;
}
```

### 🧠 Structure:

```
for (start; condition; update)
```

---

# 🔄 6. While Loop

```cpp
int count = 1;

while (count <= 5) {
    cout << count << " ";
    count++;
}
```

⚠️ Always update variable or it runs forever 💀

---

# 📋 7. Switch Case

```cpp
int day = 3;

switch (day) {
    case 1: cout << "Monday"; break;
    case 2: cout << "Tuesday"; break;
    case 3: cout << "Wednesday"; break;
    default: cout << "Invalid";
}
```

### 🔑 Key Points:

* `break` → Stops execution
* `default` → Like `else`

---

# 🥚 8. Arrays

Store multiple values:

```cpp
int marks[5] = {90, 85, 92, 78, 88};

cout << marks[0]; // 90
```

⚠️ Index starts from **0**

---

# 🔤 9. Strings

```cpp
string firstName = "John";
string lastName = "Doe";

string fullName = firstName + " " + lastName;

cout << fullName;
cout << fullName.length();
```

---

# 🧩 10. Functions

```cpp
void sayHello() {
    cout << "Hello user!" << endl;
}

int main() {
    sayHello();
}
```

💡 Write once, use many times

---

# ⚔️ 11. Pass by Value vs Reference

### 📄 Pass by Value (Copy)

```cpp
void changeValue(int x) {
    x = 100;
}
```

👉 Original stays same

---

### 🔗 Pass by Reference (Original)

```cpp
void changeRealValue(int &x) {
    x = 100;
}
```

👉 Original changes

---

### 🧠 Analogy:

* 📄 Value → Photocopy
* 📓 Reference → Original notebook

---

# 🧠 Summary

✔️ Program Structure
✔️ Data Types
✔️ Input/Output
✔️ Conditions
✔️ Loops
✔️ Arrays & Strings
✔️ Functions
✔️ References

---

# 🎯 Next Step

👉 Don’t just read.
👉 Code it. Break it. Fix it.

---

## 🔥 If you want next level:

I can help you turn this into:

* 📁 Proper repo structure
* 🧠 Daily DSA roadmap
* 💼 GitHub that impresses recruiters

Just say: **next upgrade** 🚀
