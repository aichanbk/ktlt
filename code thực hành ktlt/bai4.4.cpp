// Nguyễn Thanh Hà - 20210298
/* Bài tập 4: Thao tác với vector
Cho hai vector, hãy xóa hết các phần tử chẵn, sắp xếp giảm dần các số trong cả 2 vector và trộn lại thành một vector cũng được sắp xếp giảm dần.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

void delete_even(vector<int> &a) {
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    for(unsigned int i = 0; i < a.size(); i++)
    {
        if(a[i]%2 == 0){
            a.erase(a.begin()+i);
            i= i-1;
        }
    }
    //*****************
}

void sort_decrease(vector<int> &a) {
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    sort(a.begin(),a.end(),[](int s1,int s2) 
    {
        return s1 > s2;
    });
    //*****************
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector<int> c;
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    unsigned int i=0, j=0;
    while(i< a.size() && j<b.size()) {
        if(a[i] >= b[j]) {
            c.push_back(a[i]);
            i = i + 1;
        } else {
            c.push_back(b[j]);
            j = j + 1;
        }
    }
    if(i<a.size()) for(; i<a.size(); i++) c.push_back(a[i]);
    if(j<b.size()) for(; j<b.size(); j++) c.push_back(b[j]);
    return c;
    //*****************
}

int main() {
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
// Nguyễn Thanh Hà - 20210298