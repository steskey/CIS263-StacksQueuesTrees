# CIS263 Stacks, Queues, and Trees

For this assignment you will implement in C++ a few simple algorithms.  These algorithms are considered some of the "classic" algorithms used to teach familiarity with these data structures.  Specifically, you are to write

- ```bool balanced(std::string expression);``` - You are given a made-up language.  This language uses the symbols ▰, ▲, and ◯ as "brackets".  Each symbol must be matched with itself to close a sub-expression.  For instance, ▰ ▲ ◯ ◯ ▲ ▰ is valid, but ▰ ▲ ◯ ▲ ▰ is not.  Using a stack return true or false to note whether the input string is or is not valid.
