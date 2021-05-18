#ifndef MEMORY_H
#define MEMORY_H

#include <string>
using std::string;

class Memory
{
public:
    char *mem;
    int top;

private:
    const size_t size;
    char *getAddress(int index);

public:
    Memory(size_t sizeInByte);
    ~Memory();
    void set(int index, void *source, size_t size);
    void *get(int index);
    void log(int bytes = 40);
    void loadVariable(string line); // edit top hereeee

    // return top value;
    int getTop();
    // read string from memory (user for system call)
    string getString(int add);
};

#endif // !MEMORY_H