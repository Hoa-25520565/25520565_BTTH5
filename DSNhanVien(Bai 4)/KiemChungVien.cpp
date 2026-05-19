#include <iostream>
#include <limits>
#include "KiemChungVien.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số lỗi phát hiện được SoLoiPHDuoc
	Output: Khởi tạo kiểm chứng viên với số lỗi phát hiện tương ứng
	Hướng giải thuật:
	Gán SoLoiPHDuoc cho thuộc tính của đối tượng
*/
KiemChungVien::KiemChungVien(int SoLoiPHDuoc) :SoLoiPHDuoc(SoLoiPHDuoc) {}

/*
	Hàm nhập thông tin kiểm chứng viên
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho kiểm chứng viên
	Hướng giải thuật:
	- Gọi hàm nhập của lớp NhanVien
	- Nhập số lỗi phát hiện được
	- Kiểm tra dữ liệu hợp lệ
*/
void KiemChungVien::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so loi phat hien duoc: ";
	while (!(cin >> SoLoiPHDuoc) || SoLoiPHDuoc < 0 || cin.peek() != '\n') {
		cout << "So loi phat hien duoc khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*
	Hàm xuất thông tin kiểm chứng viên
	Input: Kiểm chứng viên hiện tại
	Output: Hiển thị thông tin kiểm chứng viên
	Hướng giải thuật:
	- In loại nhân viên
	- Gọi hàm xuất của lớp NhanVien
	- In số lỗi phát hiện được
*/
void KiemChungVien::Xuat() {
	cout << "Kiem chung vien: ";
	NhanVien::Xuat();
	cout << "So loi phat hien duoc: " << SoLoiPHDuoc << endl;
}

/*
	Hàm tính lương kiểm chứng viên
	Input: Kiểm chứng viên hiện tại
	Output: Giá trị lương của kiểm chứng viên
	Hướng giải thuật:
	- Tính lương theo công thức:
	  Luong = LuongCB + SoLoiPHDuoc * 50000
	- Trả về lương vừa tính
*/
double KiemChungVien::TinhLuong() {
	Luong = LuongCB + SoLoiPHDuoc * 50000;
	return Luong;
}