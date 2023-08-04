//Nguyễn Thanh Hà - 20210298
/*
Bài 1.1. Viết một chương trình C nhập vào 3 số nguyên. 
Thiết lập một con trỏ để lần lượt trỏ tới từng số nguyên 
và hiển thị kết quả giá trị tham chiếu ngược của con trỏ.
Lưu ý: Phép toán & trả về địa chỉ của biến.
*/
# include <stdio.h>
int main(){
    int x, y, z; //Khai báo 3 biến kiểu nguyên x, y, z
    int* ptr; //Khai báo biến con trỏ ptr
    printf("Enter three integers: "); // In ra nhập 3 số nguyên
    scanf("%d %d %d", &x, &y, &z); // Nhập vào 3 giá trị x, y, z
    printf("\nThe three integers are:\n"); // In ra màn hình kết quả 
    ptr = &x; // Gán địa chỉ của biến x cho con trỏ ptr
    printf("x = %d\n", *ptr); //In ra giá trị của x
    
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    ptr = &y; // Gán địa chỉ của biến y cho con trỏ ptr
    printf("y = %d\n", *ptr); // In ra giá trị của y
    ptr = &z; // Gán địa chỉ của biến z cho con trỏ ptr
    printf("z = %d\n", *ptr); // In ra giá trị của z
    //*****************
    return 0;
}
//Nguyễn Thanh Hà - 20210298