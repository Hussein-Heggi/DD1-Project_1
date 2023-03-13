
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
    string Pos_Var[11] = {"'","a","b","c","d","e","f","g","h","i","j"};
    string BoFun;
    vector<string> Validated;
public:
    QM();
    void Start();
    void Num_Var(int);
    bool Validate_Bool(string);
    int Compare(string, string);
    bool strstr(string, string);
};

#endif 
