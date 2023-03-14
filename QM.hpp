
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
    int trial;
    long int num = 0;
    char Pos_Var[12] = {"'abcdefghij"};
    string Add[10] = {"a","b","c","d","e","f","g","h","i","j"};
    string Bar[10] = {"a'","b'","c'","d'","e'","f'","g'","h'","i'","j'"};
    string BoFun;
    vector<string> Variables;
    vector<string> Validator;
    vector<string> minterms;
    
    
public:
    QM(string);
    void Bool_Fun(string);
    void Validate_Fun();
};

#endif 
