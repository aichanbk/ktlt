// Nguyễn Thanh Hà - 20210298
/* Bài tập 5.6. Tổng kết
Một lớp có n sinh viên. Sinh viên thứ i có điểm tổng kết là ai theo thang điểm 10. Để đánh giá chất lượng dạy học, 
giảng viên muốn biết có bao nhiêu bạn đạt điểm A, B, C, D, F. Quy đổi thang điểm được cho như sau:
a<4: F
4≤a<5.5: D
5.5≤a<7: C
7≤a<8.5: B
8.5≤a: A
Mã nguồn sau giải quyết bài toán đó, hãy tinh chỉnh nó để tăng hiệu suất chương trình.
*/

#include <bits/stdc++.h>
using namespace std;

char cal(double a){
    if (a < 4) return 'F';
    if (4 <= a && a < 5.5) return 'D';
    if (5.5 <= a && a < 7) return 'C';
    if (7 <= a && a < 8.5) return 'B';
    if (8.5 <= a) return 'A';
}

int main(){
    cout<<"Nguyen Thanh Ha - 20210298\n";
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    while(n--){
        int a;
        cin >> a;
        if (cal(a) == 'A') ++A;
        if (cal(a) == 'B') ++B;
        if (cal(a) == 'C') ++C;
        if (cal(a) == 'D') ++D;
        if (cal(a) == 'F') ++F;
    }
    cout << A << " " << B << " " << C << " " << D << " " << F;
}
// Nguyễn Thanh Hà - 20210298