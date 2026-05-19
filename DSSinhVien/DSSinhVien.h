#pragma once
#include <vector>
#include "SVCaoDang.h"
#include "SVDaiHoc.h"

class DSSinhVien {
private:
	int n;
	std::vector<SinhVien*> a;
public:
	DSSinhVien(int n = 0);
	~DSSinhVien();
	void Nhap();
	void Xuat();
	void XuatDSSVDuDKTN();
	void XuatDSSVKhongDuDKTN();
	void TimSVDHCoDTBCaoNhat();
	void TimSVCDCoDTBCaoNhat();
	void DemSoSVKhongDuDKTN();
};