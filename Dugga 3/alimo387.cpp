//Alice Molin, 970121-6005

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;


//*******************************//
   //DECLARATION OF DATA TYPE
//******************************//

struct Debit_Note
{
    string license_plate;
    int day_of_month;
    int fee;
};

//*****************************//
    //FUNCTION DECLARATION
//****************************//

//function for splitting the struct into 3
Debit_Note split();

//function for reading the list of debit notes entered by the user from CIN and stores them in an array
int read_debit_notes (string &month, Debit_Note DN[], int n);

//function for sorting days
void sort_date (Debit_Note DN[], int n);

//function for sorting license plates in alphabetic order
void sort_lp (Debit_Note DN[], int n);

//function that displays the invoice for a given car
void do_invoice (Debit_Note DN[], int n, string month);


//**********************************//
              //MAIN
//*********************************//
int main()
{
const int SIZE = 500; //Max size
Debit_Note DN[SIZE]; //The Debit note
int howMany = 0;
string month;

//calling function to read the input
howMany = read_debit_notes (month, DN, SIZE);

//sorting the notes and dates
sort_date (DN, howMany);
sort_lp (DN, howMany);

//displaying the invoices
do_invoice (DN, howMany, month);

return 0;
}

//*********************************//
     //FUNCTIONS DEFINATIONS
//*********************************//

Debit_Note split ()
{
    Debit_Note dn;
    cin >> dn.license_plate >> dn.day_of_month >> dn.fee;

    return dn;
}

int read_debit_notes (string &month, Debit_Note DN[], int n)
{
    Debit_Note dn;
    int counter = 0;

    cout << "Enter month followed by debit notes: " << endl;
    cin >> month;

    dn = split();

    do
    {
        DN[counter] = dn;
        ++counter;

        if (counter == n)
        {
            break;
        }
        dn = split();
    }
    while (dn.license_plate != "STOP");

  return counter;
}

void sort_date (Debit_Note DN[], int n)
{
        for (int pass = 1; pass <= n -1; ++pass) //Passes
        {
            for (int i = 0; i < n - 1; ++i) //One pass
            {
                if (DN[i + 1].day_of_month < DN[i].day_of_month) //comparing two values
                {
                    //swapping
                    Debit_Note temporary_d = DN[i];
                    DN[i] = DN[i + 1];
                    DN[i + 1] = temporary_d;
                }
            }
        }
}

void sort_lp (Debit_Note DN[], int n)
{
        for (int pass = 1; pass <= n -1; ++pass) //Passes
        {
            for (int i = 0; i < n - 1; ++i) //One pass
            {
                if (DN[i + 1].license_plate < DN[i].license_plate) //comparing two letters
                {
                    //swapping
                    Debit_Note temporary = DN[i];
                    DN[i] = DN[i + 1];
                    DN[i + 1] = temporary;
                }
            }
        }
}

void do_invoice (Debit_Note DN[], int n, string month)
{
    cout << "\nCreating invoices..." << endl << endl;

    for (int i = 0; i < n; ++i)
    {
        if ((DN[i-1].license_plate != DN[i].license_plate)&&(DN[i-1].license_plate != DN[i+1].license_plate) || //Checking if license plate is unique
           ((DN[i-1].license_plate != DN[i].license_plate)&&(DN[i].license_plate == DN[i+1].license_plate)))
        {
                cout << "Invoice: " << DN[i].license_plate << endl;
                cout << "Dates: " << month << "/" << DN[i].day_of_month << " ";

                for (int j = (i+1); j < n-1; ++j)
                    {
                        if (DN[i].license_plate == DN[j].license_plate && j != i && j > i) //print every month driver gets a fee
                        {
                            DN[i].fee = DN[i].fee + DN[j].fee; //calculating total fee
                            cout << month << "/" << DN[j].day_of_month << endl;
                        }
                    }
                cout << endl;
                cout << "Amount to pay: " << DN[i].fee << endl;
                cout << "================================" << endl << endl;

        }
    }


}

