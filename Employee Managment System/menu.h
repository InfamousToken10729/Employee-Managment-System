#include <iostream>
#include <string>
#include <limits>
#include "database.h"
#include "employee.h"
#include "validator.h"
#include "inputhandler.h"

using namespace std;
#define el "\n"

class Menu {
    Input_Handler user_input;
    Employee_Validator validate_input;
    Database employee_database;
    string input;
    Employee New_employee;
    int validate_state = 0;  // Initialize validate_state to a default value

public:
    void display_menu() {
        system("cls");
        cout << "Staff Management System" << el << el;
        cout << "====================================================" << el;
        cout << "Main Menu\n"
            << "====================================================\n";
        cout << "1. Add New Employee.\n"
            << "2. Edit Employee data.\n"
            << "3. Search Employee.\n"
            << "4. Search Employee with high wage.\n"
            << "5. Delete Employee data.\n"
            << "6. Exit Program.\n";
        select_option();
    }

    void select_option() {
        int option;

        // Validate user input
        while (!(cin >> option) || option < 1 || option > 6) {
            cout << "Invalid choice. Please enter a valid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Switch case to handle different options
        switch (option) {
        case 1: {
            cout << "Add New Employee selected";
            execute_option(1);
            break;
        }
        case 2: {
            cout << "Edit Employee Data selected";
            execute_option(2);
            break;
        }
        case 3: {
            cout << "Search Employee selected";
            execute_option(3);
            break;
        }
        case 4: {
            cout << "Search Employee with High Wage selected";
            execute_option(4);
            break;
        }
        case 5: {
            cout << "Delete Employee Data selected";
            execute_option(5);
            break;
        }
        case 6: {
            execute_option(6);
        }
        }
    }
    void execute_option(int choice) {
        switch (choice) {
        case 1: {
            system("cls");
            cout << "Add new Employee Data selected";
            //Handle ID
            cout << el << "Enter ID or exit to return to the main menu!" << el;
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_id(input);
                if (validate_state == 0) {
                    break;
                }
                else if (validate_state == -1) {
                    display_menu();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid ID or exit to return to the main menu!" << el;
                }
                else if (validate_state == 2) {
                    cout << "ID is already taken, please enter a new ID!" << el;
                }
            }
            int ID = stoll(input);
            New_employee.set_id(ID); //save validated ID

            //Handle Name
            cout << "Enter Employee Name or type exit to return to the main menu!" << el;
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_name(input);
                if (validate_state == 0) {
                    break;
                }
                else if (validate_state == -1) {
                    display_menu();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid Name or exit to return to the main menu!" << el;
                }
                else if (validate_state == 2) {
                    cout << "Name already exist, please enter a new Name!" << el;
                }
            }
            New_employee.set_name(input); //save validated Name

            //Handle Age
            cout << "Enter Employee Age or type exit to return to the main menu!" << el;
            while (1) {
                validate_state = 0; //reset validate_state
                input = user_input.get_input();
                validate_state = validate_input.validate_age(input);
                if (validate_state == 0) {
                    break;
                }
                else if (validate_state == -1) {
                    display_menu();
                }
                else if (validate_state == 1) {
                    cout << "Invalid input, please enter a valid Age or type exit to return to the main menu!" << el;
                }
                else if (validate_state == 2) {
                    cout << "Age already exist, please enter a new Name!" << el;
                }
            }
            cout << "Employee data saved successfully!\n"
                "press enter to return to the menu.\n";
            string status;
            getline(cin, status);
            break;
        }
        case 2: {
            cout << "Edit Employee Data selected";
            execute_option(2);
            break;
        }
        case 3: {
            cout << "Search Employee selected";
            execute_option(3);
            break;
        }
        case 4: {
            cout << "Search Employee with High Wage selected";
            execute_option(4);
            break;
        }
        case 5: {
            cout << "Delete Employee Data selected";
            execute_option(5);
            break;
        }
        case 6: {
            exit_system();
            display_menu();
        }
        }
        display_menu();
    }
    void exit_system() {
        // Clear the console and display the exit message
        system("cls");
        cout << "Staff Management Program\n\n";
        cout << "Are you sure you want to exit the program?\n"
            "1. No.\n"
            "2. Yes.\n";

        int option;

        // Validate the user's choice
        while (!(cin >> option) || option < 1 || option > 2) {
            cout << "Invalid choice. Please enter a valid input.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Switch case to handle the user's choice
        switch (option) {
        case 1: {
            // If the user chooses not to exit, return to the main menu
            break;
        }
        case 2: {
            // If the user chooses to exit, display the credits and exit the program
            cout << "Program made by:\n"
                "Mahmoud Ahmed\tID: 235051\n"
                "Ahmed Hussein\tID: 225381\n"
                "Exiting Program...\n";
            exit(1);
            break;
        }
        }
    }
};