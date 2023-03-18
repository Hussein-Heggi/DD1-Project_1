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
    ImplicationTable();
    cout << "---------------------------------------------------------------" << endl;
    Prime_Implicants();
    cout << "---------------------------------------------------------------" << endl;
    Essential_PI();
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
                     return false;
             }
    
    for (int i = 0; i<Validator.size(); i++)
    {
        string temp = Validator[i];
        int indx = 0;
        for(int j = 1; j <= n; j++)
        {
            if (temp[0] == Pos_Var[j])
                indx = j;
        }
        
        for (int z = 1; z < temp.length(); z++)
        {
            for (int w = indx; w > 0; w--)
            {
                if (temp[z] == Pos_Var[w])
                    return false;
            }
        
        }
    }
             
    return true;
}
void QM::Gen_Fun()
{
    bool repeat = false;
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
       
        if(Validator[i] != Perfect)
        {
            string Incomplete = Variables[i];
            string I1 = Incomplete, I2 = Incomplete;
            y = 0;
            for (int z = 0; z < num+y ; z++)
            {
                if (Incomplete[z] != '\'')
                {
                    if (Incomplete[z] != Perfect[z-y])
                    {
                        I1.insert(z, Add[z-y]);
                        I2.insert(z, Bar[z-y]);
                        Variables.push_back(I1);
                        Variables.push_back(I2);
                        break;
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
//    }
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
        cout << "(" << Maxterms[i] << ")";
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

int QM::oneCount(string s)
{
    int count = 0;
    for (char c : s)
    {
        if (c == '1')
            count++;
    }
    return count;
}


bool QM::CompareBits(string s1,string s2)
{
   int n = 0;
   for(int i=0; i < s1.length(); i++)
   {
       if(s1[i] != s2[i])
        n++;
   }
   return (n==1);
}


string QM::ReplaceBits(string s1,string s2)
{
   string Vartemp = "";
   for(int i=0; i < s1.length(); i++)
   if(s1[i] != s2[i])
       Vartemp = Vartemp+"-";
   else
       Vartemp = Vartemp + s1[i];

   return Vartemp;
}


void QM::ImplicationTable()
{
    long int size = Bsterms.size();
    vector <string> col1;
    vector <string> col2;
    vector <string> col3;
    sort(Bsterms.begin(), Bsterms.end(), [](string a, string b){
        return oneCount(a) < oneCount(b);
    });
        for (int i = 0; i < Bsterms.size(); i++)
        {
            col1.push_back(Bsterms[i]);
        }
    bool visited[size];
    for (int i = 0; i < size; i++)
    {
        visited[i] = false;
    }
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                if (CompareBits(col1[i], col1[j]))
                {
                    visited[i] = true;
                    visited[j] = true;
                    col2.push_back(ReplaceBits(col1[i], col1[j]));
                    sort(col2.begin(),  col2.end(), [](string a, string b) {
                        return oneCount(a) < oneCount(b);
                    });
                }
            }
        }
    bool visited1[col2.size()];
    for (int i = 0; i < col2.size(); i++)
    {
        visited1[i] = false;
    }
    for (int i = 0; i < col2.size()-1; i++)
    {
        for (int j = i+1; j < col2.size(); j++)
        {
            if (CompareBits(col2[i], col2[j]))
            {
                visited1[i] = true;
                visited1[j] = true;
                col3.push_back(ReplaceBits(col2[i], col2[j]));
                sort(col3.begin(),  col3.end(), [](string a, string b) {
                    return oneCount(a) < oneCount(b);
                });
            }
        }
    }
    for (int i= 0; i < size; i++)
    {
        if (visited[i] != true)
        {
            PIs.push_back(col1[i]);
        }
    }
    
    
    for (int i = 0; i < col2.size(); i++)
    {
         if (visited1[i] != true)
             PIs.push_back(col2[i]);
        
    }
    for (int i = 0; i < col3.size(); i++)
    {
        for (int j = i+1; j < col3.size(); j++)
        {
            if (col3[i] != col3[j])
            {
                break;
            }
            PIs.push_back(col3[i]);
        }
    }
}


void QM::Prime_Implicants()
{
    cout << "The Prime Implicants are:" << endl;
    PreEssential = PIs;
    string target;
    string result;
    string r;
    for (int i = 0; i < PIs.size(); i++)
    {
        cout << PIs[i] << " => ";
        result = "";
        r = "";
        target = PIs[i];
        for(int j = 0; j < target.length(); j++)
        {
            if (target[j] != '-')
            {
                if (target[j] == '0')
                {
                    result.append(Bar[j]);
                    r.append(Bar[j]);
                }
                else
                {
                    result.append(Add[j]);
                    r.append(Add[j]);
                }
                    
            }
            else if (target[j] == '-')
                r.append("-");
        }
        PIs[i] = result;
        PreEssential[i] = r;
        cout << PIs[i] << endl;
    }
}

void QM::Essential_PI()
{
    cout << "The Essential Prime Implicants are:" << endl;
    bool exact;
    string temp1;
    string temp2;
    int p;
    vector<vector<string>> chart;
    vector<string> col;
    for (int i = 0; i < PreEssential.size(); i++)
    {
        temp1 = PreEssential[i];
        for(int j = 0; j < minterms.size(); j++)
        {
            p = 0;
            exact = true;
            temp2 = minterms[j];
            for (int z = 0; z < temp1.length(); z++)
            {
//                cout << temp1[z] << "  " << temp2[p] << endl;
                if (temp1[z] != '-')
                {
                    
                    if (temp1[z] != temp2[p])
                    {
//                        cout << 1 << endl;
                        exact = false;
                        break;
                    }
                    else if (z == temp1.length()-1)
                    {
                        if (temp2[p+1] == '\'')
                        {
//                            cout << 2 << endl;
                            exact = false;
                            break;
                        }
                    }
                    else
                        p++;
                }
                else
                {
                    if (temp2[p] == '\'')
                    {
//                        cout << 3 << endl;
                        exact = false;
                        break;
                    }
                    else
                    {
                        if (temp2[p+1] == '\'')
                            p++;
                        p++;
                    }
                    
                }
                
            }
                
            if (exact == true)
            {
                col.push_back(temp2);
            }
            else
                col.push_back(" -- ");
        }
        
        chart.push_back(col);
//        for (int i = 0; i<col.size(); i++)
//            cout << col[i] << " ";
//        cout << endl;
        col.clear();
    }
    
    vector<vector<int>> check(PIs.size(), vector<int>(minterms.size()));
    fill(check.begin(), check.end(), vector<int>(minterms.size(), 0));
    
    for (int j = 0; j<minterms.size(); j++)
    {
        for (int i = 0; i<PIs.size(); i++)
        {
            if (chart[i][j] != " -- ")
            {
                check[i][j] = 1;
                
            }
        }
    }
    int c, indx;
    vector<bool> unique (PIs.size(), false);
    for (int j = 0; j<minterms.size(); j++)
    {
        indx = 0;
        c = 0;
        for (int i = 0; i<PIs.size(); i++)
        {
            if (check[i][j] == 1)
            {
                c++;
                indx = i;
            }
        }
        
        if (c == 1)
            unique[indx] = true;
        
    }
    
    for (int i=0; i<PIs.size(); i++)
    {
        if (unique[i] == true)
            EPIs.push_back(PIs[i]);
    }
    
    for (int i = 0; i<EPIs.size(); i++)
    {
        cout << EPIs[i] << endl;
    }
}
                        


