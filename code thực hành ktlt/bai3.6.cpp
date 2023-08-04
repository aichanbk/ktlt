// Nguyễn Thanh Hà - 20210298
/* Bài tập 6: Tìm ước chung lớn nhất
Tính ước chung lớn nhất của hai số cho trước
*/
// Nguyễn Thanh Hà - 20210298
/* Bài tập 6: Tìm ước chung lớn nhất
Tính ước chung lớn nhất của hai số cho trước
*/
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){
    
    //# Khử đệ quy
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    while (a!=b)
    {
    if(a > b) a = a-b;
    else b = b-a;
    }
    return a;
    //*****************
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
// Nguyễn Thanh Hà - 20210298