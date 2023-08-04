// Nguyễn Thanh Hà - 20210298
/* Bài tập 5:
Viết hàm thực hiện thuật toán DFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề vector< list<int> > .
Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán DFS xuất phát từ đỉnh 1. 
Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề. Yêu cầu hàm trả 
ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <stack>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    while (!S.empty()) {
        int u = S.top();
        if (!visited[u]){
            visited[u] = true;
            std::cout<< u << std::endl;
        }
        if (!adj[u].empty()){
            int v = adj[u].front(); 
            adj[u].pop_front();
            if(!visited[v]){
                S.push(v);
            }
        }else { 
            S.pop();
        }
    }
    //*****************
}
int main()
{
int n = 7;
vector< list<int> > adj;
adj.resize(n + 1);
adj[1].push_back(2);
adj[2].push_back(4);
adj[1].push_back(3);
adj[3].push_back(4);
adj[3].push_back(5);
adj[5].push_back(2);
adj[2].push_back(7);
adj[6].push_back(7);
dfs(adj);
}
// Nguyễn Thanh Hà - 20210298