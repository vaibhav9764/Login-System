#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class User
{
    string username;
    string password;
    int option;
    string file_name;

public:
    int is_login()
    {
        string us, pw;
        cout << "Enter username :";
        cin >> username;

        cout << "Enter password :";
        cin >> password;

        ifstream in("data.txt");
    

        while (in.eof() == 0)
        {
            getline(in, us);
            getline(in, pw);
            if (us == username && pw == password)
            {
                return 1;
            }
        }
        return 0;
    }
    void append_username()
    {
        cout << "Enter username :";
        cin >> username;

        cout << "Enter password :";
        cin >> password;

        ofstream out;
        out.open("data.txt",ios_base::app);
        out<<username<<endl;
        out<<password<<endl;


    }
};

int main()
{

    cout << "****************************************\n"
         << endl;
    cout << "WELCOME TO LOGIN AND REGISTRATION SYSTEM\n"
         << endl;
    cout << "****************************************\n"
         << endl;

label:
    User u1;
    int option;

    cout << "MAIN MENU" << endl;
    cout << "1> Login" << endl;
    cout << "2> Sign in (Create New Account)" << endl;
    cout<<"3> exit"<<endl;
    cout << "Press 1 or 2 or 3 : ";
    cin >> option;
    if (option == 1)
    {
        int status = u1.is_login();
        if (status == 1)
        {
            system("cls");
            cout << "Successfully logined \n\n" << endl;
            goto label;
        }
        else
        {
            system("cls");
            cout << "Error username is not found\n\n" << endl;
            goto label;
        }
    }
    else if (option==2)
    {
       u1.append_username();
       system("cls");
       goto label;
    }
    else
    {
        exit(0);
    }

    return 0;
}
