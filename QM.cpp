

#include "QM.hpp"
QM::QM()
{
    
}
void QM::Start()
{
    cout << "=====================================" << endl;
    ifstream test1("/Users/s7s/Desktop/Uni Spring 2023/Digital Design/DD1 Project 1/Test_File.txt");
    test1 >> BoFun;
    cout << Validate_Bool(BoFun) << endl;
    cout << "Number of variables:" << num << endl;
}
int QM::Compare(string X, string Y)
{
    int i = 0;
    while (X[i] && Y[i])
    {
        if (X[i] != Y[i])
            return 0;
        
 
        i++;
    }
 
    return (Y[i] == '\0');
}
 

bool QM::strstr(string X, string Y)
{
    int i = 0;
    while (X[i] != '\0')
    {
        if ((X[i] == Y[i]) && Compare(X, Y)) {
            return 1;
        }
        i++;
    }
 
    return 0;
}
bool QM::Validate_Bool(string b)
{
    Validated.clear();
    b.erase(remove_if(b.begin(), b.end(), ::isspace),b.end());
    string stop = "+";
    string copy = b;
    copy.erase(remove(copy.begin(), copy.end(), '\''), copy.end());
    size_t pos = copy.find (stop);
    string sub;
    sub = copy.substr(0, pos);
    num = sub.length();
    pos = 0;
    while (( pos = b.find (stop)) != std::string::npos)
    {
        sub = b.substr(0, pos);
        cout << sub <<endl;
        Validated.push_back(sub);
        b.erase(0, pos + stop.length());
    }
//    for (int i = 0; i < num; i++)
//        cout <<Validated[i];
   
    for (int i = 0; i<Validated.size(); i++)
        for(int j = 1; j<= 1; j++)
            if ((strstr(Validated[i], Pos_Var[j])) == 0)
                return false;
    
    return true;
}


