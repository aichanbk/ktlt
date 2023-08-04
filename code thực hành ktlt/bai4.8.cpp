// Nguyễn Thanh Hà - 20210298
/* Bài tập 8:
Viết các hàm thực hiện các phép giao và hợp của hai tập hợp mờ được biểu diễn bằng map.
Trong đó mỗi phần tử được gán cho một số thực trong đoạn [0..1] biểu thị độ thuộc của phần tử trong tập hợp, 
với độ thuộc bằng 1 nghĩa là phần tử chắc chắn thuộc vào tập hợp và ngược lại độ thuộc bằng 0 nghĩa là phần tử chắc chắn không thuộc trong tập hợp.
Phép giao và hợp của 2 tập hợp được thực hiện trên các cặp phần tử bằng nhau của 2 tập hợp, với độ thuộc mới được tính bằng phép toán min và max 
của hai độ thuộc.
*/
#include <iostream>
#include <map>

using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    map<T, double> result;
    for (const auto &x : a) {
        result[x.first] = x.second;
    }
    for (const auto &x : b) {
        if (result.find(x.first) == result.end()) {
            result[x.first] = x.second;
        } else {
            result[x.first] = std::max(x.second, result.at(x.first));
        }
    }
    return result;
    //*****************
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    //*****************
    // YOUR CODE HERE - Nguyễn Thanh Hà - 20210298
    map<T, double> result;
    for (const auto &x : a) {
        if (b.find(x.first) != b.end()) {
            result[x.first] = std::min(x.second, b.at(x.first));
        }
    }
    return result;
    //*****************
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
// Nguyễn Thanh Hà - 20210298