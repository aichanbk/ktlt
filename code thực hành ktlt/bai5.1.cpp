// Nguyễn Thanh Hà - 20210298
/* Bài tập 5.1: Tìm và sửa các lỗi cú pháp
Đoạn code sau liệt kê tất cả các hoán vị n số. Hãy tìm và sửa các lỗi cú pháp như hướng dẫn ở trên.
*/

#include <stdio.h>

int x[100], mark[100], n;

void print(){
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    printf("\n");
}

void process(int i) {
    if (i > n){
        print();
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!mark[j]){
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            mark[j] = 0;
        }
}

int main() {
    printf("\n");
    printf("Nguyen Thanh Ha - 20210298\n");
    n = 5;
    process(1);
    return 0;
}
// Nguyễn Thanh Hà - 20210298