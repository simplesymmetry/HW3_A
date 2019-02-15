## CS2303: Systems Programming Concepts.
## C-term, 2019.
## Programming Assignment 3
Assigned: Monday, February 4, 2019
Due: Monday, February 11, 2019, 6:00 pm.

Please do each part of each section in sequence. Be sure to read each part of the assignment before you start doing that part.

This assignment covers topics earlier in the course, plus these new topics: arrays, character strings, dynamically-allocated memory, structs, and pointers to use with them. It also tests your ability to write code which obeys a specification written by somebody else, such as the writers of the C standard library.

**Section A**

# **Part 1**

If you have not already done so, complete Lab 4. This includes implementing a function called mystrcpy().

Then, from inside Eclipse, make a copy of your LAB4 project. Rename the new project **HW3A\_**** yourusername**.

**Part 2**

In the rest of this assignment, you will be re-implementing several of the string functions from the standard C library. Each must work exactly like the corresponding standard function. This does not necessarily mean that they work the same internally. Rather, they appear the same from outside the function. That is, if you give the same inputs to both functions, they produce exactly the same results.

If you are unsure of how each standard function is supposed to work, consult the class notes and/or consult the online man page.

For those unclear on the concept , &quot;It works exactly like the standard function&quot; means &quot;it must work exactly like the standard function.&quot; It does not mean &quot;it can work however you want,&quot; or &quot;it can work the way you wish the standard function worked,&quot; or &quot;I&#39;m not really sure how it is supposed to work or how it actually does work.&quot;

Use complete Doxygen header comments for all the functions you write (and for any functions we give you which do not already have complete header comments)! So, for each function, the first thing you need to do is write the header comment. Carefully specify what the function does, the parameters, the return value, and any special conditions. Only then should you write the function.

Just to make sure you do this, we are instructing the course staff not to help anyone who tries to write or debug their function without writing the header comment first. Why? Because we are being mean. Because these functions are very hard to get right if you are not perfectly clear on exactly how they are supposed to operate in all circumstances. I do not want to waste your time or their time.

In all your functions, if you need to step through a string, do it by incrementing pointers, not by using array subscripts.

Note: By &quot;incrementing pointers&quot; I mean having a pointer and incrementing it using the ++ operator, like this: **p++**. I do not mean having a counter variable and adding that to the start of the array, like this: **(p + i)**. This is because the C compiler treats **\*(p + i)** exactly like **p[i]**, so you do not get the potential speed advantage from using pointers.

You can use any of the functions you write yourself (or which we gave you) inside your own functions. But you cannot use the standard functions. So, for example, you can use mystrlen2() but not strlen(). The only standard string function you are allowed to use is strcmp() inside your testing functions.

When you write your functions, you must also write appropriate test functions which thoroughly test them.

## **Part 3**

Create your own versions these standard string functions: strcat() and strncat(). Note that we have given you skeleton and testing code for strncat().

Again, be sure they work exactly like the originals. Let me repeat that: They must work exactly like the originals, including all their shortcomings, even if you can think of a better way. As before, write the header comment for each function first, before you start coding it. Be sure the comment specifies what the function does in various circumstances, such as how many characters it copies and what it does with the terminator.

It is vitally important that you understand how each of these functions is supposed to work. Pay special attention to what strncat() does in the following &quot;corner cases&quot;:

- Length of the string is shorter than n.
- Length of the string is exactly equal to n.
- Length of the string is greater than n.

Add code to test your functions and prove that they work the same as the originals.

## **Part 4**

Create your own versions of strncpy() and strndup(), and add code to the main program to demonstrate how they work. Once again, be sure they work exactly like the originals. Include printf() statements so we know what the program is demonstrating. Be sure to test the various &quot;corner cases,&quot; such as strings with lengths shorter than, equal to, and greater than the limit.

## **Part 5**

When you are done, use a terminal window and navigate to the directory where the source code is. Then give this command:

**make docs**

This tells the make utility to run the doxygen utility. This will create two subdirectories: **html** and **latex** ; we will ignore the **latex** subdirectory. Start the Web browser in your VM and open the file **index.html** in the **html** directory. This is the home page for all the functions you created. Try following the links to see the documentation for the various functions.

## **Part 6**

Submit your assignment using Canvas. Submit it as a single ZIP file, exported from Eclipse, containing the following files:

1. 1All the source files, including header files.
2. 2The makefile. Be sure it can be used to &quot;make clean&quot; and &quot;make docs&quot;.
3. 3The Doxyfile.
4. 4The .project and .cproject files.
