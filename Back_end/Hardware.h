#ifndef HARDWARE_H
#define HARDWARE_H

#include <map>
#include "Register.h"
#include "FloatRegister.h"
#include "Memory.h"

class Hardware
{
public:
    class Flags
    {
    public:
        bool eq();
        bool ne();
        bool lt();
        bool le();
        bool gt();
        bool ge();
        bool hs();
        bool checkOverflow(long a, long b);
        bool checkFlagCarry(long a, long b);

    private:
        bool N, Z, C, V;
    };

    Hardware(size_t memsize);
    ~Hardware();
    long GetRegister(string reg_name);
    void SetRegister(string reg_name, long value);
    void set(int index, void *source, size_t size);
    long getFloatRegister(string reg_name);
    void setFloatRegister(string reg_name, float value);
    void pushData(string data);
    int indexOf(string reg_name); //TODO: rename this method

    int PC;
    Flags flags;
    map<string, int> _data;
    Register *_reg; // TODO: why public?
    FloatRegister *_floatReg;
    Memory *_mem;

private:
    void log(int bytes = 40);
};

#endif // !HARDWARE_H
