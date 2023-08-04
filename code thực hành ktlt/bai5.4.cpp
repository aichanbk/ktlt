// Nguyễn Thanh Hà - 20210298
/* Bài tập 5.4: Bài toán người du lịch
Một người xuất phát tại thành phố 1, muốn đi thăm tất cả các thành phố khác, mỗi thành phố đúng 1 lần và quay về 1. 
Chi phí để đi từ thành phố 𝑖 sang thành phố 𝑗 là  ci,j. Hãy tìm tổng chi phí nhỏ nhất có thể
*/

#include <bits/stdc++.h>
using namespace std;
int m, n, Smin = 100000;
long long S = 0;
int cmin = 100000000;
int x[100];
int c[100][100];
vector<int> flag(100, false);
void TRY(int k)
{
    for (int i = 2; i <= n; i++)
    {
        if (flag[i] == false && c[x[k - 1]][i] != -1)
        {
            flag[i] = true;
            x[k] = i;
            S = S + c[x[k - 1]][i];
            if (k == n)
            {
                if (S + c[i][1] < Smin && c[i][1] != -1)
                    Smin = S + c[i][1];
            }
            else if (S + cmin * (n - k + 1) < Smin)
            {
 
                TRY(k + 1);
            }
            flag[i] = false;
            S = S - c[x[k - 1]][i];
        }
    }
}
int main()
{
    int a, b;
    cout<<"Nguyen Thanh Ha - 20210298\n";
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                c[i][j] = 0;
            else
                c[i][j] = -1;
        }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cin >> c[a][b];
        if (c[a][b] < cmin)
            cmin = c[a][b];
    }
    x[1] = 1;
    flag[1] = true;
    TRY(2);
    cout << Smin;
}
// Nguyễn Thanh Hà - 20210298
