#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <map>
#include <vector>
using std::stringstream;
using std::ifstream;
using std::ios;
using std::cout;
using std::endl;

#include <chrono>
#include <thread>
#include <bitset>
#include <climits>
using namespace std;

#include "Utils.h"



map<string, int> PreProcess::label;
/*-----------------------------*/
vector<string> Parsing::parseTokens(string _instruction)
{
    vector<string> out;
    int length = _instruction.length();
    for (int i = 0; i < length; i++)
    {
        if (_instruction[i] == ',' || _instruction[i] == ':' || _instruction[i] == '#' || _instruction[i] == '[' || _instruction[i] == ']')
            _instruction[i] = ' ';
    }
    stringstream ss(_instruction);
    string getW;

    while (ss >> getW)
        out.push_back(getW);
    return out;
}
/*-----------------------------*/
string Parsing::parseQuote(string _instruction)
{
    string str = "";
    int begin = (int)_instruction.find('\"');
    int end = (int)_instruction.find_last_of('\"');
    str = _instruction.substr(begin + 1, end - begin - 1);
    return str;
}
/*-----------------------------*/
void PreProcess::readFile(string filename)
{
    ifstream inFile(filename, ios::binary);
    Mode mode = NONE;

    while (!inFile.eof())
    {
        string line;
        getline(inFile, line);
        vector<string> tokens = Parsing::parseTokens(line);

        if (!tokens.empty())
        {
            if (tokens[0] == ".global")
                mode = GLOBAL;
            else if (tokens[0] == ".func")
                mode = FUNC;
            else if (tokens[0] == ".data")
                mode = DATA;
        }

        string temp = line;

        switch (mode)
        {
        case NONE: // do nothing
            LOG("None");
            break;

        case GLOBAL: // TODO: add .global field
            LOG("Global");
            break;

        case DATA: // TODO: remove .data from temp
            LOG("Data");
            if ((int)temp.find(":") >= 0)
            {
                int pos = (int)temp.find(":");
                temp[pos] = ' ';
            }
            while ((int)temp.find(",") != -1)
            {
                int pos = (int)temp.find(",");
                temp[pos] = ' ';
            }
            if ((int)temp.find("//") >= 0)
            {
                int pos = (int)temp.find("//");
                temp.erase(temp.begin() + pos, temp.end());
            }
            if ((int)temp.find("@") >= 0) //
            {
                int pos = (int)temp.find("@");
                temp.erase(temp.begin() + pos, temp.end());
            }
            tokens = Parsing::parseTokens(temp);
            if (!tokens.empty() && tokens[0] != ".data") // fix this
                data.push_back(temp);
            break;

        case FUNC: // TODO: remove .func from temp, remove comma
            if ((int)temp.find("//") >= 0)
            {
                int pos = (int)temp.find("//");
                temp.erase(temp.begin() + pos, temp.end());
            }
            if ((int)temp.find("@") >= 0) //
            {
                int pos = (int)temp.find("@");
                temp.erase(temp.begin() + pos, temp.end());
            }
            if ((int)temp.find(':') >= 0)
            {
                int pos = (int)temp.find(':');
                string labelName = temp.substr(0, pos);
                labelName = Parsing::parseTokens(labelName)[0];
                label.insert({labelName, instructions.size()});
                temp.erase(temp.begin(), temp.begin() + pos + 1);
            }
            if ((int)temp.find("#") >= 0) //
            {
                int pos = (int)temp.find("#");
                temp.erase(pos, 1);
            }
            while ((int)temp.find(",") != -1)
            {
                int pos = (int)temp.find(",");
                temp[pos] = ' ';
            }
            if (!Parsing::parseTokens(temp).empty() && tokens[0] != ".func")
                instructions.push_back(temp);
            break;
        }
    }
    inFile.close();
}
/*-----------------------------*/
void PreProcess::readTextBox(string text)
{
    std::istringstream inFile(text);
    Mode mode = NONE;

    while (!inFile.eof())
    {
        string line;
        getline(inFile, line);
        vector<string> tokens = Parsing::parseTokens(line);

        if (!tokens.empty())
        {
            if (tokens[0] == ".global")
                mode = GLOBAL;
            else if (tokens[0] == ".func")
                mode = FUNC;
            else if (tokens[0] == ".data")
                mode = DATA;
        }

        string temp = line;

        switch (mode)
        {
        case NONE: // do nothing
            LOG("None");
            break;

        case GLOBAL: // TODO: add .global field
            LOG("Global");
            break;

        case DATA: // TODO: remove .data from temp
            LOG("Data");
            if ((int)temp.find(":") >= 0)
            {
                int pos = (int)temp.find(":");
                temp[pos] = ' ';
            }
            while ((int)temp.find(",") != -1)
            {
                int pos = (int)temp.find(",");
                temp[pos] = ' ';
            }
            if ((int)temp.find("//") >= 0)
            {
                int pos = (int)temp.find("//");
                temp.erase(temp.begin() + pos, temp.end());
            }
            if ((int)temp.find("@") >= 0) //
            {
                int pos = (int)temp.find("@");
                temp.erase(temp.begin() + pos, temp.end());
            }
            tokens = Parsing::parseTokens(temp);
            if (!tokens.empty() && tokens[0] != ".data") // fix this
                data.push_back(temp);
            break;

        case FUNC: // TODO: remove .func from temp, remove comma
            if ((int)temp.find("//") >= 0)
            {
                int pos = (int)temp.find("//");
                temp.erase(temp.begin() + pos, temp.end());
            }
            if ((int)temp.find("@") >= 0) //
            {
                int pos = (int)temp.find("@");
                temp.erase(temp.begin() + pos, temp.end());
            }
            if ((int)temp.find(':') >= 0)
            {
                int pos = (int)temp.find(':');
                string labelName = temp.substr(0, pos);
                labelName = Parsing::parseTokens(labelName)[0];
                label.insert({labelName, instructions.size()});
                temp.erase(temp.begin(), temp.begin() + pos + 1);
            }
            if ((int)temp.find("#") >= 0) //
            {
                int pos = (int)temp.find("#");
                temp.erase(pos, 1);
            }
            while ((int)temp.find(",") != -1)
            {
                int pos = (int)temp.find(",");
                temp[pos] = ' ';
            }
            if (!Parsing::parseTokens(temp).empty() && tokens[0] != ".func")
                instructions.push_back(temp);
            break;
        }
    }
}
/*-----------------------------*/
// template <class T>
void logVector(vector<string> vect)
{
    cout << vect.size() << ":\n";
    for (auto i : vect)
        cout << " | " << i << endl;
}

/*-----------------------------*/
long sys_rand()
{
    return ((long)rand() << 32) | rand();
}

/*
void testparse()
{
    string s = "* @author\" Christopher D. McMur\"rough";
    logVector(Parsing::parseTokens(s));
    cout <<  PreProcess::parseQuote(s) << endl;
}

int main()
{
    testparse();
    PreProcess source("example/strcmp.v");
    // PreProcess source("example.v");
    cout << "Log source\n";
    logVector(source.instructions);

    cout << "Log data\n";
    logVector(source.data);

    cout << "Log label\n";
    for (auto p: source.label)
        cout << p.first << ": " << p.second << endl;
    return 0;
}
// */