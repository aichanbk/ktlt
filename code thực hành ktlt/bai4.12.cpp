// Nguyễn Thanh Hà - 20210298
/* Bài tập 12. Lược đồ
Cho một lược đồ gồm  𝑛 cột chữ nhật liên tiếp nhau có chiều rộng bằng 1 và chiều cao lần lượt là các số nguyên không âm  ℎ1,ℎ2,…,ℎ𝑛
.Hãy xác định hình chữ nhật có diện tích lớn nhất có thể tạo thành từ các cột liên tiếp.
*/
#include<iostream>
#include<stack>
using namespace std;
    int h[1000001];
    int left_position[1000001];    // vi tri phan tu khong nho hon o ben trai nhat
    int right_position[1000001];   // vi tri phan tu không nho hon o ben phai nhat
    stack<pair<int, int>> S_right; // luu gia tri và vi tri
    stack<pair<int, int>> S_left;  // luu gia tri và vi tri
int main(){
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
        cin>>h[i];
    for (int i=0; i<n; i++){
        left_position[i] = i;
        while (!S_left.empty()){
            pair<int, int> top = S_left.top();
            if (top.first >= h[i]){
                left_position[i] = top.second;
                S_left.pop();
            } else break;
        }
        S_left.push({h[i], left_position[i]});
    }
    for (int i=n-1; i>=0; i--){
        right_position[i] = i;
        while (!S_right.empty()){
            pair<int, int> top = S_right.top();
            if (top.first >= h[i]){
                right_position[i] = top.second;
                S_right.pop();
            } else break;
        }
        S_right.push({h[i], right_position[i]});
    }
    int max_s=0;
    for (int i=0; i<n; i++){
        int current_s = h[i]*(right_position[i] - left_position[i] + 1);
        max_s = max(max_s, current_s);
    }
    cout<<max_s;
    return 0;
}
// Nguyễn Thanh Hà - 20210298