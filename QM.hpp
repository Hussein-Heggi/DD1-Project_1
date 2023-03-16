#ifndef QM_hpp
#define QM_hpp

#define ull unsigned long long int

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
    vector<string> minterms; // string values of minterms
    vector<string> Bsterms;
    vector<string> Maxterms;
    vector <int> Binterms; // decimal value of minterms
    vector <int> Bigterms;
    vector<string> MaxString;
    vector<string> PIs;
    
    
public:
    QM(string, int);
    void Get_Fun(string);
    void Gen_Fun();
    bool Validate_Fun(int);
    void Convert();
    int binaryToDecimal(int);
    long long int decimalToBinary(int);
    void TruthTable();
    void RConvert();
    void SoP_PoS();
    static int oneCount(string s);
    void ImplicationTable();
    bool CompareBits(string,string);
    string ReplaceBits(string,string);
    
    
};

#endif
