#include <iostream>
#include <limits>
#include "NhaPho.h"
using namespace std;

/*
	Constructor có tham số
	Input: Chuỗi Loai
	Output: Khởi tạo giao dịch nhà phố với loại nhà tương ứng
	Hướng giải thuật:
	Gán giá trị Loai cho thuộc tính của đối tượng
*/
NhaPho::NhaPho(string Loai) :Loai(Loai) {};

/*
	Hàm nhập thông tin giao dịch nhà phố
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho giao dịch nhà phố
	Hướng giải thuật:
	- Nhập loại nhà
	- Kiểm tra loại nhà chỉ được là "cao cap" hoặc "thuong"
	- Gọi hàm nhập của lớp GiaoDich
*/
void NhaPho::Nhap() {
	cout << "Nhap loai nha: ";
	getline(cin, Loai);
	while (Loai != "cao cap" && Loai != "thuong") {
		cout << "Loai nha khong hop le, nhap lai: ";
		getline(cin, Loai);
	}
	GiaoDich::Nhap();
}

/*
	Hàm xuất thông tin giao dịch nhà phố
	Input: Giao dịch nhà phố hiện tại
	Output: Hiển thị thông tin giao dịch nhà phố
	Hướng giải thuật:
	- In loại nhà
	- Gọi hàm xuất của lớp GiaoDich
*/
void NhaPho::Xuat() {
	cout << "Giao dich Nha pho: Loai " << Loai << ", ";
	GiaoDich::Xuat();
}

/*
	Hàm tính thành tiền giao dịch nhà phố
	Input: Giao dịch nhà phố hiện tại
	Output: Thành tiền của giao dịch nhà phố
	Hướng giải thuật:
	- Thành tiền cơ bản = Diện tích * Đơn giá
	- Nếu loại nhà là "thuong" thì giảm 10%
*/
double NhaPho::TinhThanhTien() {
	ThanhTien = DienTich * DonGia;
	if (Loai == "thuong") {
		ThanhTien *= 0.9;
	}
	return ThanhTien;
}