# Brainfuck-interpreter
This is a brainfuck interpreter implemented in c++

Notes on how to use: 
  1. enter your input brainfuck code into a file labeled 'file.txt'
  2. Run the main code in cpp
  3. If this does not work, try adding the path to the working directory in the variable named '*src*'
  4. There is also an implementation for debugging the code. Use the '#' character to get details on the code. This information is written into another text file named 'debug.txt'.
     Every entry into the debug file includes:
       a. index of the pointer within the memory
       b. value at the specified pointer
       c. position of the interpreter(index of the character in the input code)
       d. the value of all visited elements
    PS: If a '#' character is present within a for loop that is never executed, it does not show
 5. the memory is a 30,000 byte array.
 6. Input numbers will be prompted within the c++ console.
 7. The output will be shown within the c++ console.
