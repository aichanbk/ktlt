// Nguyễn Thanh Hà - 20210298
/* Bài tập 12: Map Sort. Hôm nay, cô giáo giao cho An một câu hỏi hóc búa. Cô cho một danh sách với mỗi phần tử có dạng <key, value> 
và yêu cầu An sắp xếp danh sách đó giảm dần theo giá trị value. Nếu 2 phần tử có value giống nhau thì sắp xếp giảm dần theo key.
Hãy viết một chương trình sử dụng hàm nặc danh để giúp An làm bài tập.
Input: Danh sách đầu vào. Mỗi dòng ghi một cặp giá trị key, value cách nhau bởi dấu cách (|key| ≤109≤109, |value| ≤109≤109).
Output: In danh sách đã được sắp xếp theo yêu cầu. Mỗi dòng ghi một cặp giá trị key, value cách nhau bởi dấu cách.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    vector<pair<int,int>> myVector; // vector chứa các cặp <key, value>
    int key, value;
    
    while (cin >> key >> value)
    {
        myVector.push_back(make_pair(key, value)); // thêm cặp <key, value> vào vector
    }
    // Sử dụng hàm nặc danh để sắp xếp
    sort(myVector.begin(), myVector.end(), [](pair<int,int> &x, pair<int,int> &y){
        if(x.second == y.second)
            return x.first > y.first; // nếu value bằng nhau thì sắp xếp giảm dần theo key
        else
            return x.second > y.second; // sắp xếp giảm dần theo value
    });

    cout <<"Nguyễn Thanh Hà - 20210298"<< endl;
    for (const auto &v : myVector)
    {
        cout << v.first << ' ' << v.second << endl;
    }
    return 0;
}
// Nguyễn Thanh Hà - 20210298
