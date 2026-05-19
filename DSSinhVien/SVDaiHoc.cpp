#include <iostream>
#include <limits>
#include <cctype>
#include "SVDaiHoc.h"
using namespace std;

bool ChuoiRong(string s);

/*
	Constructor có tham số
	Input: Chuỗi TenLV, số thực DiemLV
	Output: Khởi tạo sinh viên đại học với thông tin luận văn tương ứng
	Hướng giải thuật:
	Gán TenLV và DiemLV cho thuộc tính của đối tượng
*/
SVDaiHoc::SVDaiHoc(string TenLV, double DiemLV) :
	TenLV(TenLV), DiemLV(DiemLV) {
}

/*
	Hàm nhập thông tin sinh viên đại học
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho sinh viên đại học
	Hướng giải thuật:
	- Gọi hàm nhập của lớp SinhVien
	- Nhập tên luận văn và kiểm tra không được rỗng
	- Nhập điểm luận văn và kiểm tra hợp lệ
*/
void SVDaiHoc::Nhap() {
	SinhVien::Nhap();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Nhap ten luan van: ";
	getline(cin, TenLV);
	while (ChuoiRong(TenLV)) {
		cout << "Ten luan van khong hop le, nhap lai: ";
		getline(cin, TenLV);
	}
	cout << "Nhap diem luan van: ";
	while (!(cin >> DiemLV) || DiemLV < 0 || DiemLV > 10 || cin.peek() != '\n') {
		cout << "Diem luan van khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*
	Hàm xuất thông tin sinh viên đại học
	Input: Sinh viên đại học hiện tại
	Output: Hiển thị thông tin sinh viên đại học
	Hướng giải thuật:
	- In loại sinh viên
	- Gọi hàm xuất của lớp SinhVien
	- In tên luận văn và điểm luận văn
*/
void SVDaiHoc::Xuat() {
	cout << "SV Dai hoc: ";
	SinhVien::Xuat();
	cout << "Ten luan van: " << TenLV << ", "
		<< "Diem luan van: " << DiemLV << endl;
}

/*
	Hàm xét điều kiện tốt nghiệp sinh viên đại học
	Input: Sinh viên đại học hiện tại
	Output: true nếu đủ điều kiện tốt nghiệp, ngược lại false
	Hướng giải thuật:
	- Kiểm tra tổng tín chỉ >= 170
	- Kiểm tra điểm trung bình >= 5
	- Kiểm tra điểm luận văn >= 5
*/
bool SVDaiHoc::XetDKTotNghiep() {
	return (TongTC >= 170 && DTB >= 5 && DiemLV >= 5);
}