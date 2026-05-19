#include <iostream>
#include "KHLoaiB.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số nguyên SoNamThanThiet
	Output: Khởi tạo khách hàng loại B với số năm thân thiết tương ứng
	Hướng giải thuật:
	Gán SoNamThanThiet cho thuộc tính của đối tượng
*/
KHLoaiB::KHLoaiB(int SoNamThanThiet) :SoNamThanThiet(SoNamThanThiet) {}

/*
	Hàm nhập thông tin khách hàng loại B
	Input: Dữ liệu nhập từ bàn phím
	Output: Gán thông tin cho khách hàng loại B
	Hướng giải thuật:
	- Gọi hàm nhập của lớp KhachHang
	- Nhập số năm thân thiết
*/
void KHLoaiB::Nhap() {
	KhachHang::Nhap();
	cin >> SoNamThanThiet;
}

/*
	Hàm tính tổng tiền phải trả của khách hàng loại B
	Input: Khách hàng loại B hiện tại
	Output: Tổng tiền phải trả của khách hàng loại B
	Hướng giải thuật:
	- Tính phần trăm khuyến mãi:
		+ Mỗi năm thân thiết giảm 5%
		+ Tối đa giảm 50%
	- Tính tiền sau giảm giá
	- Cộng thêm 10% thuế VAT
*/
void KHLoaiB::TinhTongTienPhaiTra() {
	double KM = (SoNamThanThiet * 0.05 < 0.5) ? SoNamThanThiet * 0.05 : 0.5;
	TongTienPhaiTra = SoLuongHang * DonGiaHang * (1 - KM) * 1.1;
}