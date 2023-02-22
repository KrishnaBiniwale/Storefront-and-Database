#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}


std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> kwds;
    std::stringstream ss (rawWords);
    std::string src;
    while (ss >> src) {
        size_t index = 0;
        for (size_t i = 0; i < src.size(); i++) {
            if (!((src[i] >= 'a' && src[i] <= 'z') || (src[i] >= 'A' && src[i] <= 'Z') || (src[i] >= '0' && src[i] <= '9') || (src[i] == '-'))) {
                if (src.substr(index, i - index).size() >= 2) {
                    kwds.insert(convToLower(src.substr(index, i - index)));
                }
                index = i+1;
            }
        }
        if (src.substr(index).size() >= 2) {
            kwds.insert(convToLower(src.substr(index)));
        }
    }
    return kwds;
}

// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
