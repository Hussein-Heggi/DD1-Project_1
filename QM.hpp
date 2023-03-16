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
    vector<string> minterms; // alphabetical values of minterms
    vector<string> Bsterms; // Binary values of minterms
    vector<string> Maxterms; // Binary values of maxtrems
    vector <int> Binterms; // decimal value of minterms
    vector <int> Bigterms; // decimal values of maxtrems
    vector<string> MaxString;
    vector<string> PIs; // Prime Implicants
    
    
public:
    QM(string, int);
    void Get_Fun(string);
    void Gen_Fun();
    bool Validate_Fun(int);
    void Convert();
    int binaryToDecimal(int); // Converts from binart to decimal
    long long int decimalToBinary(int); // converts from decimal to binary
    void TruthTable(); // Generate Truth tables using minterms
    void RConvert();
    void SoP_PoS();
    static int oneCount(string s); // count number of ones
    void ImplicationTable(); // Generate Implication table and prime implicants
    bool CompareBits(string,string); // Identify complements
    string ReplaceBits(string,string); // When complementa are identified, they're replaced by _
    
    
};

#endif
