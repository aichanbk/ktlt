// Nguyễn Thanh Hà - 20210298
/* Bài tập 3.12. Đếm đường đi
Cho đồ thị vô hướng G, hãy đếm số đường đi đi qua k cạnh và không đi qua đỉnh nào quá một lần.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
int n, k;
int m;
vector<vector<int> > vt; // chuyen tu luu tru cac canh sang luu tru danh sach ke
int x[MAX];
bool visited[MAX];
int res;
void input(){
    cin >> n >> k;
    cin >> m;
    vt.resize(n+1);
    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        vt[tmp1-1].push_back(tmp2-1); // dinh tmp2 ke voi dinh tmp1
        vt[tmp2-1].push_back(tmp1-1); // dinh tmp1 ke voi dinh tmp2
    }
    for(int i=0; i<n; i++){
        visited[i] = false;
    }
    res = 0;
}
bool check(int a, int i){
    if(a == 0) return true;
    if(visited[i]) return false;

    int index = 0;
    for(int j=0; j<vt[x[a-1]].size(); j++){
        if(i == vt[x[a-1]][j]) index++;
    }
    if(index == 0) return false;
    return true;
}
void solution(){
    res++;
}
void TRY(int a){
    for(int i=0; i<n; i++){
        if(check(a, i)){
            visited[i] = true;
            x[a] = i;

            if(a == k) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}
int main(){
    input();
    TRY(0);
    cout << endl;
    cout<<"Nguyễn Thanh Hà - 20210298"<<endl;
    cout << res / 2;
}
// Nguyễn Thanh Hà - 20210298