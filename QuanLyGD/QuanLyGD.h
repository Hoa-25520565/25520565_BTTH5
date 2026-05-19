#pragma once
#include <vector>
#include "Dat.h"
#include "NhaPho.h"
#include "CanHoChungCu.h"

class QuanLyGD {
private:
	int n;
	std::vector<GiaoDich*> a;
public:
	QuanLyGD(int n = 0);
	~QuanLyGD();
	void Nhap();
	void Xuat();
	void TinhTongSL();
	void TinhTBThanhTienGDCHCC();
	void TimGDNhaPhoCoGTCaoNhat();
	void XuatGDCua12_2024();
};