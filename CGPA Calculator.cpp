
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int courses;
    string grade[50];
    double points[50], credit[50];
    double totalCredits = 0;
    double totalPoints = 0;

    cout << "===== CGPA CALCULATOR =====\n";

    cout << "Enter number of courses: ";
    cin >> courses;

    if (courses <= 0 || courses > 50)
    {
        cout << "Invalid number of courses!";
        return 0;
    }

    for (int i = 0; i < courses; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade (A, B, C, D, F): ";
        cin >> grade[i];

        cout << "Enter grade points (0-4): ";
        cin >> points[i];

        cout << "Enter credit hours: ";
        cin >> credit[i];

        if (points[i] < 0 || points[i] > 4 ||
            credit[i] <= 0)
        {
            cout << "Invalid input!";
            return 0;
        }

        totalCredits += credit[i];
        totalPoints += points[i] * credit[i];
    }

    double GPA = totalPoints / totalCredits;

    cout << "\n===== RESULT =====\n";

    for (int i = 0; i < courses; i++)
    {
        cout << "Course " << i + 1
             << " Grade: " << grade[i] << endl;
    }

    cout << "\nTotal Credit Hours: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalPoints;
    cout << "\nSemester GPA: " << GPA;

    double previousCGPA;
    double previousCredits;

    cout << "\n\nEnter previous CGPA (0 if first semester): ";
    cin >> previousCGPA;

    cout << "Enter previous completed credit hours (0 if first semester): ";
    cin >> previousCredits;

    if (previousCGPA < 0 || previousCGPA > 4 ||
        previousCredits < 0)
    {
        cout << "Invalid previous academic record!";
        return 0;
    }

    double CGPA =
        (previousCGPA * previousCredits + totalPoints) /
        (previousCredits + totalCredits);

    cout << "\nOverall CGPA: " << CGPA;

    cout << "\n\nThank you for using CGPA Calculator!\n";

    return 0;
}
