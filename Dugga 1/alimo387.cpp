//  alimo387.cpp
//  Alice Molin
//  970121-6005

//  Created by Alice Molin on 2018-09-14.
//  Copyright © 2018 Alice Molin. All rights reserved.

#include <iostream>

using namespace std;

int main()
{
    int int_date, int_year, int_month, int_day; // my variables
    bool leapyear;
    
    cout << "Enter a date (YYYYMMDD): "; // asking the user to put a date
    cin >> int_date; // example: 20110320
    
    while (int_date >= 0) // sets the loop to restart the program as long as the given condition is true
    {
    
    int_year = (int_date / 10000); // extracts the year from the date
    
    int_month = (int_date / 100) % 100; // extracts the month from the date
    
    int_day = int_date % 100; // extracts the day from the date
    
    leapyear = ((int_year % 4 == 0 && int_year % 100 != 0) || (int_year % 400 == 0)); // calculates if int_year is a leap year
    
        
    if (int_year < 1000 || int_year > 9999) // condition 2, checking year validation
        {
        cout << "Invalid date!" << endl;
        }
        else if (int_month <= 0 || int_month > 12) // condition 3, checking month validation
        {
        cout << "Invalid date!" << endl;
        }
    
        else if ((leapyear == true && int_month == 2 && int_day == 29)) // condition 4, max 29 days in month 2 if int_year is a lap year
        {
            cout << int_date << " is a valid date!" << endl;
        }
    
        else if ((int_month == 1 || int_month == 3 || int_month == 5 || int_month == 7 ||
                 int_month == 8 || int_month == 10 || int_month == 12) &&
                 (int_day < 1 || int_day > 31)) // condition 5, max 31 days and min 1 for months 1,3,5,7,8,10,12
        {
            cout << "Invalid date!" << endl;
        }
        else if ((int_month == 4 || int_month == 6 || int_month == 9 || int_month == 11)
                 && (int_day < 1 || int_day > 30)) // condition 6, max 30 days for months 4,6,9,11
        {
            cout << "Invalid date!" << endl;
        }
        else if ((int_month == 2) && (int_day < 1 || int_day > 28)) // condition 7, max 28 days for month 2 if int_year is NOT a leap year
        {
            cout << "Invalid date!" << endl;
        }
        else
        {
            cout << int_date << " is a valid date!" << endl; // if none of the above, the date is valid
        }
        
    {
        cout << "Enter a date (YYYYMMDD): "; // ask for a date again 
        cin >> int_date;
    }
    
    }
    {
    cout << "Program ended, bye!" << endl; // if input is less than 0 program is ended
    }
    
return 0;
}
