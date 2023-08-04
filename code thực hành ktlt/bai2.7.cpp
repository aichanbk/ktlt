// Nguyễn Thanh Hà - 20210298
/* Bài tập 7: Khái quát hoá hàm
Viết hàm tính tổng các phần tử trong hai mảng.
Yêu cầu sử dụng function template để cho phép hàm làm việc với các mảng số nguyên lẫn số thực.
*/

#include <iostream>
using namespace std;

//# viết hàm arr_sum
//*****************
/* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */

template <typename T>
T arr_sum(T a[], int x,T b[], int y){
    T sum=0;
    for (int i = 0; i < x; i++)
    {
        sum+=a[i];
    }
    for (int i = 0; i < y; i++)
    {
        sum+=b[i];
    }
    return sum;
}
//*****************

int main() {
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}