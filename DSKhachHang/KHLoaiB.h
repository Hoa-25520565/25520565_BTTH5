#pragma once
#include "KhachHang.h"

class KHLoaiB :public KhachHang {
private:
	int SoNamThanThiet;
public:
	KHLoaiB(int SoNamThanThiet = 0);
	void Nhap() override;
	void TinhTongTienPhaiTra() override;
};