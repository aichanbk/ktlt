#include <bits/stdc++.h>
#include <string>
#include <conio.h>
using namespace std;

typedef struct DangVien
{
    int soTheDangVien;
    string tenDangVien;
    struct namVaoDang
    {
        int ngay;
        int thang;
        int nam;
    } namVaoDang;
    double luong;
    string chucVu;
    double tienPhuCap;
}DV;

typedef struct ChiBo
{
    string tenChiBo;
    string diaChi;
    int soDangVien;
    double tongLuong;
    double tongDangPhiThu;
    double tongTroCapChucVu;
    vector<DV> dv;
}CB;

void printLine(int n)
{
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"_";
    }
    cout<<endl; 
}

void pressAnyKey()
{
    cout<<endl;
    cout<<"Bam phim bat ky de tiep tuc!";
    getch();
    system("cls");
}

int main()
{
    vector<CB> cb;
    int n;
    cout<<"Nguyen Thanh Ha - 20210298"<<endl;
    cout<<"Nhap so Chi Bo: ";
    cin>>n;
    while (true)
    {
        cout<<"Nguyen Thanh Ha - 20210298"<<endl;
        cout<<"**   CHUONG TRINH QUAN LY CHI BO - DANG VIEN **"<<endl;
        cout<<"**1. Nhap cac Chi Bo                         **"<<endl;
        cout<<"**2. In ket qua ds Chi bo Dang vien          **"<<endl;
        cout<<"**0. Thoat                                   **"<<endl;
        cout<<"***********************************************"<<endl;
        cout<<"**    Nhap lua chon cua ban                  **"<<endl;
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            cout<<endl;
            cout<<"Ban da chon nhap ds Chi bo Dang vien!"<<endl;
            for (int i = 1; i <= n; i++)
            {
                CB tmp1;
                tmp1.tongDangPhiThu = 0;
                tmp1.tongLuong = 0;
                tmp1.tongTroCapChucVu = 0;
                cout<<"Nhap thong tin Chi bo thu "<< i <<" :"<<endl;
                cout<<"\tTen Chi bo: "; cin>>tmp1.tenChiBo;
                cout<<endl;
                cout<<"\tSo dang vien: ";cin>>tmp1.soDangVien;
                cout<<endl;
                cout<<"\tNhap ds Dang Vien:"<<endl;
                for(int j = 1; j<= tmp1.soDangVien; j++)
                {
                    DV tmp2;
                    cout<<"\tDang vien thu "<< j <<endl;
                    cout<<"\t\tSo the: ";cin>>tmp2.soTheDangVien;
                    cout<<endl;
                    cout<<"\t\tTen Dang Vien: ";
                    fflush(stdin);
                    getline(cin,tmp2.tenDangVien);
                    cout<<endl;
                    cout<<"\t\tNgay vao dang:"<<endl;
                    cout<<"\t\tNgay: ";cin>>tmp2.namVaoDang.ngay;
                    //cout<<endl;
                    cout<<"\t\tThang: ";cin>>tmp2.namVaoDang.thang;
                    //cout<<endl;
                    cout<<"\t\tNam: ";cin>>tmp2.namVaoDang.nam;
                    cout<<endl;                    
                    cout<<"\t\tLuong: ";cin>>tmp2.luong;
                    cout<<endl;
                    cout<<"\t\tChuc vu: ";cin>>tmp2.chucVu;
                    cout<<endl;
                    if(tmp2.chucVu=="BiThu")
                    {
                        tmp2.tienPhuCap=0.5 * tmp2.luong;
                    }
                    else if(tmp2.chucVu=="PBThu")
                    {
                        tmp2.tienPhuCap=0.25 * tmp2.luong;
                    }
                    else if(tmp2.chucVu=="Uyvien")
                    {
                        tmp2.tienPhuCap=0.15 * tmp2.luong;
                    }
                    else if(tmp2.chucVu=="Dvien")
                    {
                    	tmp2.tienPhuCap = 0;
					}
                    tmp1.tongDangPhiThu += 0.01 * tmp2.luong;
                    tmp1.tongLuong += tmp2.luong;
                    tmp1.tongTroCapChucVu += tmp2.tienPhuCap;

                    tmp1.dv.push_back(tmp2);
                }
                cb.push_back(tmp1);
            }
            printLine(150);
            cout<<"Ban da nhap thanh cong!"<<endl;
            pressAnyKey();
            break;
        }
        
        case 2:
        {
            cout<<"Ban da chon xuat DS Chi bo!"<<endl;
            //printLine(40);
            double tongLuongCacChiBo = 0;
            double tongDangPhiThu = 0;
            double tongNopCapTren = 0;
            for(CB v: cb)
            {
            	printLine(150);
                cout<<"Ten Chi bo: "<<v.tenChiBo<<endl;
                cout<<"So Dang Vien: "<<v.soDangVien<<endl;
                cout<<"Tong Luong: "<<v.tongLuong<<endl;
                cout<<"Tong thu dang phi: "<<v.tongDangPhiThu<<endl;
                cout<<"Tong nop DP cap tren: "<<v.tongDangPhiThu * 0.7<<endl;
                cout<<"Tong tro cap chuc vu: "<<v.tongTroCapChucVu<<endl;
                cout<<"Bang Thu Dang Phi:"<<endl;
                cout << "sothe\t\tHotenDV\t\t\tNgayvaodang\t\tTuoidang\t\tChucvu\t\tTrocap\t\tLuong\tDangPhi\n";
                for(DV u : v.dv)
                {
                    cout << u.soTheDangVien<<"\t\t"<<u.tenDangVien<<"\t\t\t"<<u.namVaoDang.ngay<<"-"<<u.namVaoDang.thang<<"-"<<u.namVaoDang.nam<<"\t\t\t"<<2023 - u.namVaoDang.nam<<"\t\t\t"<<u.chucVu<<"\t\t"<<u.tienPhuCap<<"\t\t"<<u.luong<<"\t"<<u.luong * 0.01<<endl;
                }
                tongLuongCacChiBo += v.tongLuong;
                tongDangPhiThu += v.tongDangPhiThu;
                tongNopCapTren += tongDangPhiThu * 0.3;
            }
            cout<<endl;
            cout<<"Tong Luong cac chi bo: "<<tongLuongCacChiBo<<endl;
            cout<<"Tong Dang Phi thu duoc: "<<tongDangPhiThu<<endl;
            cout<<"Tong nop Cap tren: "<<tongNopCapTren<<endl;
            printLine(150);
            pressAnyKey();
            break;
        }
        case 0:
        {
            cout<<"Ban da chon thoat chuong trinh!"<<endl;
            getch();
            return 0;
        }

        default:
            cout<<"Khong co chuc nang nay"<<endl;
            pressAnyKey();
            break;
        }
    }
    return 0;
}