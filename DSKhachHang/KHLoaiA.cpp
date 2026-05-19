#include <iostream>
#include "KHLoaiA.h"

/*
	Hàm tính tổng tiền phải trả của khách hàng loại A
	Input: Khách hàng loại A hiện tại
	Output: Tổng tiền phải trả của khách hàng loại A
	Hướng giải thuật:
	- Tính tiền hàng = SoLuongHang * DonGiaHang
	- Cộng thêm 10% thuế VAT
*/
void KHLoaiA::TinhTongTienPhaiTra() {
	TongTienPhaiTra = SoLuongHang * DonGiaHang * 1.1;
}