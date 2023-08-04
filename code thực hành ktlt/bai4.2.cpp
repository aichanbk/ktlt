// Nguyễn Thanh Hà - 20210298
/* Bài tập 2: Tính diện tích tam giác
Một điểm trong không gian 2 chiều được biểu diễn bằng pair. 
Hãy viết hàm double area(Point a, Point b, Point c) tính diện tích tam giác theo tọa độ 3 đỉnh. 
Trong đó, Point là kiểu được định nghĩa sẵn trong trình chấm như sau: using Point = pair<double, double>;
*/
#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    double tmp1 = (c.first - a.first) * (b.second - a.second);
    double tmp2 = (b.first - a.first) * (c.second - a.second);
    return 1.0 * abs(tmp1 - tmp2)/2;
    //*****************
}

int main() {
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
// Nguyễn Thanh Hà - 20210298