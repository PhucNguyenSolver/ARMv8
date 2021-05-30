#include "mainwindow.h" // add new library

#ifndef INSTRUCTION
#define INSTRUCTION
#include <iostream>
#include <string>
#include "Hardware.h"
using std::string;
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
public:
    string s;
};
/*-----------------------------*/
class RInstruction : public Instruction
{
public:
    RInstruction(string s);
    RInstruction(Hardware *hardware, string s);
    void execute();
    void setFlags(long res, long a, long b);
};
/*-----------------------------*/
class IInstruction : public Instruction
{
public:
    IInstruction(string s);
    IInstruction(Hardware *hardware, string s);
    void execute();
    void setFlags(long res, long a, long b);
};
/*-----------------------------*/
class DInstruction : public Instruction
{
public:
    DInstruction(string s);
    DInstruction(Hardware *hardware, string s);
    void execute();
    void toggle(char *start, int n);
    void Load(char *des, char *source, int n, bool wide_sign, int size);
    void Store(char *des, char *source, int n, int size);
};
/*-----------------------------*/
class BInstruction : public Instruction
{
public:
    BInstruction(string s);
    BInstruction(Hardware *hardware, string s);
    void execute();
};
/*-----------------------------*/
class CBInstruction : public Instruction
{
public:
    CBInstruction(string s);
    CBInstruction(Hardware *hardware, string s);
    void execute();
};
/*-----------------------------*/
class PIInstruction : public DInstruction
{
public:
    PIInstruction(string s);
    PIInstruction(Hardware *hardware, string s);
    void execute();
    void setFlags(long res, long a, long b);
    // ~PIInstruction() {}
};
/*-----------------------------*/
class SyscallInstruction : public Instruction
{
public:
    SyscallInstruction(string s);
    SyscallInstruction(Hardware *hardware, string s);
    void execute();
};

#endif // !INSTRUCTION
