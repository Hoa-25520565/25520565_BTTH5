#include <iostream>
#include <limits>
#include "LapTrinhVien.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số thực SoGioOT
	Output: Khởi tạo lập trình viên với số giờ overtime tương ứng
	Hướng giải thuật:
	Gán SoGioOT cho thuộc tính của đối tượng
*/
LapTrinhVien::LapTrinhVien(double SoGioOT) :SoGioOT(SoGioOT) {}

/*
	Hàm nhập thông tin lập trình viên
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho lập trình viên
	Hướng giải thuật:
	- Gọi hàm nhập của lớp NhanVien
	- Nhập số giờ overtime
	- Kiểm tra dữ liệu hợp lệ
*/
void LapTrinhVien::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so gio overtime: ";
	while (!(cin >> SoGioOT) || SoGioOT < 0 || cin.peek() != '\n') {
		cout << "So gio overtime khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*
	Hàm xuất thông tin lập trình viên
	Input: Lập trình viên hiện tại
	Output: Hiển thị thông tin lập trình viên
	Hướng giải thuật:
	- In loại nhân viên
	- Gọi hàm xuất của lớp NhanVien
	- In số giờ overtime
*/
void LapTrinhVien::Xuat() {
	cout << "Lap trinh vien: ";
	NhanVien::Xuat();
	cout << "So gio overtime: " << SoGioOT << endl;
}

/*
	Hàm tính lương lập trình viên
	Input: Lập trình viên hiện tại
	Output: Giá trị lương của lập trình viên
	Hướng giải thuật:
	- Tính lương theo công thức:
	  Luong = LuongCB + SoGioOT * 200000
	- Trả về lương vừa tính
*/
double LapTrinhVien::TinhLuong() {
	Luong = LuongCB + SoGioOT * 200000;
	return Luong;
}