// Nguyễn Thanh Hà - 20210298
/* Bài tập 6:
Viết hàm thực hiện thuật toán BFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề vector< list<int> > .
Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán BFS xuất phát từ đỉnh 1. Các đỉnh được thăm theo thứ tự ưu tiên 
từ trái sang phải trong danh sách kề. Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    while (!Q.empty()) {
        int u = Q.front();
        if (!visited[u]){
            visited[u] = true;
            std::cout<< u << std::endl;
        }
        if (!adj[u].empty()){
            int v = adj[u].front(); 
            adj[u].pop_front();
            if(!visited[v]){
                Q.push(v);
            }
        }else { 
            Q.pop();
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
bfs(adj);
}
// Nguyễn Thanh Hà - 20210298