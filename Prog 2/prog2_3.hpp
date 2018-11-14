/**
 * Quang Trinh
 * CS320
 * prog2_3.hpp
 **/

#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Parser {
    private:
        bool isInteger(const string& str) {
            int i = 0;
            for(i=0; i < str.length(); i++) {
                if(!isdigit(str[i]))
                    return false;
            }
            return true;
        }  
    public:
        Parser();
        ~Parser();
        bool Parse(vector<string> *tokensArray);
};