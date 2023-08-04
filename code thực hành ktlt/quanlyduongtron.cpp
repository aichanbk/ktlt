#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
const double PI = 3.14;

typedef struct Diem
{
    char tenDiem;
    double x;
    double y;
    double z;
} Diem;

typedef struct DuongTron
{
    // char tenTamDT;
    Diem tam;
    double banKinh;
    vector<Diem> baDiem;
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
    int n;
    vector<DT> dt;
    cout << "Nhap so luong duong tron: ";
    cin >> n;
    while (true)
    {
        cout << "**   Chuong trinh quan ly cac duong tron   **" << endl;
        cout << "**1. Nhap cac duong tron va 3 diem bat ky  **" << endl;
        cout << "**2. In toa do tam, diem, ban kinh, vi tri, chu vi dien tich duong tron\n"; 
        cout << "     va chu vi, toa do trong tam cua tam giac lap tu 3 diem **" << endl;
        cout << "**0. Thoat                                 **" << endl;
        cout << "*********************************************" << endl;
        cout << "**       Nhap lua chon cua ban             **" << endl;
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
            cout << "Ban da chon nhap danh sach hinh tron!" << endl;
            for (int i = 1; i <= n; i++)
            {
                DT tmp1;
                cout << "Nhap thong tin cua tg thu " << i << " :"<<endl;
                cout << "\tTen tam duong tron: ";
                cin >> tmp1.tam.tenDiem;
                cout << endl;
                cout << "\t\tx: ";
                cin >> tmp1.tam.x;
                cout << endl;
                cout << "\t\ty: ";
                cin >> tmp1.tam.y;
                cout << endl;
                cout << "\t\tz: ";
                cin >> tmp1.tam.z;
                cout << endl;
                cout << "\tBan kinh: ";
                cin >> tmp1.banKinh;
                cout << endl;
                for (int j = 1; j <= 3; j++)
                {
                    Diem tmp2;
                    cout << "\tTen diem " << j << " : ";
                    cin >> tmp2.tenDiem;
                    cout << endl;
                    cout << "\t\tx: ";
                    cin >> tmp2.x;
                    cout << endl;
                    cout << "\t\ty: ";
                    cin >> tmp2.y;
                    cout << endl;
                    cout << "\t\tz: ";
                    cin >> tmp2.z;
                    cout << endl;

                    tmp1.baDiem.push_back(tmp2);
                }
                dt.push_back(tmp1);
            }
            cout << endl;
            cout << "Ban da nhap thanh cong!" << endl;
            pressAnyKey();
            break;
        }

        case 2:
        {
            cout << endl;
            cout << "Ban da chon xuat danh sach hinh tron!" << endl;
            for (DT v : dt)
            {
                cout << "Hinh tron tam :" << v.tam.tenDiem << endl;
                cout << "Toa do tam " << v.tam.tenDiem << "(" << v.tam.x << "," << v.tam.y << "," << v.tam.z << ")" << endl;
                cout << "Ban kinh R : " << v.banKinh<<endl;
                for (Diem u : v.baDiem)
                {
                    cout << "Toa do Diem " << u.tenDiem << "(" << u.x << "," << u.y << "," << u.z << ")" << endl;
                }
                for (Diem u : v.baDiem)
                {
                    cout << "Toa do trung diem cua doan thang:" << v.tam.tenDiem << u.tenDiem << "(" << (u.x + v.tam.x) * 0.5 << "," << (u.y + v.tam.y) * 0.5 << "," << (u.z + v.tam.z) * 0.5 << ")" << endl;
                }
                cout<<"Toa do trong tam cua tam giac lap tu 3 diem: "<<endl;
                cout<<"("<<(v.baDiem[0].x+v.baDiem[1].x+v.baDiem[2].x)/3<<","<<(v.baDiem[0].y+v.baDiem[1].y+v.baDiem[2].y)/3<<","<<(v.baDiem[0].z+v.baDiem[1].z+v.baDiem[2].z)/3<<")"<<endl;
                cout<<"Chu vi hinh tron: "<<2*PI*v.banKinh<<endl;
                cout<<"Dien tich hinh tron: "<<PI*v.banKinh*v.banKinh<<endl;
                cout<<"Chu vi tam giac "<<v.baDiem[0].tenDiem<<v.baDiem[1].tenDiem<<v.baDiem[2].tenDiem<<": "<<sqrt(pow(v.baDiem[0].x-v.baDiem[1].x,2)+pow(v.baDiem[0].y-v.baDiem[1].y,2)+pow(v.baDiem[0].z-v.baDiem[1].z,2))+sqrt(pow(v.baDiem[0].x-v.baDiem[2].x,2)+pow(v.baDiem[0].y-v.baDiem[2].y,2)+pow(v.baDiem[0].z-v.baDiem[2].z,2))+sqrt(pow(v.baDiem[2].x-v.baDiem[1].x,2)+pow(v.baDiem[2].y-v.baDiem[1].y,2)+pow(v.baDiem[2].z-v.baDiem[1].z,2))<<endl;
                cout<<"Dien tich tam giac "<<v.baDiem[0].tenDiem<<v.baDiem[1].tenDiem<<v.baDiem[2].tenDiem<<": "<<0.5*sqrt(pow(v.baDiem[0].x-v.baDiem[1].x,2)+pow(v.baDiem[0].y-v.baDiem[1].y,2)+pow(v.baDiem[0].z-v.baDiem[1].z,2))*sqrt(pow(v.baDiem[0].x-v.baDiem[2].x,2)+pow(v.baDiem[0].y-v.baDiem[2].y,2)+pow(v.baDiem[0].z-v.baDiem[2].z,2))<<endl;
                for(Diem u : v.baDiem)
                {
                    double d = sqrt(pow(v.tam.x-u.x,2)+pow(v.tam.y-u.y,2)+pow(v.tam.z-u.z,2));
                    if(d>v.banKinh)
                    {
                        cout<<"Diem "<<u.tenDiem<<" nam ngoai duong tron"<<endl;
                    }
                    else if(d<v.banKinh)
                    {
                        cout<<"Diem "<<u.tenDiem<<" nam trong duong tron"<<endl;
                    }
                    else
                    {
                        cout<<"Diem "<<u.tenDiem<<" nam tren duong tron"<<endl;
                    }
                }
                cout<<endl;
                cout<<"--------------------------------------------"<<endl;
            }
            cout<<endl;
            pressAnyKey();
            break;
        }

        default:
            break;
        }
    }

    return 0;
}