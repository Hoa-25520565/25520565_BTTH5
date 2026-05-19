#include <iostream>
#include <limits>
#include "NhanVien.h"
using namespace std;

/*
	Constructor có tham số
	Input: Hai chuỗi MaNV, HoTen, số nguyên Tuổi, hai chuỗi SDT, email, hai số thực LuongCB, Luong
	Output: Khởi tạo nhân viên với các thông tin tương ứng
	Hướng giải thuật:
	Gán các giá trị truyền vào cho thuộc tính của đối tượng
*/
NhanVien::NhanVien(string MaNV, string HoTen, int Tuoi, string SDT, string email, double LuongCB, double Luong) :
	MaNV(MaNV), HoTen(HoTen), Tuoi(Tuoi), SDT(SDT), email(email), LuongCB(LuongCB), Luong(Luong) {
}

/*
	Hàm kiểm tra số điện thoại hợp lệ
	Input: Chuỗi sdt
	Output: true nếu số điện thoại hợp lệ, ngược lại false
	Hướng giải thuật:
	- Kiểm tra độ dài bằng 10
	- Kiểm tra ký tự đầu là '0'
	- Kiểm tra tất cả ký tự đều là chữ số
*/
bool KiemTraSDT(string sdt) {
	if (sdt.length() != 10)
		return false;
	if (sdt[0] != '0')
		return false;
	for (char c : sdt) {
		if (!isdigit(c))
			return false;
	}
	return true;
}

/*
	Hàm kiểm tra email hợp lệ
	Input: Chuỗi email
	Output: true nếu email hợp lệ, ngược lại false
	Hướng giải thuật:
	- Kiểm tra email không chứa khoảng trắng
	- Kiểm tra chỉ có một ký tự '@'
	- Kiểm tra vị trí '@' hợp lệ
	- Kiểm tra tồn tại dấu '.' phía sau '@'
*/
bool KiemTraEmail(string email) {
	for (char c : email) {
		if (c == ' ')
			return false;
	}
	int at = email.find('@');
	if (at == -1 || email.find('@', at + 1) != -1)
		return false;
	if (at == 0 || at == email.length() - 1)
		return false;
	int dot = email.find('.', at);
	if (dot == -1 || dot == email.length() - 1)
		return false;
	return true;
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
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho nhân viên
	Hướng giải thuật:
	- Nhập mã nhân viên, họ tên
	- Kiểm tra chuỗi không được rỗng
	- Nhập tuổi và kiểm tra hợp lệ
	- Nhập số điện thoại và email
	- Kiểm tra định dạng hợp lệ
	- Nhập lương cơ bản
*/
void NhanVien::Nhap() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Nhap ma nhan vien: ";
	getline(cin, MaNV);
	while (ChuoiRong(MaNV)) {
		cout << "Ma nhan vien khong hop le, nhap lai: ";
		getline(cin, MaNV);
	}
	cout << "Nhap ho ten: ";
	getline(cin, HoTen);
	while (ChuoiRong(HoTen)) {
		cout << "Ho ten khong hop le, nhap lai: ";
		getline(cin, HoTen);
	}
	cout << "Nhap tuoi: ";
	while (!(cin >> Tuoi) || Tuoi < 1 || cin.peek() != '\n') {
		cout << "Tuoi khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Nhap so dien thoai: ";
	getline(cin, SDT);
	while (!KiemTraSDT(SDT)) {
		cout << "So dien thoai khong hop le, nhap lai: ";
		getline(cin, SDT);
	}
	cout << "Nhap email: ";
	getline(cin, email);
	while (!KiemTraEmail(email)) {
		cout << "Email khong hop le, nhap lai: ";
		getline(cin, email);
	}
	cout << "Nhap luong co ban: ";
	while (!(cin >> LuongCB) || LuongCB < 1 || cin.peek() != '\n') {
		cout << "Luong co ban khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*
	Hàm xuất thông tin nhân viên
	Input: Nhân viên hiện tại
	Output: Hiển thị thông tin nhân viên
	Hướng giải thuật:
	- In mã nhân viên, họ tên, tuổi
	- In số điện thoại, email
	- In lương cơ bản và lương
*/
void NhanVien::Xuat() {
	cout << "Ma nhan vien: " << MaNV << "\n"
		<< "Ho ten: " << HoTen << ", "
		<< "Tuoi: " << Tuoi << ", "
		<< "So dien thoai:\n" << SDT << ", "
		<< "Email: " << email << ", "
		<< "Luong co ban: " << LuongCB << "\n"
		<< "Luong: " << Luong << ", ";
}