#include <iostream>
using namespace std;

inline int vd(int x, int y)
{
    static int a=10;
    return (x>a || y) ? x-a+y++ : x+y;
}

int main()
{
    int m=5,n=8;
    cout << vd(m,n)<< endl;
    return 0;
}