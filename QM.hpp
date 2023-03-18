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
    vector<string> Validator; // Variables without the '
    vector<string> minterms; // alphabetical values of minterms
    vector<string> Bsterms; // Binary values of minterms
    vector<string> Maxterms; // Binary values of maxtrems
    vector <int> Binterms; // decimal value of minterms
    vector <int> Bigterms; // decimal values of maxtrems
    vector<string> MaxString;
    vector<string> PIs; // Prime Implicants
    vector<string> PreEssential; //copy of PIs with dontcares
    vector<string> EPIs; // Essential Prime Implicants
    vector<string> Copy;
    vector<string> covered; // Covered minterms by EPIs
    vector<string> uncovered; // complement of covered
    
    
    
public:
    QM(string, int); // Constructor
    void Get_Fun(string); // removes any unnecassary chars
    void Gen_Fun(); // Add missing literals
    bool Validate_Fun(int); // Validate the boolean function
    void Convert(); // Generate Binterms
    int binaryToDecimal(int); // Converts from binart to decimal
    long long int decimalToBinary(int); // Converts from decimal to binary
    void TruthTable(); // Generate Truth tables using minterms
    void RConvert(); // Generate Maxterms
    void SoP_PoS(); // Display the canonical SoP and PoS
    void Prime_Implicants(); // Convert PIs to literals and Display
    static int oneCount(string s); // Count number of ones
    void ImplicationTable(); // Generate Implication table and prime implicants
    bool CompareBits(string,string); // Identify complements
    string ReplaceBits(string,string); // When complementa are identified, they're replaced by _
    void Essential_PI(); // Generate and Display EPIs
    void restorePIs(string s1);
    
};

#endif
