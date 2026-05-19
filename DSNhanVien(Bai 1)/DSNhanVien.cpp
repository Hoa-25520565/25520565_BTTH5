#include <iostream>
#include "DSNhanVien.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số nguyên n
	Output: Khởi tạo danh sách nhân viên với số lượng nhân viên tương ứng
	Hướng giải thuật:
	Gán giá trị n cho thuộc tính n
*/
DSNhanVien::DSNhanVien(int n) :n(n) {}

/*
	Destructor
	Input: Không có
	Output: Giải phóng bộ nhớ động của danh sách nhân viên
	Hướng giải thuật:
	- Duyệt toàn bộ danh sách nhân viên
	- Giải phóng từng đối tượng nhân viên bằng delete
*/
DSNhanVien::~DSNhanVien() {
	for (int i = 0;i < n;i++) {
		delete ds[i];
	}
}

/*
	Hàm nhập danh sách nhân viên
	Input: Dữ liệu nhập từ bàn phím
	Output: Danh sách nhân viên được khởi tạo và lưu vào vector
	Hướng giải thuật:
	- Nhập số lượng nhân viên
	- Với mỗi nhân viên:
		+ Nhập loại nhân viên
		+ Khởi tạo đối tượng tương ứng
		+ Nhập thông tin và tính lương
		+ Thêm vào danh sách
*/
void DSNhanVien::Nhap() {
	cout << "Nhap so luong nhan vien: ";
	while (!(cin >> n) || n < 0 || cin.peek() != '\n') {
		cout << "So luong khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	for (int i = 0;i < n;i++) {
		int loai;
		cout << "Nhap loai nhan vien cua nhan vien thu " << i + 1 << ":\n";
		cout << "1. Nhan vien van phong\n";
		cout << "2. Nhan vien san xuat\n";
		while (!(cin >> loai) || (loai != 1 && loai != 2) || cin.peek() != '\n') {
			cout << "Loai nhan vien khong hop le, nhap lai: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		NhanVien* nv = nullptr;
		if (loai == 1)
			nv = new NhanVienVP;
		else
			nv = new NhanVienSX;
		nv->Nhap();
		nv->TinhLuong();
		ds.push_back(nv);
	}
}

/*
	Hàm xuất danh sách nhân viên
	Input: Danh sách nhân viên hiện tại
	Output: Hiển thị thông tin toàn bộ nhân viên
	Hướng giải thuật:
	- Nếu danh sách rỗng thì thông báo
	- Ngược lại duyệt và xuất từng nhân viên
*/
void DSNhanVien::Xuat() {
	if (n == 0) cout << "Danh sach rong\n";
	else
	{
		for (int i = 0;i < n;i++) {
			cout << "Nhan vien thu " << i + 1 << ": ";
			ds[i]->Xuat();
		}
	}
}

/*
	Hàm tính tổng lương của tất cả nhân viên
	Input: Danh sách nhân viên hiện tại
	Output: Tổng lương của tất cả nhân viên
	Hướng giải thuật:
	- Duyệt danh sách nhân viên
	- Cộng lương từng nhân viên vào biến tổng
*/
double DSNhanVien::TinhTongLuong() {
	double s = 0;
	for (int i = 0;i < n;i++) {
		s += ds[i]->LayLuong();
	}
	return s;
}

/*
	Hàm tìm nhân viên sản xuất có lương thấp nhất
	Input: Danh sách nhân viên hiện tại
	Output: Thông tin nhân viên sản xuất có lương thấp nhất
	Hướng giải thuật:
	- Duyệt danh sách nhân viên
	- Chỉ xét các nhân viên sản xuất
	- Tìm nhân viên sản xuất có lương nhỏ nhất
	- Xuất thông tin nhân viên tìm được
	- Nếu không có nhân viên sản xuất nào thì thông báo
*/
void DSNhanVien::TimNVSXLuongThapNhat() {
	if (n == 0) cout << "Danh sach rong\n";
	else {
		int min = -1;
		for (int i = 1;i < n;i++) {
			if (!dynamic_cast<NhanVienSX*>(ds[i])) continue;
			if (min == -1) {
				min = i;
				continue;
			}
			if (ds[min]->LayLuong() > ds[i]->LayLuong()) min = i;
		}
		if (min == -1) {
			cout << "Cong ty khong co nhan vien san xuat\n";
			return;
		}
		cout << "Thong tin nhan vien san xuat co luong thap nhat:\n";
		ds[min]->Xuat();
	}
}

/*
	Hàm so sánh tuổi của hai nhân viên
	Input: Hai con trỏ nhân viên a và b
	Output: true nếu a lớn tuổi hơn b, ngược lại false
	Hướng giải thuật:
	- Tách ngày, tháng, năm từ chuỗi ngày sinh
	- So sánh năm sinh, tháng sinh và ngày sinh
	- Người có ngày sinh nhỏ hơn thì lớn tuổi hơn
*/
bool LonTuoiHon(NhanVien* a, NhanVien* b) {
	string ns1 = a->LayNgaySinh();
	string ns2 = b->LayNgaySinh();
	int ngay1 = stoi(ns1.substr(0, 2));
	int thang1 = stoi(ns1.substr(3, 2));
	int nam1 = stoi(ns1.substr(6, 4));
	int ngay2 = stoi(ns2.substr(0, 2));
	int thang2 = stoi(ns2.substr(3, 2));
	int nam2 = stoi(ns2.substr(6, 4));
	if (nam1 != nam2)
		return nam1 < nam2;
	if (thang1 != thang2)
		return thang1 < thang2;
	return ngay1 < ngay2;
}

/*
	Hàm tìm nhân viên văn phòng lớn tuổi nhất
	Input: Danh sách nhân viên hiện tại
	Output: Thông tin nhân viên văn phòng lớn tuổi nhất
	Hướng giải thuật:
	- Duyệt danh sách nhân viên
	- Chỉ xét các nhân viên văn phòng
	- Dùng hàm LonTuoiHon để tìm người lớn tuổi nhất
	- Xuất thông tin nhân viên tìm được
	- Nếu không có nhân viên văn phòng nào thì thông báo
*/
void DSNhanVien::TimNVVPTuoiCaoNhat() {
	if (n == 0) cout << "Danh sach rong";
	else {
		int max = -1;
		for (int i = 0; i < n; i++) {
			if (!dynamic_cast<NhanVienVP*>(ds[i]))
				continue;
			if (max == -1) {
				max = i;
				continue;
			}
			if (LonTuoiHon(ds[i], ds[max])) max = i;
		}
		if (max == -1) {
			cout << "Cong ty khong co nhan vien van phong\n";
			return;
		}
		cout << "Thong tin nhan vien van phong lon tuoi nhat:\n";
		ds[max]->Xuat();
	}
}