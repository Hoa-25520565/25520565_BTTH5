#include <iostream>
#include <limits>
#include "DSSinhVien.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số lượng sinh viên n
	Output: Khởi tạo danh sách sinh viên
	Hướng giải thuật:
	Gán giá trị n cho thuộc tính của đối tượng
*/
DSSinhVien::DSSinhVien(int n) :n(n) {}

/*
	Destructor
	Input: Không có
	Output: Giải phóng bộ nhớ động của danh sách sinh viên
	Hướng giải thuật:
	- Duyệt danh sách sinh viên
	- Giải phóng từng đối tượng bằng delete
*/
DSSinhVien::~DSSinhVien() {
	for (int i = 0;i < n;i++) {
		delete a[i];
	}
}

/*
	Hàm nhập danh sách sinh viên
	Input: Dữ liệu nhập từ bàn phím
	Output: Danh sách sinh viên được khởi tạo và lưu vào vector
	Hướng giải thuật:
	- Nhập số lượng sinh viên
	- Với mỗi sinh viên:
		+ Nhập loại sinh viên
		+ Khởi tạo đối tượng tương ứng
		+ Nhập thông tin sinh viên
		+ Thêm vào danh sách
*/
void DSSinhVien::Nhap() {
	cout << "Nhap so luong sinh vien: ";
	while (!(cin >> n) || n < 0 || cin.peek() != '\n') {
		cout << "So luong khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	int loai;
	for (int i = 0;i < n;i++) {
		cout << "Nhap loai sinh vien cua sinh vien thu " << i + 1 << ":\n";
		cout << "1.Sinh vien cao dang\n";
		cout << "2.Sinh vien dai hoc\n";
		while (!(cin >> loai) || (loai != 1 && loai != 2) || cin.peek() != '\n') {
			cout << "Loai khong hop le, nhap lai: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		SinhVien* s = nullptr;
		if (loai == 1)
			s = new SVCaoDang;
		else
			s = new SVDaiHoc;
		s->Nhap();
		a.push_back(s);
	}
}

/*
	Hàm xuất danh sách sinh viên
	Input: Danh sách sinh viên
	Output: Hiển thị thông tin toàn bộ sinh viên
	Hướng giải thuật:
	- Nếu danh sách rỗng thì thông báo
	- Ngược lại duyệt và xuất từng sinh viên
*/
void DSSinhVien::Xuat() {
	if (n == 0) cout << "Danh sach rong\n";
	else {
		for (int i = 0;i < n;i++) {
			cout << "Sinh vien thu " << i + 1 << ": ";
			a[i]->Xuat();
		}
	}
}

/*
	Hàm xuất danh sách sinh viên đủ điều kiện tốt nghiệp
	Input: Danh sách sinh viên hiện tại
	Output: Các sinh viên đủ điều kiện tốt nghiệp
	Hướng giải thuật:
	- Duyệt danh sách sinh viên
	- Kiểm tra điều kiện tốt nghiệp của từng sinh viên
	- Nếu đủ điều kiện thì xuất thông tin
	- Nếu không có sinh viên nào đủ điều kiện tốt nghiệp thì thông báo
*/
void DSSinhVien::XuatDSSVDuDKTN() {
	if (n == 0) cout << "Khong co sinh vien nao du dieu kien tot nghiep\n";
	else {
		bool c = false;
		for (int i = 0;i < n;i++) {
			if (!a[i]->XetDKTotNghiep()) continue;
			if (c == false) {
				cout << "Danh sach sinh vien du dieu kien tot nghiep:\n";
				c = true;
			}
			a[i]->Xuat();
		}
		if (!c) cout << "Khong co sinh vien nao du dieu kien tot nghiep\n";
	}
}

/*
	Hàm xuất danh sách sinh viên không đủ điều kiện tốt nghiệp
	Input: Danh sách sinh viên hiện tại
	Output: Các sinh viên không đủ điều kiện tốt nghiệp
	Hướng giải thuật:
	- Duyệt danh sách sinh viên
	- Kiểm tra điều kiện tốt nghiệp của từng sinh viên
	- Nếu không đủ điều kiện thì xuất thông tin
	- Nếu không có sinh viên nào không đủ điều kiện tốt nghiệp thì thông báo
*/
void DSSinhVien::XuatDSSVKhongDuDKTN() {
	if (n == 0) cout << "Khong co sinh vien nao khong du dieu kien tot nghiep\n";
	else {
		bool c = false;
		for (int i = 0;i < n;i++) {
			if (a[i]->XetDKTotNghiep()) continue;
			if (c == false) {
				cout << "Danh sach sinh vien khong du dieu kien tot nghiep:\n";
				c = true;
			}
			a[i]->Xuat();
		}
		if (!c) cout << "Khong co sinh vien nao khong du dieu kien tot nghiep\n";
	}
}

/*
	Hàm tìm sinh viên cao đẳng có điểm trung bình cao nhất
	Input: Danh sách sinh viên hiện tại
	Output: Thông tin sinh viên cao đẳng có điểm trung bình cao nhất
	Hướng giải thuật:
	- Duyệt danh sách sinh viên
	- Chỉ xét sinh viên cao đẳng
	- Tìm sinh viên có điểm trung bình lớn nhất
	- Nếu không có sinh viên cao đẳng thì thông báo
*/
void DSSinhVien::TimSVCDCoDTBCaoNhat() {
	if (n == 0) cout << "Khong co sinh vien cao dang\n";
	else {
		int max = -1;
		for (int i = 0;i < n;i++) {
			if (!dynamic_cast<SVCaoDang*>(a[i])) continue;
			if (max == -1) {
				max = i;
				continue;
			}
			if (a[max]->LayDTB() < a[i]->LayDTB()) max = i;
		}
		if (max == -1) cout << "Khong co sinh vien cao dang\n";
		else {
			cout << "Sinh vien cao dang co diem trung binh cao nhat:\n";
			a[max]->Xuat();
		}
	}
}

/*
	Hàm tìm sinh viên đại học có điểm trung bình cao nhất
	Input: Danh sách sinh viên hiện tại
	Output: Thông tin sinh viên đại học có điểm trung bình cao nhất
	Hướng giải thuật:
	- Duyệt danh sách sinh viên
	- Chỉ xét sinh viên đại học
	- Tìm sinh viên có điểm trung bình lớn nhất
	- Nếu không có sinh viên đại học thì thông báo
*/
void DSSinhVien::TimSVDHCoDTBCaoNhat() {
	if (n == 0) cout << "Khong co sinh vien dai hoc\n";
	else {
		int max = -1;
		for (int i = 0;i < n;i++) {
			if (!dynamic_cast<SVDaiHoc*>(a[i])) continue;
			if (max == -1) {
				max = i;
				continue;
			}
			if (a[max]->LayDTB() < a[i]->LayDTB()) max = i;
		}
		if (max == -1) cout << "Khong co sinh vien dai hoc\n";
		else {
			cout << "Sinh vien dai hoc co diem trung binh cao nhat:\n";
			a[max]->Xuat();
		}
	}
}

/*
	Hàm đếm số sinh viên không đủ điều kiện tốt nghiệp
	Input: Danh sách sinh viên hiện tại
	Output: Số lượng sinh viên cao đẳng và đại học không đủ điều kiện tốt nghiệp
	Hướng giải thuật:
	- Duyệt danh sách sinh viên
	- Kiểm tra điều kiện tốt nghiệp
	- Dùng dynamic_cast để xác định loại sinh viên
	- Đếm số lượng từng loại và xuất kết quả
*/
void DSSinhVien::DemSoSVKhongDuDKTN() {
	int n1 = 0, n2 = 0;
	for (int i = 0;i < n;i++) {
		if (a[i]->XetDKTotNghiep()) continue;
		if (dynamic_cast<SVCaoDang*>(a[i])) n1++;
		else n2++;
	}
	cout << "So sinh vien cao dang khong du dieu kien tot nghiep: " << n1 << "\n\n";
	cout << "So sinh vien dai hoc khong du dieu kien tot nghiep: " << n2 << endl;
}