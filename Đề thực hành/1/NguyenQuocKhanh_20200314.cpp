#include <bits/stdc++.h>
#include <string>
#include <conio.h>
using namespace std;

typedef struct Dangvien
{
    string sotheDangVien;
    string tendangvien;
    int ngayvaodang;
    int thangvaodang;
    int namvaodang;
    double luong;
    string chucvu;
    double tienphucap;
} DV;

typedef struct ChiBo
{
    string tenChiBo;
    string diaChi;
    int soDangVien;
    double Tongluong;
    double tongdangphithu;
    double tongtrocapchucvu;
    vector <DV> dv;
} CB;

void printLine(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

void pressAnyKey(){
	    cout<<endl;
     	cout<<"Nhan phim bat ki de tiep tuc" << endl;
		getch();
		system("cls"); //Xoa man hinh ban dau cho de nhin
}


int main()
{
    vector<CB> cb;
    cout << "Nguyen Quoc Khanh 20200314\n";
    int n; // so chi bo
    cout << "Nhap so Chi Bo:";
    cin >> n;
    while(true)
    {
        cout << "Nguyen Quoc Khanh 20200314\n";
        cout << "**  CHUONG TRINH QUAN LY Chi bo - Dang Vien  **" << endl
             << "**1. Nhap cac Chi bo                 **" << endl
             << "**2. In ket qua ds Chi bo Dang vien**" << endl
             << "**0. Thoat                              **" << endl
             << "*******************************************" << endl
             << "**         Nhap lua chon cua ban        **\n";
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 1:
            {
                cout << "Ban da chon nhap ds Chi bo Dang vien!\n";
                printLine(40);
                for (int i=1; i<=n;i++)
                {
                    CB tmp1;
                    tmp1.tongdangphithu = 0;
                    tmp1.Tongluong = 0;
                    tmp1.tongtrocapchucvu = 0;
                    cout << "Nhap thong tin Chi Bo thu " << i << ": \n";
                    cout << "\tTen Chi Bo: ";
                    cin >> tmp1.tenChiBo;
                    cout << endl;
                    cout << "\tSo dang vien: ";
                    cin >> tmp1.soDangVien;
                    cout << endl;
                    cout << "\tNhap ds Dang vien:\n";
                    for (int i=1; i<=tmp1.soDangVien; i++)
                    {
                        DV tmp2;
                        cout << "\tDang vien thu " << i << endl;
                        cout << "\t\tso the: ";
                        cin >> tmp2.sotheDangVien;
                        cout << endl;
                        cout << "\t\tTen Dang vien: ";
                        fflush(stdin);
                        getline(cin, tmp2.tendangvien);
                        cout << endl;
                        cout << "\t\tNgay vao dang: ";
                        cout << endl;
                        cout << "\t\tNgay: ";
                        cin >> tmp2.ngayvaodang;
                        cout << endl;
                        cout << "\t\tThang: ";
                        cin >> tmp2.thangvaodang;
                        cout << endl;
                        cout << "\t\tNam: ";
                        cin >> tmp2.namvaodang;
                        cout << endl;
                        cout << "\t\tLuong: ";
                        cin >> tmp2.luong;
                        cout << endl;
                        cout << "\t\tChuc vu: ";
                        cin >> tmp2.chucvu;
                        cout << endl;
                        if(tmp2.chucvu=="BiThu")
                        {
                            tmp2.tienphucap = 0.5*tmp2.luong;
                        } else if (tmp2.chucvu == "PBThu")
                        {
                            tmp2.tienphucap = 0.25*tmp2.luong;
                        } else if(tmp2.chucvu == "Uyvien")
                        {
                            tmp2.tienphucap = 0.15*tmp2.luong;
                        } else if (tmp2.chucvu == "Dvien")
                        {
                            tmp2.tienphucap = 0;
                        }

                        // tinh tong dang phi thu
                        tmp1.tongdangphithu += 0.01*tmp2.luong;
                        tmp1.Tongluong += tmp2.luong;
                        tmp1.tongtrocapchucvu += tmp2.tienphucap;

                        tmp1.dv.push_back(tmp2);
                    }
                    // them cac phong ban vao danh sach
                    cb.push_back(tmp1);
                }
                printLine(40);
                cout << "Ban da nhap thanh cong\n";
                pressAnyKey();
                break;
            }
        case 2:
            {
                cout << "Ban da chon xuat DS Chi bo !\n";
                printLine(40);
                for(CB v: cb)
                {
                    cout << " Ten Chi bo: " << v.tenChiBo << endl;
                    cout << "so Dang Vien: " << v.soDangVien << endl;
                    cout << "Tong Luong: " << v.Tongluong << endl;
                    cout << "Tong thu Dang phi: " << v.tongdangphithu << endl;
                    cout << "Tong nop DP cap tren: " << v.tongdangphithu*0.3 << endl;
                    cout << "Tong tro cap Chuc vu:"<< v.tongtrocapchucvu << endl;
                    cout << "Bang bang Thu Dang Phi\n";
                    cout << "sothe\t\tHotenDV\t\t\tNgayvaodang\tTuoidang\t\tChucvu\t\tTrocap\t\tLuong\tDangPhi\n";
                    for (DV u: v.dv)
                    {
                        cout << u.sotheDangVien <<"\t\t"<< u.tendangvien	 << "\t\t" << u.ngayvaodang <<"-"<< u.thangvaodang <<"-" << u.namvaodang << "\t\t" << 2022 - u.namvaodang << "\t\t" << u.chucvu << "\t\t"<< u.tienphucap << "\t\t" << u.luong <<" \t"<< 0.01*u.luong <<endl;
                    }
                }
                printLine(40);
                pressAnyKey();
                break;
            }
        case 0:
            {
            	cout<<"Ban da chon thoat chuong trinh!";
            	getch();
                return 0;
            }
        default:
				cout << "Khong co chuc nang nay" << endl;
				pressAnyKey();
				break;
        }
    }
}
