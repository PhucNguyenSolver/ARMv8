#ifndef Instruction
#define Instruction

#include <iostream>
#include "Hardware.h"
using namespace std;

class Instruction
{
public:
    Instruction(string s);
    Instruction(Hardware *hardware, string s);
    virtual void execute() = 0;

    enum IType
    {
        R,
        I,
        D,
        B,
        CB,
        PI,     //PSEUDO INSTRUCTION SET
        Syscall // System call set newewww
    };

    static IType instructionType(string s);

protected:
    Hardware *hardware;
    string s;
};

#endif // !Instruction