#include <iostream>
#include "KHLoaiC.h"
using namespace std;

/*
	Hàm tính tổng tiền phải trả của khách hàng loại C
	Input: Khách hàng loại C hiện tại
	Output: Tổng tiền phải trả của khách hàng loại C
	Hướng giải thuật:
	- Khách hàng loại C được giảm 50%
	- Sau đó cộng thêm 10% thuế VAT
*/
void KHLoaiC::TinhTongTienPhaiTra() {
	TongTienPhaiTra = SoLuongHang * DonGiaHang * 0.5 * 1.1;
}