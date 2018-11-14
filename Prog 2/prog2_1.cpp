/**
 * Quang Trinh
 * CS320
 * prog2_1.cpp
 **/

#include "prog2_1.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// Constructor
Tokenizer::Tokenizer() {
    this->validString = new vector<string>();
}

// Deconstructor
Tokenizer::~Tokenizer() {
    delete this->validString;
}

// Check valid tokens
void Tokenizer::Tokenize(string str) {
    stringstream oss(str);
    string word;
    while(oss >> word) {
        if (isInteger(word) || word.compare("push") == 0 || word.compare("pop") == 0
          || word.compare("add") == 0 || word.compare("sub") == 0    
          || word.compare("mul") == 0 || word.compare("div") == 0
          || word.compare("mod") == 0 || word.compare("skip") == 0
          || word.compare("save") == 0|| word.compare("get")== 0 )
                this->validString->push_back(word);
        else {
            string msg, error;
            msg = "Unexpected token: ";
            error = msg + word;
            throw (error.data());
        }
    }  
}

// Store valid tokens into vector
vector<string>* Tokenizer::GetTokens() {
    if(this->validString->empty())
        throw ("No tokens");

    vector<string> *tokens = new vector<string>();
    for(unsigned i=0; i < this->validString->size(); ++i) {
        string s = this->validString->at(i);
        tokens->push_back(s);
    } 

    return tokens;
}  