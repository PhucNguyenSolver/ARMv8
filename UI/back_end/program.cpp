#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "utils.cpp"
#include "Hardware.cpp"
#include "Instruction.cpp"

const int MEMORY_SIZE = (int)10e6;

class Program
{
public:
    Program();
    Program(const Program &obj);
    ~Program();
    void pushInstruction(string raw);
    void pushData(string raw, int &byteAddress);
    void run();
    void log();
    int assemble(string src = "");

private:
    Hardware *hardware;
    vector<Instruction *> instructions;
};

Program::Program(): hardware(new Hardware(MEMORY_SIZE)) {}

Program::Program(const Program &obj) {
   hardware = obj.hardware;
   instructions = obj.instructions;
}

Program::~Program() // TODO: delete Instruction correctly
{
    // for (Instruction* ins: instructions)
    //     delete ins;
    delete hardware;
}

void Program::pushInstruction(string raw)
{
    Instruction::IType type = Instruction::instructionType(raw);
    if (type == Instruction::IType::R)
        instructions.push_back(new RInstruction(hardware, raw));
    else if (type == Instruction::IType::I)
        instructions.push_back(new IInstruction(hardware, raw));
    else if (type == Instruction::IType::D)
        instructions.push_back(new DInstruction(hardware, raw));
    else if (type == Instruction::IType::B)
        instructions.push_back(new BInstruction(hardware, raw));
    else if (type == Instruction::IType::CB)
        instructions.push_back(new CBInstruction(hardware, raw));
    else if (type == Instruction::IType::PI)
        instructions.push_back(new PIInstruction(hardware, raw));
    else
        throw "Invalid instruction";
}

void Program::pushData(string raw, int &top)
{
    hardware->pushData(raw, top);
}

void Program::run()
{
    int &PC = hardware->PC;
    while (0 <= PC && PC < (int)instructions.size())
    {
        PC++;
        instructions[PC - 1]->execute();
    }
    cout << "Program finished running\n";
}

void Program::log()
{
    cout << "Hardware Log\n";
    hardware->log();
}

// TODO: thêm debugger

int Program::assemble(string src)
{
    PreProcess source(src);

    // Load data
    int top = 0;
    for (string var : source.data)
    {
        try
        {
            this->pushData(var, top);
        }
        catch (...)
        {
            cout << "Cannot load data: \n"
                 << var;
            return -1;
        }
    }

#if 1
        cout << "Log data\n";
        logVector(source.data);
        cout << "Log source\n";
        logVector(source.instructions);
        cout << "Log label\n";
        for (auto p: source.label)
            cout << p.first << ": " << p.second << endl;
#endif

    // Load instruction
    for (string ins : source.instructions)
    {
        try
        {
            this->pushInstruction(ins);
        }
        catch (...)
        {
            cout << "Unknown instruction: \n"
                 << ins;
            return -1;
        }
    }
    return 0;
}
