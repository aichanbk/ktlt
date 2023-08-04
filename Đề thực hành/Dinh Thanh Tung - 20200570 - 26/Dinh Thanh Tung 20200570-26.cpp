#include <bits/stdc++.h>
#include <string>
#include <conio.h>
#include <vector>
using namespace std;

typedef struct NhanVien {
	string MaNV;
	string Hoten;
	int Namsinh;
	double Hesoluong;
	double Luong;
	string Chucdanh;
	double PCCV;
	double Tongluong;
	double Congdoanphi;
} NV;

typedef struct PhongBan {
	string Ten;
	string Diachi;
	int Soluongnv;
	double LuongToithieu;
	double TongluongPB; 
    double TongCDphi;
	vector <NV> nv;
} PB;

void pressAnyKey(){
	    cout<<endl;
     	cout<<"Nhan phim bat ky de tiep tuc" << endl;
		getch();
		system("cls"); //Xoa man hinh ban dau
}

int main(){
	vector <PB> pb;
    cout << "Dinh Thanh Tung - 20200570-20221-IT3040-721436-26\n";
    cout << "Nhap so phong ban: ";
    int n; // so phong ban
    cin >> n;
    while(true){
    	cout << "Dinh Thanh Tung - 20200570-20221-IT3040-721436-26\n";
        cout << "**  CHUONG TRINH QUAN LY Phong Ban - Nhan vien  **" << endl
             << "**1. Nhap cac Phong ban                 **" << endl
             << "**2. In ket qua ds phong ban va Nhan vien**" << endl
             << "**0. Thoat                              **" << endl
             << "*******************************************" << endl
             << "**         Nhap lua chon cua ban        **\n";
        int choice; 
        cin >> choice;
        switch(choice){
        	case 1:{
        		cout << "Ban da chon nhap ds phong ban nhan vien!\n";
                cout << endl;
                for (int i=1; i<=n;i++)
                {
                    PB tmp1;
                    cout << "Nhap thong tin phong ban thu " << i << ": \n";
                    cout << "\tTen Phong Ban: ";
                    cin >> tmp1.Ten;
                    cout << endl;
                    cout << "\tDia chi: ";
                    cin >> tmp1.Diachi;
                    cout << endl;
                    cout << "\tLuong toi thieu:";
                    cin >> tmp1.LuongToithieu;
                    cout << endl;
                    cout << "\tSo nhan vien:";
                    cin >> tmp1.Soluongnv;
                    cout << endl;
                    cout << "\tNhap ds Nhan vien:\n";
                    for (int i=1; i<=tmp1.Soluongnv; i++)
                    {
                        NV tmp2;
                        cout << "\tNhan vien thu " << i << endl;
                        cout << "\t\tMaNv:";
                        cin >> tmp2.MaNV;
                        cout << endl;
                        cout << "\t\tHo ten Nhan vien:";
                        fflush(stdin);
                        getline(cin, tmp2.Hoten);
                        cout << endl;
                        cout << "\t\tNhap Nam sinh:";
                        cin >> tmp2.Namsinh;
                        cout << endl;
                        cout << "\t\tNhap HS Luong:";
                        cin >> tmp2.Hesoluong;
                        cout << endl;
                        cout << "\t\tNhap chuc danh:";
                        cin >> tmp2.Chucdanh;
                        cout << endl;
                        if(tmp2.Chucdanh == "GVCC")
                        {
                            tmp2.PCCV = 2000;
                        } else if (tmp2.Chucdanh == "GVC")
                        {
                            tmp2.PCCV = 1500;
                        } else if (tmp2.Chucdanh == "GV")
                        {
                            tmp2.PCCV = 1000;
                        } else if (tmp2.Chucdanh == "CBKT")
                        {
                            tmp2.PCCV = 750;
                        } else if (tmp2.Chucdanh == "CBHC")
						{
							tmp2.PCCV = 500;
						}
						tmp2.Luong = tmp2.Hesoluong * tmp1.LuongToithieu;
						tmp2.Tongluong = tmp2.Luong + tmp2.PCCV;
						tmp2.Congdoanphi = 0.01 * tmp2.Tongluong;
                        // tinh Tong Luong PB va Tong CD Phi
                        tmp1.TongluongPB += tmp2.Luong;
                        tmp1.TongCDphi += tmp2.Congdoanphi;

                        tmp1.nv.push_back(tmp2);
                    }
                    // them cac phong ban vao danh sach
                    pb.push_back(tmp1);
                }
                cout << endl;
                cout << "Ban da nhap thanh cong\n";
                pressAnyKey();
				break;
			}
			case 2:{
                cout << "Ban da chon xuat DS Phong ban, !\n";
                cout << endl;
                for(PB v: pb)
                {
                    cout << "Ten phong ban: " << v.Ten << endl;
                    cout << "dia chi:" << v.Diachi << endl;
                    cout << "Luong TT:" << v.LuongToithieu << endl;
                    cout << "Tong Luong PB:" << v.TongluongPB << endl;
                    cout << "Tong CD Phi:" << v.TongCDphi << endl;
                    cout << "Bang Luong Nhan vien\n";
                    cout << "MaNV\t\tHotenNV\t\t\tChucdanh\tPCCV\t\tHesoL\t\tLuong\t\tCDP\tCon nhan\n";
                    cout << endl;
                    for (NV u: v.nv)
                    {
                        cout << u.MaNV << "\t\t" << u.Hoten << "\t\t\t" << u.Chucdanh << "\t\t" << u.PCCV << "\t\t\t" << u.Hesoluong << "\t\t"<< u.Luong << "\t\t" << u.Congdoanphi <<" \t"<< u.Luong - u.Congdoanphi <<endl;
                    }
                }
                cout << endl;
                pressAnyKey();
                break;
            }
            case 0:{
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








