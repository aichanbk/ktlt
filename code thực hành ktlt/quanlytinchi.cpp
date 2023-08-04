#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

typedef struct MonHoc
{
    string maMonHoc;
    int soTinChi;
    int soTinLT;
    int soTinTH;
    int soTinBT;
    float soTinChiHocPhi;
    float soTienHocPhan;
    string loaiGio;
} MH;

typedef struct HocVien
{
    string hoTen;
    int soMonHoc;
    double soTienHoc;
    double soTien1TinChi;
    double soTienDaNop;
    double soTienConLai;
    vector<MH> mh;
} HV;

void pressAnyKey()
{
    cout << endl;
    cout << "Bam phim bat ky de tiep tuc!" << endl;
    getch();
    system("cls");
}

int main()
{
    vector<HV> hv;
    int n;
    cout << "Nguyen Thanh Ha - 20210298" << endl;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    while (true)
    {
        cout << "Nguyen Thanh Ha - 20210298" << endl;
        cout << "**   Chuong trinh quan ly hoc phi             **" << endl;
        cout << "**1. Nhap cac sinh vien va mon hoc            **" << endl;
        cout << "**2. In danh sach sinh vien va hoc phi cac mon**" << endl;
        cout << "**0. Thoat                                    **" << endl;
        cout << "************************************************" << endl;
        cout << "**       Nhap lua chon cua ban                **" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Ban da chon nhap danh sach sinh vien!" << endl;
            for (int i = 1; i <= n; i++)
            {
                HV tmp1;
                tmp1.soTienHoc = 0;
                cout << "Nhap thong tin sinh vien thu " << i << " : " << endl;
                cout << "\tTen sinh vien: ";
                fflush(stdin);
                getline(cin, tmp1.hoTen);
                cout << "\tSo mon hoc: ";
                cin >> tmp1.soMonHoc;
                cout << endl;
                cout << "\tSo tien mot tin chi: ";
                cin >> tmp1.soTien1TinChi;
                cout << endl;
                for (int j = 1; j <= tmp1.soMonHoc; j++)
                {
                    MH tmp2;
                    cout << "\tMon hoc thu " << j << " : " << endl;
                    cout << "\tMa mon hoc: ";
                    cin >> tmp2.maMonHoc;
                    cout << "\t\tSo tin chi: ";
                    cin >> tmp2.soTinChi;
                    cout << "\t\tSo tin chi LT: ";
                    cin >> tmp2.soTinLT;
                    cout << "\t\tSo tin chi BT: ";
                    cin >> tmp2.soTinBT;
                    cout << "\t\tSo tin chi TH: ";
                    cin >> tmp2.soTinTH;
                    tmp2.soTinChiHocPhi = tmp2.soTinLT + tmp2.soTinBT + tmp2.soTinTH * 1.5;
                    tmp2.soTienHocPhan = tmp2.soTinChiHocPhi * tmp1.soTien1TinChi;
                    tmp1.soTienHoc += tmp2.soTinChiHocPhi * tmp1.soTien1TinChi;

                    if (tmp2.soTinTH == 3 && tmp2.soTinLT == 0 && tmp2.soTinBT == 0)
                    {
                        tmp2.loaiGio = "DAMH";
                    }
                    else if (tmp2.soTinChi == 6)
                    {
                        tmp2.loaiGio = "DATN";
                    }
                    else if (tmp2.soTinChi == 12)
                    {
                        tmp2.loaiGio = "DATN Ky su";
                    }
                    else if (tmp2.soTinBT == 0)
                    {
                        tmp2.loaiGio = "LT - TN";
                    }
                    else {
                        tmp2.loaiGio = "LT - BT - TN";
                    }
                    tmp1.mh.push_back(tmp2);
                }
                cout << endl;
                cout << "\tHoc phi da nop: ";
                cin >> tmp1.soTienDaNop;
                if (tmp1.soTienDaNop < tmp1.soTienHoc)
                {
                    tmp1.soTienConLai = tmp1.soTienHoc - tmp1.soTienDaNop;
                }
                else{
                    tmp1.soTienConLai = 0;
                }
                hv.push_back(tmp1);
            }
            pressAnyKey();
            break;
        }
        case 2:
        {
            cout << "Ban da chon xuat DS sinh vien!" << endl;
            cout << "--------------------------------------------------------";
            cout << endl;
            for (HV v : hv)
            {
                cout << "\tTen sinh vien: " << v.hoTen << endl;
                cout << "\tSo mon hoc: " << v.soMonHoc << endl;
                cout << "\tSo tien 1 TC: " << v.soTien1TinChi << endl;
                cout << "\tPhai nop: " << v.soTienHoc << endl;
                cout << "\tDa nop dot 1: " << v.soTienDaNop << endl;
                cout << "\tCon thieu: " << v.soTienConLai << endl;
                if (v.soTienConLai == 0)
                {
                    cout << "\tTinh trang nop HP: Da nop du tien" << endl;
                }
                else
                    cout << "\tTinh trang nop HP: Con thieu" << endl;
                cout << "\tChi tiet hoc phi cac mon hoc: " << endl;
                cout << "\tMa MH\tLoai gio\t\tKhoi luong\tHoc phi phai nop" << endl;
                for (MH u : v.mh)
                {
                    cout << "\t" << u.maMonHoc << "\t" << u.loaiGio << "\t\t" << u.soTinChi << "(" << u.soTinLT << "-" << u.soTinBT << "-" << u.soTinTH << "-" << u.soTinChi * 2 << ")"
                         << "\t" << u.soTienHocPhan << endl;
                }
                cout << endl;
                cout << "--------------------------------------------------------";
                cout << endl;
            }
            pressAnyKey();
            break;
        }
        case 0:
        {
            cout << "Ban da chon thoat chuong trinh!";
            getch();
            return 0;
        }
        default:
        {
            cout << "Lua chon khong hop le!" << endl;
            pressAnyKey();
            break;
        }
        }
    }
    return 0;
}