#include <iostream>
#include "DSNhanVien.h"
using namespace std;

int main() {
	DSNhanVien a;
	cout << "Nhap danh sach nhan vien:\n";
	a.Nhap();
	cout << endl;
	cout << "Danh sach nhan vien da nhap:\n";
	a.Xuat();
	cout << endl;
	a.XuatDSNVCoLuongThapHonTB();
	cout << endl;
	a.XuatTTNVLuongCaoNhat();
	cout << endl;
	a.XuatTTNVLuongThapNhat();
	cout << endl;
	a.XuatTTLTVLuongCaoNhat();
	cout << endl;
	a.XuatTTKCVLuongThapNhat();
}