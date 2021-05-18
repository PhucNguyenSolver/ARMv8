#include <iostream>
#include <cassert>
#include "Program.h"
#include "Instruction.h"
#include "Utils.h"
using namespace std;

const int MEMORY_SIZE = (int)10e6;


Program::Program() { hardware = new Hardware(MEMORY_SIZE); }

Program::~Program() // TODO: delete Instruction correctly
{
    delete hardware;
}

void Program::setSource(string src) { this->_source = src; }

bool Program::assembleSuccessfully()
{
    PreProcess source(this->_source); // TODO: flush before preprocess

    // Load data
    //int top = 0;
    for (string var : source.data)
    {
        try
        {
            this->pushData(var);
        }
        catch (...)
        {
            cout << "Cannot load data: \n"
                 << var;
            return false;
        }
    }

// #if 1
//         cout << "Log data\n";
//         logVector(source.data);
//         cout << "Log source\n";
//         logVector(source.instructions);
//         cout << "Log label\n";
//         for (auto p: source.label)
//             cout << p.first << ": " << p.second << endl;
// #endif

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
            return false;
        }
    }
    return true;
}

bool Program::executeSuccessfully(int instructionId)
{
    int PC = getPC();
    if (0 <= PC && PC < (int)instructions.size())
    {
        hardware->PC++;   
        instructions[PC - 1]->execute();
        return true;
    }
    else
        return false;
}

void Program::runAll()
{
    // flush all
    reset();
    // re-assemble
    assert(assembleSuccessfully());
    while (executeSuccessfully(getPC())); // running
    cout << "Program finished running\n";
}

void Program::reset()
{
    delete hardware;
    hardware = new Hardware(MEMORY_SIZE);
    for (auto ins: instructions)
        delete ins;
    instructions.clear();
}

int Program::getPC() { return hardware->PC; }


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
    else if (type == Instruction::IType::Syscall)
        instructions.push_back(new SyscallInstruction(hardware, raw));
    else
        throw "Invalid instruction";
}

void Program::pushData(string raw)
{
    hardware->pushData(raw);
}

void Program::log()
{
    cout << "Hardware Log\n";
    hardware->log();
}
