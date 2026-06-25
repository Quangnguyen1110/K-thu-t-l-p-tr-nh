
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "khohang.h"
#include "tienich.h"
using namespace std;

const char* FILE_SP = "data/sanpham.txt";
const char* FILE_GD = "data/giaodich.txt";


void khoiTaoKho(Kho& k) {
    k.dungLuongSP = 8;
    k.dsSP = new SanPham[k.dungLuongSP];
    k.soSP = 0;

    k.dungLuongGD = 8;
    k.dsGD = new GiaoDich[k.dungLuongGD];
    k.soGD = 0;
}

void giaiPhongKho(Kho& k) {
    delete[] k.dsSP;
    delete[] k.dsGD;
    k.dsSP = nullptr;
    k.dsGD = nullptr;
}

static void moRongSP(Kho& k) {
    if (k.soSP < k.dungLuongSP) return;
    int moi = k.dungLuongSP * 2;
    SanPham* tmp = new SanPham[moi];
    for (int i = 0; i < k.soSP; i++) tmp[i] = k.dsSP[i];
    delete[] k.dsSP;
    k.dsSP = tmp;
    k.dungLuongSP = moi;
}

static void moRongGD(Kho& k) {
    if (k.soGD < k.dungLuongGD) return;
    int moi = k.dungLuongGD * 2;
    GiaoDich* tmp = new GiaoDich[moi];
    for (int i = 0; i < k.soGD; i++) tmp[i] = k.dsGD[i];
    delete[] k.dsGD;
    k.dsGD = tmp;
    k.dungLuongGD = moi;
}


static int tachTruong(const string& dong, char truong[][MAX_CHUOI], int max) {
    int so = 0, vt = 0;
    for (int i = 0; i <= (int)dong.size() && so < max; i++) {
        char c = (i < (int)dong.size()) ? dong[i] : '|';
        if (c == '|') {
            truong[so][vt] = '\0';
            so++; vt = 0;
        } else if (vt < MAX_CHUOI - 1) {
            truong[so][vt++] = c;
        }
    }
    return so;
}

void docDuLieu(Kho& k) {
    ifstream f1(FILE_SP);
    if (f1) {
        string dong;
        char tr[7][MAX_CHUOI];
        while (getline(f1, dong)) {
            if (dong.empty()) continue;
            if (tachTruong(dong, tr, 7) < 7) continue;
            moRongSP(k);
            SanPham& s = k.dsSP[k.soSP];
            strncpy(s.maSP, tr[0], MAX_MA);          s.maSP[MAX_MA - 1] = '\0';
            strncpy(s.tenSP, tr[1], MAX_CHUOI);       s.tenSP[MAX_CHUOI - 1] = '\0';
            strncpy(s.loaiHang, tr[2], MAX_CHUOI);    s.loaiHang[MAX_CHUOI - 1] = '\0';
            strncpy(s.donViTinh, tr[3], 20);          s.donViTinh[19] = '\0';
            s.soLuongTon    = atol(tr[4]);
            s.donGia        = atof(tr[5]);
            s.nguongToiThieu = atol(tr[6]);
            k.soSP++;
        }
        f1.close();
    }

    ifstream f2(FILE_GD);
    if (f2) {
        string dong;
        char tr[6][MAX_CHUOI];
        while (getline(f2, dong)) {
            if (dong.empty()) continue;
            if (tachTruong(dong, tr, 6) < 6) continue;
            moRongGD(k);
            GiaoDich& g = k.dsGD[k.soGD];
            strncpy(g.maGD, tr[0], MAX_MA);  g.maGD[MAX_MA - 1] = '\0';
            strncpy(g.maSP, tr[1], MAX_MA);  g.maSP[MAX_MA - 1] = '\0';
            g.loai    = tr[2][0];
            g.soLuong = atol(tr[3]);
            g.donGia  = atof(tr[4]);
            strncpy(g.ngay, tr[5], MAX_NGAY); g.ngay[MAX_NGAY - 1] = '\0';
            k.soGD++;
        }
        f2.close();
    }
}

void luuDuLieu(const Kho& k) {
    ofstream f1(FILE_SP);
    for (int i = 0; i < k.soSP; i++) {
        const SanPham& s = k.dsSP[i];
        f1 << s.maSP << '|' << s.tenSP << '|' << s.loaiHang << '|'
           << s.donViTinh << '|' << s.soLuongTon << '|'
           << s.donGia << '|' << s.nguongToiThieu << '\n';
    }
    f1.close();

    ofstream f2(FILE_GD);
    for (int i = 0; i < k.soGD; i++) {
        const GiaoDich& g = k.dsGD[i];
        f2 << g.maGD << '|' << g.maSP << '|' << g.loai << '|'
           << g.soLuong << '|' << g.donGia << '|' << g.ngay << '\n';
    }
    f2.close();
}


int timTheoMa(const Kho& k, const char* ma) {
    for (int i = 0; i < k.soSP; i++)
        if (strcmp(k.dsSP[i].maSP, ma) == 0) return i;
    return -1;
}


void themSanPham(Kho& k) {
    SanPham s;
    cout << "\n--- THEM SAN PHAM ---\n";
    nhapChuoi("Ma san pham: ", s.maSP, MAX_MA);
    if (timTheoMa(k, s.maSP) != -1) {
        cout << "  -> Ma '" << s.maSP << "' da ton tai!\n";
        return;
    }
    nhapChuoi("Ten san pham: ", s.tenSP, MAX_CHUOI);
    nhapChuoi("Loai hang   : ", s.loaiHang, MAX_CHUOI);
    nhapChuoi("Don vi tinh : ", s.donViTinh, 20);
    s.soLuongTon     = nhapSoNguyen("So luong ton ban dau: ");
    s.donGia         = nhapSoThuc("Don gia (VND): ");
    s.nguongToiThieu = nhapSoNguyen("Nguong ton toi thieu: ");

    moRongSP(k);
    k.dsSP[k.soSP++] = s;
    cout << "=> Da them san pham.\n";
}

void suaSanPham(Kho& k) {
    char ma[MAX_MA];
    cout << "\n--- SUA SAN PHAM ---\n";
    nhapChuoi("Nhap ma can sua: ", ma, MAX_MA);
    int vt = timTheoMa(k, ma);
    if (vt == -1) { cout << "  -> Khong tim thay san pham!\n"; return; }

    SanPham& s = k.dsSP[vt];
    cout << "Thong tin hien tai: " << s.tenSP << " | ton " << s.soLuongTon
         << " | don gia " << s.donGia << "\n";
    cout << "(Nhap thong tin moi)\n";
    nhapChuoi("Ten san pham: ", s.tenSP, MAX_CHUOI);
    nhapChuoi("Loai hang   : ", s.loaiHang, MAX_CHUOI);
    nhapChuoi("Don vi tinh : ", s.donViTinh, 20);
    s.donGia         = nhapSoThuc("Don gia (VND): ");
    s.nguongToiThieu = nhapSoNguyen("Nguong ton toi thieu: ");
    cout << "=> Da cap nhat (so luong ton chi thay doi qua nhap/xuat kho).\n";
}

void xoaSanPham(Kho& k) {
    char ma[MAX_MA];
    cout << "\n--- XOA SAN PHAM ---\n";
    nhapChuoi("Nhap ma can xoa: ", ma, MAX_MA);
    int vt = timTheoMa(k, ma);
    if (vt == -1) { cout << "  -> Khong tim thay san pham!\n"; return; }

    // don cac phan tu phia sau len 1 vi tri
    for (int i = vt; i < k.soSP - 1; i++) k.dsSP[i] = k.dsSP[i + 1];
    k.soSP--;
    cout << "=> Da xoa san pham '" << ma << "'.\n";
}


static void inMotDong(const SanPham& s) {
    cout << left << setw(8)  << s.maSP
         << setw(22) << s.tenSP
         << setw(16) << s.loaiHang
         << setw(8)  << s.donViTinh
         << right << setw(8) << s.soLuongTon
         << setw(14) << fixed << setprecision(0) << s.donGia
         << setw(8) << s.nguongToiThieu << "\n";
}

static void inTieuDeBang() {
    cout << left << setw(8) << "Ma" << setw(22) << "Ten SP"
         << setw(16) << "Loai" << setw(8) << "DVT"
         << right << setw(8) << "Ton" << setw(14) << "Don gia"
         << setw(8) << "Nguong" << "\n";
    cout << string(84, '-') << "\n";
}

void hienThiTatCa(const Kho& k) {
    cout << "\n--- DANH SACH SAN PHAM TRONG KHO ---\n";
    if (k.soSP == 0) { cout << "(Kho trong)\n"; return; }
    inTieuDeBang();
    for (int i = 0; i < k.soSP; i++) inMotDong(k.dsSP[i]);
    cout << "Tong so mat hang: " << k.soSP << "\n";
}

void timKiemSanPham(const Kho& k) {
    cout << "\n--- TIM KIEM SAN PHAM ---\n";
    cout << "1. Theo ma\n2. Theo ten (chua tu khoa)\n";
    int chon = nhapSoNguyen("Chon: ");

    if (chon == 1) {
        char ma[MAX_MA];
        nhapChuoi("Nhap ma: ", ma, MAX_MA);
        int vt = timTheoMa(k, ma);
        if (vt == -1) { cout << "Khong tim thay.\n"; return; }
        inTieuDeBang();
        inMotDong(k.dsSP[vt]);
    } else if (chon == 2) {
        char tu[MAX_CHUOI];
        nhapChuoi("Nhap tu khoa: ", tu, MAX_CHUOI);
        int dem = 0;
        inTieuDeBang();
        for (int i = 0; i < k.soSP; i++)
            if (chuaChuoiCon(k.dsSP[i].tenSP, tu)) { inMotDong(k.dsSP[i]); dem++; }
        cout << "Tim thay " << dem << " ket qua.\n";
    } else {
        cout << "Lua chon khong hop le.\n";
    }
}

static void sinhMaGD(const Kho& k, char* kq) {
    int maxSo = 0;
    for (int i = 0; i < k.soGD; i++) {
        // bo qua 2 ky tu dau "GD", phan con lai la so
        long so = atol(k.dsGD[i].maGD + 2);
        if (so > maxSo) maxSo = (int)so;
    }
    int moi = maxSo + 1;
    // dinh dang GDxxxx
    kq[0] = 'G'; kq[1] = 'D';
    kq[2] = '0' + (moi / 1000) % 10;
    kq[3] = '0' + (moi / 100) % 10;
    kq[4] = '0' + (moi / 10) % 10;
    kq[5] = '0' + moi % 10;
    kq[6] = '\0';
}

void nhapKho(Kho& k) {
    char ma[MAX_MA];
    cout << "\n--- NHAP KHO ---\n";
    nhapChuoi("Ma san pham can nhap: ", ma, MAX_MA);
    int vt = timTheoMa(k, ma);
    if (vt == -1) { cout << "  -> San pham chua co trong danh muc!\n"; return; }

    GiaoDich g;
    sinhMaGD(k, g.maGD);
    strcpy(g.maSP, ma);
    g.loai = 'N';
    g.soLuong = nhapSoNguyenDuong("So luong nhap: ");
    g.donGia  = nhapSoThuc("Don gia nhap (VND): ");
    do {
        nhapChuoi("Ngay nhap (dd/mm/yyyy): ", g.ngay, MAX_NGAY);
        if (!ngayHopLe(g.ngay)) cout << "  -> Ngay khong hop le!\n";
    } while (!ngayHopLe(g.ngay));

    // cap nhat ton kho
    k.dsSP[vt].soLuongTon += g.soLuong;
    moRongGD(k);
    k.dsGD[k.soGD++] = g;

    cout << "=> Nhap kho thanh cong. Ton moi cua '" << ma << "': "
         << k.dsSP[vt].soLuongTon << "\n";
}

void xuatKho(Kho& k) {
    char ma[MAX_MA];
    cout << "\n--- XUAT KHO ---\n";
    nhapChuoi("Ma san pham can xuat: ", ma, MAX_MA);
    int vt = timTheoMa(k, ma);
    if (vt == -1) { cout << "  -> San pham chua co trong danh muc!\n"; return; }

    SanPham& s = k.dsSP[vt];
    cout << "Ton hien tai: " << s.soLuongTon << "\n";

    GiaoDich g;
    sinhMaGD(k, g.maGD);
    strcpy(g.maSP, ma);
    g.loai = 'X';
    g.soLuong = nhapSoNguyenDuong("So luong xuat: ");

    if (g.soLuong > s.soLuongTon) {
        cout << "  -> Khong du hang! Chi con " << s.soLuongTon << " " << s.donViTinh << ".\n";
        return;
    }
    g.donGia = nhapSoThuc("Don gia xuat (VND): ");
    do {
        nhapChuoi("Ngay xuat (dd/mm/yyyy): ", g.ngay, MAX_NGAY);
        if (!ngayHopLe(g.ngay)) cout << "  -> Ngay khong hop le!\n";
    } while (!ngayHopLe(g.ngay));

    s.soLuongTon -= g.soLuong;
    moRongGD(k);
    k.dsGD[k.soGD++] = g;

    cout << "=> Xuat kho thanh cong. Ton moi cua '" << ma << "': " << s.soLuongTon << "\n";
    if (s.soLuongTon <= s.nguongToiThieu)
        cout << "  [CANH BAO] Ton kho da xuong duoi/bang nguong toi thieu ("
             << s.nguongToiThieu << ")!\n";
}


void canhBaoSapHet(const Kho& k) {
    cout << "\n--- DANH SACH HANG SAP HET (ton <= nguong toi thieu) ---\n";
    int dem = 0;
    inTieuDeBang();
    for (int i = 0; i < k.soSP; i++)
        if (k.dsSP[i].soLuongTon <= k.dsSP[i].nguongToiThieu) {
            inMotDong(k.dsSP[i]); dem++;
        }
    if (dem == 0) cout << "Khong co mat hang nao duoi nguong.\n";
    else cout << "Co " << dem << " mat hang can nhap them.\n";
}


void nhatKyTheoThang(const Kho& k) {
    cout << "\n--- NHAT KY NHAP/XUAT THEO THANG ---\n";
    int thang = nhapSoNguyen("Thang (1-12): ");
    int nam   = nhapSoNguyen("Nam: ");
    if (thang < 1 || thang > 12) { cout << "Thang khong hop le.\n"; return; }

    cout << left << setw(8) << "Ma GD" << setw(8) << "Loai"
         << setw(10) << "Ma SP" << right << setw(8) << "SL"
         << setw(14) << "Don gia" << setw(14) << "Thanh tien"
         << "  " << "Ngay" << "\n";
    cout << string(74, '-') << "\n";

    long tongNhapSL = 0, tongXuatSL = 0;
    double tongNhapTien = 0, tongXuatTien = 0;
    int dem = 0;

    for (int i = 0; i < k.soGD; i++) {
        int d, m, y;
        if (!tachNgay(k.dsGD[i].ngay, d, m, y)) continue;
        if (m != thang || y != nam) continue;

        const GiaoDich& g = k.dsGD[i];
        double thanhTien = g.soLuong * g.donGia;
        cout << left << setw(8) << g.maGD
             << setw(8) << (g.loai == 'N' ? "Nhap" : "Xuat")
             << setw(10) << g.maSP
             << right << setw(8) << g.soLuong
             << setw(14) << fixed << setprecision(0) << g.donGia
             << setw(14) << thanhTien
             << "  " << g.ngay << "\n";
        if (g.loai == 'N') { tongNhapSL += g.soLuong; tongNhapTien += thanhTien; }
        else               { tongXuatSL += g.soLuong; tongXuatTien += thanhTien; }
        dem++;
    }

    if (dem == 0) { cout << "Khong co giao dich nao trong thang " << thang << "/" << nam << ".\n"; return; }
    cout << string(74, '-') << "\n";
    cout << "Tong nhap: " << tongNhapSL << " sp - " << fixed << setprecision(0)
         << tongNhapTien << " VND\n";
    cout << "Tong xuat: " << tongXuatSL << " sp - " << tongXuatTien << " VND\n";
}


void thongKeGiaTriTon(const Kho& k) {
    cout << "\n--- THONG KE GIA TRI HANG TON KHO ---\n";
    if (k.soSP == 0) { cout << "(Kho trong)\n"; return; }

    int* idx = new int[k.soSP];
    double* giaTri = new double[k.soSP];
    for (int i = 0; i < k.soSP; i++) {
        idx[i] = i;
        giaTri[i] = k.dsSP[i].soLuongTon * k.dsSP[i].donGia;
    }
    sapXepChiSo(idx, k.soSP, giaTri, false); // giam dan

    cout << left << setw(8) << "Ma" << setw(22) << "Ten SP"
         << right << setw(8) << "Ton" << setw(14) << "Don gia"
         << setw(16) << "Gia tri ton" << "\n";
    cout << string(68, '-') << "\n";

    double tong = 0;
    for (int i = 0; i < k.soSP; i++) {
        int j = idx[i];
        cout << left << setw(8) << k.dsSP[j].maSP << setw(22) << k.dsSP[j].tenSP
             << right << setw(8) << k.dsSP[j].soLuongTon
             << setw(14) << fixed << setprecision(0) << k.dsSP[j].donGia
             << setw(16) << giaTri[j] << "\n";
        tong += giaTri[j];
    }
    cout << string(68, '-') << "\n";
    cout << "TONG GIA TRI HANG TON KHO: " << fixed << setprecision(0) << tong << " VND\n";

    delete[] idx;
    delete[] giaTri;
}
