#include <iostream>
#include <limits>
#include "SVCaoDang.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số thực DiemThiTN
	Output: Khởi tạo sinh viên cao đẳng với điểm thi tốt nghiệp tương ứng
	Hướng giải thuật:
	Gán DiemThiTN cho thuộc tính của đối tượng
*/
SVCaoDang::SVCaoDang(double DiemThiTN) :DiemThiTN(DiemThiTN) {}

/*
	Hàm nhập thông tin sinh viên cao đẳng
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho sinh viên cao đẳng
	Hướng giải thuật:
	- Gọi hàm nhập của lớp SinhVien
	- Nhập điểm thi tốt nghiệp
	- Kiểm tra điểm hợp lệ trong đoạn từ 0 đến 10
*/
void SVCaoDang::Nhap() {
	SinhVien::Nhap();
	cout << "Nhap diem thi tot nghiep: ";
	while (!(cin >> DiemThiTN) || DiemThiTN < 0 || DiemThiTN > 10 || cin.peek() != '\n') {
		cout << "Diem thi tot nghiep khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

/*
	Hàm xuất thông tin sinh viên cao đẳng
	Input: Sinh viên cao đẳng hiện tại
	Output: Hiển thị thông tin sinh viên cao đẳng
	Hướng giải thuật:
	- In loại sinh viên
	- Gọi hàm xuất của lớp SinhVien
	- In điểm thi tốt nghiệp
*/
void SVCaoDang::Xuat() {
	cout << "SV Cao dang: ";
	SinhVien::Xuat();
	cout << "Diem thi tot nghiep: " << DiemThiTN << endl;
}

/*
	Hàm xét điều kiện tốt nghiệp sinh viên cao đẳng
	Input: Sinh viên cao đẳng hiện tại
	Output: true nếu đủ điều kiện tốt nghiệp, ngược lại false
	Hướng giải thuật:
	- Kiểm tra tổng tín chỉ >= 120
	- Kiểm tra điểm trung bình >= 5
	- Kiểm tra điểm thi tốt nghiệp >= 5
*/
bool SVCaoDang::XetDKTotNghiep() {
	return (TongTC >= 120 && DTB >= 5 && DiemThiTN >= 5);
}