#pragma once
#include <string>

class SinhVien {
protected:
	std::string MSSV;
	std::string HoTen;
	std::string DiaChi;
	int TongTC;
	double DTB;
public:
	SinhVien(std::string MSSV = "", std::string HoTen = "", std::string DiaChi = "", int TongTC = 0, double DTB = 0);
	virtual ~SinhVien() = default;
	virtual void Nhap();
	virtual void Xuat();
	virtual bool XetDKTotNghiep() = 0;
	virtual double LayDTB();
};