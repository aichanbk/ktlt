#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

typedef struct NhanVien
{
    string MaNV;
    string tenNV;
    int namSinh;
    double heSoLuong;
    string chucDanh;
    int phuCapCongViec;
    double luong;
    double tongLuong;
    double congDoanPhi;
}NV;

typedef struct PhongBan
{
    string tenPB;
    string diaChi;
    int luongToiThieu;
    double tongLuongPhongBan;
    double tongCDPhi;
    int soNhanVien;
    vector<NV> nv;
}PB;

void printLine(int n)
{
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"-";
    }
    cout<<endl;
}

void pressAnyKey()
{
    cout<<endl;
    cout<<"Bam phim bat ky de tiep tuc!"<<endl;
    getch();
    system("cls");
}

int main()
{
    vector<PB> pb;
    int n;
    cout<<"Nguyen Thanh Ha - 20210298"<<endl;
    cout<<"Nhap so phong ban: ";
    cin>>n;
    while (true)
    {
        cout<<"Nguyen Thanh Ha - 20210298"<<endl;
        cout<<"**   Chuong trinh quan ly Phong ban - Nhan vien   **"<<endl;
        cout<<"**1. Nhap cac Phong Ban               **"<<endl;
        cout<<"**2. In ket qua ds phong ban va nhan vien**"<<endl;
        cout<<"**3. Thoat                               **"<<endl;
        cout<<"**********************************************"<<endl;
        cout<<"**        Nhap lua chon cua ban            **"<<endl;
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            cout<<"Ban da chon nhap ds phong ban nhan vien!"<<endl;
            for (int i = 1; i <= n; i++)
            {
                PB tmp1;
                cout<<"Nhap thong tin phong ban thu "<<i<<endl;
                cout<<"\tTen Phong Ban: "; cin>>tmp1.tenPB;
                cout<<endl;
                cout<<"\tDia chi: "; cin>>tmp1.diaChi;
                cout<<endl;
                cout<<"\tLuong toi thieu: "; cin>>tmp1.luongToiThieu;
                cout<<endl;
                cout<<"\tSo nhan vien: "; cin>>tmp1.soNhanVien;
                cout<<endl;
                cout<<"\tNhap danh sach Nhan vien:"<<endl;
                for (int j = 1; j <= tmp1.soNhanVien; j++)
                {
                    NV tmp2;
                    cout<<"\tNhan vien thu "<< j << endl;
                    cout<<"\t\tMa Nhan Vien: "; cin>>tmp2.MaNV;
                    cout<<endl;
                    cout<<"\t\tHo va ten Nhan vien: ";
                    fflush(stdin);
                    getline(cin,tmp2.tenNV);
                    cout<<endl;
                    cout<<"\t\tNhap nam sinh: "; cin>>tmp2.namSinh;
                    cout<<endl;
                    cout<<"\t\tNhap HS Luong: "; cin>>tmp2.heSoLuong;
                    cout<<endl;
                    cout<<"\t\tNhap chuc danh: "; cin>>tmp2.chucDanh;
                    if (tmp2.chucDanh=="PVCC")
                    {
                        tmp2.phuCapCongViec = 2000;
                    }else if(tmp2.chucDanh=="GVC"){
                        tmp2.phuCapCongViec = 1500;
                    }else if(tmp2.chucDanh == "GV"){
                        tmp2.phuCapCongViec = 1000;
                    }else if(tmp2.chucDanh == "CBKT"){
                        tmp2.phuCapCongViec = 750;
                    }else if(tmp2.chucDanh == "CBHC"){
                        tmp2.phuCapCongViec = 500;
                    }
                    tmp2.luong = tmp2.heSoLuong * tmp1.luongToiThieu;
                    tmp2.tongLuong = tmp2.luong + tmp2.phuCapCongViec;
                    tmp2.congDoanPhi = 0.01 * tmp2.tongLuong;

                    tmp1.tongLuongPhongBan += tmp2.luong;
                    tmp1.tongCDPhi += tmp2.congDoanPhi;

                    tmp1.nv.push_back(tmp2);
                }
                pb.push_back(tmp1);
            }
            printLine(150);
            cout<<"Ban da nhap thanh cong!"<<endl;
            pressAnyKey();
            break;
        }
        
        case 2:
        {
            printLine(150);
            cout<<"Ban da chon xuat DS Phong ban!"<<endl;
            cout<<endl;
            double tongLuongPhongBan;
            double tongCongDoanPhi;
            for (PB v: pb)
            {
                cout<<"Ten phong ban: "<<v.tenPB<<endl;
                cout<<"Dia chi: "<<v.diaChi<<endl;
                cout<<"Luong TT: "<<v.luongToiThieu<<endl;
                cout<<"Tong Luong Phong Ban: "<<v.tongLuongPhongBan<<endl;
                cout<<"Tong Cong Doan Phi: "<<v.tongCDPhi<<endl;
                cout<<"Bang luong nhan vien"<<endl;
                cout<<"MaNV\t\tHotenNV\t\t\t\tChucDanh\t\tPCCV\t\tHeSoLuong\tLuong\tCongDoanPhi\t\tConNhan"<<endl;
                for(NV u : v.nv)
                {
                    cout<<u.MaNV<<"\t\t"<<u.tenNV<<"\t\t\t"<<u.chucDanh<<"\t\t\t"<<u.phuCapCongViec<<"\t\t"<<u.heSoLuong<<"\t\t"<<u.luong<<"\t"<<u.congDoanPhi<<"\t\t\t\t"<<u.luong-u.congDoanPhi<<endl;
                }
                printLine(150);
            }
            cout<<endl;
            pressAnyKey();
            break;
        }

        case 0: {
            cout<<"Ban da chon thoat chuong trinh!";
            getch();
            return 0;
        }
        default:{
            cout<<"Khong co chuc nang nay!"<<endl;
            pressAnyKey();
            break;
        	}
        }
    }
    
    return 0;
}