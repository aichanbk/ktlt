// Nguyễn Thanh Hà - 20210298
/* Bài tập 11. Bảo vệ lâu đài
Bức tường bao quanh một lâu đài nọ được cấu thành từ 𝑛 đoạn tường được đánh số từ 1 đến 𝑛.Quân giặc lên kế hoạch tấn công lâu đài bằng cách gửi 𝑎𝑖
tên giặc đánh vào đoạn tường thứ 𝑖. Để bảo vệ lâu đài có tất cả 𝑠 lính.Do các đoạn tường có chất lượng khác nhau nên khả năng bảo vệ tại 
các đoạn tường cũng khác nhau. Cụ thể tại đoạn tường thứ  𝑖, mỗi lính có thể đẩy lùi tấn công của  𝑘𝑖 tên giặc.
Giả sử đoạn tường thứ 𝑖 có 𝑥𝑖 lính. Khi đó nếu số tên giặc không vượt quá  𝑥𝑖×𝑘𝑖 thì không có tên giặc nào lọt 
vào được qua đoạn tường này. Ngược lại sẽ có  𝑎𝑖−𝑥𝑖×𝑘𝑖 tên giặc lọt vào lâu đài qua đoạn tường này.
Yêu cầu hãy viết chương trình phân bố lính đứng ở các đoạn tường sao cho tổng số lính là  𝑠 và tổng số lượng tên giặc lọt vào lâu đài là nhỏ nhất.
*/
#include<bits/stdc++.h>
using namespace std;
    int n, s;
    struct couple{
        int a;
        int k;
    };
    int sum = 0;        // tong so quan giac
    int died = 0;       // so quan giac da bi giet
    couple wall[100001];
    stack<int> ST;
    priority_queue<int, vector<int>> PQ; // chua phan du caa ai/ki

bool compare(couple x, couple y){
    return x.k > y.k;
}

void process(){
    for (int i=0; i < n; i++){
        // neu phan tu trong PQ lon hon kha nang bao ve
        // cua phan tu dang xet
        while (!PQ.empty() && PQ.top() > wall[i].k && s>0) {
            died += PQ.top();
            PQ.pop();
            s--;
        }
        int thuong = wall[i].a / wall[i].k;
        int du = wall[i].a % wall[i].k;
        if (du != 0) PQ.push(du);

        if (thuong <= s) {
            s -= thuong;
            died += thuong*wall[i].k;
        } else {
            died += s*wall[i].k;
            s = 0;
            break;
        }
    }
    while (s>0 && !PQ.empty()){
        died += PQ.top();
        s--;
        PQ.pop();
    }
}
int main(){
    cin>>n>>s;
    for (int i=0; i < n; i++)
    {
        cin>>wall[i].a>>wall[i].k;
        sum += wall[i].a;
    }
    sort(wall, wall+n, compare); //Sap xep giam dan theo kha nang bao ve k
    process();
    cout<<endl;
    cout<<"Nguyễn Thanh Hà - 20210298"<<endl;
    cout<<sum-died;
    return 0;
}
// Nguyễn Thanh Hà - 20210298