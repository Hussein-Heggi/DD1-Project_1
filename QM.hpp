
#ifndef QM_hpp
#define QM_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;

class QM
{
private:
    long int num;
    char Pos_Var[12] = {"'abcdefghij"};
    string Add[10] = {"a","b","c","d","e","f","g","h","i","j"};
    string Bar[10] = {"a'","b'","c'","d'","e'","f'","g'","h'","i'","j'"};
    string BoFun;
    string Perfect = "";
    vector<string> Variables;
    vector<string> Validator;
    vector<string> minterms;
    vector<string> Bsterms;
    
    
public:
    QM(string, int);
    void Get_Fun(string);
    void Validate_Fun();
    void Convert();
};

#endif 
