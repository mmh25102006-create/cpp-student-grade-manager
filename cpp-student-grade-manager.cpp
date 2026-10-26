#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
    int id;
    string name;
    double grade;
};

int main()
{
    int choice;
    vector<Student> students;

    do
    {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Edit Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Student s;

            cout << "Enter ID: ";
            cin >> s.id;

            cout << "Enter name: ";
            cin.ignore();
            getline(cin, s.name);

            cout << "Enter grade: ";
            cin >> s.grade;

            students.push_back(s);

            cout << "Student added successfully.\n";
            break;
        }

        case 2:
        {
            if (students.empty())
            {
                cout << "No students found.\n";
            }
            else
            {
                for (const Student& s : students)
                {
                    cout << "\nID: " << s.id << '\n';
                    cout << "Name: " << s.name << '\n';
                    cout << "Grade: " << s.grade << '\n';
                }
            }

            break;
        }

        case 3:
        {
            int id;
            bool found = false;

            cout << "Enter ID to search: ";
            cin >> id;

            for (const Student& s : students)
            {
                if (s.id == id)
                {
                    cout << "Name: " << s.name << '\n';
                    cout << "Grade: " << s.grade << '\n';
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";

            break;
        }

        case 4:
        {
            int id;
            bool found = false;

            cout << "Enter ID to edit: ";
            cin >> id;

            for (Student& s : students)
            {
                if (s.id == id)
                {
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, s.name);

                    cout << "Enter new grade: ";
                    cin >> s.grade;

                    cout << "Student updated.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";

            break;
        }

        case 5:
        {
            int id;
            bool found = false;

            cout << "Enter ID to delete: ";
            cin >> id;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].id == id)
                {
                    students.erase(students.begin() + i);
                    cout << "Student deleted.\n";
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student not found.\n";

            break;
        }

        case 6:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}