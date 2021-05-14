#include <iostream>
using namespace std;

class Parent
{
public:
    Parent(int a, int b) { num1 = a; num2 = b; }
    Parent() { num1 = num2 = -1; }
    int num1;
    int num2;
    int calculateSum() { return num1 + num2; }
};

class Child: public Parent
{
public:
    Child(int a, int b): Parent(a, b) {}
    int calculateProduct() { return num1 * num2; }
};


int main()
{
    cout << "Welcome to VSCode\n";
    Parent p(1, 2);
    Child c(2, 5);
    cout << p.calculateSum() << endl;
    cout << c.calculateProduct() << endl;
    return 0;
}