//Nguyễn Thanh Hà - 20210298
/*
Bài 1.4. Viết hàm countEven(int*, int) nhận một mảng số nguyên
và kích thước của mảng, trả về số lượng số chẵn trong mảng ?
*/
#include <stdio.h>

int counteven(int* arr, int size){
    int count = 0; // Khởi tạo biến count có giá trị bằng 0
    
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298*/
    for(int i = 0 ; i < size ; i++)  
    {
        if(*(arr+i)%2==0) // Kiểm tra xem giá trị của mảng tại vị trí i có là số chẵn không
        {
            count++;
        }
    }
    //*****************
    
    return count;    
}

int main()
{
	int arr[]={1, 5, 4, 8, 10, 6, 7, 2} ;
	int a=counteven(arr,8); 
	printf("%d", a);
	return 0; 
}
//Nguyễn Thanh Hà - 20210298