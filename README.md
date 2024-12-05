#  **Project Description**

This project implements the **Hamming (8,4) Algorithm**, a method for error detection and correction capable of handling one-bit errors in a given data stream. The program offers an interactive interface for users to perform the following operations:

---

## **Usage**

### 1️ - **Get the Repository:**
Option 1: Clone via HTTPS    

Clone the repository using HTTPS for quick and easy setup:
   ```bash
   git clone https://github.com/SaidMehroj/hamming
   ```
This method is ideal for users who don't have SSH keys configured.

Option 2: Clone via SSH

If you have SSH keys set up for your GitHub account, use this command for a secure connection:
   ```bash
   git clone git clone git@github.com:SaidMehroj/hamming.git
   ```
This method provides enhanced security and avoids repeated authentication prompts.   

Option 3: Download ZIP

Alternatively, download the repository as a ZIP file:

1. Visit the repository on GitHub.
2. Click the green Code button.
3. Select Download ZIP.
4. Extract the ZIP file to your desired directory.

This method is suitable if you prefer not to use Git.

### 2️ - **Build the Program:**
Linux  
   ```bash
   cmake -S . -B build
   cd build
   make
   ```
Windows  
   ```bash
   mkdir build 
   cd build
   cmake .. -G "MinGW Makefiles"
   cmake --build .
   ```   

### 3️ - **Run the Program:**
   ```bash
   ./hamming_main
   ```

---

## **Interactive Interface**

When you run the program, you will see the following menu:

```
CHOOSE OPTION:
1. ENTER A DECIMAL NUMBER
2. ENCODE
3. DECODE
4. INVERT RANDOM BIT
5. EXIT
```

---

## **Workflow**

1. **Option 1**: Input a Decimal Number: Convert a decimal number into its binary representation.
2. **Option 2**: Encode: Apply the Hamming (8,4) algorithm to encode the input binary data, introducing error correction bits.
3. **Option 3**: Decode: Decode the previously encoded data and retrieve the original binary data.
4. **Option 4**: Simulate Errors: Randomly invert one bit in the encoded data to simulate transmission errors and then decode the corrupted data to demonstrate the algorithm's error-correction capabilities.
5. **Option 5**: Exit: Close the program.
## **Key Features**
1. Error Correction: The Hamming (8,4) algorithm can detect and correct one-bit errors.
2. Interactive CLI: A simple command-line interface allows users to seamlessly interact with the program's features.
3. Binary Representation: Converts numbers to binary for visualization and manipulation.
4. Bit-Level Operations: Simulates bit inversion and correction for educational purposes.

---

**Thank you for choosing this algorithm**