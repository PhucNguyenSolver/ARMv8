#include <iostream>
#include "Register.h"

Register::Register()
{
    for (int i = 0; i < 32; i++)
        _Register[i] = 0;
}

long Register::Get(int i)
{
    return _Register[i];
}

void Register::Set(int i, long value)
{
    if (i != 31) // TODO: not a good practice
        _Register[i] = value;
    // cout << "Update: R" << i << " = " << Get(i) << endl;
}

void Register::log(int bytes)
{
    for (int i = 0; i < 32; i++)
        std::cout << "Register " << i << " : " << _Register[i] << std::endl;
}