#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <bitset>
#include <climits>

using namespace std;

void sys_get_time(unsigned long &lsb, unsigned long &msb) // milliseconds since 1 January 1970
{
    chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(
        chrono::system_clock::now().time_since_epoch());
    unsigned long msCount = ms.count();

    msb = msCount >> 32;
    lsb = msCount << 32 >> 32;
    // cout << msb << " | "<< lsb  << endl;
}

void sys_sleep(unsigned long miliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(miliseconds));
}

string sys_int2hex(unsigned long n)
{
    char cstr[128];
    sprintf(cstr, "%#010x", n);
    return (string)cstr;
}

string sys_int2bin(unsigned long n)
{
    bitset<32> a(n);
    return a.to_string();
}

string sys_int2unsigned(long n)
{
    unsigned long *cast = (unsigned long *)(&n);
    return to_string((unsigned long) (*cast));
}

void sys_set_seed(long generatorID, long seed) // ignore generatorID?!
{
    srand(seed);
}

long sys_rand()
{
    return ((long)rand() << 32) | rand();
}

long sys_rand(unsigned long upperBound)
{
    return sys_rand() % upperBound;
}

float sys_rand_f()
{
    return (float) rand() / RAND_MAX;
}

double sys_rand_d() 
{
    return (double)sys_rand() / LLONG_MAX; 
}

int main()
{
    cout << "Welcome to VSCode\n";

    /* -------------------- */
    // unsigned long msb, lsb;
    // while (1)
    // {
    //     sys_get_time(lsb, msb);
    //     cout << "Tick | " << msb << " | " << lsb << endl;
    //     system("sleep 1");
    // }

    /* -------------------- */
    // auto start = std::chrono::high_resolution_clock::now();
    // sys_sleep(2000);
    // auto end = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::milli> elapsed = end-start;
    // std::cout << "Waited " << elapsed.count() << " ms\n";

    /* -------------------- */
    // long a = 23;
    // cout << "To bin: " << sys_int2bin(a) << endl;
    // cout << "To hex: " << sys_int2hex(a) << endl;
    // cout << "To unsigned: " << sys_int2unsigned(a) << endl;
    
    /* -------------------- */
    // #define THIS_RANGE 20
    // sys_set_seed(-999, time(NULL));
    // int i = sys_rand();
    // int i2 = sys_rand(THIS_RANGE);
    // float f = sys_rand_f();
    // double d = sys_rand_d();
    // printf("Value: %i\n", i);
    // printf("Value: %i\n", i2);
    // printf("Value: %0.9f\n", f);
    // printf("Value: %0.9lf\n", d);
    // cout << "/* -------------------- */\n";
    return 0;
}
