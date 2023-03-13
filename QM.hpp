
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
    long int num = 0;
    char Pos_Var[12] = {"'abcdefghij"};
    string BoFun;
    vector<string> Variables;
    vector<string> Validator;
    
public:
    QM();
    void Start();
    void Bool_Fun(string);
    bool Validate_Bool();
};

#endif 
