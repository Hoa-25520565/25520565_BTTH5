#pragma once
#include "NhanVien.h"

class KiemChungVien :public NhanVien {
private:
	int SoLoiPHDuoc;
public:
	KiemChungVien(int SoLoiPHDuoc = 0);
	void Nhap() override;
	void Xuat() override;
	double TinhLuong() override;
};