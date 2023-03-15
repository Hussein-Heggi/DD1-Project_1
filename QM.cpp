
#include "QM.hpp"
QM::QM(string x, int n)
{
    cout << "===============================================================" << endl;
    BoFun = x;
    num = n;
    Get_Fun(BoFun);
    if (!Validate_Fun(n))
    {
        cout << "Error, Invalid SoP form." << endl;
        return;
    }
    Gen_Fun();
    Convert();
    cout << "Truth Table: " << endl;
    cout << "---------------------------------------------------------------" << endl;
    TruthTable();
    RConvert();
    SoP_PoS();
}

void QM::Get_Fun(string b)
{
    b.erase(std::remove_if(b.begin(), b.end(), ::isspace),b.end());
    string sub;
    stringstream X(b);
    while (getline(X, sub, '+'))
    {
        Variables.push_back(sub);
    }
    
}

bool QM::Validate_Fun(int n)
{
    Validator = Variables;
    for (int i = 0; i < Validator.size(); i++)
    {
        Validator[i].erase(remove(Validator[i].begin(), Validator[i].end(), '\''), Validator[i].end());
    }
    
    for (int i = 0; i<Validator.size(); i++)
             for(int j = n + 1; j < 11; j++)
             {
                 if ((Validator[i].find(Pos_Var[j]) != std::string::npos))
                     return false;;
             }
    
    
    return true;
}
void QM::Gen_Fun()
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

int QM::binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;
 
    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

void QM::TruthTable()
{
    for (int i = 0; i < num; i++)
    {
        cout << char(int('a') + i) << "      ";
    }
    cout << "Output";
    cout << endl;
    int rows = pow(2,num);
    int values[rows][num+1];
    int shiftrule[num];
    int shiftvalue[num];
    for (int i = 0; i < num; i++)
    {
        shiftrule[i] = pow(2,num-1-i);
        shiftvalue[i] = 0;
    }
    
    int Intterms[Bsterms.size()];
    for (int i = 0; i < Bsterms.size(); i++)
    {
        Intterms[i] = stoi(Bsterms[i]);
        Binterms.push_back(binaryToDecimal(Intterms[i]));
    }
    bool found = false;
    for (int i = 0; i < pow(2,num);i++)
    {
        for (int j = 0; j < Binterms.size(); j++)
        {
            if(i != Binterms[j])
            {
                found = false;
            }
            else
            {
                found = true;
                break;
            }
            
        }
        if (!found)
        {
            Bigterms.push_back(i);
        }
    }
    
    for (int i = 0; i < Bigterms.size(); i++)
    {
        MaxString.push_back(to_string(decimalToBinary(Bigterms[i])));
    }
    
    for (int i = 0; i < pow(2,num); i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (shiftvalue[j] < shiftrule[j])
            {
                values[i][j] = 0;
                shiftvalue[j]++;
            }
            else
            {
                values[i][j] = 1;
                shiftvalue[j]++;
            }
            if (shiftvalue[j] == 2*shiftrule[j]){
                shiftvalue[j] = 0;
            }
            values[i][num] = 0;
        }
    }
    for (int i = 0; i < Binterms.size(); i++){
        
        values[Binterms[i]][num] = 1;
    }

    for (int i = 0; i < pow(2,num); i++)
    {
        for (int j = 0; j < num+1; j++)
        {
            cout << values[i][j] << "      " ;
        }
        cout << endl;
    }
    for (int i = 0; i < MaxString.size(); i++)
    {
        long int len = num - MaxString[i].length();
           for(int j=0; j < len; j++)
                MaxString[i] = "0" + MaxString[i];
    }
}

void QM::SoP_PoS()
{
    cout << "---------------------------------------------------------------" << endl;
    cout << "Canonical SoP: ";
    for (int i = 0; i < minterms.size(); i++)
    {
        if(i == minterms.size()-1)
            cout << minterms[i];
        else
            cout << minterms[i] << " + ";
    }
    cout << endl;
    cout << "Canonical PoS: ";
    for (int i = 0; i < Maxterms.size(); i++)
    {
        cout << "(" << Maxterms[i] << ") ";
    }
    cout << endl;
    
}

long long int QM::decimalToBinary(int N)
{
    ull B_Number = 0;
    int cnt = 0;
    while (N != 0)
    {
        int rem = N % 2;
        ull c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
        cnt++;
    }
    return B_Number;
}

void QM::RConvert()
{
    string target;
    string result;
    for (int i = 0; i < MaxString.size(); i++)
    {
        result = "";
        target = MaxString[i];
        for(int j = 0; j < target.length(); j++)
        {
            if (j == target.length()-1)
            {
                if (target[j] == '0')
                    result.append(Bar[j]);
                else
                    result.append(Add[j]);
            }
            
            else
            {
                if (target[j] == '0')
                    result.append(Add[j]);
                else
                    result.append(Bar[j]);
                
                result.append("+");
            }
                
        }
        Maxterms.push_back(result);
    }
}
