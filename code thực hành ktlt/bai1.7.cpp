//Nguyễn Thanh Hà - 20210298
/*
Bài 1.7. Viết chương trình nhập vào một mảng các số nguyên với số lượng các phần tử nhập 
từ bàn phím.Sau đó sắp xếp mảng theo thứ tự tăng dần. Hiển thị danh sách mảng trước 
và sau khi sắp xếp.
Yêu cầu chỉ sử dụng con trỏ để truy cập mảng, không truy cập theo index mảng.
*/
#include <stdio.h>
#include <stdlib.h>

int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n); // Nhập số lượng phần tử của mảng 
    
    //#Allocate memory
    
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    a = (int* )malloc(n * sizeof(int)); // Cấp phát bộ nhớ cho n số nguyên và con trỏ a
                                    // có giá trị là địa chỉ của byte dữ liệu đầu tiên 
    //*****************

    for(int i = 0; i < n; i++)
        scanf("%d", a + i);  // Đọc mảng a từ bàn phím
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i)); // Ghi ra giá trị mảng a lúc chưa sắp xếp
    printf("\n");
    
    //#Sort array
    
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    for(int i = 0 ; i < n ; i++)     // Sắp xếp tuần tự các giá trị của mảng a
        for(int j = i ; j < n  ; j++)
            {
                if(*(a+i)>*(a+j))
                {
                    int tmp = *(a+i);
                    *(a+i) = *(a+j);
                    *(a+j) = tmp; 
                }
            }
    //*****************
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));  // In ra mảng a sau khi sắp xếp
    printf("\n");
    
    delete [] a;  //Giải phóng bộ nhớ 
    return 0;
}
//Nguyễn Thanh Hà - 20210298