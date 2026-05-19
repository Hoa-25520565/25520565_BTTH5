#pragma once
#include "NhanVien.h"

class LapTrinhVien :public NhanVien {
private:
	double SoGioOT;
public:
	LapTrinhVien(double SoGioOT = 0);
	void Nhap() override;
	void Xuat() override;
	double TinhLuong() override;
};