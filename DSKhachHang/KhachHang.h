#pragma once
#include <string>

class KhachHang {
protected:
	std::string Ten;
	int SoLuongHang;
	double DonGiaHang;
	double TongTienPhaiTra;
public:
	KhachHang(std::string Ten = "", int SoLuongHang = 0, double DonGiaHang = 0, double TongTienPhaiTra = 0);
	virtual ~KhachHang() = default;
	virtual void Nhap();
	virtual void Xuat();
	virtual void TinhTongTienPhaiTra() = 0;
	double LayTongTienPhaiTra();
};