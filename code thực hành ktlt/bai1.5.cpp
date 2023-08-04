//Nguyễn Thanh Hà - 20210298
/*
Bài 1.5. Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của 
một mảng các số double. Nếu mảng rỗng hãy trả về NULL.
*/
#include <stdio.h>
double* maximum(double* a, int size){
    double *max; //Khai báo con trỏ max kiểu double 
    max = a; // Lưu biến max vào con trỏ a kiểu double
    if (a==NULL) return NULL; //Kiểm tra mảng rỗng

    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    for(int i = 0 ; i < size ; i++)
    {
        if(*max <= *(a+i) ) //So sánh giá trị của max với giá trị của mảng tại vị trí i
        {
            max = a+i; // gán con trỏ max vào vị trí i có giá trị lớn hơn
        }   
    }
    //*****************
    return max;
}
int main()
{
    double arr[]={1., 10., 2., -7., 25., 3.} ;
	double *a=maximum(arr,6); 
	printf("%.0f", *a);
	return 0; 
}
//Nguyễn Thanh Hà - 20210298