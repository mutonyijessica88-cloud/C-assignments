// Write a program that outputs an acceptance letter for Makerere University. It should prompt a user to enter their first name, last name, study program, academic year.
// The program should have autodates

// Example:

// Date: 27th August 2026

// To: John Okello,

// Dear John,

// CONGRATULATIONS! I am pleased to inform you that the Makerere University 
// Admissions Board has approved your application for admission to the 
// 2027/2028 academic year.

// You have been offered a place for the following course:
// PROGRAM: Bachelor of Science in Computer and Communication Engineering

// As a student of Makerere University, you will be part of a historic 
// institution dedicated to academic excellence and innovation. Please ensure 
// that you report to the Academic Registrar's office with your original 
// academic documents for verification during the orientation week.

// We look forward to welcoming you to the Makerere University.

// Yours sincerely,


// John Doe
// Registra
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    string firstName, lastName, studyProgram, academicYear;

    // Get student information
    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    cin.ignore();

    cout << "Enter your study program: ";
    getline(cin, studyProgram);

    cout << "Enter your academic year: ";
    getline(cin, academicYear);

    // Get current date automatically
    time_t now = time(0);
    tm *localTime = localtime(&now);

    int day = localTime->tm_mday;
    int month = localTime->tm_mon + 1;
    int year = localTime->tm_year + 1900;

    string months[] = {
        "", "January", "February", "March", "April",
        "May", "June", "July", "August", "September",
        "October", "November", "December"
    };

    // Display acceptance letter
    cout << "\nDate: " << day << " " << months[month] << " " << year << endl;
    cout << "\nTo: " << firstName << " " << lastName << "," << endl;

    cout << "\nDear " << firstName << "," << endl;

    cout << "\nCONGRATULATIONS! I am pleased to inform you that the "
         << "Makerere University" << endl;

    cout << "Admissions Board has approved your application for admission to the "
         << academicYear << endl;

    cout << "\nYou have been offered a place for the following course:" << endl;
    cout << "PROGRAM: " << studyProgram << endl;

    cout << "\nAs a student of Makerere University, you will be part of a historic"
         << endl;
    cout << "institution dedicated to academic excellence and innovation. Please ensure"
         << endl;
    cout << "that you report to the Academic Registrar's office with your original"
         << endl;
    cout << "academic documents for verification during the orientation week."
         << endl;

    cout << "\nWe look forward to welcoming you to the Makerere University."
         << endl;

    cout << "\nYours sincerely," << endl;
    cout << "\nJohn Doe" << endl;
    cout << "Registrar" << endl;

    return 0;
}