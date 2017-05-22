# CIS263 Stacks, Queues, and Trees

For this assignment you will implement in C++ a few simple algorithms.  These algorithms are considered some of the "classic" algorithms used to teach familiarity with these data structures.  Specifically, you are to write

- ```bool balanced(std::string expression);``` - You are given a made-up language.  This language uses the symbols ▰, ▲, and ◯ as "brackets".  Each symbol must be matched with itself to close a sub-expression.  For instance, ▰ ▲ ◯ ◯ ▲ ▰ is valid, but ▰ ▲ ◯ ▲ ▰ is not.  Using a stack return true or false to note whether the input string is or is not valid.

- ```double eval(BinarySearchTree<char> bst);``` - You are given a binary search tree (class included in the ```./includes/BinarySearchTree.h``` file) that represents an arithmetic expression.  You need to write a function that will evaluate the expression and return a double value.

- ```bool palindrome(std::vector<T> v);``` - Given a vector of objects (you don't know the type so you must program generically), use a stack and a queue to determine if the vector is a palindrome.  Do not use any vector indexing operators (i.e. no "[]").

All code must be in a file called ```functions.h```.
