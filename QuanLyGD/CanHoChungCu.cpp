#include <iostream>
#include <limits>
#include <cctype>
#include "CanHoChungCu.h"
using namespace std;

bool ChuoiRong(string s);

/*
	Constructor có tham số
	Input: Chuỗi MaCan, số nguyên VTTang
	Output: Khởi tạo căn hộ chung cư với thông tin tương ứng
	Hướng giải thuật:
	Gán MaCan và VTTang cho thuộc tính của đối tượng
*/
CanHoChungCu::CanHoChungCu(string MaCan, int VTTang) :
	MaCan(MaCan), VTTang(VTTang) {
}

/*
	Hàm nhập thông tin giao dịch căn hộ chung cư
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho căn hộ chung cư
	Hướng giải thuật:
	- Nhập mã căn và kiểm tra không được rỗng
	- Nhập vị trí tầng và kiểm tra phải lớn hơn 0
	- Gọi hàm nhập của lớp GiaoDich
*/
void CanHoChungCu::Nhap() {
	cout << "Nhap ma can: ";
	getline(cin, MaCan);
	while (ChuoiRong(MaCan)) {
		cout << "Ma can khong hop le, nhap lai: ";
		getline(cin, MaCan);
	}
	cout << "Nhap vi tri tang: ";
	while (!(cin >> VTTang) || VTTang <= 0 || cin.peek() != '\n') {
		cout << "Vi tri tang khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	GiaoDich::Nhap();
}

/*
	Hàm xuất thông tin giao dịch căn hộ chung cư
	Input: Giao dịch căn hộ chung cư hiện tại
	Output: Hiển thị thông tin giao dịch căn hộ chung cư
	Hướng giải thuật:
	- In mã căn và vị trí tầng
	- Gọi hàm xuất của lớp GiaoDich
*/
void CanHoChungCu::Xuat() {
	cout << "Giao dich Can ho chung cu: Ma can: " << MaCan << ", "
		<< "Vi tri tang: " << VTTang << ", ";
	GiaoDich::Xuat();
}

/*
	Hàm tính thành tiền giao dịch căn hộ chung cư
	Input: Giao dịch căn hộ chung cư
	Output: Thành tiền của giao dịch căn hộ chung cư
	Hướng giải thuật:
	- Thành tiền cơ bản = Diện tích * Đơn giá
	- Nếu ở tầng 1 thì nhân đôi
	- Nếu tầng từ 15 trở lên thì nhân 1.2
*/
double CanHoChungCu::TinhThanhTien() {
	ThanhTien = DienTich * DonGia;
	if (VTTang == 1) {
		ThanhTien *= 2;
	}
	else if (VTTang >= 15) {
		ThanhTien *= 1.2;
	}
	return ThanhTien;
}