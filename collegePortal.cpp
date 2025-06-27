#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
class student;
student read_file_student(int i);
class admin;
class teacher;
void login();
void load_students();
int read_lines_student(int i = 0);
string integer_to_string(int n);
int string_to_integer(string str);
int dob_to_year(string str)
{
    int year = 0;
    int size = str.size();
    for (int i = 1; i <= 4; i++)
    {
        int t;
        t = (int)str[size - 5 + i] - 48;
        year = year * 10 + t;
    }
    return year;
}
char single_digit_integer_to_string(int n)
{
    return char(n + 48);
}
int nost = 0;
class student
{
    string mail, username, department, name, father_name, dob, confid, mother_name, student_password, batch;
    int roll_no, age, chances, chances_login;
    int sr_no;
    double attendance_PERCENTAGE_CSE, attendance_PERCENTAGE_ECS, attendance_PERCENTAGE_OTH;
    int attendance_CSE, attendance_ECS, attendance_OTH;
    int total_classes_CSE, total_classes_ECS, total_classes_OTH;
    int criteria;

public:
    friend void login();
    friend void admin_portal();
    friend void add_file_student(student &s);
    friend void teacher_portal(teacher &t);
    friend admin;
    friend student read_file_student(int i);
    friend teacher;
    student()
    {
        sr_no = 0;
        chances = 3;
        chances_login = 10;
        confid = "";
        attendance_PERCENTAGE_CSE = 100;
        attendance_PERCENTAGE_ECS = 100;
        attendance_PERCENTAGE_OTH = 100;
        attendance_CSE = 1;
        attendance_ECS = 1;
        attendance_OTH = 1;
        total_classes_CSE = 1;
        total_classes_ECS = 1;
        total_classes_OTH = 1;
        criteria = 75;
    }
    string getbatch()
    {
        return batch;
    }
    string get_username()
    {
        return username;
    }
    string get_pass()
    {
        return student_password;
    }
    void print_attendance()
    {
        system("cls");
        cout << "\t\t______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t               A T T E N D A N C E   I N   C S E   :   " << attendance_PERCENTAGE_CSE << "%" << endl
             << "\t\t               A T T E N D A N C E   I N   E C S   :   " << attendance_PERCENTAGE_ECS << "%" << endl
             << "\t\t               A T T E N D A N C E   I N   O T H   :   " << attendance_PERCENTAGE_OTH << "%" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl
             << endl;
        Sleep(5000);
    }
    void reset_mail()
    {
        cout << "Enter Your Mail : ";
        fflush(stdin);
        string mail1;
        cin >> mail1;
        cout << "Re-Enter Your Mail : ";
        fflush(stdin);
        string mail_confirmation;
        cin >> mail_confirmation;
        fflush(stdin);
        if (mail1 == mail_confirmation)
        {
            mail = mail1;
        }
        else
        {
            cout << "Mail Entered the Second Time is not the same as the first one !! " << endl
                 << "Please Try Again !! " << endl;
        }
    }
    void print_student_detail()
    {
        cout << "\t\t______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*                                                                           *|" << endl
             << "\t\t|*       S T U D E N T   R E G I S T E R E D   S U C C E S S F U L L Y       *|" << endl
             << "\t\t|*                                                                           *|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl
             << endl;

        cout << "Name          : " << name << endl
             << "Age           : " << age << endl
             << "Mail          : " << mail << endl
             << "Father's Name : " << father_name << endl
             << "Mother's Name : " << mother_name << endl
             << "Batch         : " << batch << endl
             << "Roll Number   : " << roll_no << endl
             << "Department    : " << department << endl
             << endl
             << endl
             << endl;

        cout << "\t\t______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*                          " << "USERNAME    :" << username << "                            *|" << endl
             << "\t\t|*                          " << "PASSWORD    :" << student_password << "                          *|" << endl
             << "\t\t|*                          " << "CONFID CODE :" << confid << "                          *|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*THIS CONFIDENTIAL(CONFID) CODE CAN BE USED IN CASE YOU FORGOT YOUR PASSWORD*|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl;
        cout << "\t\t______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*                           D O N ' T   S H A R E                           *|" << endl
             << "\t\t|*                                 T H E S E                                 *|" << endl
             << "\t\t|*                   D E T A I L S   W I T H  A N Y O N E                    *|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl;
        Sleep(10000);
    }

    void reset_username()
    {
        cout << "Enter New Username : ";
        cin >> username;
        if (username_criteria())
        {
            cout << "Username Updated !! :) " << endl
                 << "Updated Username is " << username;
        }
        else
        {
            cout << "Username is Already Taken : " << endl
                 << "Try Again !! " << endl;
        }
    }
    bool username_criteria()
    {
        return false;
    }

    void generate_confid()
    {
        int size = mail.size();
        int i;
        for (i = 0; i < 4; i++)
        {
            confid = confid + mail[(i + (rand() % 10)) % size];
        }
        size = father_name.size();
        for (i = 0; i < 3; i++)
        {
            confid = confid + father_name[(i + (rand() % 10)) % size];
        }
        size = name.size();
        for (i = 0; i < 3; i++)
        {
            confid = confid + name[(i + (rand() % 10)) % size];
        }
    }
    void update_password()
    {
        string updated_password;
    update_again:
        int u = 0, l = 0, n = 0, s = 0;
        cout << "Welcome to the Update Password Portal : " << endl
             << "Password must be a combination of at least one of each :" << endl
             << "--> Upper Case Alphabet " << endl
             << "--> Lower Case Alphabet " << endl
             << "--> Number " << endl
             << "--> Special Character " << endl
             << "Enter Your Choice : ";
        fflush(stdin);
        cin >> updated_password;
        if (check_password_criteria(updated_password, u, l, n, s))
        {
            cout << "Password Changed Successfully :) ";
        }
        else
        {
            cout << "Password Criteria Not Met!!" << endl
                 << "!!       Try Again       !!" << endl;
            goto update_again;
        }
    }
    bool check_password_criteria(string str, int &u, int &l, int &n, int &s)
    {
        for (unsigned int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 65 && str[i] <= 90)
            {
                u = 1;
            }
            else if (str[i] >= 97 && str[i] <= 122)
            {
                l = 1;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                n = 1;
            }
            else
            {
                s = 1;
            }
        }
        if (u && l && n && s)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void forgot_password()
    {
        int choice_password;
        cout << "Enter 1 to change password through E-mail : " << endl
             << "Enter 2 to change password through confidential code : " << endl
             << "Enter your choice : ";
        cin >> choice_password;
        switch (choice_password)
        {
        case 1:
        {
            cout << "";
        }
        break;
        case 2:
        {
            string check_confid;
            cout << "Enter the Confidential code : ";
            fflush(stdin);
            cin >> check_confid;
            if (check_confid == confid)
            {
            }
            else
            {
                if (chances)
                {
                    chances--;
                    cout << "Invalid Choice!! " << endl
                         << "Try Again!" << endl
                         << "Only " << chances << " Chances left " << endl;
                }
                else
                {
                    cout << "You have Exhausted All your Choices " << endl
                         << "Contact the Admin : " << endl;
                }
            }
        }
        break;
        default:
        {
            cout << "Invalid Choice!! " << endl
                 << "Try Again!" << endl;
        }
        }
    }
};
int main();
class teacher
{
protected:
    string username, doj, name, mail, confid = "", department, teacher_password;
    int userid, chances = 3, chances_login = 10;

public:
    friend int main();
    friend void login();
    friend void teacher_portal(teacher &t);
    teacher()
    {
        username = "";
        doj = "";
        name = "";
        mail = "";
        department = "";
        teacher_password = "";
        userid = 0;
        chances = 3;
        chances_login = 10;
    }
    void update_attendance(vector<student> &v)
    {
        string str;
        cout << "ENter the batch name : ";
        cin >> str;
        for (int i = 0; i < nost; i++)
        {
            char ch;
            if (v[i].batch == str)
            {
                cout << v[i].name << " ";
                ch = getche();
                fflush(stdin);
                if (ch == 'P' || ch == 'p')
                {
                    if (department == "CSE")
                    {
                        v[i].attendance_CSE++;
                        v[i].total_classes_CSE++;
                        v[i].attendance_PERCENTAGE_CSE = 100.0 * v[i].attendance_CSE / v[i].total_classes_CSE;
                    }
                    else if (department == "ECS")
                    {
                        v[i].attendance_ECS++;
                        v[i].total_classes_ECS++;
                        v[i].attendance_PERCENTAGE_ECS = 100.0 * v[i].attendance_ECS / v[i].total_classes_ECS;
                    }
                    else
                    {
                        v[i].attendance_OTH++;
                        v[i].total_classes_OTH++;
                        v[i].attendance_PERCENTAGE_OTH = 100.0 * v[i].attendance_OTH / v[i].total_classes_OTH;
                    }
                }
                else
                {
                    if (department == "CSE")
                    {
                        v[i].total_classes_CSE++;
                        v[i].attendance_PERCENTAGE_CSE = 100.0 * v[i].attendance_CSE / v[i].total_classes_CSE;
                    }
                    else if (department == "ECS")
                    {
                        v[i].total_classes_ECS++;
                        v[i].attendance_PERCENTAGE_ECS = 100.0 * v[i].attendance_ECS / v[i].total_classes_ECS;
                    }
                    else
                    {
                        v[i].total_classes_OTH++;
                        v[i].attendance_PERCENTAGE_OTH = 100.0 * v[i].attendance_OTH / v[i].total_classes_OTH;
                    }
                }
            }
        }
    }
    friend admin;
    friend void admin_portal();
    string get_username()
    {
        return username;
    }
    string get_pass()
    {
        return teacher_password;
    }
    void reset_username()
    {
        string usr;
        cout << "Enter New Username : ";
        cin >> usr;
        if (username_criteria())
        {
            cout << "Username Updated !! :) " << endl
                 << "Updated Username is " << username;
        }
        else
        {
            cout << "Username is Already Taken : " << endl
                 << "Try Again !! " << endl;
        }
    }
    bool username_criteria()
    {
        /*
            DBMS to be used here!!
        */
        return false;
    }

    void generate_confid()
    {
        confid = confid + department;
        confid = confid + name;
    }

    void print_confid()
    {
        cout << endl
             << "                    Your Confidential Code is : " << confid << endl
             << endl
             << "!!PLEASE NOTE IT DOWN TO RESET YOUR PASSWORD IN CASE YOU FORGOT YOUR PASSWORD!!" << endl;
    }
    void reset_mail()
    {
        string temp;
        cout << "Enter Your Mail : ";
        fflush(stdin);
        cin >> temp;
        cout << "Re-Enter Your Mail : ";
        fflush(stdin);
        string mail_confirmation;
        cin >> mail_confirmation;
        fflush(stdin);
        if (temp == mail_confirmation)
        {
            mail = temp;
        }
        else
        {
            cout << "Mail Entered the Second Time is not the same as the first one !! " << endl
                 << "Please Try Again !! " << endl;
        }
    }
    void update_password()
    {
        string updated_password;
    update_again:
        int u = 0, l = 0, n = 0, s = 0;
        cout << "Welcome to the Update Password Portal : " << endl
             << "Password must be a combination of at least one of each :" << endl
             << "--> Upper Case Alphabet " << endl
             << "--> Lower Case Alphabet " << endl
             << "--> Number " << endl
             << "--> Special Character " << endl
             << "Enter Your Choice : ";
        fflush(stdin);
        cin >> updated_password;
        if (check_password_criteria(updated_password, u, l, n, s))
        {
            teacher_password = updated_password;
            cout << "Password Changed Successfully :) ";
        }
        else
        {
            cout << "Password Criteria Not Met!!" << endl
                 << "!!       Try Again       !!" << endl;
            goto update_again;
        }
    }
    bool check_password_criteria(string str, int &u, int &l, int &n, int &s)
    {
        for (unsigned int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 65 && str[i] <= 90)
            {
                u = 1;
            }
            else if (str[i] >= 97 && str[i] <= 122)
            {
                l = 1;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                n = 1;
            }
            else
            {
                s = 1;
            }
        }
        if (u && l && n && s)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void forgot_password()
    {
        int choice_password;
        cout << "Enter 1 to change password through E-mail : " << endl
             << "Enter 2 to change password through confidential code : " << endl
             << "Enter your choice : ";
        cin >> choice_password;
        switch (choice_password)
        {
        case 1:
        {
        }
        break;
        case 2:
        {
            string check_confid;
            cout << "Enter the Confidential code : ";
            fflush(stdin);
            cin >> check_confid;
            if (check_confid == confid)
            {
                cout << "ENTER NEW PASSWORD : ";
                cin >> teacher_password;
                cout << "PASSWORD CHANGED SUCCESSFULLY : ";

                Sleep(2000);
                /*
                        teacher portal args.
                */
                login();
            }
            else
            {
                if (chances)
                {
                    chances--;
                    cout << "Invalid Choice!! " << endl
                         << "Try Again!" << endl
                         << "Only " << chances << " Chances left " << endl;
                }
                else
                {
                    cout << "You have Exhausted All your Choices " << endl
                         << "Contact the Admin : " << endl;
                }
            }
        }
        break;
        default:
        {
            cout << "Invalid Choice!! " << endl
                 << "Try Again!" << endl;
        }
        }
    }
    void print_td()
    {
        cout << "NAME = " << name << endl
             << "DOJ = " << doj << endl
             << "username = " << username << endl
             << "mail = " << mail << endl
             << "confid = " << department << endl
             << "password = " << teacher_password << endl
             << "userID = " << userid << endl
             << "NAME = " << name << endl;
        fflush(stdin);
        getche();
        fflush(stdin);
    }
    void set_det()
    {
        cout << "Enter Name (Teacher) : ";
        cin >> name;

        cout << "Enter Date Of Joining (dd/mm/yyyy)";
        cin >> doj;
        teacher_password = doj;

        cout << "Enter Your Personal Mail : ";
        cin >> mail;

        cout << "Enter Department : ";
        cin >> department;
        confid = department + name[0] + name[1] + name[2] + name[0] + doj[1] + doj[4] + doj[9];
        userid = 274304;
        username = integer_to_string(userid);
    }
};

class admin : public teacher, public student
{

    string username = "VAIBHAV_UP62", admin_password = "PAPA_RKS";
    vector<student> v1;
    vector<teacher> v2;
    int no_students, no_students_cse, no_batches_cse, no_students_ecs, no_batches_ecs, no_students_other, no_batches_other;
    int no_teachers;

public:
    friend void teacher_portal(teacher &t);
    friend void admin_portal();
    friend void login();
    friend void update_student_file();
    friend void load_students();
    friend int main();
    admin()
    {
        no_batches_other = 1;
        no_batches_ecs = 1;
        no_batches_cse = 1;
        no_students = 0;
        no_teachers = 3;
        no_students_cse = 0;
        no_students_ecs = 0;
        no_students_other = 0;
    }
    string get_admin_username()
    {
        return username;
    }
    string get_admin_pass()
    {
        return admin_password;
    }
    void add_student()
    {
        student s;
        cout << "Enter name (Student) : ";
        cin >> s.name;
        cout << "Enter Date Of Birth (dd/mm/yyyy) : ";
        cin >> s.dob;
        s.age = 2024 - dob_to_year(s.dob);
        cout << "Enter Father's name  : ";
        cin >> s.father_name;
        cout << "Enter Mother's name  : ";
        cin >> s.mother_name;
        cout << "Enter Mail  (Student) : ";
        cin >> s.mail;
        cout << "Enter Department : ";
        cin >> s.department;
        student_password = s.dob;
        s.generate_confid();
        if (s.department == "ECS")
        {
            s.batch = "A";
            int temp_batches;
            no_students_ecs++;
            no_batches_ecs += (no_students_ecs / 25);
            for (temp_batches = no_batches_ecs; temp_batches != 0; temp_batches /= 10)
            {
                s.batch = s.batch + single_digit_integer_to_string(temp_batches % 10);
            }
            s.roll_no = 23102899 + no_students_ecs;
        }
        else if (s.department == "CSE")
        {
            s.batch = "B";
            no_students_cse++;
            no_batches_cse += (no_students_cse / 25);
            int temp_batches;
            for (temp_batches = no_batches_cse; temp_batches != 0; temp_batches /= 10)
            {
                s.batch = s.batch + single_digit_integer_to_string(temp_batches % 10);
            }
            s.roll_no = 23103099 + no_students_cse;
        }
        else
        {
            s.batch = "O";
            no_students_other++;
            no_batches_other += (no_students_other / 25);
            int temp_batches;
            for (temp_batches = no_batches_other; temp_batches != 0; temp_batches /= 10)
            {
                s.batch = s.batch + single_digit_integer_to_string(temp_batches % 10);
            }
            s.roll_no = 23102699 + no_students_other;
        }
        s.username = student_username_generator(s.roll_no);
        s.student_password = s.dob;
        no_students++;
        s.sr_no = no_students;
        nost = no_students;
        v1.push_back(s);
        add_file_student(s);
        print_student_detail(s);
        string str = "PAPA";
        int n = 0;
        ifstream fin;
        fin.open("STUDENT'S_DATA.txt");
        if (fin.is_open())
        {
            string str1;
            while (getline(fin, str1))
            {
                n++;
                if (str1 == str)
                {
                    break;
                }
            }
        }
        read_file_student(n);
    }
    string student_username_generator(int n)
    {
        string str = "";
        for (; n != 0; n = n / 10)
        {
            str = (char)('0' + n % 10) + str;
        }
        return str;
    }
    void print_student_detail(student &s)
    {
        cout << "\t\t______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*                                                                           *|" << endl
             << "\t\t|*       S T U D E N T   R E G I S T E R E D   S U C C E S S F U L L Y       *|" << endl
             << "\t\t|*                                                                           *|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl
             << endl;
        cout << "Name          : " << s.name << endl
             << "Age           : " << s.age << endl
             << "Mail          : " << s.mail << endl
             << "Father's Name : " << s.father_name << endl
             << "Mother's Name : " << s.mother_name << endl
             << "Batch         : " << s.batch << endl
             << "Roll Number   : " << s.roll_no << endl
             << "Department    : " << s.department << endl
             << endl
             << endl
             << endl;
        cout << "\t\t______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*                          " << "USERNAME    :" << s.username << "                            *|" << endl
             << "\t\t|*                          " << "PASSWORD    :" << s.student_password << "                          *|" << endl
             << "\t\t|*                          " << "CONFID CODE :" << s.confid << "                          *|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*THIS CONFIDENTIAL(CONFID) CODE CAN BE USED IN CASE YOU FORGOT YOUR PASSWORD*|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl;
        cout << "\t\t______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*                           D O N ' T   S H A R E                           *|" << endl
             << "\t\t|*                                 T H E S E                                 *|" << endl
             << "\t\t|*                   D E T A I L S   W I T H  A N Y O N E                    *|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl;
        Sleep(10000);
    }

    void view_teacher();

    void default_teachers()
    {
        teacher t;
        t.username = "ashish_mishra";
        t.doj = "20/05/2017";
        t.name = "Ashish Mishra";
        t.mail = "ashish1234@gmail.com";
        t.confid = "asmcse6789";
        t.department = "CSE";
        t.teacher_password = "ashish123#";
        t.userid = 274304;
        t.chances = 3;
        t.chances_login = 10;

        v2.push_back(t);

        t.username = "vijay_khare";
        t.doj = "06/10/2019";
        t.name = "Vijay Khare";
        t.mail = "vijay5569@gmail.com";
        t.confid = "vjkecs0987";
        t.department = "ECS";
        t.teacher_password = "khare457%";
        t.userid = 201311;
        t.chances = 3;
        t.chances_login = 10;

        v2.push_back(t);

        t.username = "himanshu_agarwal";
        t.doj = "29/11/2020";
        t.name = "Himanshu Agarwal";
        t.mail = "hagarwal89@gmail.com";
        t.confid = "haloth7860";
        t.department = "OTS";
        t.teacher_password = "hagarwal321#";
        t.userid = 221002;
        t.chances = 3;
        t.chances_login = 10;

        v2.push_back(t);
    }
    void print_teacher_detail(teacher &t)
    {
        cout << "\t\t_______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*                                                                           *|" << endl
             << "\t\t|*           T E A C H E R   J O I N E D   S U C C E S S F U L L Y           *|" << endl
             << "\t\t|*                                                                           *|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl;

        cout << "Name          : " << t.name << endl
             << "DOJ           : " << t.doj << endl
             << "Mail          : " << t.mail << endl;

        cout << "Department    : " << t.department << endl
             << endl
             << endl;

        cout << "\t\t_______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*                          " << "USERNAME    :" << t.username << "                            *|" << endl
             << "\t\t|*                          " << "PASSWORD    :" << t.teacher_password << "                          *|" << endl
             << "\t\t|*                          " << "CONFID CODE :" << t.confid << "                          *|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t| THIS CONFIDENTIAL(CONFID) CODE CAN BE USED IN CASE YOU FORGOT YOUR PASSWORD |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl;
        cout << "\t\t_______________________________________________________________________________" << endl
             << "\t\t|                                                                             |" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|*                           D O N ' T   S H A R E                           *|" << endl
             << "\t\t|*                                 T H E S E                                 *|" << endl
             << "\t\t|*                   D E T A I L S   W I T H  A N Y O N E                    *|" << endl
             << "\t\t|* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl
             << "\t\t|_____________________________________________________________________________|" << endl
             << endl
             << endl;
        Sleep(5000);
        fflush(stdin);
        getche();
    }

    string teacher_username_generator(int n)
    {
        string str = "";
        for (; n != 0; n = n / 10)
        {
            str = (char)('0' + n % 10) + str;
        }
        return str;
    }

    void reset_student_password(student &v, string password)
    {
        v.student_password = password;
        cout << "Password Reset Successfull";
    }
    void reset_teacher_password(teacher &v, string password)
    {
        v.teacher_password = password;
        cout << "Password Reset Successfull";
    }
};
admin a;
void intro()
{
    cout << "\t\t\t\t      ______________________________________________________________________________" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |                                                                             |" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                                                                           *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                            A T T E N D A N C E                            *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                                                                           *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                            M A N A G E M E N T                            *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                                                                           *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                                S Y S T E M                                *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                                                                           *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |_____________________________________________________________________________|" << endl;
    cout << endl
         << endl;
    getch();
    cout << "\t\t\t\t      ______________________________________________________________________________" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |                                                                             |" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                                                                           *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                            +- M A D E   B Y -+                            *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                            +- V A I B H A V -+                            *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                            +-  S O M E S H  -+                            *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                            +-  B H A W Y A  -+                            *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                            +-   D A K S H   -+                            *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                            +-     B - 5     -+                            *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |*                                                                           *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *|" << endl;
    Sleep(100);
    cout << "\t\t\t\t      |_____________________________________________________________________________|" << endl;
    cout << endl
         << endl;
}

void student_portal(student &s)
{
    char ch;
    system("cls");
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*         W E L C O M E   T O   S T U D E N T ' S   P O R T A L         *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                                                       *\n";
    cout << "*   * * * * * * * * * * * *                    * * * * * * * * * * *    *\n";
    cout << "*   * 1. RESET USERNAME   *                    *   2. RESET MAIL   *    *\n";
    cout << "*   * * * * * * * * * * * *                    * * * * * * * * * * *    *\n";
    cout << "*                                                                       *\n";
    cout << "*                                                                       *\n";
    cout << "*   * * * * * * * * * * * *                    * * * * * * * * * * *    *\n";
    cout << "*   * 3. UPDATE PASSWORD  *                    * 4.GO TO MAIN MENU *    *\n";
    cout << "*   * * * * * * * * * * * *                    * * * * * * * * * * *    *\n";
    cout << "*                                                                       *\n";
    cout << "*                                                                       *\n";
    cout << "*                       * * * * * * * * * * * * *                       *\n";
    cout << "*                       *  5. VIEW  ATTENDANCE  *                       *\n";
    cout << "*                       * * * * * * * * * * * * *                       *\n";
    cout << "*                                                                       *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "\n\n\t\tENTER YOUR CHOICE - ";
    fflush(stdin);
    ch = getche();
    fflush(stdin);

    switch (ch)
    {
    case '1':
    {
        s.reset_username();
    }
    break;
    case '2':
    {
        s.reset_mail();
    }
    break;
    case '3':
    {
        s.update_password();
    }
    break;
    case '4':
    {
        login();
    }
    break;
    case '5':
    {
        s.print_attendance();
        student_portal(s);
    }
    break;

    default:
    {
        student_portal(s);
    }
    break;
    }
    /*
            file updation!!
    */
}
void teacher_portal(teacher &t)
{
    char ch;
    system("cls");
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*         W E L C O M E   T O   T E A C H E R ' S    P O R T A L        *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                                                       *\n";
    cout << "*   * * * * * * * * * * * *                    * * * * * * * * * * *    *\n";
    cout << "*   * 1. RESET USERNAME   *                    *   2. RESET MAIL   *    *\n";
    cout << "*   * * * * * * * * * * * *                    * * * * * * * * * * *    *\n";
    cout << "*                                                                       *\n";
    cout << "*                                                                       *\n";
    cout << "*   * * * * * * * * * * * *                    * * * * * * * * * * *    *\n";
    cout << "*   * 3. UPDATE PASSWORD  *                    * 4.GOTO LOGIN PAGE *    *\n";
    cout << "*   * * * * * * * * * * * *                    * * * * * * * * * * *    *\n";
    cout << "*                                                                       *\n";
    cout << "*                                                                       *\n";
    cout << "*                       * * * * * * * * * * * * *                       *\n";
    cout << "*                       * 5. UPDATE ATTENDANCE  *                       *\n";
    cout << "*                       * * * * * * * * * * * * *                       *\n";
    cout << "*                                                                       *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "\n\n\t\tENTER YOUR CHOICE - ";
    fflush(stdin);
    ch = getche();
    fflush(stdin);
    switch (ch)
    {
    case '1':
    {
        t.reset_username();
    }
    break;
    case '2':
    {
        t.reset_mail();
    }
    break;
    case '3':
    {
        t.update_password();
    }
    break;
    case '4':
    {
        login();
    }
    break;
    case '5':
    {
        t.update_attendance(a.v1);
    }
    break;
    default:
        teacher_portal(t);
    }
}
void admin_portal()
{
    char ch;
    system("cls");
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*            W E L C O M E   T O   A D M I N ' S   P O R T A L          *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "*                                                                       *\n";
    cout << "*   * * * * * * * * * *                          * * * * * * * * * *    *\n";
    cout << "*   * 1. ADD STUDENT  *                          * 2. VIEW TEACHER *    *\n";
    cout << "*   * * * * * * * * * *                          * * * * * * * * * *    *\n";
    cout << "*                                                                       *\n";
    cout << "*                                                                       *\n";
    cout << "*  * * * * * * * * * * * * * * * *    * * * * * * * * * * * * * * * *   *\n";
    cout << "*  * 3. RESET STUDENT'S PASSWORD *    * 4. RESET TEACHER'S PASSWORD *   *\n";
    cout << "*  * * * * * * * * * * * * * * * *    * * * * * * * * * * * * * * * *   *\n";
    cout << "*                                                                       *\n";
    cout << "*                                                                       *\n";
    cout << "*                             * * * * * * *                             *\n";
    cout << "*                             *  5. EXIT  *                             *\n";
    cout << "*                             * * * * * * *                             *\n";
    cout << "*                                                                       *\n";
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";
    cout << "\n\n\t\tENTER YOUR CHOICE - ";
    ch = getche();
    fflush(stdin);
    switch (ch)
    {
    case '1':
    {
        a.add_student();
        admin_portal();
    }
    break;
    case '2':
    {
        a.view_teacher();
        admin_portal();
    }
    break;
    case '3':
    {
        cout << "ENTER STUDENT'S USERNAME : ";
        string str;
        fflush(stdin);
        cin >> str;
        fflush(stdin);
        bool found = false;
        for (int i = 0; i < a.no_students; i++)
        {
            if (a.v1[i].username == str)
            {
                found = true;
                if (str == a.v1[i].confid && a.v1[i].chances)
                {
                    cout << "Enter New Password : ";
                    fflush(stdin);
                    cin >> str;
                    fflush(stdin);
                    a.v1[i].username = str;
                }
            }
        }
        if (!found)
        {
            cout << "STUDENT NOT FOUND !!";
            login();
        }
        // a.reset_student_password();
        admin_portal();
    }
    break;
    case '4':
    {

        admin_portal();
    }
    break;
    case '5':
    {
        cout << "ENTER STUDENT'S USERNAME : ";
        string str;
        fflush(stdin);
        cin >> str;
        fflush(stdin);
        bool found = false;
        for (int i = 0; i < a.no_teachers; i++)
        {
            if (a.v2[i].username == str)
            {
                found = true;
                if (str == a.v2[i].confid && a.v2[i].chances)
                {
                    cout << "Enter New Password : ";
                    fflush(stdin);
                    cin >> str;
                    fflush(stdin);
                    a.v2[i].username = str;
                }
            }
        }
        if (!found)
        {
            cout << "STUDENT NOT FOUND !!";
            login();
        }
        login();
    }
    break;
    default:
    {
        admin_portal();
    }
    }
    /*
            FUNCTIONS TO BE ADDED
    */
}
void login()
{
    char ch;
    system("cls");
    cout << "\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t\t\t*            W E L C O M E  T O   J I I T   W E B   P O R TA L          *" << endl;
    cout << "\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t\t\t*                                                                       *" << endl;
    cout << "\t\t\t\t\t\t*         * * * * * * * * * * *              * * * * * * * * * * *      *" << endl;
    cout << "\t\t\t\t\t\t*         *         1.        *              *         2.        *      *" << endl;
    cout << "\t\t\t\t\t\t*         * S T U D E N T ' S *              * T E A C H E R ' S *      *" << endl;
    cout << "\t\t\t\t\t\t*         *    P O R T A L    *              *    P O R T A L    *      *" << endl;
    cout << "\t\t\t\t\t\t*         * * * * * * * * * * *              * * * * * * * * * * *      *" << endl;
    cout << "\t\t\t\t\t\t*                                                                       *" << endl;
    cout << "\t\t\t\t\t\t*                                                                       *" << endl;
    cout << "\t\t\t\t\t\t*                                                                       *" << endl;
    cout << "\t\t\t\t\t\t*                           * * * * * * * * * * *                       *" << endl;
    cout << "\t\t\t\t\t\t*                           *         3.        *                       *" << endl;
    cout << "\t\t\t\t\t\t*                           *   A D M I N ' S   *                       *" << endl;
    cout << "\t\t\t\t\t\t*                           *    P O R T A L    *                       *" << endl;
    cout << "\t\t\t\t\t\t*                           * * * * * * * * * * *                       *" << endl;
    cout << "\t\t\t\t\t\t*                                                                       *" << endl;
    cout << "\t\t\t\t\t\t*                                                                       *" << endl;
    cout << "\t\t\t\t\t\t*                                                                       *" << endl;
    cout << "\t\t\t\t\t\t*         * * * * * * * * * * *              * * * * * * * * * * *      *" << endl;
    cout << "\t\t\t\t\t\t*         *         4.        *              *         5.        *      *" << endl;
    cout << "\t\t\t\t\t\t*         * S T U D E N T ' S *              * T E A C H E R ' S *      *" << endl;
    cout << "\t\t\t\t\t\t*         *  FORGOT PASSWORD  *              *  FORGOT PASSWORD  *      *" << endl;
    cout << "\t\t\t\t\t\t*         * * * * * * * * * * *              * * * * * * * * * * *      *" << endl;
    cout << "\t\t\t\t\t\t*                                                                       *" << endl;
    cout << "\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t\t\t*                     E N T E R   Y O U R   C H O I C E                 *" << endl;
    cout << "\t\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
    cout << "\t\t\t\t\t\t                                    ";
    ch = getche();
    cout << endl;
    if (ch == '1')
    {
        string id_check, pass_check;
        cout << "ENTER STUDENT'S LOGIN ID : ";
        cin >> id_check;
        fflush(stdin);
        student s;
        for (int i = 0; i < a.no_students; i++)
        {
            s = a.v1[i];
            if (s.get_username() == id_check)
            {
                cout << "ENTER STUDENT'S PASSWORD : ";
                cin >> pass_check;
                student_portal(s);
            }
        }
    }
    else if (ch == '2')
    {
        string id_check, pass_check;
        cout << "ENTER TEACHER'S LOGIN ID : ";
        cin >> id_check;

        fflush(stdin);
        teacher t;
        for (int i = 0; i < a.no_teachers; i++)
        {
            t = a.v2[i];
            if (t.get_username() == id_check)
            {
                cout << "ENTER TEACHER'S PASSWORD : ";
                cin >> pass_check;
                teacher_portal(t);
            }
        }
    }
    else if (ch == '3')
    {
        string check;
        cout << "ENTER USERNAME : ";
        fflush(stdin);
        cin >> check;
        fflush(stdin);
        if (check == a.get_admin_username())
        {
            cout << "ENTER PASSWORD : ";
            fflush(stdin);
            cin >> check;
            fflush(stdin);
            if (check == a.get_admin_pass())
            {
                admin_portal();
            }
        }
        login();
    }
    else if (ch == '4')
    {
        cout << "ENTER STUDENT'S USERNAME : ";
        string str;
        fflush(stdin);
        cin >> str;
        fflush(stdin);
        bool found = false;
        for (int i = 0; i < a.no_students; i++)
        {
            if (a.v1[i].username == str)
            {
                found = true;
                cout << "ENTER CONFIDENTIAL CODE TO CHANGE THE PASSWORD : ";
                fflush(stdin);
                cin >> str;
                fflush(stdin);
                if (str == a.v1[i].confid && a.v1[i].chances)
                {
                    cout << "Enter New Password : ";
                    fflush(stdin);
                    cin >> str;
                    fflush(stdin);
                    a.v1[i].student_password = str;
                    cout << "Password Changed SuccessFully !! \n";
                    Sleep(1000);
                }
                else
                {
                    if (a.v1[i].chances)
                    {
                        a.v1[i].chances--;
                    }
                    else
                    {
                        cout << "YOU HAVE EXHAUSTED ALL YOUR CHANCES CONTACT THE ADMIN!!" << endl
                             << "Contact The Admin :)" << endl
                             << "PRESS ANY KEY TO CONTINUE!!";
                        fflush(stdin);
                        getche();
                        fflush(stdin);
                        login();
                    }
                }
            }
        }
        if (!found)
        {
            cout << "STUDENT NOT FOUND !!";
            login();
        }
    }

    else if (ch == '5')
    {
        cout << "ENTER TEACHER'S USERNAME : ";
        string str;
        fflush(stdin);
        cin >> str;
        fflush(stdin);
        bool found = false;
        for (int i = 0; i < a.no_teachers; i++)
        {
            if (a.v2[i].username == str)
            {
                found = true;
                cout << "ENTER CONFIDENTIAL CODE TO CHANGE THE PASSWORD : ";
                fflush(stdin);
                cin >> str;
                fflush(stdin);
                if (str == a.v2[i].confid && a.v2[i].chances)
                {
                    cout << "Enter New Password : ";
                    fflush(stdin);
                    cin >> str;
                    fflush(stdin);
                    a.v2[i].username = str;
                }
                else
                {
                    if (a.v2[i].chances)
                    {
                        a.v2[i].chances--;
                    }
                    else
                    {
                        cout << "YOu HAVE EXHAUSTED ALL YOUR CHANCES CONTACT THE ADMIN!!" << endl
                             << "PRESS ANY KEY TO CONTINUE!!";
                        fflush(stdin);
                        getche();
                        fflush(stdin);
                        login();
                    }
                }
            }
        }
        if (!found)
        {
            cout << "TEACHER NOT FOUND !!";
            login();
        }
    }
    else
    {

        login();
    }
}
int main()
{
    a.no_students = read_lines_student() / 22;
    system("cls");
    system("color 6F");
    a.default_teachers();
    cout << a.no_students;
    load_students();
    intro();
    cout << a.no_students;
    getch();
    while (1)
    {
        system("cls");
        system("color 6F");
        system("cls");
        login();
    }
}

void add_file_student(student &s)
{
    ofstream fin;
    string str;
    fin.open("STUDENT'S_DATA.txt", ios::app);
    if (fin.is_open())
    {
        fin << integer_to_string(s.sr_no) << endl;
        fin << integer_to_string(s.roll_no) << endl;
        fin << s.mail << endl;
        fin << s.username << endl;
        fin << s.department << endl;
        fin << s.name << endl;
        fin << s.father_name << endl;
        fin << s.dob << endl;
        fin << s.confid << endl;
        fin << s.mother_name << endl;
        fin << s.student_password << endl;
        fin << s.batch << endl;
        str = integer_to_string(s.age);
        fin << str << endl;
        str = integer_to_string(s.chances);
        fin << str << endl;
        str = integer_to_string(s.chances_login);
        fin << str << endl;
        str = integer_to_string(s.attendance_CSE);
        fin << str << endl;
        str = integer_to_string(s.attendance_ECS);
        fin << str << endl;
        str = integer_to_string(s.attendance_OTH);
        fin << str << endl;
        str = integer_to_string(s.total_classes_CSE);
        fin << str << endl;
        str = integer_to_string(s.total_classes_ECS);
        fin << str << endl;
        str = integer_to_string(s.total_classes_OTH);
        fin << str << endl;
        str = integer_to_string(s.criteria);
        fin << str << endl;
        fin.close();
    }
}

student read_file_student(int i)
{
    student s;
    ifstream fin;
    fin.open("STUDENT'S_DATA.txt");
    int c = 0;
    if (fin.is_open())
    {
        string str;
        while (getline(fin, str))
        {
            c++;
            if (c >= i && c <= i + 21)
            {
                if (c == i)
                    s.sr_no = string_to_integer(str);
                else if (c == (i + 1))
                    s.roll_no = string_to_integer(str);
                else if (c == (i + 0 + 2))
                    s.mail = str;
                else if (c == (i + 1 + 2))
                    s.username = str;
                else if (c == (i + 2 + 2))
                    s.department = str;
                else if (c == (i + 3 + 2))
                    s.name = str;
                else if (c == (i + 4 + 2))
                    s.father_name = str;
                else if (c == (i + 5 + 2))
                    s.dob = str;
                else if (c == (i + 6 + 2))
                    s.confid = str;
                else if (c == (i + 7 + 2))
                    s.mother_name = str;
                else if (c == (i + 8 + 2))
                    s.student_password = str;
                else if (c == (i + 9 + 2))
                    s.batch = str;
                else if (c == (i + 11 + 1))
                    s.age = string_to_integer(str);
                else if (c == (i + 12 + 1))
                    s.chances = string_to_integer(str);
                else if (c == (i + 13 + 1))
                    s.chances_login = string_to_integer(str);
                else if (c == (i + 14 + 1))
                    s.attendance_CSE = string_to_integer(str);
                else if (c == (i + 15 + 1))
                    s.attendance_ECS = string_to_integer(str);
                else if (c == (i + 16 + 1))
                    s.attendance_OTH = string_to_integer(str);
                else if (c == (i + 17 + 1))
                    s.total_classes_CSE = string_to_integer(str);
                else if (c == (i + 18 + 1))
                    s.total_classes_ECS = string_to_integer(str);
                else if (c == (i + 19 + 1))
                    s.total_classes_OTH = string_to_integer(str);
                else if (c == (i + 20 + 1))
                    s.criteria = string_to_integer(str);
            }
        }
    }
    fin.close();
    return s;
}

string integer_to_string(int n)
{
    string str;
    for (; n != 0; n = n / 10)
    {
        str = single_digit_integer_to_string(n % 10) + str;
    }
    return str;
}

int string_to_integer(string str)
{
    int n = 0;
    for (unsigned int i = 0; i < str.size(); i++)
    {
        int temp = ((int)str[i]) - 48;
        n = n * 10 + temp;
    }
    return n;
}

void update_student_file()
{
    for (unsigned int i = 0; i < (sizeof(a.v1) / sizeof(student)); i++)
    {
        add_file_student(a.v1[i]);
    }
}
void load_students()
{
    for (int i = 0; i < a.no_students; i++)
    {
        student s = read_file_student(1 + 22 * i);
        a.v1.push_back(s);
    }
}

void admin::view_teacher()
{
    print_teacher_detail(v2[0]);
    print_teacher_detail(v2[1]);
    print_teacher_detail(v2[2]);
}

int read_lines_student(int i)
{
    i = 7;
    student s;
    ifstream fin;
    fin.open("STUDENT'S_DATA.txt");
    int c = 0;
    if (fin.is_open())
    {
        string str;
        while (getline(fin, str))
        {
            c++;
        }
    }
    fin.close();
    return c;
}