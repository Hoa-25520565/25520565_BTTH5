#include <iostream>
#include <limits>
#include "DSNhanVien.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số lượng nhân viên n
	Output: Khởi tạo danh sách nhân viên với số lượng tương ứng
	Hướng giải thuật:
	Gán giá trị n cho thuộc tính của đối tượng
*/
DSNhanVien::DSNhanVien(int n) :n(n) {}

/*
	Destructor
	Input: Không có
	Output: Giải phóng bộ nhớ động của danh sách nhân viên
	Hướng giải thuật:
	- Duyệt toàn bộ danh sách nhân viên
	- Giải phóng từng đối tượng bằng delete
*/
DSNhanVien::~DSNhanVien() {
	for (int i = 0;i < n;i++) {
		delete(a[i]);
	}
}

/*
	Hàm nhập danh sách nhân viên
	Input: Dữ liệu nhập từ bàn phím
	Output: Danh sách nhân viên được khởi tạo
	Hướng giải thuật:
	- Nhập số lượng nhân viên
	- Kiểm tra dữ liệu hợp lệ
	- Với mỗi nhân viên:
		+ Nhập loại nhân viên
		+ Khởi tạo đối tượng tương ứng
		+ Nhập thông tin nhân viên
		+ Tính lương
		+ Thêm vào danh sách
*/
void DSNhanVien::Nhap() {
	cout << "Nhap so luong nhan vien: ";
	while (!(cin >> n) || n < 0 || cin.peek() != '\n') {
		cout << "So luong nhan vien khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	int loai;
	for (int i = 0;i < n;i++) {
		cout << "Nhap loai nhan vien cua nhan vien thu " << i + 1 << ":\n";
		cout << "1.Lap trinh vien\n";
		cout << "2.Kiem chung vien\n";
		while (!(cin >> loai) || (loai != 1 && loai != 2) || cin.peek() != '\n') {
			cout << "Loai nhan vien khong hop le, nhap lai: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		NhanVien* s = nullptr;
		if (loai == 1) s = new LapTrinhVien;
		else s = new KiemChungVien;
		s->Nhap();
		s->TinhLuong();
		a.push_back(s);
	}
}

/*
	Hàm xuất danh sách nhân viên
	Input: Danh sách nhân viên hiện tại
	Output: Hiển thị toàn bộ nhân viên
	Hướng giải thuật:
	- Nếu danh sách rỗng thì thông báo
	- Ngược lại duyệt danh sách và xuất từng nhân viên
*/
void DSNhanVien::Xuat() {
	if (n == 0) cout << "Danh sach rong\n";
	else {
		for (int i = 0;i < n;i++) {
			cout << "Nhan vien thu " << i + 1 << ": ";
			a[i]->Xuat();
		}
	}
}

/*
	Hàm tính lương trung bình
	Input: Danh sách nhân viên
	Output: Giá trị lương trung bình của các nhân viên
	Hướng giải thuật:
	- Nếu danh sách rỗng thì trả về 0
	- Tính tổng lương của tất cả nhân viên
	- Chia tổng lương cho số lượng nhân viên
*/
double DSNhanVien::TinhLuongTB() {
	if (n == 0) return 0;
	double s = 0;
	for (int i = 0;i < n;i++) {
		s += a[i]->TinhLuong();
	}
	return s / n;
}

/*
	Hàm xuất danh sách nhân viên có lương thấp hơn trung bình
	Input: Danh sách nhân viên hiện tại
	Output: Các nhân viên có lương thấp hơn trung bình
	Hướng giải thuật:
	- Tính lương trung bình
	- Duyệt danh sách nhân viên
	- Xuất các nhân viên có lương nhỏ hơn trung bình
*/
void DSNhanVien::XuatDSNVCoLuongThapHonTB() {
	if (n == 0) cout << "Danh sach rong\n";
	else {
		bool c = false;
		double tb = TinhLuongTB();
		for (int i = 0;i < n;i++) {
			if (a[i]->TinhLuong() < tb) {
				if (!c) {
					cout << "Danh sach nhan vien co luong thap hon trung binh:\n";
					c = true;
				}
				a[i]->Xuat();
			}
		}
		if (!c) cout << "Khong co nhan vien nao luong thap hon trung bing\n";
	}
}

/*
	Hàm xuất thông tin nhân viên có lương cao nhất
	Input: Danh sách nhân viên hiện tại
	Output: Thông tin nhân viên có lương cao nhất
	Hướng giải thuật:
	- Duyệt danh sách nhân viên
	- Tìm nhân viên có lương lớn nhất
	- Xuất thông tin nhân viên đó
*/
void DSNhanVien::XuatTTNVLuongCaoNhat() {
	if (n == 0) cout << "Danh sach rong\n";
	else {
		int max = 0;
		for (int i = 0;i < n;i++) {
			if (a[max]->TinhLuong() < a[i]->TinhLuong()) max = i;
		}
		cout << "Thong tin nhan vien co luong cao nhat:\n";
		a[max]->Xuat();
	}
}

/*
	Hàm xuất thông tin nhân viên có lương thấp nhất
	Input: Danh sách nhân viên hiện tại
	Output: Thông tin nhân viên có lương thấp nhất
	Hướng giải thuật:
	- Duyệt danh sách nhân viên
	- Tìm nhân viên có lương nhỏ nhất
	- Xuất thông tin nhân viên đó
*/
void DSNhanVien::XuatTTNVLuongThapNhat() {
	if (n == 0) cout << "Danh sach rong\n";
	else {
		int min = 0;
		for (int i = 0;i < n;i++) {
			if (a[min]->TinhLuong() > a[i]->TinhLuong()) min = i;
		}
		cout << "Thong tin nhan vien co luong thap nhat:\n";
		a[min]->Xuat();
	}
}

/*
	Hàm xuất thông tin lập trình viên có lương cao nhất
	Input: Danh sách nhân viên hiện tại
	Output: Thông tin lập trình viên có lương cao nhất
	Hướng giải thuật:
	- Chỉ xét các đối tượng LapTrinhVien
	- Tìm lập trình viên có lương lớn nhất
	- Xuất thông tin lập trình viên đó
	- Nếu không có lập trình viên thì thông báo
*/
void DSNhanVien::XuatTTLTVLuongCaoNhat() {
	if (n == 0) cout << "Danh sach rong\n";
	else {
		int max = -1;
		for (int i = 0;i < n;i++) {
			if (dynamic_cast<KiemChungVien*>(a[i])) continue;
			if (max == -1) {
				max = i;
				continue;
			}
			if (a[i]->TinhLuong() > a[max]->TinhLuong()) max = i;
		}
		if (max == -1) cout << "Khong co lap trinh vien\n";
		else {
			cout << "Thong tin lap trinh vien co luong thap nhat:\n";
			a[max]->Xuat();
		}
	}
}

/*
	Hàm xuất thông tin kiểm chứng viên có lương thấp nhất
	Input: Danh sách nhân viên hiện tại
	Output: Thông tin kiểm chứng viên có lương thấp nhất
	Hướng giải thuật:
	- Chỉ xét các đối tượng KiemChungVien
	- Tìm kiểm chứng viên có lương nhỏ nhất
	- Xuất thông tin kiểm chứng viên đó
	- Nếu không có kiểm chứng viên thì thông báo
*/
void DSNhanVien::XuatTTKCVLuongThapNhat() {
	if (n == 0) cout << "Danh sach rong\n";
	else {
		int min = -1;
		for (int i = 0;i < n;i++) {
			if (dynamic_cast<LapTrinhVien*>(a[i])) continue;
			if (min == -1) {
				min = i;
				continue;
			}
			if (a[i]->TinhLuong() < a[min]->TinhLuong()) min = i;
		}
		if (min == -1) cout << "Khong co kiem chung vien\n";
		else {
			cout << "Thong tin kiem chung vien co luong thap nhat:\n";
			a[min]->Xuat();
		}

	}
}