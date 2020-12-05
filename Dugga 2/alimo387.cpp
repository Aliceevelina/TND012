// Alice Molin, 970121-6005

#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    bool runprogram = true;
    
    do
    {
        //Variable Declaration
        const int SIZE = 200; //Maximum slots in array
        int integers[SIZE]; //Store the sequence
        int input = 0;
        bool triple = false;
        
        
        cout << "Enter a list of positive integers: "; //Tells the user to enter the numbers
        for (int i = 0; i < SIZE; ++i) //Makes the program pick out only the first 200
        {
            cin >> integers[i];
            ++input;
            
            if (integers[0] < 0)
            {
                cout << "Exiting the program..." << endl; // Program shuts down if first input is negative
                return 0;
            }
            
            else if (integers[i] < 0) // stop input when a negative number is typed
            {
                break;
            }
            
        }
        
        //sort (från lecture 5)
        for (int pass = 1; pass <= input -1; pass++) //Passes
        {
            for (int i = 0; i < input - 1; i++) //One pass
            {
                if (integers[i] > integers[i + 1]) //comparing two values
                {
                    //the swapping
                    int temporary = integers[i];
                    integers[i] = integers[i+1];
                    integers[i + 1] = temporary;
                }
            }
        }
        //hitta a,b,c
        for (int a = 0; a < input; ++a)
        {
            for (int b = 0; b < input; ++b)
            {
                for (int c = 0; c < input; ++c)
                {
                    if (((integers[a]*integers[a]) + (integers[b]*integers[b]) == (integers[c]*integers[c])) && (integers[a] < integers[b]) && (integers[b] < integers[c])) //condition for finding valid triples
                    {
                        cout << "(" << integers[a] << ", " << integers[b] << ", " << integers[c] << ")" << endl;
                        triple = true;
                    }
                }
            }
        }
        
        if (triple == false) //if no triples are found
        {
            cout << "No triples found..." << endl;
            
        }
    }
    while (runprogram == true);
    
    return 0;
    }
