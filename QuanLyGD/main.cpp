#include <iostream>
#include "QuanLyGD.h"
using namespace std;

int main() {
	QuanLyGD a;
	cout << "Nhap danh sach cac giao dich:\n";
	a.Nhap();
	cout << endl;
	a.TinhTongSL();
	cout << endl;
	a.TinhTBThanhTienGDCHCC();
	cout << endl;
	a.TimGDNhaPhoCoGTCaoNhat();
	cout << endl;
	a.XuatGDCua12_2024();
}