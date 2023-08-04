// Nguyễn Thanh Hà - 20210298
/* Bài tập 7: Liệt kê xâu nhị phân
Sử dụng phương pháp khử đệ quy bằng stack, hãy liệt kê các xâu nhị phân độ dài n không có k bit 1 nào liên tiếp
*/
#include <bits/stdc++.h>
using namespace std;

struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        
        //# Khử đệ quy
        //*****************
        /* YOUR CODE HERE - Nguyễn Thanh Hà - 20210298 */
        if(top.j > 0)
            L = top.old_L;
        if(top.j >1){
            s.pop();
            continue;
        }
        if(L + 1 < k || top.j == 0)
        {
            x[top.i] = top.j;
            top.old_L = L;
            L = top.j ? L + 1 : 0;
            s.push(state(top.i + 1, 0));
        }
        ++top.j;
        //*****************
    }
    return 0;
}
// Nguyễn Thanh Hà - 20210298
