#include <iostream>
#include <limits>
#include "SinhVien.h"
using namespace std;

/*
	Constructor có tham số
	Input: Ba chuỗi MSSV, HoTen, DiaChi, số nguyên TongTc, số thực DTB
	Output: Khởi tạo sinh viên với các thông tin tương ứng
	Hướng giải thuật:
	Gán các giá trị truyền vào cho thuộc tính của đối tượng
*/
SinhVien::SinhVien(string MSSV, string HoTen, string DiaChi, int TongTC, double DTB) :
	MSSV(MSSV), HoTen(HoTen), DiaChi(DiaChi), TongTC(TongTC), DTB(DTB) {
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
	Hàm nhập thông tin sinh viên
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho sinh viên
	Hướng giải thuật:
	- Nhập MSSV, họ tên, địa chỉ
	- Kiểm tra các chuỗi không được rỗng
	- Nhập tổng số tín chỉ và điểm trung bình
	- Kiểm tra dữ liệu hợp lệ
*/
void SinhVien::Nhap() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Nhap ma so sinh vien: ";
	getline(cin, MSSV);
	while (ChuoiRong(MSSV)) {
		cout << "Ma so sinh vien khong hop le, nhap lai: ";
		getline(cin, MSSV);
	}
	cout << "Nhap ho ten: ";
	getline(cin, HoTen);
	while (ChuoiRong(HoTen)) {
		cout << "Ho ten sinh vien khong hop le, nhap lai: ";
		getline(cin, HoTen);
	}
	cout << "Nhap dia chi: ";
	getline(cin, DiaChi);
	while (ChuoiRong(DiaChi)) {
		cout << "Dia chi khong hop le, nhap lai: ";
		getline(cin, DiaChi);
	}
	cout << "Nhap tong so tin chi: ";
	while (!(cin >> TongTC) || TongTC < 0 || cin.peek() != '\n') {
		cout << "Tong so tin chi khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "Nhap diem trung binh: ";
	while (!(cin >> DTB) || DTB < 0 || DTB > 10 || cin.peek() != '\n') {
		cout << "Diem trung binh khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*
	Hàm xuất thông tin sinh viên
	Input: Sinh viên hiện tại
	Output: Hiển thị thông tin sinh viên
	Hướng giải thuật:
	- In MSSV, họ tên, địa chỉ, tổng tín chỉ và điểm trung bình
*/
void SinhVien::Xuat() {
	cout << "Ma so sinh vien: " << MSSV << "\n"
		<< "Ho ten: " << HoTen << ", "
		<< "Dia chi: " << DiaChi << "\n"
		<< "Tong so tin chi: " << TongTC << ", "
		<< "Diem trung binh: " << DTB << "\n";
}

/*
	Hàm lấy điểm trung bình
	Input: Sinh viên hiện tại
	Output: Giá trị điểm trung bình của sinh viên
	Hướng giải thuật:
	Trả về thuộc tính DTB
*/
double SinhVien::LayDTB() {
	return DTB;
}