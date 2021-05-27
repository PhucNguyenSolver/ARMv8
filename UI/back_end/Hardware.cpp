#include <iostream>
#include <sstream>
#include <map>
#include <limits>

#include "Hardware.h"
#include "Memory.h"
#include "Register.h"
#include "FloatRegister.h"

using std::stringstream;
using std::cout;
using std::numeric_limits;


Hardware::Flags::Flags() { N = Z = V = C = false; }
void Hardware::Flags::setN(bool on) { N = on; }
void Hardware::Flags::setZ(bool on) { Z = on; }
void Hardware::Flags::setV(bool on) { V = on; }
void Hardware::Flags::setC(bool on) { C = on; }

Hardware::Hardware(size_t memsize): flags()
{
    _reg = new Register();
    _floatReg = new FloatRegister();
    _mem = new Memory(memsize);
    PC = 0;
}
Hardware::~Hardware()
{
    delete _reg;
    delete _mem;
}

long Hardware::GetRegister(string reg_name) { return _reg->Get(indexOf(reg_name)); }
void Hardware::SetRegister(string reg_name, long value) { _reg->Set(indexOf(reg_name), value); }
void Hardware::set(int index, void *source, size_t size) { _mem->set(index, source, size); }
long Hardware::getFloatRegister(string reg_name) { return _floatReg->Get(indexOf(reg_name)); }
void Hardware::setFloatRegister(string reg_name, float value) { _floatReg->Set(indexOf(reg_name), value); }

// TODO: init value for SP

void Hardware::pushData(string data)
{
    // try
    // {
        stringstream ss(data);
        string data_name;
        ss >> data_name;
        _data[data_name] = _mem->getTop();
        _mem->loadVariable(data.substr(data_name.length() + 1, data.length()));
    // }
    // catch(const char* msg)
    // {
    //     throw msg;
    // }
    
}

void Hardware::log(int bytes)
{
    cout << "-------------MEMORY-------------\n";
    _mem->log(bytes);
    cout << "-------------REGISTER-------------\n";
    _reg->log();
    //update float Register
    cout << "-------------FLOAT REGISTER-------------\n";
    _floatReg->log();
}

int Hardware::indexOf(string reg_name)
{
    if (reg_name == "SP") // stack pointer
        return 28;
    else if (reg_name == "FP") // frame pointer
        return 29;
    else if (reg_name == "LR") // link register
        return 30;
    else if (reg_name == "XZR") // zero register
        return 31;
    else
    {
        stringstream ss(reg_name.substr(1, reg_name.length()));
        int i = -1;
        ss >> i;
        return i;
    }
}

bool Hardware::Flags::eq() { return Z; }
bool Hardware::Flags::ne() { return !Z; }
bool Hardware::Flags::lt() { return N != V; }
bool Hardware::Flags::le() { return Z || N != V; }
bool Hardware::Flags::gt() { return !Z && N == V; }
bool Hardware::Flags::ge() { return N == V; }
bool Hardware::Flags::hs() { return C == 1; }

bool Hardware::Flags::checkOverflow(long a, long b)
{
    long result = a + b;
    // cout << "result: " << (int)result << endl;
    if (a > 0 && b > 0 && result < 0)
        return true;
    if (a < 0 && b < 0 && result > 0)
        return true;
    return false;
}

bool Hardware::Flags::checkFlagCarry(long a, long b)
{
    if ((numeric_limits<unsigned long>::max() - (unsigned long)a) < (unsigned long)b)
        return true;
    return false;
}

map<string, int> Hardware::getData() {
    return this->_data;
}
