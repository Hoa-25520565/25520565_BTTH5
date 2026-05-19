#include <iostream>
#include "DSKhachHang.h"
using namespace std;

/*
	Constructor có tham số
	Input: Ba số nguyên x, y, z
	Output: Khởi tạo danh sách khách hàng
	Hướng giải thuật:
	Gán các giá trị x, y, z cho thuộc tính của đối tượng
*/
DSKhachHang::DSKhachHang(int x, int y, int z) :x(x), y(y), z(z) {}

/*
	Destructor
	Input: Không có
	Output: Giải phóng bộ nhớ động của danh sách khách hàng
	Hướng giải thuật:
	- Duyệt toàn bộ danh sách khách hàng
	- Giải phóng từng đối tượng bằng delete
*/
DSKhachHang::~DSKhachHang() {
	for (int i = 0;i < x + y + z;i++) {
		delete a[i];
	}
}

/*
	Hàm nhập danh sách khách hàng
	Input: Dữ liệu nhập từ bàn phím
	Output: Danh sách khách hàng được khởi tạo
	Hướng giải thuật:
	- Nhập số lượng khách hàng từng loại
	- Với mỗi khách hàng:
		+ Khởi tạo đối tượng tương ứng
		+ Nhập thông tin khách hàng
		+ Tính tổng tiền phải trả
		+ Thêm vào danh sách
*/
void DSKhachHang::Nhap() {
	cin >> x >> y >> z;
	for (int i = 0;i < x + y + z;i++) {
		KhachHang* s = nullptr;
		if (i < x) s = new KHLoaiA;
		else if (i >= x && i < x + y) s = new KHLoaiB;
		else s = new KHLoaiC;
		s->Nhap();
		s->TinhTongTienPhaiTra();
		a.push_back(s);
	}
}

/*
	Hàm xuất danh sách khách hàng
	Input: Danh sách khách hàng
	Output: Hiển thị thông tin các khách hàng và tổng tiền công ty thu được
	Hướng giải thuật:
	- In số lượng khách hàng từng loại
	- Duyệt danh sách và xuất từng khách hàng
	- In tổng tiền công ty thu được
*/
void DSKhachHang::Xuat() {
	cout << x << " " << y << " " << z << endl;
	for (int i = 0;i < x + y + z;i++) {
		a[i]->Xuat();
	}
	cout << TinhTongTienCTThuDuoc();
}

/*
	Hàm tính tổng tiền công ty thu được
	Input: Danh sách khách hàng
	Output: Tổng tiền công ty thu được
	Hướng giải thuật:
	- Duyệt toàn bộ danh sách khách hàng
	- Cộng tổng tiền phải trả của từng khách hàng
	- Trả về tổng tiền
*/
double DSKhachHang::TinhTongTienCTThuDuoc() {
	double s = 0;
	for (int i = 0;i < x + y + z;i++) {
		s += a[i]->LayTongTienPhaiTra();
	}
	return s;
}