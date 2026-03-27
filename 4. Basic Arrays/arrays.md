🌈 Understanding Arrays
📦 A Comprehensive Overview
🚀 What is an Array?

An Array is one of the most fundamental data structures in programming.

👉 It stores a collection of elements in a linear format
👉 All elements are of the same data type

💡 Examples:

🔢 Integers → 1, 2, 3
🌊 Floats → 3.14, 2.5
🔬 Doubles → 10.55
🧱 Defining an Array

In C++, we declare an array like this:

int arr[] = {4, 2, 3};

👉 This creates an array with 3 elements

🔁 Traversing an Array

Traversing means visiting each element one by one

for(int i = 0; i < 3; i++) {
    cout << arr[i] << endl;
}
📌 Output:
4
2
3
🧠 Key Idea:
Start from index 0
End at n - 1
Use loops (usually for loop)

⚠️ Always stay within bounds to avoid errors 💀

🎯 Accessing Elements

Each element is accessed using its index

cout << arr[0]; // First element
cout << arr[2]; // Third element
📌 Important:
Index starts from 0
Last index = n - 1
🧠 Memory Storage

Arrays are stored in contiguous memory 🧩

👉 Meaning:

[4][2][3]

✔️ Stored next to each other in memory
✔️ Fast access using index

⚠️ Limitation:
Fixed size (cannot change later)
🧮 Two-Dimensional Arrays (2D Arrays)

Used for matrices or grids 📊

int arr[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
🔁 Traversing 2D Array
for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 3; j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
📌 Output:
1 2 3
4 5 6
🧪 Practice Problems

Try these to get strong 💪

➕ Sum of array elements
🔢 Count odd numbers
🔄 Reverse an array
✅ Check if array is sorted
🧠 Why Arrays Matter

✔️ Fast access (O(1))
✔️ Simple and efficient
✔️ Foundation for advanced DSA

🎯 Conclusion

Arrays are:

📦 Simple
⚡ Efficient
🧠 Essential for DSA

They are used in almost every programming language:

C++
Java
Python
JavaScript