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
 */
bool balanced(std::string expression){

    // Characters that will be treated as brackets
    static const char* RHOMBUS = "▰";
    static const char* TRIANGLE = "▲";
    static const char* CIRCLE = "◯";

    // Get the size of the special characters 
    int charSize2 = sizeof(RHOMBUS)/sizeof(RHOMBUS[0]);
    std::cout << "Character size: " << charSize2 << std::endl;
    int charSize = std::char_traits<char>::length(RHOMBUS);
    std::cout << "Character size from length: " << charSize << std::endl;

    // Create a char array with a max capacity equal to the string 
    char charStack[expression.length()][charSize];
    //char charStack[charSize][expression.length()];

    // Track the current size of our stack
    int stackSize = 0;
   
    // Iterate through the all the chars in the string 
    for(auto it = expression.begin(); it != expression.end(); ++it){

        // Obtain the current index as the distance from the start
        int index = std::distance(expression.begin(), it);

        // Obtain the substring that encompasses a special character
        std::string charSubStr = expression.substr(index, charSize);

        // Only process the bracket-type characters
        if(0 == charSubStr.compare(0, charSize, RHOMBUS) || 0 == charSubStr.compare\
                (0, charSize, TRIANGLE) || 0 == charSubStr.compare(0, charSize, CIRCLE)){
           
            std::cout << "Current substring: " << charSubStr << std::endl;
           
            // If this character is on the top of the stack, pop it
            if(stackSize > 0){
                if(0 == charSubStr.compare(0, charSize, charStack[(stackSize - 1)*charSize])){
                    std::cout << "Popped substring!" << std::endl;
                    --stackSize;
                    continue;
                }
            }
            // Otherwise, push the character onto the stack
            charSubStr.copy(charStack[stackSize*charSize], charSize);
            ++stackSize;
            std::cout << "Pushed substring!" << std::endl;
            std::cout << "Contents: " << charStack[(stackSize - 1)*charSize] << std::endl;
        }
        else{
            //std::cout << "Not a bracket char" << std::endl;
        } 
    } 
   
    // If expression is balanced, no chars should be left on the stack
    std::cout << "Ending stack: " << std::endl;
    for(int i = 0; i < stackSize * charSize; i += charSize)
    {
        std::cout << charStack[i] << std::endl; 
    }
    std::cout << "Stack size: " << stackSize << std::endl;
    return (0 == stackSize);
}

/**
 *
 */
template <typename T>
bool palindrome(std::vector<T> v){

}

#endif
