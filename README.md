# HuffmanCoding


## How to Run

Follow these steps to compile and run the Huffman Coding program on your system:

### 1. Navigate to the Project Folder

```bash
cd HuffmanCoding
```

### 2. Compile the Program

Use the `g++` compiler to compile the source code:

```bash
g++ huffman_array_final_output.cpp -o huffman
```


### 3. Run the Executable

After successful compilation, run the program:

```bash
./huffman
```

### 4. Provide Input

The program will prompt you for:

* The number of unique characters
* The characters themselves
* Their corresponding frequencies

Example:

```
Enter number of unique characters: 6
Enter characters: a b c d e f
Enter their frequencies: 5 9 12 13 16 45
```

**Expected Output:**

```
Huffman Codes (Preorder Traversal):

f: 0
c: 100
d: 101
a: 1100
b: 1101
e: 111
```

---

