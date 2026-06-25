
#ifndef TIENICH_H
#define TIENICH_H


int    nhapSoNguyen(const char* thongBao);      
long   nhapSoNguyenDuong(const char* thongBao);  
double nhapSoThuc(const char* thongBao);         
void   nhapChuoi(const char* thongBao, char* kq, int max); 


void   chuanHoaChuoi(char* s);                    
void   doiChuThuong(const char* nguon, char* dich);
bool   chuaChuoiCon(const char* chuoi, const char* mau); 

// ---- Xu ly ngay dd/mm/yyyy ----
bool   ngayHopLe(const char* ngay);
bool   tachNgay(const char* ngay, int& d, int& m, int& y);


void   sapXepChiSo(int* idx, int n, const double* khoa, bool tang); 
int    timNhiPhanTheoMa(int* idxDaSapXep, int n, char (*dsMa)[15], const char* ma);

#endif
