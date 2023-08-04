// Nguyễn Thanh Hà - 20210298
/* Bài tập 3: Tính tích có hướng của 2 vector
Một vector trong không gian 3 chiều được biểu diễn bằng tuple<double, double, double>. 
Hãy viết hàm Vector cross_product(Vector a, Vector b) tính tích có hướng của 2 vector. 
Trong đó Vector là kiểu dữ liệu được định nghĩa sẵn trong trình chấm như sau: using Vector = tuple<double, double, double>;
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    double x1 = get<0>(a);
    double y1 = get<1>(a);
    double z1 = get<2>(a);
    double x2 = get<0>(b);
    double y2 = get<1>(b);
    double z2 = get<2>(b);
    double x = y1*z2 - y2*z1;
    double y = z1*x2 - z2*x1;
    double z = x1*y2 - x2*y1;
    return make_tuple(x, y, z);
    //*****************
}

int main() {
    cout << setprecision(2) << fixed;
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}
// Nguyễn Thanh Hà - 20210298