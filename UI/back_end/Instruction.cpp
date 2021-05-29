#include <algorithm>
#include <vector>
#include <bitset>
#include <chrono>
#include <climits>
#include <iostream>
#include <sstream>
#include <thread>

#include "Utils.h"
#include "Instruction.h"


inline long sys_rand() { return ((long)rand() << 32) | rand(); }

Instruction::Instruction(string s)
{
    this->s = s;
}

Instruction::Instruction(Hardware *hardware, string s) : hardware(hardware)
{
    this->s = s;
}

/*-----------------------------*/

Instruction::IType Instruction::instructionType(string s) // TODO: add defined instruction to sets
{
    static vector<string> CBSet{"CBZ", "CBNZ", "B.NE", "B.EQ", "B.LT", "B.LE", "B.GT", "B.GE", "B.HS"};
    static vector<string> RSet{"ADD", "AND", "SUB", "EOR", "LSL", "LSR", "ORR", "AND", "BR", "FADDS", "FCMPS", "FDIVS", "FMULS", "FSUBS"};
    static vector<string> ISet{"ADDI", "ANDI", "SUBI", "ADDIS", "ANDIS", "SUBIS", "EORI", "ORRI"};
    static vector<string> DSet{"LDUR", "LDURB", "LDURH", "LDURSW", "LDXR", "STUR", "STURB", "LDURH", "LDURSW", "LDXR"}; // 10 types
    static vector<string> BSet{"B", "BL"};
    static vector<string> PISet{"CMP", "CMPI", "LDA", "MOV"};

    string name = Parsing::parseTokens(s)[0];
    if (find(RSet.begin(), RSet.end(), name) != RSet.end())
        return IType::R;
    else if (find(ISet.begin(), ISet.end(), name) != ISet.end())
        return IType::I;
    else if (find(DSet.begin(), DSet.end(), name) != DSet.end())
        return IType::D;
    else if (find(BSet.begin(), BSet.end(), name) != BSet.end())
        return IType::B;
    else if (find(CBSet.begin(), CBSet.end(), name) != CBSet.end())
        return IType::CB;
    else if (find(PISet.begin(), PISet.end(), name) != PISet.end())
        return IType::PI;
    else if (name == "syscall")
        return IType::Syscall;
    else
    {
        string errorMessage = "undefined instruction here [" + name + "]";
        throw errorMessage.c_str();
    }
}

/*-----------------------------*/

void RInstruction::setFlags(long res, long a, long b)
{
    if (res < 0)
        hardware->flags.setN(true);
    else if (res == 0)
        hardware->flags.setZ(true);
    if (hardware->flags.checkOverflow(a, b))
        hardware->flags.setC(true);
    if (hardware->flags.checkFlagCarry(a, b))
        hardware->flags.setV(true);
}

// RInstruction::RInstruction(string s) : Instruction(s) {}
// RInstruction::RInstruction(Hardware *hardware, string s) : Instruction(hardware, s) {}

/*-----------------------------*/

void IInstruction::setFlags(long res, long a, long b)
{
    if (res < 0)
        hardware->flags.setN(true);
    else if (res == 0)
        hardware->flags.setZ(true);
    if (hardware->flags.checkOverflow(a, b))
        hardware->flags.setC(true);
    if (hardware->flags.checkFlagCarry(a, b))
        hardware->flags.setV(true);
}

/*-----------------------------*/

void DInstruction::Store(char *des, char *source, int n, int size)
{
    for (int i = 0; i < n; i++)
        *(des + i) = *(source + size - n + i);
}

/*-----------------------------*/

void RInstruction::execute()
{

    vector<string> insWord = Parsing::parseTokens(s);
    if (!insWord[0].compare("ADD") || !insWord[0].compare("ADDS"))
    {
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) + hardware->GetRegister(insWord[3]));
        if (!insWord[0].compare("ADDS"))
            setFlags(hardware->GetRegister(insWord[1]), hardware->GetRegister(insWord[2]), hardware->GetRegister(insWord[3]));
    }
    else if (!insWord[0].compare("AND") || !insWord[0].compare("ANDS"))
    {
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) & hardware->GetRegister(insWord[3]));
        if (!insWord[0].compare("ANDS"))
            setFlags(hardware->GetRegister(insWord[1]), hardware->GetRegister(insWord[2]), hardware->GetRegister(insWord[3]));
    }
    else if (!insWord[0].compare("EOR"))
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) ^ hardware->GetRegister(insWord[3]));
    else if (!insWord[0].compare("LSL"))
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) << stoi(insWord[3]));
    else if (!insWord[0].compare("LSR"))
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) >> stoi(insWord[3]));
    else if (!insWord[0].compare("ORR"))
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) | hardware->GetRegister(insWord[3]));
    else if (!insWord[0].compare("AND"))
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) & hardware->GetRegister(insWord[3]));
    else if (!insWord[0].compare("SUB") || !insWord[0].compare("SUBS"))
    {
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) - hardware->GetRegister(insWord[3]));
        if (!insWord[0].compare("SUBS"))
            setFlags(hardware->GetRegister(insWord[1]), hardware->GetRegister(insWord[2]), hardware->GetRegister(insWord[3]));
    }
    else if (!insWord[0].compare("BR"))
        hardware->PC = hardware->GetRegister(insWord[1]);

    //update float instructions
    else if (!insWord[0].compare("FADDS"))
        hardware->setFloatRegister(insWord[1], hardware->getFloatRegister(insWord[2]) + hardware->getFloatRegister(insWord[3]));
    else if (!insWord[0].compare("FSUBS"))
        hardware->setFloatRegister(insWord[1], hardware->getFloatRegister(insWord[2]) - hardware->getFloatRegister(insWord[3]));
    else if (!insWord[0].compare("FMULS"))
        hardware->setFloatRegister(insWord[1], hardware->getFloatRegister(insWord[2]) * hardware->getFloatRegister(insWord[3]));
    else if (!insWord[0].compare("FDIVS"))
        hardware->setFloatRegister(insWord[1], hardware->getFloatRegister(insWord[2]) / hardware->getFloatRegister(insWord[3]));
}

void IInstruction::execute()
{
    vector<string> insWord = Parsing::parseTokens(s);
    if (!insWord[0].compare("ADDI") || !insWord[0].compare("ADDIS"))
    {
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) + stoi(insWord[3]));
        if (!insWord[0].compare("ADDIS"))
            setFlags(hardware->GetRegister(insWord[1]), hardware->GetRegister(insWord[2]), stoi(insWord[3]));
    }
    else if (!insWord[0].compare("ANDI") || !insWord[0].compare("ANDIS"))
    {
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) & stoi(insWord[3]));
        if (!insWord[0].compare("ANDIS"))
            setFlags(hardware->GetRegister(insWord[1]), hardware->GetRegister(insWord[2]), stoi(insWord[3]));
    }
    else if (!insWord[0].compare("EORI"))
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) ^ stoi(insWord[3]));
    else if (!insWord[0].compare("ORRI"))
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) | stoi(insWord[3]));
    else if (!insWord[0].compare("SUBI") || !insWord[0].compare("SUBIS"))
    {
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]) - stoi(insWord[3]));
        if (!insWord[0].compare("SUBIS"))
            setFlags(hardware->GetRegister(insWord[1]), hardware->GetRegister(insWord[2]), stoi(insWord[3]));
    }
}

void BInstruction::execute()
{
    vector<string> insWord = Parsing::parseTokens(s);
    if (!insWord[0].compare("B"))
    {
        hardware->PC = PreProcess::label[insWord[1]];
        cout << "PC is: " << hardware->PC << '\n';
    }
    else if (!insWord[0].compare("BL"))
    {
        hardware->SetRegister("X30", hardware->PC);
        hardware->PC = PreProcess::label[insWord[1]];
    }
}

// TODO: test LDUR - offset in byte
void CBInstruction::execute()
{
    vector<string> insWord = Parsing::parseTokens(s);
    string command = insWord[0];
    if (command == "CBZ")
    {
        if (hardware->GetRegister(insWord[1]) == 0)
            hardware->PC = PreProcess::label[insWord[2]];
    }
    else if (command == "CBNZ")
    {
        if (hardware->GetRegister(insWord[1]) != 0)
            hardware->PC = PreProcess::label[insWord[2]];
    }
    else if ((command == "B.NE" && hardware->flags.ne()) ||
             (command == "B.EQ" && hardware->flags.eq()) ||
             (command == "B.LT" && hardware->flags.lt()) ||
             (command == "B.LE" && hardware->flags.le()) ||
             (command == "B.GT" && hardware->flags.gt()) ||
             (command == "B.GE" && hardware->flags.ge()) ||
             (command == "B.HS" && hardware->flags.hs()))
        hardware->PC = PreProcess::label[insWord[1]];
}

/*-----------------------------*/

void DInstruction::toggle(char *start, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        std::swap(start[i], start[n - i - 1]);
    }
}

void DInstruction::Load(char *des, char *source, int n, bool wide_sign, int size)
{
    int sign = *(source)&0x80;
    for (int i = 0; i < n; i++)
        *(des + size - n + i) = *(source + i);
    for (int i = 0; i < size - n; i++)
        *(des + i) = *(des + i) & 0x00;
    if (wide_sign)
    {
        if (sign != 0)
            for (int i = 0; i < size - n; i++)
                *(des + i) = *(des + i) | 0xff;
    }
    this->toggle(des, size);
}

void DInstruction::execute()
{
    vector<string> insWord = Parsing::parseTokens(s);
    if (!insWord[0].compare("LDUR"))
    {
        if (hardware->_data.find(insWord[2]) != hardware->_data.end())
        {
            int value = hardware->_data[insWord[2]];
            hardware->SetRegister(insWord[1], value);
            return;
        }
        long tempregister;
        int size = sizeof(tempregister);
        int index;
        index = hardware->GetRegister(insWord[2]) + stoi(insWord[3]);
        this->Load((char *)(&tempregister), hardware->_mem->mem + index, size, false, size);
        hardware->SetRegister(insWord[1], tempregister);
    }

    else if (!insWord[0].compare("LDURB"))
    {
        long tempregister;
        int size = sizeof(tempregister);
        int index = hardware->GetRegister(insWord[2]) + stoi(insWord[3]);
        this->Load((char *)(&tempregister), hardware->_mem->mem + index, 1, false, size);
        hardware->SetRegister(insWord[1], tempregister);
    }

    else if (!insWord[0].compare("LDURH"))
    {
        long tempregister;
        int size = sizeof(tempregister);
        int index = hardware->GetRegister(insWord[2]) + stoi(insWord[3]);
        this->Load((char *)(&tempregister), hardware->_mem->mem + index, 2, false, size);
        hardware->SetRegister(insWord[1], tempregister);
    }

    else if (!insWord[0].compare("LDURSW"))
    {
        long tempregister;
        int size = sizeof(tempregister);
        int index = hardware->GetRegister(insWord[2]) + stoi(insWord[3]);
        this->Load((char *)(&tempregister), hardware->_mem->mem + index, 4, true, size);
        hardware->SetRegister(insWord[1], tempregister);
    }

    else if (!insWord[0].compare("LDXR"))
        cout << 0;

    else if (!insWord[0].compare("STUR"))
    {
        long tempregister = hardware->GetRegister(insWord[1]);
        int size = sizeof(tempregister);
        this->toggle((char *)(&tempregister), size);
        int index = hardware->GetRegister(insWord[2]);
        int offset = stoi(insWord[3]);
        //cout << "index: " << index << endl
        //   << "ofsset: " << offset << endl;
        this->Store(hardware->_mem->mem + index + offset, (char *)(&tempregister), size, size);
    }

    else if (!insWord[0].compare("STURB"))
    {
        long tempregister = hardware->GetRegister(insWord[1]);
        int size = sizeof(tempregister);
        this->toggle((char *)(&tempregister), size);
        int index = hardware->GetRegister(insWord[2]);
        int offset = stoi(insWord[3]);
        this->Store(hardware->_mem->mem + index + offset, (char *)(&tempregister), 1, size);
    }

    else if (!insWord[0].compare("STURH"))
    {
        long tempregister = hardware->GetRegister(insWord[1]);
        int size = sizeof(tempregister);
        this->toggle((char *)(&tempregister), size);
        int index = hardware->GetRegister(insWord[2]);
        int offset = stoi(insWord[3]);
        this->Store(hardware->_mem->mem + index + offset, (char *)(&tempregister), 2, size);
    }

    else if (!insWord[0].compare("STURW"))
    {
        long tempregister = hardware->GetRegister(insWord[1]);
        int size = sizeof(tempregister);
        this->toggle((char *)(&tempregister), size);
        int index = hardware->GetRegister(insWord[2]);
        int offset = stoi(insWord[3]);
        this->Store(hardware->_mem->mem + index + offset, (char *)(&tempregister), 4, size);
    }

    else if (!insWord[0].compare("STUXR")) // TODO: STUXR
        cout
            << 0;
    else
        cout << 0;
}

/*-----------------------------*/

RInstruction ::RInstruction(Hardware *hardware, string s) : Instruction(hardware, s) {}
IInstruction ::IInstruction(Hardware *hardware, string s) : Instruction(hardware, s) {}
DInstruction ::DInstruction(Hardware *hardware, string s) : Instruction(hardware, s) {}
BInstruction ::BInstruction(Hardware *hardware, string s) : Instruction(hardware, s) {}
CBInstruction ::CBInstruction(Hardware *hardware, string s) : Instruction(hardware, s) {}
PIInstruction ::PIInstruction(Hardware *hardware, string s) : DInstruction(hardware, s) {}
SyscallInstruction::SyscallInstruction(Hardware *hardware, string s) : Instruction(hardware, s) {}

RInstruction ::RInstruction(string s) : Instruction(s) {}
IInstruction ::IInstruction(string s) : Instruction(s) {}
DInstruction ::DInstruction(string s) : Instruction(s) {}
BInstruction ::BInstruction(string s) : Instruction(s) {}
CBInstruction ::CBInstruction(string s) : Instruction(s) {}
PIInstruction ::PIInstruction(string s) : DInstruction(s) {}
SyscallInstruction::SyscallInstruction(string s) : Instruction(s) {}

void PIInstruction::setFlags(long res, long a, long b)
{
    if (res < 0)
        hardware->flags.setN(true);
    else if (res == 0)
        hardware->flags.setZ(true);
    if (hardware->flags.checkOverflow(a, b))
        hardware->flags.setC(true);
    if (hardware->flags.checkFlagCarry(a, b))
        hardware->flags.setV(true);
}

void PIInstruction::execute()
{
    vector<string> insWord = Parsing::parseTokens(s);
    if (!insWord[0].compare("CMP"))
    {
        long tempregister;
        tempregister = hardware->GetRegister(insWord[1]) - hardware->GetRegister(insWord[2]);
        if (!insWord[0].compare("SUBS"))
            setFlags(tempregister, hardware->GetRegister(insWord[1]), hardware->GetRegister(insWord[2]));
    }

    else if (!insWord[0].compare("CMPI"))
    {
        long tempregister;
        tempregister = hardware->GetRegister(insWord[1]) - stoi(insWord[2]);
        if (!insWord[0].compare("SUBS"))
            setFlags(tempregister, hardware->GetRegister(insWord[1]), stoi(insWord[2]));
    }

    else if (!insWord[0].compare("LDA"))
    {
        long tempregister;
        int size = sizeof(tempregister);
        int index;
        if (hardware->_data.find(insWord[2]) != hardware->_data.end())
            index = hardware->_data[insWord[2]];
        else
            index = hardware->GetRegister(insWord[2]) + stoi(insWord[3]);
        this->Load((char *)(&tempregister), hardware->_mem->mem + index, size, false, size);
        hardware->SetRegister(insWord[1], tempregister);
    }

    else if (!insWord[0].compare("MOV"))
    {
        hardware->SetRegister(insWord[1], hardware->GetRegister(insWord[2]));
    }
}

/*-----------------------------*/

void SyscallInstruction::execute()
{
    using namespace std;
    long value = hardware->GetRegister("X0");

    switch (value)
    {
    case 1: // print integer
    {
        long print_value = hardware->GetRegister("X1");
        MainWindow::buffer << print_value;
        MainWindow::printOutput();
        break;
    }
    case 2: // print float
    {
        MainWindow::buffer << "float print";
        MainWindow::printOutput();
        break;
    }
    case 3: // print double
    {
        MainWindow::buffer << "double print";
        MainWindow::printOutput();
        break;
    }
    case 4: // print string
    {
        int index = (int)hardware->GetRegister("X1");
        string print_value = "";
        print_value = hardware->_mem->getString(index);
        MainWindow::buffer << print_value << endl;
        MainWindow::printOutput();
        break;
    }
    case 5: // read integer
    {
        long read_value;
        string msg = "Enter an integer value (syscall 5)";
        read_value = (MainWindow::getInputWithMessage(msg)).toLong();
        // read_value = (MainWindow::getInput()).toLong();
        hardware->SetRegister("X0", read_value);
        break;
    }
    case 6: // read float
    {
        cout << "read float";
        break;
    }
    case 7: // read double
    {
        cout << "read double";
        break;
    }
    case 8: // read string
    {
        string read_value;
        string msg = "Enter a string of maximum length oo (syscall 8)";
        read_value = (MainWindow::getInputWithMessage(msg)).toStdString();
        // read_value = (MainWindow::getInput()).toStdString();
        MainWindow::buffer << read_value;
        MainWindow::printOutput();
        hardware->SetRegister("X2", read_value.length());
        string raw = (string) ".asciz" + (string) " \"" + read_value + (string) "\" ";
        hardware->SetRegister("X1", hardware->_mem->getTop());
        hardware->_mem->loadVariable(raw);
        break;
    }
    case 10: // terminate execution
    {
        break;
        exit(0);
    }
    case 11: // print character
    {
        long print_value = hardware->GetRegister("X1");
        MainWindow::buffer << print_value;
        MainWindow::printOutput();
        break;
    }
    case 12: // read character
    {
        char read_value;
        string msg = "Enter a character value (syscall 12)";
        read_value = (MainWindow::getInputWithMessage(msg)).toStdString().c_str()[0];
        // read_value = (MainWindow::getInput()).toStdString().c_str()[0];
        hardware->SetRegister("X0", (long)read_value);
        break;
    }
    case 30: // system time
    {
        chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(
            chrono::system_clock::now().time_since_epoch());
        unsigned long msCount = ms.count();

        long msb = msCount >> 32;
        long lsb = msCount << 32 >> 32;
        // cout << msb << " | "<< lsb  << endl;
        hardware->SetRegister("X0", lsb);
        hardware->SetRegister("X1", msb);
        break;
    }
    case 32: // sleep
    {
        long miliseconds = hardware->GetRegister("X0");
        std::this_thread::sleep_for(chrono::milliseconds(miliseconds));
        break;
    }
    case 34: // print int2hex
    {
        long n = hardware->GetRegister("X0");
        char cstr[128];
        sprintf(cstr, "%#010x", n);
        string out = cstr;
        MainWindow::buffer << out;
        MainWindow::printOutput();
        // cout << out;
        break;
    }
    case 35: // print int2bin
    {
        long n = hardware->GetRegister("X0");
        bitset<32> a(n);
        string out = a.to_string();
        MainWindow::buffer << out;
        MainWindow::printOutput();
        // cout << out;
        break;
    }
    case 36: // print int2unsigned
    {
        long n = hardware->GetRegister("X0");
        unsigned long *cast = (unsigned long *)(&n);
        string out = to_string((unsigned long)(*cast));
        MainWindow::buffer << out;
        MainWindow::printOutput();
        // cout << out;
        break;
    }
    case 40: // set seed
    {
        long seed = hardware->GetRegister("X0");
        srand(seed);
        break;
    }
    case 41: // random int
    {
        long out = sys_rand();
        hardware->SetRegister("X0", out);
        break;
    }
    case 42: // random int range
    {
        unsigned long upperBound = hardware->GetRegister("X1");
        long out = sys_rand() % upperBound;
        hardware->SetRegister("X0", out);
        break;
    }
    case 43: // random float
    {
        float out = (float)rand() / RAND_MAX;
        hardware->setFloatRegister("F0", out); // TODO: check this
        break;
    }
    case 44: // random double
    {
        float out = (double)sys_rand() / (double)LLONG_MAX;
        hardware->setFloatRegister("F0", out); // TODO: check this
    }
    default:
    {
        string errorMessage = (string)"unknown syscall" + to_string(value);
        throw errorMessage.c_str();
    }
    }
}
