#pragma once
#include "GiaoDich.h"
class NhaPho :public GiaoDich {
private:
	std::string Loai;
public:
	NhaPho(std::string Loai = "");
	void Nhap() override;
	void Xuat() override;
	double TinhThanhTien() override;
};