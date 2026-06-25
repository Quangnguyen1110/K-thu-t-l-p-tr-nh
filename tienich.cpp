
#include <iostream>
#include <cstring>
#include "tienich.h"
using namespace std;


int nhapSoNguyen(const char* thongBao) {
    long gt;
    while (true) {
        cout << thongBao;
        if (cin >> gt) {
            cin.ignore(10000, '\n'); 
            return (int)gt;
        }
        cout << "  -> Gia tri khong hop le, hay nhap lai!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

long nhapSoNguyenDuong(const char* thongBao) {
    while (true) {
        long gt = nhapSoNguyen(thongBao);
        if (gt > 0) return gt;
        cout << "  -> Phai la so nguyen duong!\n";
    }
}

double nhapSoThuc(const char* thongBao) {
    double gt;
    while (true) {
        cout << thongBao;
        if (cin >> gt && gt >= 0) {
            cin.ignore(10000, '\n');
            return gt;
        }
        cout << "  -> Gia tri khong hop le, hay nhap lai!\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void nhapChuoi(const char* thongBao, char* kq, int max) {
    cout << thongBao;
    cin.getline(kq, max);
    chuanHoaChuoi(kq);
}


void chuanHoaChuoi(char* s) {
    int n = (int)strlen(s);
    // cat dau cach o cuoi
    while (n > 0 && (s[n - 1] == ' ' || s[n - 1] == '\t')) {
        s[--n] = '\0';
    }
    // dem so dau cach o dau
    int dau = 0;
    while (s[dau] == ' ' || s[dau] == '\t') dau++;
    if (dau > 0) {
        int i = 0;
        while (s[dau]) s[i++] = s[dau++];
        s[i] = '\0';
    }
}

void doiChuThuong(const char* nguon, char* dich) {
    int i = 0;
    for (; nguon[i]; i++) {
        char c = nguon[i];
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
        dich[i] = c;
    }
    dich[i] = '\0';
}


bool chuaChuoiCon(const char* chuoi, const char* mau) {
    char a[200], b[200];
    doiChuThuong(chuoi, a);
    doiChuThuong(mau, b);
    int la = (int)strlen(a), lb = (int)strlen(b);
    if (lb == 0) return true;
    for (int i = 0; i + lb <= la; i++) {
        int j = 0;
        while (j < lb && a[i + j] == b[j]) j++;
        if (j == lb) return true;
    }
    return false;
}


bool tachNgay(const char* ngay, int& d, int& m, int& y) {
    // ky vong dung 2 dau '/'
    d = m = y = 0;
    int phan = 0; // 0->ngay, 1->thang, 2->nam
    for (int i = 0; ngay[i]; i++) {
        char c = ngay[i];
        if (c == '/') { phan++; if (phan > 2) return false; }
        else if (c >= '0' && c <= '9') {
            if (phan == 0) d = d * 10 + (c - '0');
            else if (phan == 1) m = m * 10 + (c - '0');
            else y = y * 10 + (c - '0');
        } else return false; // ky tu la
    }
    return phan == 2;
}

bool ngayHopLe(const char* ngay) {
    int d, m, y;
    if (!tachNgay(ngay, d, m, y)) return false;
    if (y < 1900 || y > 3000) return false;
    if (m < 1 || m > 12) return false;
    int songay[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    // nam nhuan
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) songay[1] = 29;
    if (d < 1 || d > songay[m - 1]) return false;
    return true;
}


void sapXepChiSo(int* idx, int n, const double* khoa, bool tang) {
    for (int i = 0; i < n - 1; i++) {
        int chon = i;
        for (int j = i + 1; j < n; j++) {
            bool doi = tang ? (khoa[idx[j]] < khoa[idx[chon]])
                            : (khoa[idx[j]] > khoa[idx[chon]]);
            if (doi) chon = j;
        }
        if (chon != i) {
            int t = idx[i]; idx[i] = idx[chon]; idx[chon] = t;
        }
    }
}


int timNhiPhanTheoMa(int* idxDaSapXep, int n, char (*dsMa)[15], const char* ma) {
    int trai = 0, phai = n - 1;
    while (trai <= phai) {
        int giua = (trai + phai) / 2;
        int sosanh = strcmp(dsMa[idxDaSapXep[giua]], ma);
        if (sosanh == 0) return giua;
        if (sosanh < 0) trai = giua + 1;
        else phai = giua - 1;
    }
    return -1;
}
