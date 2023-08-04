// Nguyễn Thanh Hà - 20210298
/* Bài tập 5: Năm nhuận
Một năm được coi là nhuận nếu hoặc nó chia hết cho 4 nhưng không chia hết cho 100, hoặc nó chia hết cho 400.
Cho một danh sách các năm, kiểm tra xem có tồn tại năm nhuận trong danh sách đó hay không.
Mã nguồn sau giải quyết bài toán đó, hãy tinh chỉnh nó để tăng hiệu suất chương trình.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool found = false;
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 100 == 0))
            found = true;
            cout<<"Yes";
            return 0;
    }
    cout << "No";
}
// Nguyễn Thanh Hà - 20210298