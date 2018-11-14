/**
 * Quang Trinh
 * CS320
 * prog2_4.cpp
 **/

#include "prog2_1.hpp"
#include "prog2_3.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int, char *argv[]) {
    cout << "Assignment #2-4, Quang Trinh, jasontrinh233@gmail.com" << endl;

    fstream file(argv[1]);
    vector<string> *tokensArray = new vector<string>();

    // Store each line into an array
    while(!file.eof()) {
        string s;
        getline(file, s);
        tokensArray->push_back(s);
    }

    // Check if token is valid for every word in the file
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

    // Parse each line for entire file
    for(unsigned i=0; i < tokensArray->size(); ++i) {
        Tokenizer *myTokenizer2 = new Tokenizer();
        Parser  *myParser2 = new Parser();

        myTokenizer2->Tokenize(tokensArray->at(i));
        // Setting up Parse with exception message algorithm
        if( !myParser2->Parse(myTokenizer2->GetTokens()) ) {
            cout << "Parse error on line " << i+1 << ": ";
            for(unsigned k=0; k < myTokenizer2->GetTokens()->size(); k++)
                cout << myTokenizer2->GetTokens()->at(k) << " ";
            cout << endl;
            return 0;
            }
            myTokenizer2->~Tokenizer(); // Delete instance for next usage
            myParser2->~Parser(); // Delete instance for next usage
    }

    // Print out each valid tokens line
    for(unsigned i=0; i < tokensArray->size(); ++i) {
        Tokenizer *otherTokenizer = new Tokenizer();
        try{
            otherTokenizer->Tokenize(tokensArray->at(i));
            // Print comma separated algorithm
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
