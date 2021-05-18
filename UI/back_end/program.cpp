#include "Program.h"
//using std::cout;
//using std::endl;

//const int MEMORY_SIZE = (int)10e6;

Program::Program() { hardware = new Hardware(MEMORY_SIZE); }

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
    else if (type == Instruction::IType::Syscall)
        instructions.push_back(new SyscallInstruction(hardware, raw));
    else
        throw "Invalid instruction";
}

void Program::pushData(string raw)
{
    hardware->pushData(raw);
}

void Program::run()
{
    int &PC = hardware->PC;
    while (0 <= PC && PC < (int)instructions.size())
    {
        PC++;
        //if(instructions[PC-1].s == "syscall")
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
//int top = 0; // global variable; 

int Program::assemble(string src)
{
//    string example[] = {"test.v", "strcmp.v", "example.v", "non_leaf.v", "loop.v", "syscall.v"};
//    int fileN = 2;

//    if (argc > 1)
//        fileN = atoi(argv[1]);
//    Program leg;
    PreProcess source(src);

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
            return -1;
        }
    }

//#if 1
//        cout << "Log data\n";
//        logVector(source.data);
//        cout << "Log source\n";
//        logVector(source.instructions);
//        cout << "Log label\n";
//        for (auto p: source.label)
//            cout << p.first << ": " << p.second << endl;
//#endif

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

   this->run();
  //  leg.log();
    return 0;
}
