#pragma once
#include "GiaoDich.h"
class CanHoChungCu :public GiaoDich {
private:
	std::string MaCan;
	int VTTang;
public:
	CanHoChungCu(std::string MaCan = "", int VTTang = 0);
	void Nhap() override;
	void Xuat() override;
	double TinhThanhTien() override;
};