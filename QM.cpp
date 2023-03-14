
#include "QM.hpp"
QM::QM(string x, int n)
{
    cout << "=============================================" << endl;
    BoFun = x;
    num = n;
    Get_Fun(BoFun);
    Validate_Fun();
    Convert();
    
    for (int i = 0; i < Bsterms.size(); i++)
    {
        cout << Bsterms[i] << " - ";
    }
}

void QM::Get_Fun(string b)
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
    int y;
    for (int i = 1; i <= num ; i++)
    {
        Perfect.push_back(Pos_Var[i]);
    }
        
    for (int i = 0; i<Variables.size(); i++)
    {
        Validator = Variables;
        for (int i = 0; i < Validator.size(); i++)
        {
            Validator[i].erase(remove(Validator[i].begin(), Validator[i].end(), '\''), Validator[i].end());
        }
        for(int j = 1; j<= num; j++)
        {
            if(Validator[i].length() != Perfect.length())
            {
                string Incomplete = Variables[i];;
                string I1 = Incomplete, I2 = Incomplete;
                y = 0;
                for (int z = 0; z < num+y ; z++)
                {
                    if (Incomplete[z+y] != '\'')
                    {
                        if (Incomplete[z+y] != Perfect[z])
                        {
                            I1.insert(z+y, Add[z]);
                            I2.insert(z+y, Bar[z]);
                            Variables.push_back(I1);
                            Variables.push_back(I2);
                        }
                    }
                    else
                        y++;
                }
                    
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
                        
                    }
                    
                    if (repeat == false)
                        minterms.push_back(Variables[i]);
                }
                
            }
                
        }
    }
        
            
}

void QM::Convert()
{
    string zero = "0";
    string one = "1";
    string target;
    string result;
    for (int i = 0; i < minterms.size(); i++)
    {
        result = "";
        target = minterms[i];
        for(int j = 0; j < target.length(); j++)
        {
            if (target[j] != '\'')
            {
                if (target[j+1] == '\'')
                    result.append(zero);
                else
                    result.append(one);
            }
        }
        Bsterms.push_back(result);
    }
    
    
}



