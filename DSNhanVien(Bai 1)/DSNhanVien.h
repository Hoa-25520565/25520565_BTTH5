#pragma once
#include <vector>
#include "NhanVienSX.h"
#include "NhanVienVP.h"

class DSNhanVien {
private:
	int n;
	std::vector<NhanVien*> ds;
public:
	DSNhanVien(int n = 0);
	~DSNhanVien();
	void Nhap();
	void Xuat();
	double TinhTongLuong();
	void TimNVVPTuoiCaoNhat();
	void TimNVSXLuongThapNhat();
};