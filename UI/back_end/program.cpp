#include <iostream>
#include <cassert>
#include "Program.h"
#include "Instruction.h"
#include "Utils.h"
using namespace std;

const int MEMORY_SIZE = (int)10e6;

#define UI_MODE // comment this line to run on terminal only
#ifndef UI_MODE
#include <sstream>
class MainWindow // API to UI::MainWindow
{
public:
    static stringstream buffer;
    void printOutput(string something);
    void printOutput();
};

void MainWindow::printOutput() { cout << buffer.str(); }
void MainWindow::printOutput(string something)
{
    buffer << something;
    printOutput();
}

stringstream MainWindow::buffer;
#endif // UI_MODE

Program::Program()
{
    hardware = new Hardware(MEMORY_SIZE);
}

Program::~Program() // TODO: delete Instruction correctly
{
    delete hardware;
}

void Program::setSource(string src) { this->_source = src; }

bool Program::assembleSuccessfully()
{
    PreProcess source(this->_source);

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
            MainWindow::buffer << "Cannot load data from this line: \n"
                               << var << endl;
            return false;
        }
    }

    // Load instruction
    int size = source.instructions.size();
    for (int i = 0; i < size; i++)
    {
        try
        {
            this->pushInstruction(source.instructions[i]);
            this->pushLineNumber(source.lineNumber[i]);
        }
        catch (...)
        {
            MainWindow::buffer << "Unknown instruction: \n"
                               << source.instructions[i] << endl;
            return false;
        }
    }
    return true;
}

bool Program::executeSuccessfully(int instructionId)
{
    int currentPC = getPC();
    if (currentPC < 0 || currentPC >= (int)instructions.size())
        return false;

    try
    {
        hardware->PC++;
        instructions[currentPC]->execute();
    }
    catch (...)
    {
        MainWindow::buffer << "A Runtime Error has occurred.\n\n"
                           << "Line: " << lineNumber[currentPC] << "\nError: !!!\n";
        return false;
    }
    return true;
}

/**
 * Re-assemble then run all.
 *
 * Throw exception when encounter failed execution.
 */
void Program::runAll()
{
    reset();
    if (assembleSuccessfully())
    {
        MainWindow::printOutput("-------Program starts running-------\n");
        while (executeSuccessfully(getPC()))
            ; // running
        MainWindow::printOutput("-------Program finished running-------\n");
    }
}

void Program::reset()
{
    delete hardware;
    hardware = new Hardware(MEMORY_SIZE);
    for (auto ins : instructions)
        delete ins; // warning
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

void Program::pushLineNumber(int i)
{
    lineNumber.push_back(i);
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

long Program::getRegisterValue(int index)
{
    return hardware->_reg->Get(index);
}

int Program::getLineNumber(int index)
{
    return lineNumber[index];
}

map<string, int> Program::getLabel()
{
    return PreProcess::label;
}
map<string, int> Program::getData()
{
    return hardware->getData();
}
int Program::getMemoryValue(int index)
{
    return int(*((char *)(hardware->_mem->get(index))));
}
