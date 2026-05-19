#pragma once
#include "NhanVien.h"

class NhanVienVP :public NhanVien {
private:
	int SoNgayLamViec;
public:
	NhanVienVP(int snlv = 0);
	void Nhap() override;
	void Xuat() override;
	double TinhLuong() override;
};