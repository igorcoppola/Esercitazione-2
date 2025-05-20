///@file user_interface.cpp
///@brief Implementation of a menu for the user
///@author Coppola Igor - Morandi Marco

#include "user_interface.h"

/// @brief print the possible selection for the user
/// @return user choice 
int displayMenu()
{
    int choice;
    do
    {
        cout << "*****   MENU   ******" << "\n";
        cout << "0 - Exit" << "\n";
        cout << "1 - View all function in the list" << "\n";
        cout << "2 - Insert a function in the list" << "\n";
        cout << "3 - Delete a function from the list" << "\n";
        cout << "4 - Delete all function from the list" << "\n";
        cout << "5 - Select a function from the list" << "\n\n";

        cout << "Please insert your choice: " << "\n";
        cin >> choice;
        if(choice < 0 || choice > 5)
        {
            ErrorMessage("Invalid input. Please insert a number from 0 to 5 included");
        }
    } while (choice < 0 || choice > 5);

    return choice;
}

void ErrorMessage(const char* string)
{
    cout << "User_Interface - " << string << "\n";
}

/// @brief print list of current functions
/// @param list list of functions
void displayList(vector <Function*> list)
{
    int dim = list.size();
    if(list.empty())
    {
        cout << "Display List - The list is empty" << "\n";
        return;
    }
    for(int i = 0; i < dim; i++)
    {
        cout << " << i << -   ";
        list[i]->Dump();
        cout << "\n" << endl;
    }
}

/// @brief delete an element of the list
/// @param list list of function 
/// @return 0 if insertion went smootly
void deleteFunction(vector <Function*> list)
{
    int choice;

    //Controlling how many function are inside the list
    int dim = list.size();

    //Controll if the list is empty
    if(list.empty())
    {
        cout << "Delete function - The list is empty" << "\n";
        return;
    }

    cout << "Insert the ID of the function that you want to delete:" << "\n";

    do
    {
        cin >> choice;
        if(choice > dim || choice < 0)
        {
            ErrorMessage("There is no function with the ID inserted");
            cout << "Choose from these possible id:" << "\n";
            //Print all element of the list, so that rhe user can see all the possible value ID
            for(int i = 0; i < dim; i++)
            {
                cout << " << i << -   ";
                list[i]->Dump();
                cout << "\n" << endl;
            }
        
            cout << "Please insert a valid ID" << endl;
            cin >> choice;
        }
    } while (choice > dim || choice < 0);

    cout << "The function with the inserted ID is: \n";
    list[choice]->Dump();

    cout << "If you want to delete this function press 0, otherwise press 1: " << "\n";
    int cancel;
    cin >> cancel;
    //Controlling cancel if = 0 the element choice inside the list will be elimineted
    do
    {
        cout << "Invalid input. Please insert 0 (to not cancel the function) or 1 (to cancel the function)" << "\n";
        cin >> cancel;
    } while (cancel != 0 || cancel != 1);
    
    if(cancel == 0)
    {
        list.erase(list.begin() + choice);
    }
    else if (cancel = 1)
        return;
}