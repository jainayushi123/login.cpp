#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string userName, email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void singUp();
    void forgotPassword();
} obj;

int main()
{
    char choice;
    cout << "\n1 - Login";
    cout << "\n2 - Sign-Up";
    cout << "\n3 - Forgot Password";
    cout << "\n4 - Exit";
    cout << "\nEnter Your choice :: ";
    cin >> choice;

    switch (choice)
    {
    case '1':
        cin.ignore();
        obj.login();
        break;
    case '2':
        cin.ignore();
        obj.singUp();
        break;
    case '3':
        cin.ignore();
        obj.forgotPassword();
        break;
    case '4':
        return 0;
        break;
    default:
        cout << " Invalid Selection";
        break;
    }
}

void temp ::singUp()
{
    cout << "\n Enter Your User Name :: ";
    getline(cin, userName);
    cout << " Enter Your Email Address :: ";
    getline(cin, email);
    cout << " Enter Your Password :: ";
    getline(cin, password);

    file.open("loginData.txt", ios ::out | ios ::app);
    file << userName << "*" << email << "*" << password << endl;
    file.close();
}

void temp ::login()
{

    cout << "---------LOGIN-------" << endl;
    cout << "Enter Your User Name :: " << endl;
    getline(cin, searchName);
    cout << "Enter Your Password :: " << endl;
    getline(cin, searchPass);

    file.open("loginData.txt", ios ::in);
    getline(file, userName, '*');
    getline(file, email, '*');
    getline(file, password, '\n');
    while (!file.eof())
    {
        if (userName == searchName)
        {
            if (password == searchPass)
            {
                cout << "\n Account Login is Successful....!";
                cout << "\n Username :: " << userName << endl;
                cout << "\n Email :: " << email << endl;
            }
            else
            {
                cout << "Password is Incorrect...!";
            }
        }
        getline(file, userName, '*');
        getline(file, email, '*');
        getline(file, password, '\n');
    }
    file.close();
}

void temp ::forgotPassword()
{
    cout << "\nEnter Your UserName :: ";
    getline(cin, searchName);
    cout << "\nEnter Your Email Address :: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios ::in);
    getline(file, userName, '*');
    getline(file, email, '*');
    getline(file, password, '*');
    while (!file.eof())
    {
        if (userName == searchName)
        {
            if (email == searchEmail)
            {
                cout << "\n Account Found....!" << endl;
                cout << "Your Password :: " << password << endl;
            }
            else
            {
                cout << "Not Found....!\n";
            }
        }
        else
        {
            cout << "\nNot Found...!\n";
        }
    }
    file.close();
}