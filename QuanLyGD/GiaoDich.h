#pragma once
#include <string>
class GiaoDich {
protected:
	std::string MaGD;
	std::string NgayGD;
	double DonGia;
	double DienTich;
	double ThanhTien;
public:
	GiaoDich(std::string MaGD = "", std::string NgayGD = "", double DonGia = 0, double DienTich = 0, double ThanhTien = 0);
	virtual ~GiaoDich() = default;
	virtual void Nhap();
	virtual void Xuat();
	virtual double TinhThanhTien() = 0;
	virtual std::string LayNgayGD();
};