
#include "QM.hpp"
QM::QM()
{
    
}
void QM::Start()
{
    cout << "=====================================" << endl;
    ifstream test1("/Users/s7s/Desktop/Uni Spring 2023/Digital Design/DD1 Project 1/Test_File.txt");
    if (test1.fail())
    {
        cout << "Error loading file" << endl;
        exit(EXIT_SUCCESS);
    }
    
    stringstream buffer;
    buffer << test1.rdbuf();
    BoFun = buffer.str();
    Bool_Fun(BoFun);
    
    if (Validate_Bool() == false)
    {
        cout << "The function is not in a correct SoP form" << endl;
        return;
    }
        
    for (int i = 0; i < Variables.size(); i++)
        cout << Variables[i] << " ";
    cout << endl;
    cout << "Number of variables:" << num << endl;

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
bool QM::Validate_Bool()
{
    int z = 1;
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
            if (Variables[i].find(Pos_Var[j]) != std::string::npos)
                z = 1;
            else
                return false;
        }
            
    
    return true;
}


