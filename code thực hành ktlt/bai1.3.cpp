//Nguyễn Thanh Hà - 20210298
/*
Bài 1.3. Viết chương trình yêu cầu 
nhập giá trị cho 3 biến số nguyên x, y, z 
kiểu int. Sau đó sử dụng duy nhất một con 
trỏ để cộng giá trị của mỗi biến thêm 100.
*/
#include <stdio.h>

int main() {

    int x, y, z; //Khai báo 3 biến kiểu nguyên x, y, z

    int *ptr; //Khai báo con trỏ ptr

    scanf("%d %d %d", &x, &y, &z); //Nhập vào giá trị của x, y, z

    printf("Here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z); //In ra giá trị ban đầu của x, y, z khi chưa cộng thêm 100

    //*****************
    /* YOUR CODE HERE - Nguyen Thanh Ha - 20210298 */
    ptr = &x; 
    *ptr = *ptr + 100;
    ptr = &y;
    *ptr = *ptr + 100;
    ptr = &z;
    *ptr = *ptr + 100;
    //*****************
    printf("Once again, here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z); //In ra giá trị của x, y, z sau khi cộng thêm 100
    return 0;
}
//Nguyễn Thanh Hà - 20210298