#ifndef INSTRUCTION
#define INSTRUCTION

#include <string>
#include "Hardware.h"

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

#endif // !INSTRUCTION