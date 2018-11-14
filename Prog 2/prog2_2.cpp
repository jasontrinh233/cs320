/**
 * Quang Trinh
 * CS320
 * prog2_2.cpp
 **/

#include "prog2_1.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int, char *argv[]) {
    cout << "Assignment #2-2, Quang Trinh, jasontrinh233@gmail.com" << endl;

    fstream file(argv[1]);
    vector<string> *tokensArray = new vector<string>();

    // Store each line into an array
    while(!file.eof()) {
        string s;
        getline(file, s);
        tokensArray->push_back(s);
    }
 
    // Check for valid tokens for entire file
    for(unsigned i=0; i < tokensArray->size(); ++i) {
        Tokenizer *myTokenizer = new Tokenizer();
        try{
            myTokenizer->Tokenize(tokensArray->at(i));
        } catch(const char* error) {
            cerr << "Error on line " << i+1 << ": " << error << endl;
            return 0;
        }
        myTokenizer->~Tokenizer();
    }

    // Print out each valid tokens line
    for(unsigned i=0; i < tokensArray->size(); ++i) {
        Tokenizer *otherTokenizer = new Tokenizer();
        try{
            otherTokenizer->Tokenize(tokensArray->at(i));
            for(unsigned j=0; j < otherTokenizer->GetTokens()->size()-1; j++) {
                cout << otherTokenizer->GetTokens()->at(j) << ",";
            }
            cout << otherTokenizer->GetTokens()->back() << endl;
        } catch(const char* msg){
            cerr << msg << endl;
        }
        otherTokenizer->~Tokenizer();
    }

}
