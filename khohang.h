
#ifndef KHOHANG_H
#define KHOHANG_H


const int MAX_CHUOI   = 60;   
const int MAX_MA      = 15;   
const int MAX_NGAY    = 11;   

struct SanPham {
    char maSP[MAX_MA];          
    char tenSP[MAX_CHUOI];      
    char loaiHang[MAX_CHUOI];    
    char donViTinh[20];          
    long soLuongTon;            
    double donGia;             
    long nguongToiThieu;      
};

struct GiaoDich {
    char maGD[MAX_MA];         
    char maSP[MAX_MA];         
    char loai;                
    long soLuong;               
    double donGia;             
    char ngay[MAX_NGAY];       
};


struct Kho {
    SanPham*  dsSP;      
    int       soSP;       
    int       dungLuongSP;

    GiaoDich* dsGD;      
    int       soGD;
    int       dungLuongGD;
};


void khoiTaoKho(Kho& k);
void giaiPhongKho(Kho& k);


void docDuLieu(Kho& k);
void luuDuLieu(const Kho& k);


void themSanPham(Kho& k);
void suaSanPham(Kho& k);
void xoaSanPham(Kho& k);
void hienThiTatCa(const Kho& k);


int  timTheoMa(const Kho& k, const char* ma);  
void timKiemSanPham(const Kho& k);


void nhapKho(Kho& k);
void xuatKho(Kho& k);


void canhBaoSapHet(const Kho& k);
void nhatKyTheoThang(const Kho& k);
void thongKeGiaTriTon(const Kho& k);

#endif
