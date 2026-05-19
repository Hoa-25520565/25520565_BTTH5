#include <iostream>
#include <limits>
#include <sstream>
#include <cctype>
#include "GiaoDich.h"
using namespace std;

/*
	Constructor có tham số
	Input: Hai chuỗi MaGD, NgayGD, ba số thực DonGia, DienTich, ThanhTien
	Output: Khởi tạo giao dịch với các thông tin tương ứng
	Hướng giải thuật:
	Gán các giá trị truyền vào cho thuộc tính của đối tượng
*/
GiaoDich::GiaoDich(string MaGD, string NgayGD, double DonGia, double DienTich, double ThanhTien) :
	MaGD(MaGD), NgayGD(NgayGD), DonGia(DonGia), DienTich(DienTich), ThanhTien(ThanhTien) {}

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
	Hàm kiểm tra định dạng và tính hợp lệ của ngày tháng năm
	Input: Chuỗi ngày dạng dd/mm/yyyy
	Output: True nếu ngày hợp lệ, false nếu ngày không hợp lệ hoặc sai định dạng
	Hướng giải thuật:
	- Kiểm tra độ dài chuỗi phải đúng 10 ký tự
	- Kiểm tra vị trí dấu '/' phải nằm ở index 2 và 5
	- Dùng stringstream để tách ngày, tháng, năm
	- Kiểm tra không còn ký tự dư sau khi tách dữ liệu
	- Gọi hàm HopLe để kiểm tra tính hợp lệ của ngày tháng năm
*/
bool KiemTraNgay(string s) {
	if (s.length() != 10)
		return false;
	if (s[2] != '/' || s[5] != '/')
		return false;
	int d, m, y;
	char c1, c2;
	stringstream ss(s);
	ss >> d >> c1 >> m >> c2 >> y;
	if (ss.fail() || c1 != '/' || c2 != '/')
		return false;
	if (!ss.eof())
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
	Hàm nhập thông tin giao dịch
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho giao dịch
	Hướng giải thuật:
	- Nhập mã giao dịch và kiểm tra không được rỗng
	- Nhập ngày giao dịch và kiểm tra hợp lệ
	- Nhập đơn giá và diện tích
	- Kiểm tra dữ liệu phải không âm
*/
void GiaoDich::Nhap() {
	cout << "Nhap ma giao dich: ";
	getline(cin, MaGD);
	while (ChuoiRong(MaGD)) {
		cout << "Ma giao dich khong hop le, nhap lai: ";
		getline(cin, MaGD);
	}
	cout << "Nhap ngay giao dich: ";
	getline(cin, NgayGD);
	while (!KiemTraNgay(NgayGD)) {
		cout << "Ngay giao dich khong hop le, nhap lai: ";
		getline(cin, NgayGD);
	}
	cout << "Nhap don gia: ";
	while (!(cin >> DonGia) || DonGia < 0 || cin.peek() != '\n') {
		cout << "Don gia khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Nhap dien tich: ";
	while (!(cin >> DienTich) || DienTich < 0 || cin.peek() != '\n') {
		cout << "Dien tich khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*
	Hàm xuất thông tin giao dịch
	Input: Giao dịch hiện tại
	Output: Hiển thị thông tin giao dịch ra màn hình
	Hướng giải thuật:
	- In mã giao dịch, ngày giao dịch, đơn giá, diện tích và thành tiền
*/
void GiaoDich::Xuat() {
	cout << "Ma giao dich: " << MaGD << "\n"
		<< "Ngay giao dich: " << NgayGD << ", "
		<< "Don gia: " << DonGia << "\n"
		<< "Dien tich: " << DienTich << ", "
		<< "Thanh tien: " << ThanhTien << endl;
}

/*
	Hàm lấy ngày giao dịch
	Input: Giao dịch hiện tại
	Output: Chuỗi ngày giao dịch
	Hướng giải thuật:
	Trả về thuộc tính NgayGD
*/
string GiaoDich::LayNgayGD() {
	return NgayGD;
}