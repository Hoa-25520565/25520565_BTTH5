#include <iostream>
#include "NhanVienSX.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số thực lcb và số nguyên sosp
	Output: Khởi tạo nhân viên sản xuất với thông tin tương ứng
	Hướng giải thuật:
	Gán lcb và sosp lần lượt cho thuộc tính LuongCB và SoSP
*/
NhanVienSX::NhanVienSX(double lcb, int sosp) :
	LuongCB(lcb), SoSP(sosp) {}

/*
	Hàm nhập thông tin nhân viên sản xuất
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho nhân viên sản xuất
	Hướng giải thuật:
	- Gọi hàm nhập của lớp nhân viên
	- Nhập lương cơ bản và số sản phẩm
	- Kiểm tra dữ liệu phải không âm
	- Nếu không hợp lệ thì yêu cầu nhập lại
*/
void NhanVienSX::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap luong co ban: ";
	while (!(cin >> LuongCB) || LuongCB < 0 || cin.peek() != '\n') {
		cout << "Luong co ban khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Nhap so san pham: ";
	while (!(cin >> SoSP) || SoSP < 0 || cin.peek() != '\n') {
		cout << "So san pham khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*
	Hàm xuất thông tin nhân viên sản xuất
	Input: Nhân viên sản xuất hiện tại
	Output: Hiển thị thông tin nhân viên sản xuất
	Hướng giải thuật:
	- In loại nhân viên
	- Gọi hàm xuất của lớp nhân viên
*/
void NhanVienSX::Xuat() {
	cout << "NVSX, ";
	NhanVien::Xuat();
}

/*
	Hàm tính lương nhân viên sản xuất
	Input: Nhân viên sản xuất hiện tại
	Output: Lương của nhân viên sản xuất
	Hướng giải thuật:
	Lương = Lương cơ bản + Số sản phẩm * 5000
*/
double NhanVienSX::TinhLuong() {
	Luong = LuongCB + SoSP * 5000;
	return Luong;
}