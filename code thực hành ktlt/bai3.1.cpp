// Nguyễn Thanh Hà - 20210298
/* Bài tập 1: Tính dãy Lucas
Dãy Lucas được định nghĩa bởi  𝐿𝑛=𝐿𝑛−1+𝐿𝑛−2 và bắt đầu bởi  𝐿0=2, 𝐿1=1
.Viết hàm tính số Lucas thứ 𝑛
*/

#include <bits/stdc++.h>
using namespace std;

int lucas(int n) {
    
    //*****************
    /* YOUR CODE HERE - Nguyển Thanh Hà - 20210298 */
    if(n==0) return 2;
    else if(n==1) return 1;
    else return lucas(n-1) + lucas(n-2);
    //*****************
}

int main()
{
    int n;
    cin>>n;
    cout<<lucas(n);
    return 0;
}
// Nguyễn Thanh Hà - 20210298