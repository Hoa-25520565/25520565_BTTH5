#pragma once
#include <vector>
#include "KHLoaiA.h"
#include "KHLoaiB.h"
#include "KHLoaiC.h"

class DSKhachHang {
private:
	int x;
	int y;
	int z;
	std::vector<KhachHang*> a;
public:
	DSKhachHang(int x = 0, int y = 0, int z = 0);
	~DSKhachHang();
	void Nhap();
	void Xuat();
	double TinhTongTienCTThuDuoc();
};