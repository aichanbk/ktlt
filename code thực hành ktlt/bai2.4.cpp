// Nguyễn Thanh Hà - 20210298
/* Bài tập 4: Đa năng hoá hàm
Viết các hàm tính lập phương của số nguyên và số thực.
*/
#include <stdio.h>

int cube(int x) {
    //# trả về lập phương của x
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    return x*x*x;
    //*****************
}

//# viết hàm tính lập phương của một số kiểu double
double cube(double x) {

    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    return x*x*x;
    //*****************
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}