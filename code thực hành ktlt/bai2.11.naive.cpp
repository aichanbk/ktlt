// Nguyễn Thanh Hà - 20210298
/* Bài tập 11: Tính tích hai đa thức
Cho 2 đa thức A(x) và B(x) tương ứng có bậc  𝑁 và  𝑀
Hãy tính ma trận tích C(x) = A(x) * B(x) có bậc  𝑁+𝑀−1
Input: Gồm 2 dòng biểu diễn các đa thức A(x) và B(x), mỗi dòng
Số đầu tiên  𝑁 là bậc của đa thức;
𝑁+1 số nguyên tiếp theo, số thứ i là hệ số của  𝑥𝑖−1
Output: Một số nguyên duy nhất là XOR của các hệ số của đa thức C(x).
*/

// Naive solution

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a,b,c; //Khai báo các đa thức A(x), B(x), C(x)
    int n,m;    // Khai báo bậc của hai đa thức A(x) và B(x)

    // Nhập vào A(x)
    cin>>n;
    a.resize(n+1);
    for (int i = 0; i <= n; i++)
    {
        cin>>a[i];
    }
    // Nhập vào B(x)
    cin>>m;
    b.resize(m+1);
    for (int i = 0; i <= m; i++)
    {
        cin>>b[i];
    }
    // Tính toán giá trị của đa thức C(x)=A(x) * B(x)
    c.resize(m*n,0);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            c[i+j] +=a[i]*b[j];
        }
    }
    int result;
    for (int i = 0; i < c.size(); i++)
    {
        result^=c[i]; // XOR kết quả thực hiện
    }
    cout<<endl;
    cout<<"Nguyễn Thanh Hà - 20210298"<<endl<<endl;
    cout<<result;
    cout<<endl;
    return 0;
}
//Nguyễn Thanh Hà - 20210298