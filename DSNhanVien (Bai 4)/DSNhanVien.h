#pragma once
#include <vector>
#include "LapTrinhVien.h"
#include "KiemChungVien.h"

class DSNhanVien {
private:
	int n;
	std::vector<NhanVien*> a;
public:
	DSNhanVien(int n = 0);
	~DSNhanVien();
	void Nhap();
	void Xuat();
	double TinhLuongTB();
	void XuatDSNVCoLuongThapHonTB();
	void XuatTTNVLuongCaoNhat();
	void XuatTTNVLuongThapNhat();
	void XuatTTLTVLuongCaoNhat();
	void XuatTTKCVLuongThapNhat();
};