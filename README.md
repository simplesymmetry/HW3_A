# CS2303: Systems Programming Concepts
```
C-term, 2019
Programming Assignment 3
Assigned: Monday, February 4, 2019
Due: Monday, February 11 , 20 19 , 6 :00 pm.
```
Please do each part of each section in sequence. Be sure to read each part of the assignment
before you start doing that part.

This assignment covers topics earlier in the course, plus these new topics: arrays, character
strings, dynamically-allocated memory, structs, and pointers to use with them. It also tests your
ability to write code which obeys a specification written by somebody else, such as the writers of
the C standard library.

# Section A

## Part 1

If you have not already done so, complete Lab 4. This includes implementing a function called
mystrcpy().

Then, from inside Eclipse, make a copy of your LAB4 project. Rename the new project
**HW3A_** **_yourusername_**.

## Part 2

In the rest of this assignment, you will be re-implementing several of the string functions from
the standard C library. Each must work exactly like the corresponding standard function. This
does not necessarily mean that they work the same internally. Rather, they appear the same from
outside the function. That is, if you give the same inputs to both functions, they produce exactly
the same results.

If you are unsure of how each standard function is supposed to work, consult the class notes
and/or consult the online man page.

For those unclear on the concept J, “It works exactly like the standard function” means ”it must
work exactly like the standard function.” It does not mean “it can work however you want,” or
“it can work the way you wish the standard function worked,” or “I’m not really sure how it is
supposed to work or how it actually does work.”

Use complete Doxygen header comments for all the functions you write (and for any functions
we give you which do not already have complete header comments)! So, for each function, the
first thing you need to do is write the header comment. Carefully specify what the function does,
the parameters, the return value, and any special conditions. Only then should you write the
function.


Just to make sure you do this, we are instructing the course staff not to help anyone who tries to
write or debug their function without writing the header comment first. Why? Because we are
being mean. Because these functions are very hard to get right if you are not perfectly clear on
exactly how they are supposed to operate in all circumstances. I do not want to waste your time
or their time.

In all your functions, if you need to step through a string, do it by incrementing pointers, not by
using array subscripts.

Note: By “incrementing pointers” I mean having a pointer and incrementing it using the ++
operator, like this: **p++**. I do not mean having a counter variable and adding that to the start of
the array, like this: **(p + i)**. This is because the C compiler treats ***(p + i)** exactly like
**p[i]** , so you do not get the potential speed advantage from using pointers.

You can use any of the functions you write yourself (or which we gave you) inside your own
functions. But you cannot use the standard functions. So, for example, you can use mystrlen2()
but not strlen(). The only standard string function you are allowed to use is strcmp() inside your
testing functions.

When you write your functions, you must also write appropriate test functions which thoroughly
test them.

## Part 3

Create your own versions these standard string functions: strcat() and strncat(). Note that we
have given you skeleton and testing code for strncat().

Again, be sure they work exactly like the originals. Let me repeat that: They must work exactly
like the originals, including all their shortcomings, even if you can think of a better way. As
before, write the header comment for each function first, before you start coding it. Be sure the
comment specifies what the function does in various circumstances, such as how many
characters it copies and what it does with the terminator.
It is vitally important that you understand how each of these functions is supposed to work. Pay
special attention to what strncat() does in the following “corner cases”:

- Length of the string is shorter than n.
- Length of the string is exactly equal to n.
- Length of the string is greater than n.

Add code to test your functions and prove that they work the same as the originals.

## Part 4

Create your own versions of strncpy() and strndup(), and add code to the main program to
demonstrate how they work. Once again, be sure they work exactly like the originals. Include
printf() statements so we know what the program is demonstrating. Be sure to test the various
“corner cases,” such as strings with lengths shorter than, equal to, and greater than the limit.


## Part 5

When you are done, use a terminal window and navigate to the directory where the source code
is. Then give this command:
**make docs**

This tells the make utility to run the doxygen utility. This will create two subdirectories: **html**
and **latex** ; we will ignore the **latex** subdirectory. Start the Web browser in your VM and
open the file **index.html** in the **html** directory. This is the home page for all the functions

you created. Try following the links to see the documentation for the various functions.

## Part 6

Submit your assignment using Canvas. Submit it as a single ZIP file, exported from Eclipse,
containing the following files:
1 All the source files, including header files.
2 The makefile. Be sure it can be used to “make clean” and “make docs”.
3 The Doxyfile.
4 The .project and .cproject files.

# Section B

## Part 1

Download the file **HW3Bstarter.zip** , import it into Eclipse, and rename the project
**HW3B_** **_yourusername_**. Compile and run it.

## Part 2

The skeleton and prototype for a function which prints a struct of type Employee. Fill in the code
and header comment. It should output something like this:
**Birth year = 1952
Starting year = 1999
Name = Mike Ciaraldi**

## Part 3

The skeleton, header comment, and prototype already exist for a function that allocates a struct
of type Employee and fills its fields with data passed in as parameters. Its prototype looks like
this:
struct Employee* makeEmployee(char* name, int birth_year, int start_year);

Fill in the body of the function. Be sure that this function copies (the contents of) the parameter
string into the array in the struct. Do not try copying the pointer to the string, since that string
might go away. Be sure you do not go off the end of the string, and be sure the string is properly
terminated.


## Part 4

Write a function which creates a struct of that type and fills it with random data. That is, it will
generate a random string (filled with printable characters) and two random integers, and then call
the makeEmployee() function from Part 2. Then it will return the newly-created struct.

You will have to create several “helper” functions, such as one which returns a random integer
from 0 to some specified maximum, inclusive. How can you do that? Well, there is a function
call rand() in the standard C library. You can find out about it using this command:
**man –s3 rand**
This will tell you how to use this function, including which header file or files you need to
#include. Why do you need the “-s3”? It turns out that there is also a command with that name,
and if you just ask the man program for rand, it will give you the man page for the command
instead of the function. For more about this, look at the man page for the man program itself!

When you call rand(), it returns a pseudo-random number from 0 to RAND_MAX, which is one
of the standard symbolic constants. RAND_MAX is a very large number, so you can use the
modulo operator to generate a smaller number. For example, if you have a random integer r, and
you calculate **r%n** , that will give you a random integer from 0 to n-1.

You will also need a helper function which generates a random string (of specified length) of
printable characters (in other words, not including ones like Tab or Newline). If you want to
restrict the set of printable characters (e.g., only capital letters, letters and numbers, etc.) feel
free. Remember, any time you have to do the same thing in more than one place, that is a
candidate for a function.

Tip: Consider first creating a function which generates a single random character. Then you can
call it from inside the function which creates the random string.

Another tip: In your code, avoid using the literal numeric codes for the characters. For example,
use ‘A’ instead of 65. The compiler does not care, but your code will be much more readable.

Yet another tip: Use the “man ascii” command to see the numeric codes for the various
characters. Observe the patterns. Note that, for example, the code for ‘B’ is the same as the code
for ‘A’, plus one. The code for ‘C’ is the code for ‘A’, plus two. And so on.

Once you have this working, if you run your program several times you will notice that you
always get the same sequence of random characters. This is a deliberate choice in the design of
the C library. It is intended to make testing easier by always generating the same sequence, so
the program always run the same. Once you have your program totally working, if you want, at
the beginning of the program add a call to the function srand(), like this:
**srand(time(0));**
That changes what is called the _seed_ of the pseudo-random sequence. In this case the seed is
based on the time, so every time you run the program you will get a different seed. Warning:
Whenever you use this technique, remember to call srand() only once, probably at the beginning
of the program. Do not call it repeatedly, such as inside a loop, because that will keep resetting
the seed, which you do not want to do.


Note: For each of your functions, write an appropriate test function. Of course, in the case where
you are using random data, there is no way to prove it is random. But try creating some structs
and printing them to show that this seems to work.

## Part 5

Then write a function which takes one parameter, a count. It should allocate an array which can
hold that many pointers to the Employee struct, then fill each element of the array with a pointer
to a newly-created struct filled with random data.

Finally, write a function that takes an array of pointers and a count, and prints out all the structs.
Modify your main program so it demonstrates all these functions.

Remember: Nothing in C works by magic. If you need an array to hold a character string or an
array, you need to allocate it before you can put data into it. If you allocate it with malloc() or
calloc(), be sure to free() it when you no longer need it. And if you are allocating space for a
character string, be sure to include space for the null terminator at the end.

## Part 6

Write a function that duplicates an array of pointers to structs of this type. Be sure you have a
way to tell the function the number of elements in the array. This is known as a “shallow copy”;
it duplicates the pointers but not the things pointed to.

Write a test function to demonstrate how it works.

## Part 7

Create a function which takes an array of pointers to the struct, and frees (de-allocates) all the
structs pointed to. Do you have to make any assumptions about the pointers? Add code to
demonstrate it. Note: Once you have freed a block of memory, there is no way to prove that it
has actually been freed. So, for this step, being able to run this function without error is a
sufficient demonstration.

## Part 8 (Extra Credit)

Create another version of the function which duplicates an array of pointers to the structs (i.e. the
function from Part 5). In this one, duplicate the structs, then fill the array with pointers to these
new structs. This is called a “deep copy.” Demonstrate.

## Part 9

As in Section A, use Doxygen to generate the documentation Web pages. Then look at them.

## Part 10

As you did for Section A, export and submit the project to Canvas.


