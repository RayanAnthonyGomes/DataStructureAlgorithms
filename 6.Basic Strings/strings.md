# 🌈 Strings & Characters

### 🔤 *Text Handling in Programming*

---

## 🚀 What is a String?

A **string** is a sequence of characters used to represent text.

👉 Examples:

* `"Hello"`
* `"DSA"`
* `"12345"`

💡 Strings are available in almost **every programming language**

---

# 🧰 String Definitions Across Languages

```cpp
// C++
std::string str = "Hello";
```

```java
// Java
String str = "Hello";
```

```python
# Python
str = "Hello"
```

```javascript
// JavaScript
let str = "Hello";
```

---

# ⚔️ Mutability (IMPORTANT)

## 🟢 C++ (Mutable)

```cpp
std::string s = "taj";
s = s + 'j'; // "tajj"
```

✔️ Can change directly

---

## 🔴 Java (Immutable)

```java
String s = "raj";
s = s + 'j'; // new string created
```

❗ Original string unchanged
👉 New object is created

---

# 🎯 Accessing Characters

## C++

```cpp
std::string s = "raj";
char c = s[1]; // 'a'
```

## Java

```java
char c = s.charAt(1); // 'a'
```

📌 Indexing starts from **0**

---

# 🧱 Character Arrays

```c
char str[] = "Hello";
```

✔️ Stored in **contiguous memory**
✔️ Ends with `'\0'`

---

# 🔍 String vs Character

| Type         | Syntax | Example   |
| ------------ | ------ | --------- |
| 🔤 String    | `" "`  | `"Hello"` |
| 🔡 Character | `' '`  | `'H'`     |

---

# 🔁 Traversing a String

```cpp
for (int i = 0; i < s.length(); i++) {
    char c = s[i];
}
```

👉 Loop through each character

---

# 🔢 ASCII Values

| Character | ASCII  |
| --------- | ------ |
| A-Z       | 65–90  |
| a-z       | 97–122 |

---

## 🔥 Frequency Counting Trick

```cpp
int freq[256] = {0};
freq['c']++;
```

👉 `'c'` → ASCII 99
👉 Used in **hashing & string problems**

---

# ✂️ Substrings

## C++

```cpp
string s = "string";
string sub = s.substr(2, 3); // "rin"
```

👉 (start, length)

---

## Java

```java
String s = "string";
String sub = s.substring(2, 4); // "ri"
```

👉 (start, end) → end NOT included

---

# ⚠️ Key Difference

| Language | Method         | Meaning   |
| -------- | -------------- | --------- |
| C++      | substr(2,3)    | 3 chars   |
| Java     | substring(2,4) | end index |

---

# 🧠 Why Strings Matter

✔️ Used everywhere
✔️ Core of many DSA problems
✔️ Needed for interviews

---

# 🧪 Practice Problems

🔥 Try these:

* 🔄 Reverse String
* 🔁 Palindrome Check
* 🔢 Largest Odd Number
* 📏 Longest Common Prefix
* 🔄 Rotate String
* 🔡 Valid Anagram
* 📊 Sort by Frequency

---

# 🎯 Conclusion

Strings are:

* 🔤 Fundamental
* ⚡ Powerful
* 🧠 Essential for DSA

---

