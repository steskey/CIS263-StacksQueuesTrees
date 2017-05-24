# CIS263 Stacks, Queues, and Trees

For this assignment you will implement in C++ a few simple algorithms.  These algorithms are considered some of the "classic" algorithms used to teach familiarity with these data structures.  Specifically, you are to write

- ```bool balanced(std::string expression);``` - You are given a made-up language.  This language uses the symbols ▰, ▲, and ◯ as "brackets".  Each symbol must be matched with itself to close a sub-expression.  For instance, ▰ ▲ ◯ ◯ ▲ ▰ is valid, but ▰ ▲ ◯ ▲ ▰ is not.  Using a stack return true or false to note whether the input string is or is not valid.

- ```bool palindrome(std::vector<T> v);``` - Given a vector of objects (you don't know the type so you must program generically), use a stack and a queue to determine if the vector is a palindrome.  Do not use any vector indexing operators (i.e. no "[]").

- Study for exam.  Read sections 1.4, 1.5, 1.6, ensure you understand Chapter 2, Chapter 3, and sections 4.2, 4.3, 4.4, 4.6, 4.7, and 4.8 in the book. Ensure you understand Red Black trees - these are NOT in the book so you will need to refer to your notes and your own research.  With each tree type make sure you can perform an insertion and balance the tree (if necessary).

All code must be in a file called ```functions.h```.
