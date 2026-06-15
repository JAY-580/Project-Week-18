#include "project.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    vector<Student> students;
    int choice;
    do
    {
        cout << "\n===== Student Grades Management System =====\n";
        cout << "1. Add student\n";
        cout << "2. List all students\n";
        cout << "3. Sort by score\n";
        cout << "4. Search by id\n";
        cout << "5. Show statistics\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        while (!(cin >> choice))
        {
            cout << "Invalid choice. Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice)
        {
            case 1: addStudent(students); break;
            case 2: listStudents(students); break;
            case 3: sortByScore(students); break;
            case 4: searchStudent(students); break;
            case 5: showStatistics(students); break;
            case 0: cout << "Program terminated.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}