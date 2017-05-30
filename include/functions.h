/**
 * These functions implement the stack and queue data structures
 * to evaluate if a given string or vector follows specific
 * criteria. The function balanced() determines if bracket
 * symbols are used correctly in a string, while palindrome()
 * determines if a vector of objects follows a palindrome
 * pattern.
 * @author Samantha Teskey
 * @file functions.h
 * @version 5-29-2017
 */

#ifndef __H_FUNCTIONS_
#define __H_FUNCTIONS_

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>

/**
 * This function uses an array-based stack to determine if
 * a given string contains valid use of 'bracket' symbols
 * to enclose sub-expressions. The symbols ▰, ▲, and ◯ must
 * appear in pairs in order for the function to return true.
 * 
 * Sources used: 
 * http://www.cplusplus.com/reference/string/string/ 
 * https://stackoverflow.com/questions/2172943
 *      /size-of-character-a-in-c-c 
 * https://stackoverflow.com/questions/1315041
 *      /how-can-i-iterate-through-a-string
 *      -and-also-know-the-index-current-position 
 * http://www.cplusplus.com/reference/stack/stack/ 
 */
bool balanced(std::string expression){

    // Characters that will be treated as brackets
    static const char* RHOMBUS = u8"\u25b0"; //"▰";
    static const char* TRIANGLE = u8"\u25b2"; //"▲";
    static const char* CIRCLE = u8"\u25cb"; //"◯";

    // Get the size of the special characters 
    int charSize = std::char_traits<char>::length(CIRCLE);
    //int charSize = sizeof(CIRCLE);
    std::cout << "Character size: " << charSize << std::endl;

    // Create a stack to hold chars as we process them
    std::stack<char*, std::vector<char*> > charStack;

    // Iterate through all the chars in the string
    for(auto it = expression.begin(); it != expression.end(); ++it){
        // Obtain the current index as the distance from the start
        int index = std::distance(expression.begin(), it);
        // Obtain the substring just large enough for these characters
        std::string charSubStr = expression.substr(index, charSize);
    

        char currChar[charSize];
        // Only process the bracket-type characters
        if(0 == charSubStr.compare(0, charSize, RHOMBUS)){
            strcpy(currChar, RHOMBUS); 
        }
        else if(0 == charSubStr.compare(0, charSize, TRIANGLE)){
            strcpy(currChar, TRIANGLE); 
        }
        else if(0 == charSubStr.compare(0, charSize, CIRCLE)){
            strcpy(currChar, CIRCLE); 
        }
        else{
            continue;
        }

        // Check if we have something on the stack
        if(charStack.size() > 0){
            // If the characters match, pop the stack
            if(0 == strcmp(currChar, charStack.top())){ 
                char* popped = charStack.top();
                std::cout << "Popping: " << popped << std::endl;
                charStack.pop();
                delete[] popped;
                continue;
            }
        }

        // If they don't match, push the character onto the stack
        char* pushChar = new char[charSize];
        strcpy(pushChar, currChar); 
        charStack.push(pushChar);
        std::cout << "Pushing: " << std::string(pushChar) << std::endl;
    }
    
    // If the expression is balanced, no chars should be left
    if (charStack.empty()){
        return true;
    }

    // We will need to free up the memory if the above is not true
    std::cout << "Stack not empty: " << std::endl;
    while(!charStack.empty()){
        char* popped = charStack.top();
        std::cout << std::string(popped) << std::endl;
        charStack.pop();
        delete[] popped;
    }

    return false;
}

/**
 *
 * Sources used:
 * http://www.cplusplus.com/reference/vector/vector/ 
 * http://www.cplusplus.com/reference/stack/stack/ 
 * http://www.cplusplus.com/reference/queue/queue/
 */
template <typename T>
bool palindrome(std::vector<T> v){
    // Create a stack (FILO) 
    std::stack<T> myStack;
    // Create a queue (FIFO)
    std::queue<T> myQueue;

    // Fill both with the contents of the vector
    for(auto it = v.begin(); it != v.end(); ++it){
        myStack.push(*it);
        myQueue.push(*it);
    }
    
    // Pop the top of the stack and the front of the queue 
    while(!myQueue.empty() && !myStack.empty()){
        T front = myQueue.front();
        myQueue.pop();
        T top = myStack.top();
        myStack.pop(); 
        
       // These should be the same in a palindrome
       if(front != top){
           return false;
       } 
    }
    // If the contents were equivalent backward (stack) and forward
    // (queue), we have a palindrome. 
    return true;
}

#endif
