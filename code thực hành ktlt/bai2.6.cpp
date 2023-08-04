// Nguyễn Thanh Hà - 20210298
/* Bài tập 6: Con trỏ hàm
Giả thuyết Collatz: bắt đầu từ số dương 𝑛 bất kỳ, nếu 𝑛 chẵn thì chia 2, nếu n lẻ thì nhân 3 cộng 1, giả thuyết cho rằng ta luôn đi đến 𝑛=1
Hãy viết chương trình mô phỏng lại quá trình biến đổi để kiếm chứng giả thuyết với giá trị của 𝑛 nhập từ bàn phím.
*/
#include <stdio.h>

void print(int n) {
    printf("n=%d\n", n);
}

int mul3plus1(int n) {
    return n * 3 + 1;
}

int div2(int n) {
    return n / 2;
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int))  {
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}

int main() {
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;

    //*****************
    /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
    odd = mul3plus1;
    even = div2;
    //*****************

    int n;
    scanf("%d", &n);
    simulate(n, odd, even, print);

    return 0;
}