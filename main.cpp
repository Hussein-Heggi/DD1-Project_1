
#include <iostream>
#include "QM.hpp"
using namespace std;

int main()
{
    QM t;
    cout << "============================================" << endl;
    cout << " Quine-McCluskey Logic Minimization Program" << endl;
    cout << "============================================" << endl;
    int q,c;
    do
    {
    cout << "How can I help you?" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1- Perform a Quine-McCluskey operation" << endl;
    cout << "2- Exit" << endl;
    cin >> q;
    c = q;
    switch (q)
        {
            case 1:
                cout << "--------------------------------------------" << endl;
                t.Start();
                break;
                
            case 2:
                cout << "--------------------------------------------" << endl;
                cout << "Thanks for using our Program" << endl;
                cout << "Created by Hussein Heggi and Youssef Elmahdy" << endl;
                exit(EXIT_SUCCESS);
                break;
                
            default:
                cout << "--------------------------------------------" << endl;
                cout << "Error Wrong Input, please try again" << endl;
                cout << "--------------------------------------------" << endl;
                break;
        }
    }while ((q != 1) && (c != 2));
}
