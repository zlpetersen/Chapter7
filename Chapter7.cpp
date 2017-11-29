#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::cin;
using std::array;
using std::string;

const int SCAMT = 10;
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void ignore();
void showMenu();
void pairZero();
int inputScores(array<int, SCAMT>*);
void displayScores(const array<int, SCAMT>*, int, double);
double averageScores(const array<int, SCAMT>*, int);
void golfScores();
bool isNum(const std::string&);
void displayBox(box);
void volumeBox(box*);
void boxCaller();
int factorial(int);
void factorialCaller();
int fillArray(double[], int);
void showArray(double[], int);
void reverseArray(double[], int);
void arrayCaller();
void calculateCaller();
void calculate(double, double);
double add(double, double);
double multiply(double, double);
double divide(double, double);
double subtract(double, double);

double(*pf[4])(double, double) = { &add, &subtract, &multiply, &divide };


int main()
{
    int choice;
    string input;
    showMenu();
    while (cin >> input)
    {
        if (input == "q" || input == "Q")
            break;
        char cinput = input[0];
        if (!(isdigit(cinput)))
        {
            ignore();
            cout << "Please enter a valid input\n";
            showMenu();
            continue;
        }
        choice = cinput - '0';
        switch (choice)
        {
        case 0: pairZero(); showMenu();  break;
        case 1: golfScores(); showMenu(); break;
        case 2: factorialCaller(); showMenu(); break;
        case 3: arrayCaller(); showMenu(); break;
        case 4: calculateCaller(); showMenu(); break;
        default: cout << "Please enter a valid input\n"; showMenu(); break;
        }
    }
    return 0;
}


void ignore()
{
    cin.clear();
    cin.ignore(100, '\n');
}


void showMenu()
{
    cout << "0) Harmonic Mean\n1) Golf Scores\n2) Factorial\n3) Reverse Array\n4) Calculator\nq) Quit\n>";
}


void pairZero()
{
    int x, y;
    cout << "Enter 2 numbers (0 to quit): ";
    while (cin >> x >> y)
    {
        if (x == 0 || y == 0)
            break;
        double mean = (2.0 * x * y / (x + y));
        cout << "Harmonic mean: " << mean;
        cout << "\nEnter 2 numbers (0 to quit): ";
    }
}


array<int, SCAMT> scs;

int inputScores(array<int, SCAMT>* scores)
{
    scs = {};
    cout << "Enter up to 10 scores (q to quit):\n";
    int i = 0;
    int score = 0;
    cout << "Score 1: ";
    ignore();
    while (i < 10)
    {
        std::string in;
        cin >> in;
        if (in == "q" || in == "Q")
        {
            break;
        }
        while (!(isNum(in)))
        {
            ignore();
            cout << "Invalid input. try again\n";
            cout << "Score " << i + 2 << ": ";
            cin >> in;
            if (in == "q" || in == "Q")
            {
                break;
            }
        }
        score = atoi(in.c_str());
        if (i < 9)
            cout << "Score " << i + 2 << ": ";
        scs.at(i) = score;
        i++;
    }
    scores = &scs;
    return i;
}


void displayScores(const array<int, SCAMT>* scores, int len, double avg)
{
    cout << "\nScores:\n";
    for (int i=0; i < len; i++)
        cout << scs.at(i) << ",\t";
    cout << "\n" << "Average: " << avg << "\n";
}


double averageScores(const array<int, SCAMT>* scores, int len)
{
    int total = 0;
    double avg;
    int x = 0;
    for (int i=0; i < len; i++)
    {
        x++;
        total += scs.at(i);
    }
    avg = total / x;
    return avg;
}


void golfScores()
{
    array<int, SCAMT>* scores{};
    int len;
    len = inputScores(scores);
    double avg = averageScores(scores, len);
    displayScores(scores, len, avg);
}


bool isNum(const std::string &str)
{
    char* cptr;
    strtol(str.c_str(), &cptr, 10);
    return *cptr == '\0';
}


bool isDouble(const std::string &str)
{
    char* endptr = 0;
    strtod(str.c_str(), &endptr);
    return *endptr == '\0';
}


void displayBox(box b)
{
    cout << b.maker << "\n";
    cout << b.height << "\n";
    cout << b.width << "\n";
    cout << b.length << "\n";
    cout << b.volume << "\n";
}


void volumeBox(box* b)
{
    b->volume = b->height * b->width * b->length;
}


void boxCaller()
{
    box b{ "this is a box", 5, 4, 3, 0 };
    cout << "Box before volume:\n";
    displayBox(b);
    volumeBox(&b);
    cout << "Box after volume:\n";
    displayBox(b);
}


int factorial(int x)
{
    int result = x;
    for (int i = 1; i < x; i++)
    {
        result *= x - i;
    }
    return result;
}


void factorialCaller()
{
    int x;
    cout << "Enter an integer (non-numeric or negative to quit): ";
    string xs;
    while (cin >> xs)
    {
        if (!(isNum(xs)))
            break;
        x = atoi(xs.c_str());
        if (x < 0)
            break;
        int fact = factorial(x);
        cout << "Factorial: " << fact << "\n";
        cout << "Enter an integer (non-numeric or negative to quit): ";
    }
}


int fillArray(double arr[], int size)
{
    cout << "Enter up to " << size << " doubles (non-numeric to quit):\n";
    int dbl = 0;
    ignore();
    int i;
    for (i = 0; i < size; i++)
    {
        cout << "Double " << i + 1 << ": ";
        std::string in;
        cin >> in;
        if (!(isDouble(in)))
            break;
        arr[i] = atof(in.c_str());
    }
    return i;
}


void showArray(double arr[], int size)
{
    cout << "Doubles:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
}


void reverseArray(double arr[], int size)
{
    double tmp[10];
    for (int i = 0; i < size; i++)
        tmp[i] = arr[i];
    for (int i = 0; i < size; i++)
        arr[i] = tmp[size-(i+1)];
}


void arrayCaller()
{
    int size = 10;
    double arr[10]{ 0 };
    size = fillArray(arr, size);
    cout << "Original array:\n";
    showArray(arr, size);
    reverseArray(arr, size);
    cout << "\nReversed array:\n";
    showArray(arr, size);
    cout << "\n";
}


void calculateCaller()
{
    int x, y;
    cout << "Enter 2 numbers (non-numeric to quit): ";
    while (cin >> x >> y)
    {
        calculate(x, y);
        cout << "\nEnter 2 numbers (non-numeric to quit): ";
    }
    ignore();
}


void calculate(double a, double b)
{
    for (auto f : pf)
    {
        cout << f(a, b) << "\n";
    }
}


double add(double a, double b)
{
    cout << a << " + " << b << " = ";
    return a + b;
}


double subtract(double a, double b)
{
    cout << a << " - " << b << " = ";
    return a - b;
}


double multiply(double a, double b)
{
    cout << a << " * " << b << " = ";
    return a * b;
}


double divide(double a, double b)
{
    cout << a << " / " << b << " = ";
    return a / b;
}
