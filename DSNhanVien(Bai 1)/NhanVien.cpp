#include <iostream>
#include <sstream>
#include <limits>
#include "NhanVien.h"
using namespace std;

/*
	Constructor có tham số
	Input: Hai chuỗi ht và ns, số thực luong
	Output: Khởi tạo nhân viên với thông tin tương ứng
	Hướng giải thuật:
	Gán các giá trị ht, ns, luong lần lượt cho các thuộc tính
	HoTen, NgaySinh, Luong của đối tượng
*/
NhanVien::NhanVien(string ht, string ns, double luong) :
	HoTen(ht), NgaySinh(ns), Luong(luong) {}

/*
	Hàm kiểm tra năm nhuận
	Input: Năm y
	Output: true nếu là năm nhuận, ngược lại false
	Hướng giải thuật:
	Nếu năm chia hết cho 400 hoặc chia hết cho 4 nhưng không chia hết cho 100
	thì là năm nhuận
*/
bool LaNamNhuan(int y) {
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

/*
	Hàm kiểm tra ngày hợp lệ
	Input: Ngày d, tháng m, năm y
	Output: true nếu ngày hợp lệ, ngược lại false
	Hướng giải thuật:
	- Kiểm tra điều kiện cơ bản của ngày, tháng, năm
	- Xác định số ngày tối đa của từng tháng bằng cách gán vào mảng với chỉ số tương ứng
	- Nếu tháng 2 và là năm nhuận thì tối đa 29 ngày
	- So sánh ngày với số ngày tối đa
*/
bool HopLe(int d, int m, int y) {
	if (y < 0 || m < 1 || m > 12 || d < 1) return false;
	int NgayTrongThang[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m == 2 && LaNamNhuan(y))
		return d <= 29;
	return d <= NgayTrongThang[m];
}

/*
	Hàm kiểm tra định dạng ngày tháng năm sinh
	Input: Chuỗi ngày dạng dd/mm/yyyy
	Output: true nếu hợp lệ, ngược lại false
	Hướng giải thuật:
	- Dùng stringstream để tách ngày, tháng, năm
	- Kiểm tra định dạng dấu '/'
	- Gọi hàm HopLe để kiểm tra tính hợp lệ của ngày tháng năm
*/
bool KiemTraNgay(string s) {
	int d, m, y;
	char c1, c2;
	stringstream ss(s);
	ss >> d >> c1 >> m >> c2 >> y;
	if (ss.fail() || c1 != '/' || c2 != '/')
		return false;
	return HopLe(d, m, y);
}

/*
	Hàm kiểm tra chuỗi rỗng hoặc chỉ chứa khoảng trắng
	Input: Chuỗi s
	Output: true nếu chuỗi rỗng hoặc chỉ chứa khoảng trắng, ngược lại false
	Hướng giải thuật:
	- Duyệt từng ký tự trong chuỗi
	- Nếu tồn tại ký tự không phải khoảng trắng thì trả về false
	- Nếu duyệt hết mà không có ký tự hợp lệ thì trả về true
*/
bool ChuoiRong(string s) {
	for (char c : s) {
		if (!isspace(c))
			return false;
	}
	return true;
}

/*
	Hàm nhập thông tin nhân viên
	Input: Dữ liệu nhập từ bàn phím gồm họ tên và ngày sinh
	Output: Gán giá trị cho họ tên và ngày sinh của nhân viên
	Hướng giải thuật:
	- Nhập họ tên và kiểm tra chuỗi không được rỗng
	- Nhập ngày sinh và kiểm tra định dạng hợp lệ
	- Nếu dữ liệu không hợp lệ thì yêu cầu nhập lại
*/
void NhanVien::Nhap() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Nhap ho ten: ";
	getline(cin, HoTen);
	while (ChuoiRong(HoTen)) {
		cout << "Ho ten khong hop le, nhap lai: ";
		getline(cin, HoTen);
	}
	cout << "Nhap ngay sinh: ";
	getline(cin, NgaySinh);
	while (!KiemTraNgay(NgaySinh)) {
		cout << "Ngay sinh khong hop le, nhap lai: ";
		getline(cin, NgaySinh);
	}
}

/*
	Hàm xuất thông tin nhân viên
	Input: Nhân viên hiện tại
	Output: Hiển thị họ tên, ngày sinh và lương của nhân viên
	Hướng giải thuật:
	- In lần lượt họ tên, ngày sinh và lương ra màn hình
*/
void NhanVien::Xuat() {
	cout << "Ho ten: " << HoTen << "\n";
	cout << "Ngay sinh: " << NgaySinh << ", ";
	cout << "Luong: " << Luong << endl;
}

/*
	Hàm lấy lương nhân viên
	Input: Nhân viên hiện tại
	Output: Giá trị lương của nhân viên
	Hướng giải thuật:
	Trả về thuộc tính Luong
*/
double NhanVien::LayLuong() {
	return Luong;
}

/*
	Hàm lấy ngày sinh nhân viên
	Input: Nhân viên hiện tại
	Output: Chuỗi ngày sinh của nhân viên
	Hướng giải thuật:
	Trả về thuộc tính NgaySinh
*/
string NhanVien::LayNgaySinh() {
	return NgaySinh;
}