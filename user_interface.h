///@file user_interface.h
///@brief Declaration of function used for the user interface
///@author Coppola Igor - Morandi Marco


#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H


#include <iostream>
#include <cstdlib>
#include <vector>
#include "CFunction.h"
#include "CExponential.h"
#include "Power.h"
#include "Polynomial.h"

/// @brief print the possible selection for the user
/// @return user choice 
int displayMenu();

/// @brief print list of current functions
/// @param list list of functions
void displayList(vector <Function*> list);

///@brief add an element at the end of the list
///@return 0 if insertion went smootly
void insertFunction(vector <Function*> list);

/// @brief delete an element of the list
/// @param list list of function 
/// @return 0 if insertion went smootly
void deleteFunction(vector <Function*> list);

/// @brief delete all function from the list
/// @param list list of functions
/// @return 0 if insertion went smootly
void flushList(vector <Function*> list);

/// @brief select a function from the list. Can print the value of function for a specific input
/// @param list list of functions
void selectFunction(vector <Function*> list);

///@brief print error message 
///@param string error message to be printed
void ErrorMessage(const char* string);

#endif



