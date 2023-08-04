#include <iostream>
#include <fstream>
#include <climits>
#define START 0

using namespace std;

int **a,n;
int *x; // Chứa các kết quả thăm các thành phố
int total; // Tổng chi phí của phương án trong x
int *best; // Chứa kết quả tốt nhất(chi phí ít nhất)
int totalBest; // tổng chi phí tốt nhất
bool *d; // Kiểm tra 1 thành phố đã thăm chưa: d[i]= true -> thành phố i đã thăm rồi

void readData()
{
    ifstream f;
    f.open("travel.inp",ios::in);
    
    f >>n;
    a = new int*[n];
    for(int i = 0; i<n;i++)
    {
        a[i] = new int[n];
    }
    
    for(int i = 0; i<n;i++)
        for(int j = 0; j<n;j++)
            f>>a[i][j];
    
    f.close();
}

void initData()
{
    readData();
    
    x = new int[n];
    best = new int[n];
    d = new bool[n];

    total = 0;
    totalBest = INT_MAX;
    
    for(int i = 0;i<n;i++)  
        d[i] = false;
    x[0] = START;
    d[START] = true;
    
}

void output()
{
    ofstream f;
    f.open("travel.out",ios::out);

    f<<totalBest<<endl;
    for(int i = 0;i<n;i++)
        f<<best[i] + 1<<" -> "; 
    f<<START+1;
    f.close();    
}

void update()
{
    if(a[x[n-1]][START]>0 && total + a[x[n-1]][START] < totalBest)
    {
        totalBest = total + a[x[n-1]][START];
        for (int i = 0; i < n; i++)
        {
            best[i] = x[i];
        }  
    }
}

void travel(int idx)
{
    if(total > totalBest) return;

    for(int i=0; i < n; i++)
        if(d[i]==false && a[x[idx-1]][i] > 0)
        {
            x[idx] = i;
            d[i] = true;
            total += a[x[idx-1]][i];
            
            if(idx == n-1) 
                update();
            else 
                travel(idx+1);
                
            d[i] = false;
            total -= a[x[idx-1]][i];
        }
}

int main()
{
    initData();
    
    travel(1);
    output();

    delete[] d;
    delete[] x;
    for(int i = 0; i<n;i++) 
        delete[] a[i];
    delete[] a;

    return 0;
}