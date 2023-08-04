#include <iostream>
using namespace std;

int hoanvi(int *px, int *py)
{
    int z;
    z = *px;
    *px = *py;
    *py = z;
}

int main()
{
    int a = 15, b = 20;
    hoanvi(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}