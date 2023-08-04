// Nguyễn Thanh Hà - 20210298
/* Bài tập 9:
Cài đặt thuật toán Dijkstra trên đồ thị vô hướng được biểu diễn bằng danh sách kề sử dụng priority_queue 
Cụ thể, bạn cần cài đặt hàm vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) nhận đầu vào là danh sách kề 
chứa các cặp pair<int, int> biểu diễn đỉnh kề và trọng số tương ứng của cạnh. Đồ thị gồm n đỉnh được đánh số từ 0 tới n-1. 
Hàm cần trả vector<int> chứa n phần tử lần lượt là khoảng cách đường đi ngắn nhất từ đỉnh 0 tới các đỉnh 0, 1, 2, ..., n-1.
*/
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

const int INF = 1e9;
vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    int n = adj.size();
    vector<int> distance(n, INF);
    distance[0] = 0;
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != distance[u]) continue;
        for (const auto &edge : adj[u]) {
            int v = edge.first;
            int uv = edge.second;
            if (distance[v] > du + uv) {
                distance[v] = du + uv;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
    //*****************
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    auto add_edge = [&adj] (int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }
    return 0;
}
// Nguyễn Thanh Hà - 20210298