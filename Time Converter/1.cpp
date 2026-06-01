#include <iostream>
using namespace std;

class TimeConverter
{
public:
    void secondsToHMS()
    {
        int totalSeconds, hours, minutes, seconds;

        cout << "Enter total seconds: ";
        cin >> totalSeconds;

        hours = totalSeconds / 3600;
        minutes = (totalSeconds % 3600) / 60;
        seconds = totalSeconds % 60;

        cout << "HH:MM:SS => " << hours << ":" << minutes << ":" << seconds << endl;
    }

    void hmsToSeconds()
    {
        int hours, minutes, seconds, total;

        cout << "Enter hours: ";
        cin >> hours;

        cout << "Enter minutes: ";
        cin >> minutes;

        cout << "Enter seconds: ";
        cin >> seconds;

        total = (hours * 3600) + (minutes * 60) + seconds;

        cout << "Total seconds: " << total << endl;
    }
};

int main()
{
    TimeConverter tc;
    int choice;

    cout << "1. Seconds to HH:MM:SS" << endl;
    cout << "2. HH:MM:SS to Seconds" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        tc.secondsToHMS();
    }
    else if (choice == 2)
    {
        tc.hmsToSeconds();
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }
}