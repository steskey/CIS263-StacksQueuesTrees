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
    // Create a char array with a max capacity equal to the string 
    //char charStack[expression.length()][charSize];
    //char charStack[charSize][expression.length()];

    // Create a stack to hold chars as we process them
    std::stack<char*, std::vector<char*> > charStack;

    // Track the current size of our stack
    //int stackSize = 0;
 
    // Iterate through all the chars in the string
    for(auto it = expression.begin(); it != expression.end(); ++it){
        // Obtain the current index as the distance from the start
        int index = std::distance(expression.begin(), it);
        // Obtain the substring just large enough for these characters
        std::string charSubStr = expression.substr(index, charSize);
    

        // Only process the bracket-type characters
        if(0 == charSubStr.compare(0, charSize, RHOMBUS, 0, charSize) || 0 == charSubStr.compare(0, charSize, TRIANGLE, 0, charSize) || 0 == charSubStr.compare(0, charSize, CIRCLE, 0, charSize)){
            // Check if we have something on the stack
            if(charStack.size() > 0){
                if(0 == charSubStr.compare(0, charSize, charStack.top(), 0, charSize)){
                    // If the characters match, pop the stack
                    char* popped = charStack.top();
                    std::cout << "Popping: " << std::string(popped) << std::endl;;
                    charStack.pop();
                    delete[] popped;
                    continue; 
                }
            }
            // If they don't match, push the character onto the stack
            char* pushChar = new char[charSize];
            std::cout << "Pushing: " << std::string(pushChar) << std::endl;
            charSubStr.copy(pushChar, charSize);  
            charStack.push(pushChar);
        }
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
 */
template <typename T>
bool palindrome(std::vector<T> v){


    return true;
}

#endif
