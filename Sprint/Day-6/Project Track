#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <chrono>
using namespace std;

class Password
{
    /* Descrition of Variables :
    int command -->> Helps the user to choose the utility they want to avail from the menu
    string website[100]-->> an array of string which stores the name of website
    string username[100]-->> an array of string which stores the username
    string password[100]-->> an array of string which stores the password
    string credential-->> a string which stores the credential which u want to update
    int initializer -->> helps to initialize the array of string
    int updater -->> helps the user to choose the entry they want to modify
    int credential_delete  -->> helps the user to choose the entry they want to delete
    bool enter -->> helps to run the menu again and again
    string website -->>
    char c   ---->>>
    bool deletechecker---->>>
    string readabletime
    int strike ; ;
    int audit -->>


    */

private:
    int command = 0;
    string website[100], username[100], password[100], credential, websiteentry, readableTime;
    int initializer = 0;
    int updater = 0;
    int strike = 0;
    int credential_delete = 0;

public:
    bool enter = true;
    void loadFromFile();
    void start();
    void menu();
    void choosing();
    void menu1();
    void menu2();
    void menu3helper();
    void fileentry();
    void menu3();
    void menu4();
    void menu5();
    void menu6();
    void timestamp_generator();
    void password_security(int audit);
    void password_display(int audit2);
};

void Password::timestamp_generator()
{
    auto now = chrono::system_clock::now();

    time_t t = chrono::system_clock::to_time_t(now);
    tm *tmPtr = localtime(&t);

    char buffer[30];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tmPtr);

    readableTime = buffer;
    cout << "(!)  Created On..." << readableTime;
}

void Password::loadFromFile()
{
    ifstream file("vault_data.txt");

    if (!file)
        return;

    string line;
    initializer = 0;

    while (getline(file, line))
    {
        if (initializer >= 100)   
            break;

        int p1 = line.find('|');
        int p2 = line.find('|', p1 + 1);

        if (p1 == string::npos || p2 == string::npos)
            continue;

        website[initializer]  = line.substr(0, p1);
        username[initializer] = line.substr(p1 + 1, p2 - p1 - 1);
        password[initializer] = line.substr(p2 + 1);

        initializer++;
    }

    file.close();
}


void Password ::start()
{
    loadFromFile();
    while (enter)
    {
        menu();
    }
}
void Password ::menu()
{
    cout << endl
         << endl;
    cout << "+------------------------------------------------------------------+" << endl;
    cout << "|    Welcome To Vault OS 2.0 - Your Personal Password Commander    |" << endl;
    cout << "+------------------------------------------------------------------+" << endl;
    cout << "|                     Choose An Operation                          |" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|  1. Access Stored Credentials                                    |" << endl;
    cout << "|  2. Store A New Credential                                       |" << endl;
    cout << "|  3. Update Existing Credential                                   |" << endl;
    cout << "|  4. Remove A Saved Credential                                    |" << endl;
    cout << "|  5. Shut Down Vault OS                                           |" << endl;
    cout << "|  6. Search Credential By Website                                 |" << endl;
    cout << "+------------------------------------------------------------------+" << endl;
    cout << endl;
    cout << "(!) | Vault OS Command  :  ";
    cin >> command;
    choosing();
}

void Password ::choosing()
{
    switch (command)
    {
    case 1:
        strike = 0;
        system("cls");

        menu1();
        break;

    case 2:
        strike = 0;
        system("cls");

        menu2();
        break;

    case 3:
        strike = 0;
        system("cls");

        menu3();
        break;

    case 4:
        strike = 0;
        system("cls");

        menu4();
        break;

    case 5:
        strike = 0;
        system("cls");

        menu5();
        break;

    case 6:
        strike = 0;
        system("cls");
        menu6();
        break;

    default:
        system("cls");
        strike++;
        cout << "(!)  You Entered Wrong Number || Error || Try Again " << endl;
        cout << endl;
        if (strike < 3 && strike >= 0)
        {
            cout << "(!)  Number of attempts left :  " << (3 - strike);
            cout << endl;
            cout << "(!)  Returning to Vault OS menu... " << endl;
            break;
            ;
        }
        else
        {
            system("cls");
            enter = false;
            cout << "(!)  Too many invalid attempts. Exiting Vault OS.";
            return;
        }
    }
}

void Password ::menu1()
{
    if (initializer == 0)
    {
        cout << "Vault OS Database is empty , Commander " << endl;
        cout << endl;
        cout << "Returning to Vault OS menu... " << endl;
    }
    else
    {
        cout << "                          Credentials                              " << endl;
        cout << "+------------------------------------------------------------------+" << endl;
        cout << endl;

        char showAll;
        cout << "Show all passwords? (Y/N) : ";
        cin >> showAll;
        cin.ignore();

        for (int i = 0; i < initializer; i++)
        {
            cout << "(" << i + 1 << ")    Website   :  " << website[i] << endl;
            cout << "    UserName  :  " << username[i] << endl;
            cout << "    Password  :  ";

            if (showAll == 'Y' || showAll == 'y')
            {
                password_display(i);
            }
            else
            {
                password_security(i);
                cout << endl;
            }

            cout << endl;
        }

        cout << endl;
        cout << "+------------------------------------------------------------------+" << endl;
        cout << endl;
        cout << "(!)  Returning to Vault OS Menu" << endl;
    }
}

void Password ::menu2()
{
    if (initializer >= 100)
    {
        cout << "Vault capacity full!" << endl;
        cout << "(!)  Returning to Vault OS Menu" << endl;
        return;
    }
    cout << "                     ENTER THE CREDENTIALS                          " << endl;
    cout << "+------------------------------------------------------------------+" << endl;
    cin.ignore();
    cout << "(!)  Website  : ";
    getline(cin, website[initializer]);
    cout << "(!)  UserName : ";
    getline(cin, username[initializer]);
    cout << "(!)  Password : ";
    getline(cin, password[initializer]);
    cout << "+------------------------------------------------------------------+" << endl;
    system("cls");

    cout << "(!)  Saving to Vault..." << endl;
    timestamp_generator();
    cout << "(!)  Operation Completed. Returning to menu..." << endl;

    initializer++;
    fileentry(); // AUTO-SAVE
}

void Password::fileentry()
{
    ofstream file("vault_data.txt");

    for (int i = 0; i < initializer; i++)
    {
        file << website[i] << "|"
             << username[i] << "|"
             << password[i] << endl;
    }

    file.close();
}

void Password ::menu3()
{
    menu3helper();
    cout << endl;
    cout << "(!)  Enter The S.No Of Entry To Update : ";
    cin >> updater;
    if (updater < 1 || updater > initializer)
    {
        cout << "Please Type A Number Within Range || Error || Try Again ";
        cout << "(!)  Returning to Vault OS Menu" << endl;
        return;
    }
    cin.ignore();
    cout << "(!)  Enter The Category To Update (Website / Username / Password) : ";
    cin >> credential;
    cin.ignore();

    for (char &c : credential)
    {
        c = tolower(static_cast<unsigned char>(c));
    }

    if (credential == "website")
    {
        cout << "(!)  Enter the New Website Name : ";
        getline(cin, website[updater - 1]);
    }

    else if (credential == "username")
    {
        cout << "(!)  Enter the New UserName Name : ";
        getline(cin, username[updater - 1]);
    }

    else if (credential == "password")
    {
        cout << "(!)  Enter the New Password Name : ";
        getline(cin, password[updater - 1]);
    }
    else
    {
        cout << "Invalid Category " << endl;
        cout << "(!)  Returning to Vault OS Menu" << endl;
        return;
    }
    system("cls");
    cout << endl;
    cout << "Credential Updated Successfully" << endl;
    cout << endl;
    cout << "(!)  Returning to Vault OS Menu" << endl;
    cout << endl;

    fileentry(); // AUTO-SAVE
}

void Password ::menu3helper()
{
    cout << "                            Credentials                             " << endl;
    cout << "+------------------------------------------------------------------+" << endl;
    cout << endl;
    char showAll;
    cout << "Show all passwords? (Y/N) : ";
    cin >> showAll;
    cin.ignore();

    for (int i = 0; i < initializer; i++)
    {
        cout << "(" << i + 1 << ")    Website   :  " << website[i] << endl;
        cout << "    UserName  :  " << username[i] << endl;
        cout << "    Password  :  ";

        if (showAll == 'Y' || showAll == 'y')
        {
            password_display(i);
        }
        else
        {
            password_security(i);
            cout << endl;
        }

        cout << endl;
    }

    cout << "+------------------------------------------------------------------+" << endl;
    cout << endl;
}

void Password ::menu4()
{
    menu3helper();
    cout << "(!)  Enter The Number Of The Credential Which You Want To Delete : ";
    cin >> credential_delete;
    cin.ignore();
    if (credential_delete < 1 || credential_delete > initializer)
    {
        cout << "Please Type A Number Within Range || Error || Try Again ";
        cout << "(!)  Returning to Vault OS Menu" << endl;
        return;
    }

    char c;
    cout << "(!)  ARE YOU SURE YOU WANT TO DELETE? (Y/N) : ";
    cin >> c;
    cin.ignore();

    if (c == 'Y' || c == 'y')

    {
        int index = credential_delete - 1;
        for (index; index < initializer - 1; index++)
        {
            website[index] = website[index + 1];
            username[index] = username[index + 1];
            password[index] = password[index + 1];
        }
        cout << endl;
        initializer--;
        system("cls");
        cout << endl;
        cout << "Credential Deleted Successfully" << endl;
        cout << endl;
        cout << "(!)  Returning to Vault OS Menu" << endl;
        cout << endl;
        fileentry(); // AUTO-SAVE
    }
    else if (c == 'N' || c == 'n')
    {
        return;
    }
    else
    {
        system("cls");
        cout << "You Entered Wrong Character || Try Again" << endl;
        cout << endl;
        cout << "(!)  Returning to Vault OS Menu" << endl;
    }
}

void Password ::menu5()
{
    system("cls");
    cout << "Adios Commander - Bye";
    enter = false;
}

void Password::menu6()
{
    if (initializer == 0)
    {
        cout << "Nothing is stored" << endl;
        cout << "(!)  Returning to Vault OS Menu" << endl;
        cout << endl;
        return;
    }

    cout << "                   Enter Website Name To Search                     " << endl;
    cout << "+------------------------------------------------------------------+" << endl;
    cout << "        Website Name :  ";
    cin.ignore();
    getline(cin, websiteentry);
    system("cls");

    
    for (char &c : websiteentry)
        c = tolower(static_cast<unsigned char>(c));

    bool found = false;

    for (int j = 0; j < initializer; j++)
    {
        string temp = website[j];

      
        for (char &c : temp)
            c = tolower(static_cast<unsigned char>(c));

        if (temp == websiteentry)
        {
            found = true;

            cout << endl;
            cout << "Website   :  " << website[j] << endl;
            cout << "UserName  :  " << username[j] << endl;
            cout << "Password  :  ";
            password_security(j);
            cout << endl;

            char ch;
            cout << "Show password? (Y/N) : ";
            cin >> ch;
            cin.ignore();

            if (ch == 'Y' || ch == 'y')
            {
                cout << "Password  :  ";
                password_display(j);
                cout << endl;
            }

            cout << endl;
        }
    }

    if (!found)
    {
        cout << "No credential found for given website" << endl;
    }
    else
    {
        cout << "Credential Displayed Successfully" << endl;
    }

    cout << endl;
    cout << "(!)  Returning to Vault OS Menu" << endl;
    cout << endl;
}


void Password ::password_security(int audit)
{
    for (int i = 0; i < password[audit].length(); i++)
    {
        cout << "*";
    }
}

void Password::password_display(int audit_2)
{
    cout << password[audit_2];
}


int main()
{
    Password user;
    user.start();

    return 0;
}
