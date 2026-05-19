#pragma once
#include "SinhVien.h"

class SVDaiHoc :public SinhVien {
private:
	std::string TenLV;
	double DiemLV;
public:
	SVDaiHoc(std::string TenLV = "", double DiemLV = 0);
	void Nhap() override;
	void Xuat() override;
	bool XetDKTotNghiep() override;
};