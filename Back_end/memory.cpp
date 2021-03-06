#include <iostream>
#include <sstream>
#include <cstring> // cstring::memmove()
#include "Memory.h"
using std::cout;
using std::endl;

Memory::Memory(size_t sizeInByte) : size(sizeInByte), top(0) { mem = new char[sizeInByte]; }

Memory::~Memory() { delete mem; }

char *Memory::getAddress(int index)
{
    return mem + index;
}

void Memory::set(int index, void *source, size_t size)
{
    char *dest = getAddress(index);
    memmove(dest, source, size);
}

void Memory::log(int bytes)
{
    int lines = std::min((int)size, bytes);
    char *readPtr = mem;
    for (int i = 0; i < lines; i++)
    {
        // cout << " | " << *readPtr;
        cout << " | " << (unsigned short)(*readPtr);
        readPtr++;
        cout << std::endl;
    }
}

void Memory::loadVariable(string raw)
{
    std::stringstream ss(raw);
    string header;
    ss >> header;

    bool success = true;

    while (success)
    {
        success = false;
        if (header == ".byte")
        {
            char a;
            if (ss >> a)
            {
                success = true;
                set(top, &a, 1);
            }
            top += 1;
        }
        else if (header == ".half")
        {
            short a;
            if (ss >> a)
            {
                success = true;
                set(top, &a, 2);
            }
            top += 2;
        }
        else if (header == ".word")
        {
            int a;
            if (ss >> a)
            {
                success = true;
                set(top, &a, 4);
            }
            top += 4;
        }
        else if (header == ".long")
        {
            long a;
            if (ss >> a)
            {
                success = true;
                set(top, &a, 8);
            }
            top += 8;
        }
        else if (header == ".asciz") // TODO: tìm cách bắt skip character \n\t\0, ...
        {
            // char a;
            // if (ss >> a)
            // {
            //     success = true;
            //     set(top, &a, 1);
            //     top += 1;
            // }
            // else
            // {
            //     a = '\n';
            //     set(top, &a, 1);
            //     top += 1;
            // }
            string a = raw.substr(raw.find_first_of("\""), raw.length());
            for (int i = 1; i < a.length() - 2; i++)
            {
                set(top, &a[i], 1);
                top += 1;
            }
            char endkey = '\n';
            set(top, &endkey, 1);
            top += 1;
        }
        else if (header == ".skip")
        {
            int space;
            ss >> space;
            top += space;
        }
        else // TODO: add ascii
            cout << "Invalid type: " << header << endl;
    }
}

string Memory::getString(int add)
{
    std::stringstream ss;
    for (int i = 0; i < 100; i++, add++)
    {
        if (this->mem[add] == '\n')
            break;
        ss << this->mem[add];
    }
    return ss.str();
}

int Memory::getTop()
{
    return this->top;
}
/*
int main()
{
    Memory mem(4 * 10);

    string data[] = { ".word 10 21 22 23", ".asciz abc\n" };
    stringstream ss(data[1]);

    int N = sizeof(data) / sizeof(data[0]);
    int top = 0;
    for (int i = 0; i < N; i++)
        mem.loadVariable(data[i], top);

    mem.log();
    return 0;
}
// */