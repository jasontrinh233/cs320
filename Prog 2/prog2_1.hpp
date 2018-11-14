/**
 * Quang Trinh
 * CS320
 * prog2_1.hpp
 **/

#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class Tokenizer {
    private:
        vector<string> *validString;
        bool isInteger(const string& str) {
            int i = 0;
            for(i=0; i < str.length(); i++) {
                if(!isdigit(str[i]))
                    return false;
            }
            return true;
        } 
    public:
        Tokenizer();
        ~Tokenizer();
        void Tokenize(string str);
        vector<string>* GetTokens();
};