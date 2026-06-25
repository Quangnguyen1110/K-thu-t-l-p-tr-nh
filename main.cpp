
#include <iostream>
#include "khohang.h"
#include "tienich.h"
using namespace std;

void inMenu() {
    cout << "\n========== HE THONG QUAN LY KHO HANG ==========\n";
    cout << " 1. Them san pham\n";
    cout << " 2. Sua san pham\n";
    cout << " 3. Xoa san pham\n";
    cout << " 4. Hien thi toan bo kho\n";
    cout << " 5. Tim kiem san pham\n";
    cout << " 6. Nhap kho\n";
    cout << " 7. Xuat kho\n";
    cout << " 8. Canh bao hang sap het\n";
    cout << " 9. Nhat ky nhap/xuat theo thang\n";
    cout << "10. Thong ke gia tri hang ton kho\n";
    cout << " 0. Luu va thoat\n";
    cout << "===============================================\n";
}

int main() {
    Kho kho;
    khoiTaoKho(kho);
    docDuLieu(kho);   // nap du lieu da luu (neu co)
    cout << "Da nap du lieu: " << kho.soSP << " san pham, "
         << kho.soGD << " giao dich.\n";

    int chon;
    do {
        inMenu();
        chon = nhapSoNguyen("Chon chuc nang: ");
        switch (chon) {
            case 1:  themSanPham(kho);       break;
            case 2:  suaSanPham(kho);        break;
            case 3:  xoaSanPham(kho);        break;
            case 4:  hienThiTatCa(kho);      break;
            case 5:  timKiemSanPham(kho);    break;
            case 6:  nhapKho(kho);           break;
            case 7:  xuatKho(kho);           break;
            case 8:  canhBaoSapHet(kho);     break;
            case 9:  nhatKyTheoThang(kho);   break;
            case 10: thongKeGiaTriTon(kho);  break;
            case 0:
                luuDuLieu(kho);
                cout << "Da luu du lieu. Tam biet!\n";
                break;
            default:
                cout << "Chuc nang khong ton tai, hay chon lai.\n";
        }
    } while (chon != 0);

    giaiPhongKho(kho);
    return 0;
}
