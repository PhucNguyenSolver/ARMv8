#include <iostream>
#include "FloatRegister.h"

using std::cout;
using std::endl;

FloatRegister::FloatRegister()
{
    for (int i = 0; i < 32; i++)
        _floatRegister[i] = 0.0;
}

float FloatRegister::Get(int i)
{
    return _floatRegister[i];
}

void FloatRegister::Set(int i, float value)
{
    if (i != 31)
        _floatRegister[i] = value;
    // cout << "Update: R" << i << " = " << Get(i) << endl;
}

void FloatRegister::log(int bytes)
{
    for (int i = 0; i < 32; i++)
        cout << "Register " << i << " : " << _floatRegister[i] << endl;
}
