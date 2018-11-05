# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

An artificial long word said to mean a lung disease caused by
inhaling very fine ash and sand dust.

## According to its man page, what does `getrusage` do?

getrusage returns the system resource usage measures for "who". "Who" can be
RUSAGE_SELF, RUSAGE_CHILDREN, or RUSAGE_THREAD

What are threads?
What are processes?

A thread in computer science is short for a thread of execution. Threads
are a way for a program to divide (termed "split") itself into two or more
simultaneously (or pseudo-simultaneously) running tasks. Threads and processes
differ from one operating system to another but, in general, a thread is
contained inside a process and different threads in the same process share
same resources while different processes in the same multitasking operating
system do not. Threads are lightweight, in terms of the system resources they
consume, as compared with processes.

In computing, a process is an instance of a computer program that is being sequentially
executed[1] by a computer system that has the ability to run several computer programs concurrently.

A computer program itself is just a passive collection of instructions, while a process
is the actual execution of those instructions.

Several processes may be associated with the same program; for example, opening up
several windows of the same program often means more than one process is being executed.
In the computing world, processes are formally defined by the operating systems (OS) running
them and so may differ in detail from one OS to another; for example in Microsoft
Windows environment each instance of the same application is called a task.

the function getrusage returns an int that corresponds with resource usage.

## Per that same man page, how many members are in a variable of type `struct rusage`?

there are 16 members in the variable type 'struct rusage'.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

we pass 'before' and 'after' by reference instead of by value even though we are not changing their contents because passing
copies of structs (by value) can be memory intensive (potential stack overflow). the calculate function prototype accepts two pointers
to different rusage structs, usage of pointers is more memory efficient.

"pointers provide the ability to pass data structures by pointer without incurring large overhead"

passing by reference means ...
passing by value means ...

The simplest way to get this is on an Excel file. Let’s say for example that you have
two numbers, 5 and 2 in cells A1 and B1 accordingly, and you want to find their sum in
a third cell, let's say A2. You can do this in two ways.

Either by passing their values to cell A2 by typing = 5 + 2 into this cell. In this
case, if the values of the cells A1 or B1 change, the sum in A2 remains the same.

Or by passing the “references” of the cells A1 and B1 to cell A2 by typing = A1 + B1. In
this case, if the values of the cells A1 or B1 change, the sum in A2 changes too.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words
## from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

main goes about reading words from a file by fopening text with file pointer and initializing 'c' as the first character in text.
we then loop until the EOF, first checking to see if 'c' is an alphabetical character
or an apostrophe. if it is, 'c' is appended to the word array at index position and
index is incremented by one. if the index exceeds LENGTH (set to 45), consume
the remainder of the alphabetical string, if c = '\0', then the while loop is exited
and the index is reset to 0. If 'c' is a number, consume the rest of the alphanumeric
string (checking with isalumn()) and set index 0 to prepare for the next word.
Otherwise, if index is > 0 and all other criteria are met, we must have found a whole
word. We terminate the current word by setting index to the null terminator and increment
words to keep track of how many words we have checked. we then check to see if the word
exists in dictionary while timing performance with getrusage. if the word does not exist
in dictionary (mispelled is true), then print the word and increment mispellings. then
reset index to 0 to prepare for the next word.

## Why do you think we used `fgetc` to read each word's characters one at a time rather
## than use `fscanf` with a format string like `"%s"` to read whole words at a time?
## Put another way, what problems might arise by relying on `fscanf` alone?

fgetc is useful because we can check each character to confirm whether it is
a letter or apostrophe as well as determine the end of a word based on whitespace.
fscanf does not take into account whitespace

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

we declared parameters for 'check' and 'load' as const because their parameters,
word and dictionary respectively, should not change throughout the execution of
the program.

parameters for 'check' and 'load' are pointers to a constant character. the pointers
cannot change the values of the characters they are pointing to. this way, check and load
are reading input and not altering anything.
