#ifndef HARDWARE_H
#define HARDWARE_H

#include <string>
#include <map>
#include "FloatRegister.h"
#include "Register.h"
#include "Memory.h"
using std::map;

class Hardware
{
public:
    class Flags;
    Hardware(size_t memsize);
    ~Hardware();
    long GetRegister(string reg_name);
    void SetRegister(string reg_name, long value);
    void set(int index, void *source, size_t size);
    long getFloatRegister(string reg_name);
    void setFloatRegister(string reg_name, float value);
    void pushData(string data);
    int indexOf(string reg_name); //TODO: rename this method
    void log(int bytes = 40);
    
public:
    class Flags
    {
        public:
            Flags();
            bool eq();
            bool ne();
            bool lt();
            bool le();
            bool gt();
            bool ge();
            bool hs();
            bool checkOverflow(long a, long b);
            bool checkFlagCarry(long a, long b);
            void setN(bool on);
            void setZ(bool on);
            void setV(bool on);
            void setC(bool on);

        private:
            bool N, Z, C, V;
    };

    int PC;
    Flags flags;
    map<string, int> _data;
    Register *_reg; // TODO: why public?
    FloatRegister *_floatReg;
    Memory *_mem;

private:
    Flags flag;
};

#endif // !HARDWARE_H
