#pragma once
#include "GiaoDich.h"
class Dat :public GiaoDich {
private:
	std::string Loai;
public:
	Dat(std::string Loai = "");
	void Nhap() override;
	void Xuat() override;
	double TinhThanhTien();
};