#include <iostream>
#include <fstream>
#include <cerrno>
#include "Program.h"
#include "Utils.h"

using namespace std;

#define FILE_LOOP "example/loop.v"
#define FILE_SYSCALL "example/syscall.v"


template <class T>
void logVector(vector<T> vect)
{
    cout << vect.size() << ":\n";
    for (auto i : vect)
        cout << " | " << i << endl;
}

string get_file_contents(const char *filename)
{
    ifstream in(filename, ios::in | ios::binary);
    if (in)
    {
        string contents;
        in.seekg(0, ios::end);
        contents.resize(in.tellg());
        in.seekg(0, ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return (contents);
    }
    throw(errno);
}


int main()
{
    string raw = get_file_contents(FILE_SYSCALL);
    // cout << raw;
    Program p;
    p.setSource(raw);
    
    // /*
    if (p.assembleSuccessfully())
    {
        p.runAll();
        p.log();        
    // #if 1
    //         auto source = PreProcess(raw);
    //         cout << "Log data\n";
    //         logVector(source.data);
    //         cout << "Log source\n";
    //         logVector(source.instructions);
    //         cout << "Log label\n";
    //         for (auto p: source.label)
    //             cout << p.first << ": " << p.second << endl;
    // #endif
    }
    else
        cout << "Failed to assemble\n";
    // */

    return 0;
}