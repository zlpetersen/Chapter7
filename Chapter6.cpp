// Chapter6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using std::cout;
using std::cin;
using std::string;
using std::ifstream;

void pause();
void showmenu();
void lowup();
void donationsumavg();
void showbopmenu();


struct bop
{
    string fullname;
    string title;
    string bopname;
    int preference;
};

void dbn(std::vector<bop> people);
void dbt(std::vector<bop> people);
void dbb(std::vector<bop> people);
void dbp(std::vector<bop> people);
void bopper();
void taxes();
void spri();
void alphaTest();
void readFileLength();
void readSPRIFile();
std::vector<bop> initializeBop();


std::vector<bop> initializeBop()
{
    std::vector<bop> people =
    {
        {"John Smith", "Junior Programmer", "bop0", 0},
        {"Jane Doe", "Analyst", "bop1", 2},
        {"Kevin Malone", "Accountant", "bop2", 1},
        {"Jim Halpert", "Salesman", "bop3", 2},
        {"Pam Beezly", "Receptionist", "bop4", 1}
    };
    return people;
}

int main()
{
    showmenu();
    string choice;
    cin >> choice;
    while (!(choice == "q"))
    {
        int option = std::stoi(choice);
        switch (option)
        {
            case 1: lowup(); break;
            case 2: bopper(); break;
            case 3: taxes(); break;
            case 4: spri(); break;
            case 5: alphaTest(); break;
            case 6: readFileLength(); break;
            case 7: readSPRIFile(); break;
            default: "\nThat's not a choice\n"; break;
        }
        //pause();
        showmenu();
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> choice;
    }
    cout << "Bye";
    return 0;
}

void pause()
{
    cin.get();
    cin.get();
}

void showmenu()
{
    cout << "Choose an option:\n"
        "1) Lower Upper\n2) BOP\n"
        "3) Taxes\n4) SPRI\n5) Word Beginnings\n6) File Character Count\n7) SPRI From File\nq) quit\n> ";
}

void lowup()
{
    cin.get();
    cout << "Enter a string (@ to end): ";
    string input;
    char delimiter('@');
    std::getline(cin, input, delimiter);
    string output;
    for (char i : input)
    {
        if (isdigit(i))
            continue;
        else if (islower(i))
        {
            output += (char)toupper(i);
        }
        else
        {
            output += (char)tolower(i);
        }
    }
    cout << "output: " << output << "\n";
}

void donationsumavg()
{/*
    cout << "Enter up to 10 values. Type a character to quit.\n";
    std::array<double, 10> donations{};
    int count = 1;
    cout << "Donation " << count << ": ";
    for (auto item : donations)
    {
        cin >> item;
        cout << item;
        if (cin.fail())
        {
            cin.clear();
            cin.clear();
            return;
        }
        cout << "Donation " << count << ": ";
        count++;
    }
    for (auto donation : donations)
    {
        cout << donation;
    }
    double avg = 0;
    int amtover = 0;
    for(auto item : donations)
    {
        avg += item;
        cout << "calculating avg: " << item << "\n";
    }
    avg /= count;
    cout << "Average: " << avg << "\n";
    for(auto don: donations)
    {
        if (don > avg)
            amtover++;
    }
    cout << "Amount of donations over average: " << amtover << "\n";*/
}

void dbn(std::vector<bop> people)
{
    for(auto person : people)
    {
        cout << person.fullname << "\n";
    }
}

void dbt(std::vector<bop> people)
{
    for (int i=0; i < 5; i++)
    {
        cout << people[i].title << "\n";
    }
}

void dbb(std::vector<bop> people)
{
    for (int i=0; i < 5; i++)
    {
        cout << people[i].bopname << "\n";
    }
}

void dbp(std::vector<bop> people)
{
    for (int i=0; i < 5; i++)
    {
        switch (people[i].preference)
        {
            case 0: cout << people[i].fullname; break;
            case 1: cout << people[i].title; break;
            case 2: cout << people[i].bopname; break;
            default: cout << "Incorrect usage"; break;
        }
        cout << "\n";
    }
}

void bopper()
{
    std::vector<bop> people = initializeBop();
    showbopmenu();
    char choice;
    cin >> choice;
    while(choice != 'q')
    {
        switch(choice)
        {
            case 'a': dbn(people); break;
            case 'b': dbt(people); break;
            case 'c': dbb(people); break;
            case 'd': dbp(people); break;
            default: "Choose a displayed option\n> "; break;
        }
        showbopmenu();
        cin >> choice;
    }
}

void showbopmenu()
{
    cout << "Benevolent Order of Programmers Report\n"
            "a. display by name    b. display by title\n"
            "c. display by bopname d. display by preference\n"
            "q. quit\n> ";
}

void taxes()
{
    float nextTen = 0.1f;
    float nextTwenty = 0.15f;
    float afterThirtyFive = 0.2f;
    float totalTaxes{};
    float income{};

    cout << "Enter your income: ";
    cin >> income;

    while (cin.fail())
    {
        cout << "Enter a number.\n";
        cin >> income;
    }

    if (income > 5000)
    {
        if (income <= 15000)
            totalTaxes += (15000 - income) * nextTen;
        else
            totalTaxes += 10000 * nextTen;
    }
    if (income > 15000)
    {
        if (income <= 35000)
            totalTaxes += (35000 - income) * nextTwenty;
        else
            totalTaxes += 20000 * nextTwenty;
    }
    if (income > 35000)
        totalTaxes += (income - 35000) * afterThirtyFive;

    cout << "You owe " << totalTaxes << " tvarps in income taxes.\n";
}

void spri()
{
    struct contributor
    {
        string name;
        double donation{};
    };
    cout << "Society for the Preservation of Rightful Influence\n\n";
    cout << "Enter the number of contributions: ";
    int contributions{};
    cin >> contributions;
    while (cin.fail())
    {
        cout << "Please enter an integer\n";
        cin >> contributions;
    }
    if (contributions == 0)
    {
        cout << "\nGrand Patrons\nNone\n\nPatrons\nNone\n";
        return;
    }
    contributor* contributors;
    contributors = new contributor[contributions];
    for (int i=0; i < contributions; i++)
    {
        cin.get();
        if (i > contributions)
            break;
        cout << "Contribution " << i + 1 << ":\n";
        cout << "Name of Donor: ";
        std::getline(cin, contributors[i].name);
        if (contributors[i].name.length() > 15)
        {
            contributors[i].name.resize(12);
            contributors[i].name.append("...");
        }
        cout << "Donation Amount: ";
        cin >> contributors[i].donation;
        while (cin.fail())
        {
            cout << "Enter a number\n";
            cout << "Donation Amount: ";
            cin >> contributors[i].donation;
        }
    }
    cout << "Grand Patrons\n";
    for (int i=0; i < contributions; i++)
    {
        string tabs = "\t";
        if (contributors[i].name.length() < 8)
            tabs = "\t\t";
        if (contributors[i].donation >= 10000)
            cout << contributors[i].name << tabs << contributors[i].donation << "\n";
    }
    cout << "\nPatrons\n";
    for (int i=0; i < contributions; i++)
    {
        string tabs = "\t";
        if (contributors[i].name.length() < 8)
            tabs = "\t\t";
        if (contributors[i].donation < 10000)
            cout << contributors[i].name << tabs << contributors[i].donation << "\n";
    }
    delete[] contributors;
}

std::vector<string> getQInput()
{
    string word;
    std::vector<string> sentence;
    while (cin >> word)
    {
        if (word == "q")
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return sentence;
        }
        sentence.push_back(word);
    }
}

void alphaTest()
{
    cout << "Enter words (q to quit):\n";
    std::vector<string> sentence;
    sentence = getQInput();
    int vowelBegin{};
    int consBegin{};
    int otherBegin{};
    std::set<char> vowels {'a', 'e', 'i', 'o', 'u'};
    for (auto item : sentence)
    {
        if (isalpha(item[0]))
        {
            if (vowels.find(item[0]) != vowels.end())
                vowelBegin++;
            else
                consBegin++;
        }
        else
            otherBegin++;
    }
    cout << vowelBegin << " words beginning with vowels\n"
         << consBegin << " words beginning with consonants\n"
         << otherBegin << " others\n";
}

void readFileLength()
{
    cout << "Enter the filename (q to quit): ";
    std::fstream fileReader;
    string fname;
    cin >> fname;
    if (fname == "q" || fname == "Q")
        return;
    fileReader.open(fname);
    while (fileReader.fail())
    {
        cout << "File not found.\nEnter the filename (q to quit): ";
        cin >> fname;
        if (fname == "q" || fname == "Q")
            return;
        fileReader.open(fname);
    }
    int count{};
    char ch;
    while (fileReader >> std::noskipws >> ch)
    {
        count++;
    }
    cout << fname << " has " << count << " characters.";
}

void readSPRIFile()
{
    struct contributor
    {
        string name;
        double donation{};
    };
    std::ifstream fileReader("donors.txt");
    if (fileReader.fail())
    {
        cout << "File not found.\n";
        return;
    }
    int len;
    string l;
    std::getline(fileReader, l);
    len = atoi(l.c_str());
    cout << "Society for the Preservation of Rightful Influence\n\n";
    cout << "Number of contributors: " << len << "\n";
    if (len == 0)
    {
        cout << "\nGrand Patrons\nNone\n\nPatrons\nNone\n";
        return;
    }
    contributor* contributors;
    contributors = new contributor[len];
    for (int i=0; i < len; i++)
    {
        std::getline(fileReader, contributors[i].name);
        if (contributors[i].name.length() > 15)
        {
            contributors[i].name.resize(12);
            contributors[i].name.append("...");
        }
        string don{};
        std::getline(fileReader, don);
        contributors[i].donation = atof(don.c_str());
    }
    cout << "Grand Patrons\n";
    for (int i=0; i < len; i++)
    {
        string tabs = "\t";
        if (contributors[i].name.length() < 8)
            tabs = "\t\t";
        if (contributors[i].donation >= 10000)
            cout << contributors[i].name << tabs << contributors[i].donation << "\n";
    }
    cout << "\nPatrons\n";
    for (int i=0; i < len; i++)
    {
        string tabs = "\t";
        if (contributors[i].name.length() < 8)
            tabs = "\t\t";
        if (contributors[i].donation < 10000)
            cout << contributors[i].name << tabs << contributors[i].donation << "\n";
    }
    delete[] contributors;
}
