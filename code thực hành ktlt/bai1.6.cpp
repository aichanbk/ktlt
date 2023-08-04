//Nguyễn Thanh Hà - 20210298
/*
Bài 1.6. Viết hàm đảo ngược một mảng các số nguyên theo hai cách: dùng chỉ số 
và dùng con trỏ.
Ví dụ mảng đầu vào là [9, -1, 4, 5, 7] thì kết quả là [7, 5, 4, -1, 9].
*/
#include <iostream>

using namespace std;
void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp; //Khởi tạo giá trị nguyên đầu, cuối, tạm
    
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    while(l < r)  // vòng while để đảo giá trị 2 giá trị ở đầu và cuối
    {
        tmp = arr[l];
        arr[l] = arr[r]; 
        arr[r] = tmp;
        l++;  //Tăng giá trị l
        r--;  //Giảm giá trị r
    }
    //*****************
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    //*****************

    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    while(l < r) // vòng while để đảo giá trị 2 giá trị ở đầu và cuối
    {
       tmp = *(arr+l);
       *(arr+l) = *(arr+r);
       *(arr+r) = tmp;
       l++; //Tăng giá trị l
       r--; //Giảm giá trị r
    }
    //*****************
}
int main()
{
	
int arr[] = {9, 3, 5, 6, 2, 5};
reversearray(arr, 6);
for(int i = 0; i < 6; i++) cout << arr[i] << " ";
int arr2[] = {4, -1, 5, 9};
ptr_reversearray(arr2, 4);
for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
	return 0; 
}
//Nguyễn Thanh Hà - 20210298