#include <cstring>
#include <iostream>
using namespace std;

void ktra(int *a,int *b, int c)
{
    *((*a+1==1)?b:a)=*a?*b:c;
}

int main()
{
    int a=1,b=2,c=0;
    ktra(&c,&a,b);
    cout << a << " " << b << " " << c << endl;
    return 0;
}
