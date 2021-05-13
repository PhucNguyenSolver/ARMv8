#ifndef FLOAT_REGISTER_H
#define FLOAT_REGISTER_H

class FloatRegister
{
private:
    float _floatRegister[32];

public:
    FloatRegister();
    float Get(int i);
    void Set(int i, float value);
    void log(int bytes = 40);
};
#endif // !FLOAT_REGISTER_H
