#include<iostream>
#include<iomanip>
#include<string.h>
#include<vector>
#include<conio.h>
using namespace std;

struct DangVien{
    int sothedv;
    string tendangvien;
    struct ngayvaodang{
        int ngay;
        int thang;
        int nam;
    } ngayvaodang;
    string chucvudang;
    int Luong;
    //dang phi = 1% Luong
    //phu cap : BT 'BiThu' 0.5%, PBT 'Pbthu' 0.25%, UV 'UyVien' 0.15%, DV 'Dvien'
    // DangVien(int sothedv, string tendangvien, int ngay, int thang, int nam, string chucvudang, int Luong){
    //     this->sothedv = sothedv;
    //     this->tendangvien  = tendangvien;
    //     this->ngayvaodang.ngay = ngay;
    //     this->ngayvaodang.thang =  thang;
    //     this->ngayvaodang.nam = nam;
    //     this->Luong = Luong;
    // };
    DangVien(){};

    float tienphucap(){
        if(this->chucvudang == "BiThu"){
            return 0.005 * (this->Luong);
        }else if(this->chucvudang == "Pbthu"){
            return 0.0025 * (this->Luong);
        }else if(this->chucvudang == "Uyvien"){
            return 0.0015 * (this->Luong);
        }else return 0;
    }

    string layngayvaodang(){
        string ngay = to_string(ngayvaodang.ngay) + "-" + to_string(ngayvaodang.thang) + "-" + to_string(ngayvaodang.nam);
        return ngay;
    }


};

struct chibo{
    string TenCB;
    string diachi;
    int sodangvien;
    vector<DangVien> danhsachDangVien;
    //Chi Bo giu lai = 30% TongDangPhiThu
    //nop cap tren = 70% TongDangPhiThu
    int TongLuong(){
        float tongluong = 0;
        for(DangVien Dangvien : (this->danhsachDangVien)){
            tongluong += Dangvien.Luong;
        }
    }
    float TongDangPhiThu(){
        float tongdangphithu = 0;
        for(DangVien Dangvien : danhsachDangVien){
            tongdangphithu += Dangvien.Luong * 0.01;
        }
        return tongdangphithu;
    }
    float TongTroCapChucVu(){
        float tongtrocap = 0;
        for(DangVien dangvien : danhsachDangVien){
            tongtrocap += dangvien.tienphucap();
        }
        return tongtrocap;
    }

    chibo(){};

    chibo(string TenCB, int sodangvien, vector<DangVien> danhsachDangVien){
        this->TenCB = TenCB;
        this->sodangvien = sodangvien;
        this->danhsachDangVien = danhsachDangVien;
    }
    
};

vector<chibo> dsChibo;

DangVien nhapdangvien(){
    DangVien dangvientmp;
    cout << "so the: "; cin >> dangvientmp.sothedv;
    cin.ignore();
    cout << "Ten Dang vien: "; getline(cin, dangvientmp.tendangvien);
    cin.ignore();
    cout << "Ngay vao dang:\n";
    cout << "Ngay: "; cin >> (dangvientmp.ngayvaodang.ngay);
    cout << "Thang: "; cin >> (dangvientmp.ngayvaodang.thang);
    cout << "Nam: "; cin >> (dangvientmp.ngayvaodang.nam);
    cout << "Luong: "; cin >> dangvientmp.Luong;
    cout << "Chuc vu: "; cin >> dangvientmp.chucvudang;
    cout << endl;
    return dangvientmp;
}

void nhapcacchibo(int n){
    for(int i = 0; i < n; i++){
        chibo chibotmp;
        cout << "Nhap thong tin chi bo thu " << i+1 << " :\n";
        cout << "Ten Chi bo: "; cin >> chibotmp.TenCB;
        cout << "So dang vien: "; cin >> chibotmp.sodangvien;
        vector<DangVien> danhsachdangvien;
        for(int j = 0; j < chibotmp.sodangvien; j++){
            cout << "Dang vien thu " << j+1 << "\n";
            DangVien dangvientmp = nhapdangvien();
           danhsachdangvien.push_back(dangvientmp);
        }
        chibotmp.danhsachDangVien = danhsachdangvien;
        dsChibo.push_back(chibotmp);
    }
    cout << "Ban da nhap thanh cong!";
}

void inThongtinDangvien(DangVien dangvien){
    cout << setfill(' ') << left << setw(10) << dangvien.sothedv;
    cout << setfill(' ') << left << setw(25) << dangvien.tendangvien;
    cout << setfill(' ') << left << setw(16) << dangvien.layngayvaodang();
    cout << setfill(' ') << left << setw(12) << 2023 - dangvien.ngayvaodang.nam;
    cout << setfill(' ') << left << setw(12) << dangvien.chucvudang;
    cout << setfill(' ') << left << setw(12) << dangvien.tienphucap();
    cout << setfill(' ') << left << setw(12) << dangvien.Luong;
    cout << setfill(' ') << left << setw(12) << 0.01 * (dangvien.Luong);
    cout << endl;
}

void xuatds(){
    for(chibo chibotmp : dsChibo){
        cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\nTen Chi bo: " << chibotmp.TenCB << endl;
        cout << "So Dang vien: " << chibotmp.sodangvien << endl;
        cout << "Tong Luong: " << chibotmp.TongLuong() << endl;
        cout << "Tong thu Dang Phi: " << chibotmp.TongDangPhiThu() << endl;
        cout << "Tong nop DP cap tren: " << 0.7 *  (chibotmp.TongDangPhiThu());
        cout << "Tong tro cap chuc vu: " << chibotmp.TongTroCapChucVu() << endl;
        cout << "Bang Bang thu Dang Phi: \n";
        cout << setfill(' ') << left << setw(10) << "sothe";
        cout << setfill(' ') << left << setw(25) << "HotenDV";
        cout << setfill(' ') << left << setw(16) << "Ngayvaodang";
        cout << setfill(' ') << left << setw(12) << "Tuoidang";
        cout << setfill(' ') << left << setw(12) << "Chucvu";
        cout << setfill(' ') << left << setw(12) << "Trocap";
        cout << setfill(' ') << left << setw(12) << "Luong";
        cout << setfill(' ') << left << setw(12) << "Dangphi\n";
        for(DangVien dangvientmp : chibotmp.danhsachDangVien){
            inThongtinDangvien(dangvientmp);
        }
    }
}

void menu(){
    cout << "Vu Van Hao 20215572\n";
    cout << "**     CHUONG TRINH QUAN LY Chi bo - Dang vien     **\n";
    cout << "**1. Nhap cac chi bo       **\n";
    cout << "**2. In danh sach ket qua Chi bo Dang vien**\n";
    cout << "**0. Thoat                             **\n";
    cout << "*******************************************\n";
    cout << "**         Nhap lua chon cua ban           **\n";
}

int main(){
    int n;  // so chi bo
    cout << "Vu Van Hao 20215572\n";
    cout << "Nhap so Chi Bo: "; cin >> n;
    while(1){
        menu();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Ban da chon nhap ds Chi bo Dang vien!\n";
            nhapcacchibo(n);
            break;
        
        case 2:
            cout << "Ban da chon xuat DS Chi Bo!\n";
            xuatds();
            break;
        case 0:
            exit(0);

        default:
            cout << "Hay nhap dung lua chon!!";
        }
        cout << "Bam phim bat ki de tiep tuc!\n";
        getch();
    }
}