#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::cin;
using std::array;

const int SCAMT = 10;

void pairZero();
array<int, SCAMT>* inputScores();
void displayScores(const array<int, SCAMT>*, double);
double averageScores(const array<int, SCAMT>);
void golfScores();
bool isNum(const std::string&);

int main()
{
    golfScores();
    cin.clear();
    cin.ignore();
    cin.get();
    return 0;
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

array<int, SCAMT>* inputScores()
{
    cout << "Enter up to 10 scores (q to quit):\n";
    int i = 0;
    array<int, SCAMT> scores{ };
    int score = 0;
    cout << "Score 1: ";
    while (i < 10)
    {
        std::string in;
        std::getline(cin, in);
        if (in == "q" || in == "Q")
            return &scores;
        else if (isNum(in))
        {
            char* cptr;
            score = strtol(in.c_str(), &cptr, 10);
            if (score < 9)
                cout << "Score " << i + 2 << ": ";
            scores[i] = score;
            i++;
        }
        else
        {
            cout << "Invalid input. Try again.\n";
            continue;
        }
    }
    return &scores;
}

void displayScores(const array<int, SCAMT>* scores, double avg)
{
    cout << "Scores:\n";
    for (int i = 0; i < SCAMT; i++)
        cout << (*scores)[i] << "\t";
    cout << "\n" << "Average: " << avg << "\n";
}

double averageScores(const array<int, SCAMT>* scores)
{
    int total = 0;
    double avg;
    int x = 0;
    for (int score : (*scores))
    {
        x++;
        total += score;
    }
    avg = total / x;
    return avg;
}

void golfScores()
{
    array<int, SCAMT>* scores = inputScores();
    cout << "Score 1 " << (*scores)[0];
    double avg = averageScores(scores);
    displayScores(scores, avg);
}

bool isNum(const std::string &str)
{
    char* cptr;
    strtol(str.c_str(), &cptr, 10);
    return *cptr == '\0';
}
