# 🌈 Hashing

### ⚡ *Fast Data Retrieval Made Easy*

---

## 🚀 What is Hashing?

**Hashing** is a technique used to:

* ⚡ Store data efficiently
* 🔍 Retrieve data quickly
* 📦 Manage large datasets

👉 It converts input (number/string) into a **fixed-size value (hash)**
👉 This hash points to a location in a **hash table**

---

# 🧠 Why Hashing?

✔️ Fast lookups (almost **O(1)**)
✔️ Efficient storage
✔️ Used in real-world systems

---

# 🍔 Real-Life Example (Food App)

Imagine using a food delivery app:

* 🥇 First time → you enter address & payment
* 🥈 Next time → it auto-fills

👉 How?

**Hashing stores your data and retrieves it instantly** ⚡

---

# 🔢 Number Hashing

Hashing maps numbers to an index:

```id="9a1h2f"
h(k) = k % p
```

👉 `k` = key
👉 `p` = prime number

---

## 🔍 Example

Keys: `{56, 75, 42, 88, 91}`
Prime: `p = 7`

| Key | Hash   | Index           |
| --- | ------ | --------------- |
| 56  | 56 % 7 | 0               |
| 75  | 75 % 7 | 5               |
| 42  | 42 % 7 | 0 ❌ (collision) |

---

# ⚠️ Collision

When two values map to same index 💥

👉 Example:

```id="q9pz4j"
56 → index 0  
42 → index 0  
91 → index 0
```

---

# 🔗 Chaining (Solution)

Use linked list at same index:

```id="k2s8m1"
Index 0 → 56 → 42 → 91
```

✔️ Prevents data loss
✔️ Keeps all values

---

# 🔄 Hashing in Arrays (Frequency Count)

## ❌ Method 1: Basic Loop

```cpp id="4l5c4h"
int count = 0;
for(int i = 0; i < 6; i++) {
    if(arr[i] == 6) count++;
}
```

⏱️ Time: O(N)

---

## ✅ Method 2: Hashing (Better)

```cpp id="gx7q3b"
int hashTable[10] = {0};

for(int i = 0; i < 6; i++) {
    hashTable[arr[i]]++;
}

cout << hashTable[6];
```

⚡ Time: O(N)
⚡ Query: O(1)

---

# 🔤 Character Hashing

Uses **ASCII values**

👉 Example:

```id="9s2nzl"
'a' → 97  
'z' → 122
```

---

## 🔥 Optimization (Best Trick)

```cpp id="j5dfq8"
hash[ch - 'a']++;
```

👉 Only 26 size needed instead of 123

---

# 📊 Time & Space Complexity

| Operation  | Complexity      |
| ---------- | --------------- |
| Build Hash | O(N)            |
| Query      | O(1)            |
| Space      | O(26) or O(123) |

---

# 🧠 Hashing Data Structures

## ⚡ C++

* `unordered_map` → O(1) avg
* `map` → O(log N)

## ☕ Java

* `HashMap` → O(1) avg
* `TreeMap` → O(log N)

---

# ⚙️ Hashing Techniques

---

## 1️⃣ Division Method

```id="s0jv3x"
h(k) = k % p
```

✔️ Simple
✔️ Efficient

---

## 2️⃣ Folding Method

👉 Split number → Add parts

Example:

```id="d7x8p2"
1234 → 12 + 34 = 46
```

---

## 3️⃣ Mid-Square Method

👉 Square number → Take middle digits

Example:

```id="c8m2zp"
56² = 3136 → middle = 13
```

---

# ⚠️ Challenges

❌ Collisions
❌ High Load Factor
❌ Poor hash functions
❌ Extra memory (chaining)

---

# 📊 Load Factor

```id="z1b7qw"
Load Factor = n / size
```

👉 High → more collisions
👉 Low → memory waste

---

# 🎯 Conclusion

Hashing is:

* ⚡ Fast
* 🧠 Efficient
* 🔥 Core of modern systems

Used in:

* Databases
* Password systems
* Search engines

---

# 🧪 Practice Problems

🔥 Try these:

* 🥇 Highest Occurring Element
* 🥈 Second Highest Frequency
* ➕ Sum of Frequencies

---

