#pragma once
#include <string>
class NhanVien {
protected:
	std::string HoTen;
	std::string NgaySinh;
	double Luong;
public:
	NhanVien(std::string ht = "", std::string ns = "", double luong = 0);
	virtual ~NhanVien() = default;
	virtual void Nhap();
	virtual void Xuat();
	virtual double TinhLuong() = 0;
	double LayLuong();
	std::string LayNgaySinh();
};