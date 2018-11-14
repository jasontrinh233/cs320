# Assignment 1

Quang Trinh

jasontrinh233@gmail.com

## Part 1

prog1_1.c is a program that prompts the user to enter their name. The program will then take 
in their full name and print a greeting to them using their full name.

## Part 2

The header file prog1_2.h will have prototype functions of `MakeStack()`, `Push()`, `Pop`, and `Grow()`.

The source file prog1_2.c has all the functions' implementations of the header file.

## Part 3

The driver file prog1_3.c will use prog1_2.h as its own library. It takes a single command line argument N. The command line argument N will be integer. If there is 
not a single command line argument your program should print an error message and quit.For valid inputs, the program will print a single right carrot take N lines of input from STDIN (entire line inputs).The program will split each of these lines on a space delimiter. The program should ignore multiple space characters (i.e. treat as many spaces in a row as a single space. It should also ignore leading and trailing spaces.
If there are exactly two tokens **AND** the first token is the string 'push' then your 
program should convert the second token to an integer and push the result onto the STACK. If there is exactly one token **AND** the token is the string 'pop' then the program should Pop a value off of the STACK and print it to STDOUT on its own line. All other input should be ignored. **The program should only print the assignment header, the error message, the carrot at the beginning of the input line orthe result of a Pop.** The program can assume that all STDIN inputs will be less than 256 characters, the 
command line argument will be an integer (if it exists) and the second token in a two token input that has 'push' as the first token will be an integer.

Example compilation:
```
gcc prog1_3.c prog1_2.c -o prog1_3
```

Example execution:
```
./prog1_3 8
```

Example run:
```
Assignment #1-3, Quang Trinh, jasontrinh233@gmail.com
> Push 4
> push 2
> abs
> pop
2
> pop
-1
> push 3 more
> push 2
> pop
2
```

