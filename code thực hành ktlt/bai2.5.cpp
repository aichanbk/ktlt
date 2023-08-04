// Nguyễn Thanh Hà - 20210298
/* Bài tập 5: Đa năng hoá toán tử
Viết các toán tử tính tổng, hiệu, tích và thương của hai số phức.
*/
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

struct Complex {
    double real;
    double imag;
    
};

Complex operator + (Complex a, Complex b) {
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    Complex tmp;
    tmp.real = a.real + b.real;
    tmp.imag = a.imag + b.imag;
    return tmp;
    //*****************
}

Complex operator - (Complex a, Complex b) {
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    Complex tmp;
    tmp.real = a.real - b.real;
    tmp.imag = a.imag - b.imag;
    return tmp;
    //*****************
}

Complex operator * (Complex a, Complex b) {
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    Complex tmp;
    tmp.real = a.real * b.real - a.imag * b.imag;
    tmp.imag = a.real * b.imag + a.imag * b.real;
    return tmp;
    //*****************
}

Complex operator / (Complex a, Complex b) {
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    Complex tmp;
    if (b.real == 0 && b.imag == 0) {
        tmp.real = 0;
        tmp.imag = 0;
    } else if (b.real == 0) {
        tmp.real = 0;
        tmp.imag = a.imag / b.imag;
    } else if (b.imag == 0) {
        tmp.real = a.real / b.real;
        tmp.imag = 0;
    } else {
        tmp.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
        tmp.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
    }
    return tmp;
    //*****************
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    
    return 0;
}