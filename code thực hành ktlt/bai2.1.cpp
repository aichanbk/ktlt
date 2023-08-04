// Nguyễn Thanh Hà - 20210298
/*Bài tập 1: Truyền tham trị
Viết hàm tính độ dài cạnh huyền của tam giác theo hai cạnh góc vuông
*/
#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */ 
    return sqrt(x*x + y*y);
    //*****************
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);
    
    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);
    
    return 0;
}