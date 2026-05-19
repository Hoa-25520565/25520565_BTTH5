#pragma once
#include <string>

class NhanVien {
protected:
	std::string MaNV;
	std::string HoTen;
	int Tuoi;
	std::string SDT;
	std::string email;
	double LuongCB;
	double Luong;
public:
	NhanVien(std::string MaNV = "", std::string HoTen = "", int Tuoi = 0, std::string SDT = "", std::string email = "", double LuongCB = 0, double Luong = 0);
	virtual ~NhanVien() = default;
	virtual void Nhap();
	virtual void Xuat();
	virtual double TinhLuong() = 0;
};