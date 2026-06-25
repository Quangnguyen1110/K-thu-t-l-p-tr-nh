# Dự Án Quản Lý Kho Hàng (C++)

Dự án môn học **Kỹ thuật lập trình** nhằm xây dựng một ứng dụng console bằng ngôn ngữ C++ để quản lý thông tin hàng hóa, nhập xuất kho và theo dõi số lượng tồn kho một cách hiệu quả.

---

## 📌 Tính Năng Chính

* **Quản lý danh mục hàng hóa:** Thêm, sửa, xóa và hiển thị danh sách sản phẩm trong kho.
* **Quản lý nhập/xuất:** Thực hiện các nghiệp vụ nhập kho, xuất kho và tự động cập nhật số lượng tồn kho thực tế.
* **Tìm kiếm & Lọc:** Tìm kiếm sản phẩm nhanh chóng theo mã sản phẩm, tên sản phẩm hoặc loại hàng.
* **Thống kê & Báo cáo:** Hiển thị danh sách các mặt hàng sắp hết hoặc các mặt hàng tồn kho nhiều.
* **Tiện ích đi kèm:** Hỗ trợ định dạng hiển thị, xử lý chuỗi và kiểm tra dữ liệu đầu vào hợp lệ.

---

## 📂 Cấu Trúc Thư Mục Dự Án

Dự án được chia nhỏ thành các file module để dễ dàng quản lý và bảo trì:

* `main.cpp`: Điểm khởi đầu của chương trình, chứa menu điều khiển chính (`Menu`).
* `khohang.h` / `khohang.cpp`: Định nghĩa cấu trúc dữ liệu của hàng hóa (Sản phẩm, Danh sách sản phẩm) và các hàm xử lý nghiệp vụ kho (Nhập, Xuất, Thêm, Sửa, Xóa).
* `tienich.h` / `tienich.cpp`: Chứa các hàm bổ trợ như chuẩn hóa chuỗi, xóa màn hình console, kiểm tra tính hợp lệ của dữ liệu đầu vào.
* `.gitignore`: Cấu hình bỏ qua các file biên dịch không cần thiết khi push lên GitHub (như file `.exe`, `.obj`).

---

## 🛠️ Hướng Dẫn Cài Đặt và Chạy Dự Án

### Yêu cầu hệ thống
* Trình biên dịch C++ (GCC/G++ hoặc MSVC).
* Công cụ hỗ trợ: Visual Studio Code, Dev-C++, hoặc Visual Studio.

### Các bước thực hiện

1. **Cloning mã nguồn về máy cục bộ:**
   ```bash
   git clone [https://github.com/Quangnguyen1110/K-thu-t-l-p-tr-nh.git](https://github.com/Quangnguyen1110/K-thu-t-l-p-tr-nh.git)
   cd K-thu-t-l-p-tr-nh
