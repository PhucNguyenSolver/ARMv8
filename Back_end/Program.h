#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
#include <vector>
#include "Hardware.h"
#include "Instruction.h"

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

private:
    std::string _source;
    Hardware *hardware;
    std::vector<Instruction *> instructions;
    void pushInstruction(std::string raw);
    void pushData(std::string raw);
    void log();
};

#endif // !PROGRAM_H

