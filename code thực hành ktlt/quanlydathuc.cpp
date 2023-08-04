#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

typedef struct daThuc
{
    char tenDaThuc;
    double x;
    int bac;
    vector<double> heSo;
} DT;

void pressAnyKey()
{
    cout << endl;
    cout << "Bam phim bat ky de tiep tuc!";
    getch();
    system("cls");
}

int main()
{
    vector<DT> dt;
    int n;
    cout << "Nguyen Thanh Ha - 20210298" << endl;
    cout << "Nhap so luong da thuc: ";
    cin >> n;
    while (true)
    {
        cout << "******************************************" << endl;
        cout << "Nguyen Thanh Ha - 20210298" << endl;
        cout << "**   Chuong trinh quan ly cac da thuc   **" << endl;
        cout << "**1. Nhap cac da thuc, gia tri x        **" << endl;
        cout << "**2. In danh sach da thuc va gia tri    **" << endl;
        cout << "**0. Thoat                              **" << endl;
        cout << "******************************************" << endl;
        cout << "**       Nhap lua chon cua ban          **" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            cout << "Ban da chon thoat chuong trinh!";
            getch();
            return 0;
        }
        case 1:
        {
            cout << "Ban da chon nhap danh sach da thuc!" << endl;
            cout << "---------------------------------------------------------" << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << "Nhap da thuc thu " << i << endl;
                DT tmp;
                cout << "Nhap ten da thuc: ";
                cin >> tmp.tenDaThuc;
                cout << endl;
                cout << "Nhap bac da thuc: ";
                cin >> tmp.bac;
                cout << endl;
                cout << "Nhap gia tri x: ";
                cin >> tmp.x;
                cout << endl;
                for (int j = tmp.bac; j >= 0; j--)
                {
                    cout << "Nhap he so bac " << j << ": ";
                    double hs;
                    cin >> hs;
                    tmp.heSo.push_back(hs);
                }
                reverse(tmp.heSo.begin(), tmp.heSo.end());
                dt.push_back(tmp);
            }
            cout << "---------------------------------------------------------" << endl;
            cout << "Ban da nhap thanh cong!" << endl;
            pressAnyKey();
            break;
        }
        case 2:
        {
            cout << "Ban da chon xuat danh sach da thuc va gia tri da thuc!" << endl;
            cout << "Nguyen Thanh Ha - 20210298" << endl;
            cout << "---------------------------------------------------------" << endl;
            for (DT v : dt)
            {
                cout << "Da thuc : " << v.tenDaThuc << "(x) = ";
                for (int i = v.bac; i >= 0; i--)
                {
                    if (i == 0)
                    {
                        cout << v.heSo[i];
                    }
                    else
                    {
                        if (v.heSo[i] != 0)
                        {
                            cout << v.heSo[i] << "x^" << i << " + ";
                        }
                    }
                }
                cout << endl;
                cout << "Gia tri da thuc: " << v.tenDaThuc << "(" << v.x << ") = ";
                double gt = 0;
                for (int i = v.bac; i >= 0; i--)
                {
                    if (i == 0)
                    {
                        gt += v.heSo[i];
                    }
                    else
                    {
                        gt += v.heSo[i] * pow(v.x, i);
                    }
                }
                cout << gt << endl;
                cout << "---------------------------------------------------------" << endl;
            }
            pressAnyKey();
            break;
        }
        }
    }
    return 0;
}