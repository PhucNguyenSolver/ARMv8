#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;


inline void LOG(string s) {};
// inline void LOG(string s) { std::cout << s; };

class Parsing
{
public:
    static vector<string> parseTokens(string _instruction);
    static string parseQuote(string _instruction);
};

class PreProcess // static class
{
public:
    enum Mode
    {
        NONE,
        GLOBAL,
        FUNC,
        DATA
    };

    PreProcess(string src) { readTextBox(src); }
    static map<string, int> label; // TODO: why static rather than instant's local
    vector<string> instructions; // TODO: make these variable external and singleton 
    vector<string> data;

private:
    void readFile(string filename);
    void readTextBox(string text);
};

// template <class T> // TODO: how to use template here - undefined reference
void logVector(vector<string> vect);

#endif // !UTILS_H
