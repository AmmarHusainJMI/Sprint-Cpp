#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct UserStats
{
    string password;
    int wins = 0;
    int losses = 0;
    int draws = 0;
    int matches = 0;
};

class login;
class registerr;
class gamesessionclass;
class rps;

class entrypoint
{
    friend class registerr;
    friend class login;
    friend class gamesessionclass;

private:
    int choose;
    map<string, UserStats> user;
    string activeUser;

public:
    void entrypointsir();
    void choosing();
    void load();
    void save();
};

class registerr
{
    friend class entrypoint;

private:
    string username, password;

public:
    void registeringg(entrypoint &ok1);
};

class login
{
    friend class entrypoint;

private:
    string username, password;

public:
    void logging(entrypoint &ok1);
};

class rps
{
public:
    int khelogerps();
};

class gamesessionclass
{
    rps rp;

private:
    int n;

public:
    void kheloge(entrypoint &ok1);
};

void entrypoint::load()
{
    ifstream file("users.txt");
    if (!file)
        return;

    string uname;
    UserStats u;
    while (file >> uname >> u.password >> u.wins >> u.losses >> u.draws >> u.matches)
    {
        user[uname] = u;
    }
    file.close();
}

void entrypoint::save()
{
    ofstream file("users.txt");
    for (auto &p : user)
    {
        file << p.first << " "
             << p.second.password << " "
             << p.second.wins << " "
             << p.second.losses << " "
             << p.second.draws << " "
             << p.second.matches << endl;
    }
    file.close();
}

void entrypoint::entrypointsir()
{
    cout << endl;
    cout << "___________________________________________________________________" << endl
         << " From the scroll of elders it was decreed that a noble will arrive " << endl
         << "      and will cut off the chains of isolation of this engine      " << endl
         << "___________________________________________________________________" << endl
         << "                      + WELCOME NOBLE +                            " << endl
         << endl
         << "Choose your scroll.... " << endl
         << endl
         << "(1)  Login " << endl
         << "(2)  Register " << endl
         << endl
         << "Enter the Scroll (1/2): ";
    cin >> choose;
    cin.ignore();
    choosing();
}

void entrypoint::choosing()
{
    registerr r;
    login l;

    switch (choose)
    {
    case 1:
        system("cls");
        l.logging(*this);
        break;

    case 2:
        system("cls");
        r.registeringg(*this);
        break;

    default:
        entrypointsir();
    }
}

void registerr::registeringg(entrypoint &ok1)
{
    cout << "Set Your Noble Name Warrior : ";
    getline(cin, username);

    if (ok1.user.count(username))
    {
        ok1.entrypointsir();
        return;
    }

    cout << "Set Your Cipher Warrior : ";
    getline(cin, password);

    UserStats u;
    u.password = password;
    ok1.user[username] = u;
    ok1.save();
    ok1.entrypointsir();
}

void login::logging(entrypoint &ok1)
{
    cout << "Enter Your Noble Name Warrior : ";
    getline(cin, username);

    cout << "Enter Your Cipher Warrior : ";
    getline(cin, password);

    auto it = ok1.user.find(username);
    if (it == ok1.user.end() || it->second.password != password)
    {
        ok1.entrypointsir();
        return;
    }

    ok1.activeUser = username;
    gamesessionclass g;
    g.kheloge(ok1);
    ok1.save();
    ok1.entrypointsir();
}

int rps::khelogerps()
{
    int choice;
    cout << endl;
    cout << "_____________________________________________" << endl;
    cout << "Choose Your Weapon, Noble Warrior:" << endl;
    cout << "(1) Rock    (2) Paper    (3) Scissors" << endl;
    cout << "Enter Thy Choice (1/2/3): ";
    cin >> choice;

    string moves[3] = {"Rock", "Paper", "Scissors"};
    int compChoice = rand() % 3;

    cout << endl;
    cout << "The Oracle has chosen: " << moves[compChoice] << endl;

    if (choice < 1 || choice > 3)
    {
        cout << "Confusion is in U warrior. This round is void." << endl;
        return 0;
    }

    if (choice - 1 == compChoice)
    {
        cout << "The clash ends in a stalemate!" << endl;
        return 0;
    }

    if ((choice == 1 && compChoice == 2) ||
        (choice == 2 && compChoice == 0) ||
        (choice == 3 && compChoice == 1))
    {
        cout << "Alas! Defeat shadows thy blade!" << endl;
        return -1;
    }

    cout << "Victory sings in thy name, Noble!" << endl;
    return 1;
}

void gamesessionclass::kheloge(entrypoint &ok1)
{
    cout << "Enter Number Of Battles You Want Noble : ";
    cin >> n;

    int w = 0, l = 0, d = 0;

    for (int i = 1; i <= n; i++)
    {
        int r = rp.khelogerps();
        if (r == 1)
            w++;
        else if (r == -1)
            l++;
        else
            d++;
    }

    UserStats &u = ok1.user[ok1.activeUser];
    u.wins += w;
    u.losses += l;
    u.draws += d;
    u.matches++;

    system("cls") ; 
    cout << "---------------------------------" << endl;
    cout << "        MATCH SUMMARY             " << endl;
    cout << "---------------------------------" << endl;
    cout << "Player        : " << ok1.activeUser << endl;
    cout << "Wins          : " << w << endl;
    cout << "Losses        : " << l << endl;
    cout << "Draws         : " << d << endl;

    if (w > l)
        cout << "Match Result  : Victory crowns thee!" << endl;
    else if (l > w)
        cout << "Match Result  : Defeat humbles the proud." << endl;
    else
        cout << "Match Result  : Balance reigns. A draw!" << endl;

    cout << endl;
    cout << "Profile etched into the history of this eden successfully." << endl<<endl<<endl;
    cout << "Returning to thy entrypoint !!!" << endl;

    cout << "---------------------------------" << endl<< endl<< endl;

    
}

int main()
{
    srand(time(0));
    entrypoint ok;
    ok.load();
    ok.entrypointsir();
}
