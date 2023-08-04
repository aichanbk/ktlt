#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

struct Monhoc{
    string MaMH;
    int sotinchi;
    int tcLT;
    int tcBT;
    int tcTH;
    float sotinchihocphi(){
        return this->tcLT + this->tcBT + 1.5*this->tcTH;
    }
    string loaigio(){
        if(this->tcLT && this->tcBT && this->tcTH)
            return "LT-BT-TH";
        else if(this->tcLT && this->tcBT)
            return "LT-BT";
        else if(this->tcLT && this->tcTH)
            return "LT-TH";
        else if(this->tcLT == 0 && this->tcBT == 9 && this->tcTH == 3)
            return "DAMH";
        else if(this->sotinchi == 6)
            return "DATN Cu Nhan";
        else if(this->sotinchi == 12)
            return "DATN Ky su";
    }

    string khoiluong(){
        string khoiluongtmp = to_string(this->sotinchi) + "(" + to_string(this->tcLT) + "-" 
            + to_string(this->tcBT) + "-" + to_string(this->tcTH) + "-" + to_string(this->sotinchi *2) + ")";
        return khoiluongtmp; 
    }

    Monhoc(){};
};

struct Hocvien{
    string Mahv;
    string hotenhv;
    int somonhoc;
    int sotien1tin;
    vector<Monhoc> dsMonhoc;
    int sotiendanop;

    int sotienhoc(){
        int tienhoc = 0;
        for(Monhoc monhoc : dsMonhoc){
            tienhoc += this->sotien1tin * monhoc.sotinchihocphi();
        }
        return  tienhoc;
    };

    string tinhtrangnophp(){
        if(this->sotiendanop - this->sotienhoc() < 0)
            return "Con thieu";
        else
            return "Da nop du";
    }

    Hocvien(){};
};

vector<Hocvien> dsHocvien;

Monhoc nhapmonhoc(){
    Monhoc monhoctmp;
    cout << "\tMa mon hoc: "; cin.ignore(); 
    getline(cin, monhoctmp.MaMH);
    cout << "\tSo tin chi: "; cin >> monhoctmp.sotinchi;
    if(monhoctmp.sotinchi == 6 || monhoctmp.sotinchi == 12){
        monhoctmp.tcLT = 0;
        monhoctmp.tcBT = 0;
        monhoctmp.tcTH = monhoctmp.sotinchi;
    }else{
        cout << "\t\tNhap tin chi LT: ";    cin >> monhoctmp.tcLT;
        cout << "\t\tNhap tin chi BT: ";    cin >> monhoctmp.tcBT;
        cout << "\t\tNhap tin chi TH: ";    cin >> monhoctmp.tcTH;
    }
    return monhoctmp;
}

void NhapdsHocvien(int n){
    for(int i = 0; i < n; i++){
        cout << "\nNhap thong tin sinh vien thu " << i+1 << endl;
        Hocvien hocvien;
        cout << "\tTen sinh vien: "; cin.ignore();  getline(cin, hocvien.hotenhv);
        cout << "\tSo mon hoc: "; cin >> hocvien.somonhoc;
        cout << "\tSo tien mot tin chi: "; cin >> hocvien.sotien1tin;
        for(int j = 0; j < hocvien.somonhoc; j++){
            cout << "\tMon hoc thu " << j+1 <<endl;
            Monhoc monhoc = nhapmonhoc();
            hocvien.dsMonhoc.push_back(monhoc);
        }
        cout << "\tHoc phi da nop: "; cin >> hocvien.sotiendanop;
        dsHocvien.push_back(hocvien);
    }
}

void thongtinMonhoc(Monhoc monhoc, int sotien1tin){
    cout << "\t" << setfill(' ') << left << setw(12) << monhoc.MaMH;
    cout << "\t" << setfill(' ') << left << setw(14) << monhoc.loaigio();
    cout << "\t" << setfill(' ') << left << setw(15) << monhoc.khoiluong();
    cout << "\t" << setfill(' ') << setw(14) << monhoc.sotinchihocphi() * sotien1tin;
    cout << endl;
}

void xuatdsHocvien(){
    for(Hocvien hocvien : dsHocvien){
        cout << "\tTen sv: " << hocvien.hotenhv << endl;
        cout << "\tSo mon hoc: " << hocvien.somonhoc << endl;
        cout << "\tSo tien 1 TC" << hocvien.sotien1tin << endl;
        cout << "\tPhai nop: " << hocvien.sotienhoc() << endl;
        cout << "\tDa nop dot 1: " << hocvien.sotiendanop << endl;
        cout << "\tSo tien thieu: " << hocvien.sotienhoc() - hocvien.sotiendanop << endl;
        cout << "\tTinh trang nop HP: " << hocvien.tinhtrangnophp() << endl;
        cout << "\tChi tiet hoc phi cac mon hoc:" << endl;
        cout << "\t" << setfill(' ') << left << setw(12) << "Ma MH";
        cout << "\t" << setfill(' ') << left << setw(14) << "Loai gio";
        cout << "\t" << setfill(' ') << left << setw(15) <<  "Khoi luong";
        cout << "\t" << setfill(' ') << left << setw(14) << "hocphiphai nop" << endl;
        for(Monhoc monhoc : hocvien.dsMonhoc){
            thongtinMonhoc(monhoc, hocvien.sotien1tin);
        }
    }
}

void menu(){
    cout << "\nVu Van Hao 20215572\n";
    cout << "**     CHUONG TRINH QUAN LY HOC PHI    **\n";
    cout << "**1.   Nhap cac sinh vien, va mon hoc   **\n";
    cout << "**2.   In danh sach hoc vien va hoc phi cac mon**\n";
    cout << "**0.   Thoat                             **\n";
    cout << "*******************************************\n";
    cout << "**         Nhap lua chon cua ban           **\n";
}

int main(){
    int n;  // so chi bo
    cout << "Vu Van Hao 20215572\n";
    cout << "Nhap so sinh vien: "; cin >> n;
    while(1){
        menu();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Ban da chon nhap ds Chi bo Dang vien!\n";
            NhapdsHocvien(n);
            cout << "Ban da nhap thanh cong!";
            break;
        
        case 2:
            cout << "Ban da chon xuat danh sach sinh vien!\n";
            xuatdsHocvien();
            break;
        case 0:
            exit(0);

        default:
            cout << "Hay nhap dung lua chon!!";
        }
        cout << "Bam phim bat ki de tiep tuc!\n";
        cout << "--------------------------------------------------------------------------------------------------------------\n";
        getch();
    }
}