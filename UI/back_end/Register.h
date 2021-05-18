#ifndef REGISTER_H
#define REGISTER_H

class Register
{
private:
    long _Register[32];

public:
    Register();
    long Get(int i);
    void Set(int i, long value);
    void log(int bytes = 40);
};

#endif // !REGISTER_H
