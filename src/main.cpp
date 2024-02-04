/** 
 * Simple program to convert a binary 
 * number to a decimal number, 
 */ 

// included libraries
#include <stdlib.h> 
#include <iostream> 
#include <cmath> 

// defined constants
#define ERROR_MESSAGE "\ninvalid arguments, please put in the form:\n \n \tbintodec <binary number> \n \n **note: binary number inputs can have a maximum of 8 digits.**\n\n"

/** 
 * convert: 
 * 
 * converts a string representing 
 * a binary number to its decimal form 
 * and returns the answer as an int 
 * 
 */
int convert(std::string user_binary){ 
    // variables representing the result and a power of 2 (starting with 0)
    auto answer = 0; 
    auto power = 0; 

    // iterate through the user input, adding the value of the binary digit to the answer
    for(int i = user_binary.length()-1; i >= 0; i--) { 
        auto current_digit = user_binary.at(i); 
        if(current_digit == '1'){ 
            answer += (pow(2.0, power));
        } 
        power++;
    } 

    // return the answer
    return (int)answer;
} 

/** 
 * verify_input: 
 * 
 * verifies that the user_input is a valid binary number with a  
 * maximum of 8 digits.
 */
bool verify_input(std::string user_input){ 
    // variable to keep track of the amount of digits
    auto iterator = 1;

    // checks user input to see if its valid, also checks if we go over the allowed amount of digits 
    for(char curr : user_input){  
        // checks if the current digit is not 1 or 0, if so, return false
        if(curr != '1'){ 
            if(curr != '0'){  
                return false;
            }
        }      

        // checks if iterator is over 8, meaning we have too many digits
        if(iterator > 8){ 
            return false;
        } 
        iterator++; 
    } 

    // if the entire loop executes, the user string is a valid binary number
    return true;
} 

/** 
 * main: 
 * 
 * executes the main functionality 
 * of the program
 */
int main(int argc, char** argv){ 
    // checks number of args, if invalid, print error message
    if(argc != 2){  
        std::cout << ERROR_MESSAGE;
        return 1;
    } 

    // creates a variable representing the user inputed binary number and verifies it
    auto user_string = argv[1];   
    if(!verify_input(user_string)){ 
        std::cout << ERROR_MESSAGE;
        return 1;
    } 

    // converts to decimal and prints the result
    int result = convert(user_string); 
    std::cout << "\nanswer:\n \n" << "\t" << user_string << " -> " << result << "\n \n";

    // terminate the program upon successful execution
    return 0;
}
