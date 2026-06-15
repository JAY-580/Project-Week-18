#ifndef PROJECT_H
#define PROJECT_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;

struct Student
{
    string id;
    string name;
    int score;
};

template <class T>
T getMax(T a, T b){return (a > b) ? a : b;}

template <class T>
T getMin(T a, T b){return (a < b) ? a : b;}

void addStudent(vector<Student>& students)
{
    Student s;

    cout << "Enter ID: ";
    cin >> s.id;

    for (const auto& student : students)
    {
        if (student.id == s.id)
        {
            cout << "Error: ID already exists.\n";
            return;
        }
    }

    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, s.name);
    while (s.name.empty())
    {
        cout << "Name cannot be empty. Enter Name: ";
        getline(cin, s.name);
    }

    cout << "Enter Score: ";
    while (!(cin >> s.score))
    {
        cout << "Invalid score. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    students.push_back(s);

    cout << "Student added successfully.\n";
}

void listStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No student data available.\n";
        return;
    }

    cout << left << setw(12) << "ID" << setw(15) << "Name" << setw(10) << "Score" << endl;
    cout << string(37, '-') << endl;

    for (const auto& s : students){cout << left<< setw(12) << s.id<< setw(15) << s.name<< setw(10) << s.score<< endl;}
}

void sortByScore(vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No student data available.\n";
        return;
    }

    sort(students.begin(), students.end(), [](const Student& a, const Student& b){return a.score > b.score;});

    cout << "Students sorted by score (high to low).\n";
}

void searchStudent(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No student data available.\n";
        return;
    }

    string targetID;

    cout << "Enter ID to search: ";
    cin >> targetID;

    for (const auto& s : students)
    {
        if (s.id == targetID)
        {
            cout << "\nStudent Found\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Score: " << s.score << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void showStatistics(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No student data available.\n";
        return;
    }

    int highest = students[0].score;
    int lowest = students[0].score;
    int sum = 0;
    int pass = 0;
    int fail = 0;

    for (const auto& s : students)
    {
        highest = getMax(highest, s.score);
        lowest = getMin(lowest, s.score);

        sum += s.score;

        if (s.score >= 60){pass++;}
        else{fail++;}
    }

    double average = static_cast<double>(sum) / students.size();

    cout << fixed << setprecision(2);

    cout << "\n===== Statistics =====\n";
    cout << "Average Score : " << average << endl;
    cout << "Highest Score : " << highest << endl;
    cout << "Lowest Score  : " << lowest << endl;
    cout << "Pass Count    : " << pass << endl;
    cout << "Fail Count    : " << fail << endl;
}

#endif