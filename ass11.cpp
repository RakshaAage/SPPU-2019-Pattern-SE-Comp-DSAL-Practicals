#include <iostream>
#include <fstream>
#include<iomanip>
#include<conio.h>
using namespace std;
fstream fp;
class studentdata{
    public:
    int roll_no;
    string name;
    string Branch;
    string Division;
    void accept_data(){
        cout<<"enter roll no:"<<endl;
        cin>>roll_no;
        cout<<"enter name:"<<endl;
        cin>>name;
        cout<<"enter branch:"<<endl;
        cin>>Branch;
        cout<<"enter division:"<<endl;
        cin>>Division;
        cout<<"Student record added successfully!!!"<<endl;
    }
    void display_student(){
        cout << "\nRoll Number: " << roll_no;
        cout << "\nStudent's Name: " << name;
        cout << "\nStudent's Branch: " << Branch;
        cout << "\nStudent's Division: " << Division;
    }
    void report()
    {
        cout <<"\t"<< roll_no << setw(22) << name << setw(20) << Branch << setw(20) << Division << endl;
    }
};
studentdata h;
void save_student()
{
    system("cls");
    int option;
    fp.open("student.dat", ios::out | ios::app);
    do
    {
        h.accept_data();
        fp.write((char *)&h, sizeof(studentdata));
        cout << "\nPress 1 to add more students.";
        cout << "\nPress 2 to return to main menu.\n";
        cout << "Option: ";
        cin >> option;
    } while (option == 1);

    fp.close();
}
void display_a_student(int r_number)
{
    system("cls");
    cout << "\n Student DETAILS\n";
    int check = 0;
    fp.open("student.dat", ios::in);
    while (fp.read((char *)&h, sizeof(studentdata)))
    {
        if (h.roll_no == r_number)
        {
            h.display_student();
            check = 1;
        }
    }
    fp.close();
    if (check == 0)
        cout << "\n\nCustomer does not exist";
    getch();
}
void display_all_Student()
{
    system("cls");
    fp.open("student.dat", ios::in);
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }
    cout << "\n\n\t\t Student LIST\n\n";
    cout << "=========================================================================\n";
    cout << "\tRoll Number." << setw(10) << "Name" << setw(20) << "Branch" << setw(20) << "Division" << endl;
    cout << "=========================================================================\n";
    while (fp.read((char *)&h, sizeof(studentdata)))
    {
        h.report();
    }
    fp.close();
    getch();
}
void delete_student(int r_no)
{
    system("cls");
    fstream fp2;
    fp.open("student.dat", ios::in);
    fp2.open("temp.dat", ios::out);
    int check = 0;
    
    while (fp.read((char *)&h, sizeof(studentdata)))
    {
        if (h.roll_no != r_no)
        {
            fp2.write((char *)&h, sizeof(studentdata));
        }
        else
        {
            check = 1;
        }
    }
    
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    
    if (check == 1)
    {
        cout << "Student record deleted successfully!";
    }
    else
    {
        cout << "Student does not exist";
    }
    
    getch();
}



void main_menu()
{
    int option;

    for (;;)
    {

        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout << "\n\t\tPress 1 to Accept and Save Data of Student";
        cout << "\n\t\tPress 2 to DISPLAY ALL Students Data";
        cout << "\n\t\tPress 3 to DISPLAY SPECIFIC Student RECORD";
        cout << "\n\t\tPress 4 to delete";
        cout << "\n\t\tPress 5 to Exit";
        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "\n\t\tOption: ";
        cin >> option;
        switch (option)
        {
        case 1:
            save_student();
            system("cls");
            break;
        case 2:
            display_all_Student();
            system("cls");
            break;
        case 3:
            int r_number;
            system("cls");
            cout << "\n\n\tPlease Enter Customer's Room Number: ";
            cin >> r_number;
            display_a_student(r_number);
            break;
         case 4:
            int r_no;
            system("cls");
            cout << "\n\n\tPlease Enter Customer's Room Number: ";
            cin >> r_no;
            delete_student(r_no);
            break;
        default:
            cout << "\a";
        }
    }
}

int main()
{
    main_menu();
    return 0;
}