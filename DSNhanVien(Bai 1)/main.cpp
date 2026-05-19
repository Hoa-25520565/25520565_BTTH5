#include <iostream>
#include "DSNhanVien.h"
using namespace std;

int main() {
	DSNhanVien a;
	cout << "Nhap danh sach nhan vien cua cong ty:\n";
	a.Nhap();
	cout << endl;
	cout << "Danh sach nhan vien cua cong ty:\n";
	a.Xuat();
	cout << endl;
	cout << "Tong luong cong ty phai tra: " << a.TinhTongLuong() << endl;
	cout << endl;
	a.TimNVSXLuongThapNhat();
	cout << endl;
	a.TimNVVPTuoiCaoNhat();
}