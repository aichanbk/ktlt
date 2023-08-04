#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Mở file input.inp
    ifstream fin("input.inp");
    if (!fin.is_open()) {
        cout << "Khong the mo file input.inp" << endl;
        return 1;
    }

    // Đọc nội dung từ file input.inp
    string content((istreambuf_iterator<char>(fin)), (istreambuf_iterator<char>()));
    fin.close();

    // In nội dung đọc được trên command line
    cout << content;

    return 0;
}