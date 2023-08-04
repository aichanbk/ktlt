#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

typedef struct Dat
{
    string maDat;
    string hinhDang;
    float chieuDai;
    float chieuRong;
    float dayLon;
    float dayBe;
    float chieuCao;
    float day;
    float canhHinhVuong;
    float dienTich;
    double thanhTien;
    double tienDatCoc;
    double giamGia;
} Dat;

float tinhDienTich(Dat dat)
{
    if (dat.hinhDang == "Vuong")
    {
        return dat.canhHinhVuong * dat.canhHinhVuong;
    }
    else if (dat.hinhDang == "Thang")
    {
        return (dat.dayLon + dat.dayBe) * dat.chieuCao / 2;
    }
    else if (dat.hinhDang == "TamGiac")
    {
        return dat.day * dat.chieuCao / 2;
    }
    else if (dat.hinhDang == "HCNhat")
    {
        return dat.chieuDai * dat.chieuRong;
    }
    else
    {
        return 0;
    }
}

float tinhDonGia(Dat dat)
{
    if (dat.maDat == "MD001")
    {
        return 50;
    }
    else if (dat.maDat == "MD002")
    {
        return 30;
    }
    else if (dat.maDat == "MD003")
    {
        return 10;
    }
    else
    {
        return 0;
    }
}

float tinhGiamGia(Dat dat)
{
    float dienTich = tinhDienTich(dat);
    float donGia = tinhDonGia(dat);
    if (dat.hinhDang == "Thang" || dat.hinhDang == "TamGiac")
    {
        return dienTich * donGia * 0.1;
    }
    else
    {
        return 0;
    }
}

float tinhThanhTien(Dat dat)
{
    float dienTich = tinhDienTich(dat);
    float donGia = tinhDonGia(dat);
    if (dat.hinhDang == "Thang" || dat.hinhDang == "TamGiac")
    {
        return dienTich * donGia * 0.9;
    }
    else
    {
        return dienTich * donGia;
    }
}

float tinhTienDatCoc(Dat dat)
{
    float thanhTien = tinhThanhTien(dat);
    if (dat.maDat == "MD001")
    {
        return thanhTien * 0.7;
    }
    else if (dat.maDat == "MD002")
    {
        return thanhTien * 0.5;
    }
    else if (dat.maDat == "MD003")
    {
        return thanhTien * 0.3;
    }
    else
    {
        return 0;
    }
}

typedef struct CongTy
{
    string tenCongTy;
    string diaChi;
    int soLuongDat;
    vector<Dat> danhSachDat;
    double donGiaTrungBinh;
    double tongDienTich;
    double tongThanhTien;
    double tongDatCoc;
    double tongGiamGia;
} CT;

void pressAnyKey()
{
    cout << endl;
    cout << "Bam phim bat ky de tiep tuc!";
    getch();
    system("cls");
}

int main()
{
    vector<CT> ct;
    int n;
    cout << "Nguyen Thanh Ha - 20210298" << endl;
    cout << "Nhap so cong ty BDS: ";
    cin >> n;
    double tongThanhTienCacCongTy = 0;
    double tongDienTichCacCongTy = 0;
    double tongDatCocCacCongTy = 0;
    double tongGiamGiaCacCongTy = 0;
    while (true)
    {
        cout << "Nguyen Thanh Ha - 20210298" << endl;
        cout << "**   CHUONG TRINH QUAN LY BDS      **" << endl;
        cout << "**1. Nhap thong tin cong ty BDS    **" << endl;
        cout << "**2. In ket qua dien tich mieng dat**" << endl;
        cout << "**0. Thoat chuong trinh            **" << endl;
        cout << "*************************************" << endl;
        cout << "**  Nhap lua chon cua ban          **" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Ban da chon nhap mieng dat va do dai !" << endl;
            for (int i = 1; i <= n; i++)
            {
                cout << "Nhap thong tin cong ty " << i << ": " << endl;
                CT tmp1;
                double donGiaTrungBinh = 0;
                cout << "\tTen cong ty: ";
                fflush(stdin);
                getline(cin, tmp1.tenCongTy);
                cout << endl;
                cout << "\tDia chi Cong ty: ";
                fflush(stdin);
                getline(cin, tmp1.diaChi);
                cout << endl;
                cout << "\tNhap so luong mieng dat: ";
                cin >> tmp1.soLuongDat;
                cout << endl;
                cout << "\tNhap danh sach cac mieng dat: " << endl;
                for (int j = 1; j <= tmp1.soLuongDat; j++)
                {
                    Dat tmp2;
                    cout << "\tMa mieng dat thu " << j << " (MD001,MD002,MD003): ";
                    cin >> tmp2.maDat;
                    cout << endl;
                    cout << "\tDon gia theo m^2: " << tinhDonGia(tmp2) << endl;
                    cout << "\tMieng dat hinh(Vuong,Thang,TamGiac,HCNhat): ";
                    cin >> tmp2.hinhDang;
                    cout << endl;
                    if (tmp2.hinhDang == "Vuong")
                    {
                        cout << "\t\tNhap canh hinh vuong: ";
                        cin >> tmp2.canhHinhVuong;
                    }
                    else if (tmp2.hinhDang == "Thang")
                    {
                        cout << "\t\tNhap day lon: ";
                        cin >> tmp2.dayLon;
                        cout << endl;
                        cout << "\t\tNhap day nho: ";
                        cin >> tmp2.dayBe;
                        cout << endl;
                        cout << "\t\tNhap chieu cao: ";
                        cin >> tmp2.chieuCao;
                    }
                    else if (tmp2.hinhDang == "TamGiac")
                    {
                        cout << "\t\tNhap day: ";
                        cin >> tmp2.day;
                        cout << endl;
                        cout << "\t\tNhap chieu cao: ";
                        cin >> tmp2.chieuCao;
                    }
                    else if (tmp2.hinhDang == "HCNhat")
                    {
                        cout << "\t\tNhap chieu dai: ";
                        cin >> tmp2.chieuDai;
                        cout << endl;
                        cout << "\t\tNhap chieu rong: ";
                        cin >> tmp2.chieuRong;
                    }
                    else
                    {
                        cout << "Nhap sai hinh dang!" << endl;
                    }

                    tmp2.dienTich = tinhDienTich(tmp2);
                    tmp1.tongDienTich += tmp2.dienTich;
                    tmp2.thanhTien = tinhThanhTien(tmp2);
                    tmp1.tongThanhTien += tmp2.thanhTien;
                    tmp2.tienDatCoc = tinhTienDatCoc(tmp2);
                    tmp1.tongDatCoc += tmp2.tienDatCoc;
                    tmp2.giamGia = tinhGiamGia(tmp2);
                    tmp1.tongGiamGia += tmp2.giamGia;
                    cout << "\t\tDien tich: " << tmp2.dienTich << endl;
                    cout << "\t\tThanh tien: " << tmp2.thanhTien << endl;
                    cout << "\t\tTien dat coc: " << tmp2.tienDatCoc << endl;
                    cout << "\t\tGiam gia: " << tmp2.giamGia << endl;
                    cout << endl;
                    tmp1.danhSachDat.push_back(tmp2);
                }
                for (Dat v : tmp1.danhSachDat)
                {
                    donGiaTrungBinh += tinhDonGia(v);
                }
                tmp1.donGiaTrungBinh = donGiaTrungBinh / tmp1.soLuongDat;
                ct.push_back(tmp1);
                tongThanhTienCacCongTy += tmp1.tongThanhTien;
                tongDienTichCacCongTy += tmp1.tongDienTich;
                tongDatCocCacCongTy += tmp1.tongDatCoc;
                tongGiamGiaCacCongTy += tmp1.tongGiamGia;
            }
            cout << endl;
            cout << "Ban da nhap thanh cong!" << endl;
            pressAnyKey();
            break;
        }

        case 2:
        {
            cout << "Ban da chon in ra mieng dat!" << endl;
            cout<<endl;
            for (CT v : ct)
            {
                cout << "\tTen cong ty: " << v.tenCongTy << endl;
                cout << "\tDia chi cong ty: " << v.diaChi << endl;
                cout << "\tSo luong mieng dat: " << v.soLuongDat << endl;
                cout << "\tDon gia trung binh: " << v.donGiaTrungBinh << endl;
                cout << "\tTong dien tich: " << v.tongDienTich << endl;
                cout << "\tTong thanh tien: " << v.tongThanhTien << endl;
                cout << "\tTong tien dat coc: " << v.tongDatCoc << endl;
                cout << "\tTong giam gia: " << v.tongGiamGia << endl;
                cout << "\tChi tiet cac mieng dat: " << endl;
                cout << "\tMaMD\tHinhDang\tDon gia\tDien Tich\tThanhTien\tGiam gia\tDat coc" << endl;
                for (Dat u : v.danhSachDat)
                {
                    cout << "\t" << u.maDat << "\t" << u.hinhDang << "\t\t" << tinhDonGia(u) << "\t" << tinhDienTich(u) << "\t\t" << tinhThanhTien(u) << "\t\t" << tinhGiamGia(u) << "\t\t" << tinhTienDatCoc(u) << endl;
                }
                cout << endl
                     << endl;
            }
            cout << "Tong thanh tien cac cong ty: " << tongThanhTienCacCongTy << endl;
            cout << "Tong dien tich cac cong ty: " << tongDienTichCacCongTy << endl;
            cout << "Tong tien dat coc cac cong ty: " << tongDatCocCacCongTy << endl;
            cout << "Tong giam gia cac cong ty: " << tongGiamGiaCacCongTy << endl;
            pressAnyKey();
            break;
        }
        case 0:
        {
            cout << "Ban da chon thoat chuong trinh!" << endl;
            getch();
            return 0;
        }
        default:
        {
            cout << "Nhap sai, vui long nhap lai!" << endl;
            pressAnyKey();
            break;
        }
            return 0;
        }
    }
}