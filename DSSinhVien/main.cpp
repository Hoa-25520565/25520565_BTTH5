#include <iostream>
#include "DSSinhVien.h"
using namespace std;

int main() {
	DSSinhVien a;
	cout << "Nhap danh sach sinh vien:\n";
	a.Nhap();
	cout << "Danh sach sinh vien da nhap:\n";
	a.Xuat();
	cout << endl;
	a.XuatDSSVDuDKTN();
	cout << endl;
	a.XuatDSSVKhongDuDKTN();
	cout << endl;
	a.TimSVDHCoDTBCaoNhat();
	cout << endl;
	a.TimSVCDCoDTBCaoNhat();
	cout << endl;
	a.DemSoSVKhongDuDKTN();
}