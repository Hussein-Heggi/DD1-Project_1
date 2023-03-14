
#include "QM.hpp"
QM::QM(string x)
{
    cout << "=============================================" << endl;
    BoFun = x;
    Bool_Fun(BoFun);
    Validate_Fun();
//    for (int i = 0; i < Variables.size(); i++)
//        cout << Variables[i] << " ";
//    cout << endl;
//    cout << "Number of variables:" << num << endl;
}

void QM::Bool_Fun(string b)
{
    b.erase(remove_if(b.begin(), b.end(), ::isspace),b.end());
    string sub;
    stringstream X(b);
    while (getline(X, sub, '+'))
    {
        Variables.push_back(sub);
    }
    
}
void QM::Validate_Fun()
{
    bool repeat;
    Validator = Variables;
    for (int i = 0; i < Validator.size(); i++)
    {
        Validator[i].erase(remove(Validator[i].begin(), Validator[i].end(), '\''), Validator[i].end());
        if (num < Validator[i].length())
            num = Validator[i].length();
    }
        
    for (int i = 0; i<Variables.size(); i++)
        for(int j = 1; j<= num; j++)
        {
            if (!(Variables[i].find(Pos_Var[j]) != std::string::npos))
            {
                
            }
            else
            {
                repeat = false;
                if (minterms.size() == 0)
                    minterms.push_back(Variables[i]);
                else
                {
                    for (int z = 0; z < minterms.size(); z++)
                    {
                        if (Variables[i] == minterms[z])
                            repeat = true;
                        
                        if (repeat == false)
                            minterms.push_back(Variables[i]);
                    }
                }
                
            }
                
        }
            
}


