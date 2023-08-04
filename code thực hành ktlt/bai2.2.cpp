// Nguyễn Thanh Hà - 20210298
/* Bài tập 2: Truyền tham chiếu
Viết hàm hoán vị vòng tròn 3 biến a, b, c. 
Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận các giá trị mới b, c, a.
*/
#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    int tmp;
    tmp = x;
    x=y;
    y=z;
    z=tmp;
    //*****************
}

int main() {
    int x, y, z;
    
    //# Nhập 3 số nguyên
    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    scanf("%d %d %d",&x,&y,&z);
    //*****************
    
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}