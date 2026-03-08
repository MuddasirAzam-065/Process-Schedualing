#include <iostream>
#include "process.h"
using namespace std;
int main()
{
    string filename;
    ProcessScheduler scheduler("sample.txt");
    scheduler.printExecutionOrder();
    scheduler.simulateCPU();
    return 0;
}