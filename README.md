# Quản lý kho hàng

Bài tập lớn học phần **Kỹ thuật lập trình** (kỳ 20252) — Chủ đề 03: Quản lý kho hàng.

Chương trình console viết bằng C++, điều khiển bằng menu, dữ liệu lưu trong tệp văn
bản. Theo yêu cầu của đề bài, các cấu trúc dữ liệu (mảng động) và thuật toán
(sắp xếp, tìm kiếm, so khớp chuỗi) đều **tự cài đặt**, không dùng thư viện dựng sẵn.

## Chức năng
- Quản lý danh mục sản phẩm: thêm / sửa / xóa / hiển thị
- Tìm kiếm sản phẩm theo mã hoặc theo tên
- Nhập kho / xuất kho (tự động cập nhật tồn, kiểm tra tồn khi xuất)
- Cảnh báo hàng có tồn dưới ngưỡng tối thiểu
- Nhật ký nhập/xuất theo tháng
- Thống kê giá trị hàng tồn kho

## Biên dịch
```
g++ -std=c++11 -o khohang main.cpp khohang.cpp tienich.cpp
```
Sau đó chạy `./khohang` (Linux/macOS) hoặc `khohang.exe` (Windows). Cần có thư mục
`data/` cùng cấp với file thực thi.

## Cấu trúc thư mục
```
khohang.h        khai báo struct và prototype
tienich.h/.cpp   hàm tiện ích + thuật toán tự cài
khohang.cpp      nghiệp vụ chính + đọc/ghi tệp
main.cpp         vòng lặp menu
data/            sanpham.txt, giaodich.txt
```

## Định dạng tệp dữ liệu
- `data/sanpham.txt`: `mã|tên|loại|đơn vị|tồn|đơn giá|ngưỡng`
- `data/giaodich.txt`: `mã GD|mã SP|loại(N/X)|số lượng|đơn giá|ngày(dd/mm/yyyy)`
