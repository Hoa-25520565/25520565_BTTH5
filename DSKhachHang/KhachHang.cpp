#include <iostream>
#include <limits>
#include "KhachHang.h"
using namespace std;

/*
	Constructor có tham số
	Input: Chuỗi Ten, số nguyên SoLuongHang, hai số thực DonGiaHang, TongTienPhaiTra
	Output: Khởi tạo khách hàng với các thông tin tương ứng
	Hướng giải thuật:
	Gán các giá trị truyền vào cho thuộc tính của đối tượng
*/
KhachHang::KhachHang(string Ten, int SoLuongHang, double DonGiaHang, double TongTienPhaiTra) :
	Ten(Ten), SoLuongHang(SoLuongHang), DonGiaHang(DonGiaHang), TongTienPhaiTra(TongTienPhaiTra) {
}

/*
	Hàm nhập thông tin khách hàng
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho khách hàng
	Hướng giải thuật:
	- Nhập tên khách hàng
	- Nhập số lượng hàng và đơn giá hàng
*/
void KhachHang::Nhap() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Ten);
	cin >> SoLuongHang >> DonGiaHang;
}

/*
	Hàm xuất thông tin khách hàng
	Input: Khách hàng hiện tại
	Output: Hiển thị tên khách hàng và tổng tiền phải trả
	Hướng giải thuật:
	- In tên khách hàng
	- In tổng tiền phải trả
*/
void KhachHang::Xuat() {
	cout << Ten << endl;
	cout << TongTienPhaiTra << endl;
}

/*
	Hàm lấy tổng tiền phải trả
	Input: Khách hàng hiện tại
	Output: Giá trị tổng tiền phải trả của khách hàng
	Hướng giải thuật:
	Trả về thuộc tính TongTienPhaiTra
*/
double KhachHang::LayTongTienPhaiTra() {
	return TongTienPhaiTra;
}