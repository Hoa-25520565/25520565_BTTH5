#pragma once
#include "SinhVien.h"

class SVCaoDang :public SinhVien {
private:
	double DiemThiTN;
public:
	SVCaoDang(double DiemThiTN = 0);
	void Nhap() override;
	void Xuat() override;
	bool XetDKTotNghiep() override;
};