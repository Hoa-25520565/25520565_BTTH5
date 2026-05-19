#include <iostream>
#include <limits>
#include "Dat.h"
using namespace std;

/*
	Constructor có tham số
	Input: Chuỗi Loai
	Output: Khởi tạo giao dịch đất với loại đất tương ứng
	Hướng giải thuật:
	Gán giá trị Loai cho thuộc tính của đối tượng
*/
Dat::Dat(string Loai) : Loai(Loai) {}

/*
	Hàm nhập thông tin giao dịch đất
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho giao dịch đất
	Hướng giải thuật:
	- Nhập loại đất
	- Kiểm tra loại đất chỉ được là A, B hoặc C
	- Gọi hàm nhập của lớp GiaoDich
*/
void Dat::Nhap() {
	cout << "Nhap loai dat: ";
	cin >> Loai;
	while (Loai != "A" && Loai != "B" && Loai != "C") {
		cout << "Loai dat khong hop le, nhap lai: ";
		cin >> Loai;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	GiaoDich::Nhap();
}

/*
	Hàm xuất thông tin giao dịch đất
	Input: Giao dịch đất hiện tại
	Output: Hiển thị thông tin giao dịch đất
	Hướng giải thuật:
	- In loại đất
	- Gọi hàm xuất của lớp GiaoDich
*/
void Dat::Xuat() {
	cout << "Giao dich Dat: Loai " << Loai << ", ";
	GiaoDich::Xuat();
}

/*
	Hàm tính thành tiền giao dịch đất
	Input: Giao dịch đất hiện tại
	Output: Thành tiền của giao dịch đất
	Hướng giải thuật:
	- Thành tiền cơ bản = Diện tích * Đơn giá
	- Nếu loại đất là A thì nhân thêm 1.5
*/
double Dat::TinhThanhTien() {
	ThanhTien = DienTich * DonGia;
	if (Loai == "A")
		ThanhTien *= 1.5;
	return ThanhTien;
}