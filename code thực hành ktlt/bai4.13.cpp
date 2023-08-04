// Nguyễn Thanh Hà - 20210298
/* Bài tập 13: Đếm xâu con
Cho một xâu nhị phân độ dài 𝑛. Hãy viết chương trình đếm số lượng xâu con chứa số ký tự 0 và số ký tự 1 bằng nhau.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    map<int, int> Map;
    int sum = 0;
    int count_chain = 0;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    cin>>s;
    Map.insert({0, 1});
    int l = s.length();
    for (int i=0; i<l; i++){
        if (s[i] == '0') sum += -1;
        else sum += 1;
        count_chain += Map[sum];
        Map[sum]++;
    }
    cout<<endl;
    cout<<"Nguyễn Thanh Hà - 20210298"<<endl;
    cout<<count_chain;
    return 0;
}
// Nguyễn Thanh Hà - 20210298
