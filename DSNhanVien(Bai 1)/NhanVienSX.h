#pragma once
#include "NhanVien.h"

class NhanVienSX :public NhanVien {
private:
	double LuongCB;
	int SoSP;
public:
	NhanVienSX(double luongcb = 0, int sosp = 0);
	void Nhap() override;
	void Xuat() override;
	double TinhLuong() override;
};