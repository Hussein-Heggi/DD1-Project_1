
#include <iostream>
#include "QM.hpp"
using namespace std;

void Examples(string &x, int &y)
{
    int r = 0;
    string Ex[10];
    int E[10];
    E[0] = 4;
    E[1] = 4;
    E[2] = 3;
    Ex[0] = "abc + a'b'c";
    Ex[1] = "abce + a'b'";
    Ex[2] = "a + b + c";
    Ex[3] = "";
    Ex[4] = "";
    Ex[5] = "";
    Ex[6] = "";
    Ex[7] = "";
    Ex[8] = "";
    Ex[9] = "";
    
    do
    {
        cout << "Please select an option: " << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "1-"  << Ex[0] << endl;
        cout << "2-"  << Ex[1] << endl;
        cout << "3-"  << Ex[2] << endl;
        cout << "4-"  << Ex[3] << endl;
        cout << "5-"  << Ex[4] << endl;
        cout << "6-"  << Ex[5] << endl;
        cout << "7-"  << Ex[6] << endl;
        cout << "8-"  << Ex[7] << endl;
        cout << "9-"  << Ex[8] << endl;
        cout << "10-" << Ex[9] << endl;
        cout << "---------------------------------------------------------------" << endl;
        cin >> r;
        
        if (r > 10)
        {
            cout << "Error, Please try again." << endl;
        }
        
    }while (r > 10);
    
    
    x = Ex[r-1];
    y = E[r-1];
}
void Operation()
{
    int o = 0;
    cout << "Please select an option: " << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "1- Choose an Example" << endl;
    cout << "2- Insert a new Example" << endl;
    cout << "3- Exit" << endl;
    cin >> o;
    do
    {
        switch (o)
            {
                case 1:
                {
                    cout << "---------------------------------------------------------------" << endl;
                    string e,cont;
                    int n;
                    Examples(e,n);
                    QM test(e,n);
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "Do you want to try again?...Press E to exit." << endl;
                    cin >> cont;
                    if ((cont == "E") || (cont == "e"))
                        o = 3;
                    break;
                }
                case 2:
                {
                    int n;
                    string e, cont;
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "Please enter the number of literals in your example: " << endl;
                    cin >> n;
                    cout << "Please enter your example in a SoP form: (press $ to complete)" << endl;
                    getline(cin, e, '$');
                    QM test(e,n);
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "Do you want to try again? ... Press E to exit." << endl;
                    cin >> cont;
                    if ((cont == "E") || (cont == "e"))
                        o = 3;
                    
                    break;
                }
                case 3:
                {
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "Thanks for using our Program =)" << endl;
                    cout << "Created by Hussein Heggi and Youssef Elmahdy" << endl;
                    exit(EXIT_SUCCESS);
                    break;
                }
                
                default:
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "Error Wrong Input, please try again" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                    break;
        }
    }while (o != 3);
}

int main()
{
    cout << "===============================================================" << endl;
    cout << " Quine-McCluskey Logic Minimization Program" << endl;
    int q = 0;
    do
    {
        cout << "===============================================================" << endl;
        cout << "How can I help you?" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "1- Perform a Quine-McCluskey operation" << endl;
        cout << "2- Exit" << endl;
        cin >> q;
        switch (q)
            {
                case 1:
                    cout << "---------------------------------------------------------------" << endl;
                    Operation();
                    break;
                    
                case 2:
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "Thanks for using our Program =)" << endl;
                    cout << "Created by Hussein Heggi and Youssef Elmahdy" << endl;
                    exit(EXIT_SUCCESS);
                    break;
                    
                default:
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "Error: Wrong Input, please try again" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                    break;
        }
    }while (q != 2);
}
