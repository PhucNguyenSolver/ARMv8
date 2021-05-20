#include "Instruction.h"

#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <vector>
#include "Hardware.h"
//#include "Instruction.h"

class Program 
{
public:
    Program(); 
    ~Program();

    void setSource(std::string source);
    bool assembleSuccessfully(); // return true on success
    bool executeSuccessfully(int instructionId);
    void runAll();
    void reset();

    int getPC();
    long getRegisterValue(int index);
    int getLineNumber(int index);
private:
    std::string _source;
    Hardware *hardware;
    std::vector<Instruction *> instructions;
    std::vector<int> lineNumber;

    void pushInstruction(std::string raw);
    void pushLineNumber(int i);
    void pushData(std::string raw);
    void log();
};

#endif // !PROGRAM_H

