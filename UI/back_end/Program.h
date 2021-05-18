#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <vector>
#include "Instruction.h"
#include "Hardware.h"
#include "Utils.h"
using std::cout;
using std::endl;

const int MEMORY_SIZE = (int)10e6;

class Program
{
public:
    Program();
    ~Program();
    void pushInstruction(string raw);
    void pushData(string raw);
    void run();
    void log();
    int assemble(string src);
private:
    Hardware *hardware;
    vector<Instruction *> instructions;
};

#endif // PROGRAM_H
