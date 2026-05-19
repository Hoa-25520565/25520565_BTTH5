#include <iostream>
#include "NhanVienVP.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số nguyên snlv
	Output: Khởi tạo nhân viên văn phòng với số ngày làm việc tương ứng
	Hướng giải thuật:
	Gán giá trị snlv cho thuộc tính SoNgayLamViec
*/
NhanVienVP::NhanVienVP(int snlv) :SoNgayLamViec(snlv) {}

/*
	Hàm nhập thông tin nhân viên văn phòng
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho nhân viên văn phòng
	Hướng giải thuật:
	- Gọi hàm nhập của lớp nhân viên
	- Nhập số ngày làm việc
	- Kiểm tra dữ liệu phải là số nguyên không âm
	- Nếu không hợp lệ thì yêu cầu nhập lại
*/
void NhanVienVP::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so ngay lam viec: ";
	while (!(cin >> SoNgayLamViec) || SoNgayLamViec < 0 || cin.peek() != '\n') {
		cout << "So ngay lam viec khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*
	Hàm xuất thông tin nhân viên văn phòng
	Input: Nhân viên văn phòng hiện tại
	Output: Hiển thị thông tin nhân viên văn phòng
	Hướng giải thuật:
	- In loại nhân viên
	- Gọi hàm xuất của lớp nhân viên
*/
void NhanVienVP::Xuat() {
	cout << "NVVP, ";
	NhanVien::Xuat();
}

/*
	Hàm tính lương nhân viên văn phòng
	Input: Nhân viên văn phòng hiện tại
	Output: Lương của nhân viên văn phòng
	Hướng giải thuật:
	Lương = Số ngày làm việc * 100000
*/
double NhanVienVP::TinhLuong() {
	Luong = SoNgayLamViec * 100000;
	return Luong;
}