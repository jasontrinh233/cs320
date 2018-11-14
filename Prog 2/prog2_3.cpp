/**
 * Quang Trinh
 * CS320
 * prog2_3.cpp
 **/

#include "prog2_1.hpp"
#include "prog2_3.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Constructor
Parser::Parser() {
}

// Destructor
Parser::~Parser() {
}

// Parsing function
bool Parser::Parse(vector<string> *tokensArray) {
    vector<string> *arr = new vector<string>();

    // Store input array to local array
    for(unsigned i=0; i < tokensArray->size(); ++i) {
        string s = tokensArray->at(i);
        arr->push_back(s);
    }

    if(arr->size()==1 && ( arr->at(0).compare("pop")==0 ||
                           arr->at(0).compare("add")==0 ||
                           arr->at(0).compare("sub")==0 ||
                           arr->at(0).compare("mul")==0 ||
                           arr->at(0).compare("div")==0 ||
                           arr->at(0).compare("mod")==0 ||
                           arr->at(0).compare("skip")==0 ) ) {
        return true;
    } 
    else if(arr->size()==2 && ( arr->at(0).compare("push")==0 ||
                           arr->at(0).compare("save")==0 ||
                           arr->at(0).compare("get")==0 ) 
                      && isInteger(arr->at(1)) ){
        return true;
    }
    else {
        return false;
    }
}
