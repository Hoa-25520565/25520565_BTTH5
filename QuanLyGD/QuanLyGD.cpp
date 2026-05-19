#include <iostream>
#include <sstream>
#include <limits>
#include "QuanLyGD.h"
using namespace std;

/*
	Constructor có tham số
	Input: Số lượng giao dịch n
	Output: Khởi tạo danh sách quản lý giao dịch
	Hướng giải thuật:
	Gán giá trị n cho thuộc tính của đối tượng
*/
QuanLyGD::QuanLyGD(int n) :n(n) {}

/*
	Destructor
	Input: Không có
	Output: Giải phóng bộ nhớ động của danh sách giao dịch
	Hướng giải thuật:
	- Duyệt danh sách giao dịch
	- Giải phóng từng đối tượng bằng delete
*/
QuanLyGD::~QuanLyGD() {
	for (int i = 0;i < n;i++) {
		delete a[i];
	}
}

/*
	Hàm nhập danh sách giao dịch
	Input: Dữ liệu nhập từ bàn phím
	Output: Danh sách giao dịch được khởi tạo và lưu vào vector
	Hướng giải thuật:
	- Nhập số lượng giao dịch
	- Với mỗi giao dịch:
		+ Nhập loại giao dịch
		+ Khởi tạo đối tượng tương ứng
		+ Nhập thông tin giao dịch
		+ Tính thành tiền
		+ Thêm vào danh sách
*/
void QuanLyGD::Nhap() {
	cout << "Nhap so luong giao dich: ";
	while (!(cin >> n) || n < 0 || cin.peek() != '\n') {
		cout << "So luong khong hop le, nhap lai: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	for (int i = 0;i < n;i++) {
		int loai;
		cout << "Nhap loai giao dich cua giao dich thu " << i + 1 << ":\n";
		cout << "1.Dat\n";
		cout << "2.Nha pho\n";
		cout << "3.Can ho chung cu\n";
		while (!(cin >> loai) || (loai != 1 && loai != 2 && loai != 3) || cin.peek() != '\n') {
			cout << "Loai giao dich khong hop le, nhap lai: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		GiaoDich* s = nullptr;
		if (loai == 1)
			s = new Dat;
		else if (loai == 2)
			s = new NhaPho;
		else s = new CanHoChungCu;
		s->Nhap();
		a.push_back(s);
		a[i]->TinhThanhTien();
	}
}

/*
	Hàm xuất danh sách giao dịch
	Input: Danh sách giao dịch hiện tại
	Output: Hiển thị thông tin toàn bộ giao dịch
	Hướng giải thuật:
	- Nếu danh sách rỗng thì thông báo
	- Ngược lại duyệt và xuất từng giao dịch
*/
void QuanLyGD::Xuat() {
	if (n == 0) cout << "Danh sach rong\n";
	else {
		for (int i = 0;i < n;i++) {
			cout << "Giao dich thu " << i + 1 << ": ";
			a[i]->Xuat();
		}
	}
}

/*
	Hàm tính tổng số lượng từng loại giao dịch
	Input: Danh sách giao dịch hiện tại
	Output: Số lượng giao dịch đất, nhà phố và căn hộ chung cư
	Hướng giải thuật:
	- Duyệt danh sách giao dịch
	- Dùng dynamic_cast để xác định loại giao dịch
	- Đếm số lượng từng loại và xuất kết quả
*/
void QuanLyGD::TinhTongSL() {
	int n1 = 0, n2 = 0, n3 = 0;
	for (int i = 0;i < n;i++) {
		if (dynamic_cast<Dat*>(a[i])) n1++;
		else if (dynamic_cast<NhaPho*>(a[i])) n2++;
		else n3++;
	}
	cout << "Tong so luong giao dich Dat: " << n1 << endl;
	cout << "Tong so luong giao dich Nha pho: " << n2 << endl;
	cout << "Tong so luong giao dich Can ho chung cu: " << n3 << endl;
}

/*
	Hàm tính trung bình thành tiền giao dịch căn hộ chung cư
	Input: Danh sách giao dịch hiện tại
	Output: Giá trị trung bình thành tiền của giao dịch căn hộ chung cư
	Hướng giải thuật:
	- Duyệt danh sách giao dịch
	- Chỉ xét các giao dịch căn hộ chung cư
	- Tính tổng thành tiền và số lượng giao dịch
	- Tính trung bình và xuất kết quả
	- Nếu không có giao dịch căn hộ chung cư nào thì thông báo
*/
void QuanLyGD::TinhTBThanhTienGDCHCC() {
	double s = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (dynamic_cast<CanHoChungCu*>(a[i])) {
			s += a[i]->TinhThanhTien();
			t++;
		}
	}
	if (t == 0)
		cout << "Khong co giao dich Can ho chung cu\n";
	else
		cout << "Trung binh thanh tien cua giao dich Can ho chung cu: "
		<< s / t << endl;
}

/*
	Hàm tìm giao dịch nhà phố có giá trị cao nhất
	Input: Danh sách giao dịch hiện tại
	Output: Thông tin giao dịch nhà phố có giá trị cao nhất
	Hướng giải thuật:
	- Duyệt danh sách giao dịch
	- Chỉ xét các giao dịch nhà phố
	- Tìm giao dịch có thành tiền lớn nhất
	- Xuất thông tin giao dịch tìm được
	- Nếu không có giao dịch nhà phố nào thì thông báo
*/
void QuanLyGD::TimGDNhaPhoCoGTCaoNhat() {
	int max = -1;
	for (int i = 0;i < n;i++) {
		if (!(dynamic_cast<NhaPho*>(a[i]))) continue;
		if (max == -1) {
			max = i;
			continue;
		}
		if (a[max]->TinhThanhTien() < a[i]->TinhThanhTien())
			max = i;
	}
	if (max == -1)
		cout << "Khong co giao dich Nha pho\n";
	else {
		cout << "Giao dich Nha pho co gia tri cao nhat:\n";
		a[max]->Xuat();
	}
}

/*
	Hàm kiểm tra giao dịch có thuộc tháng 12 năm 2024 hay không
	Input: Chuỗi ngày dạng dd/mm/yyyy
	Output: true nếu thuộc tháng 12 năm 2024, ngược lại false
	Hướng giải thuật:
	- Dùng stringstream để tách ngày, tháng, năm
	- Kiểm tra tháng bằng 12 và năm bằng 2024
*/
bool KTLaThang12_2024(string s) {
	int d, m, y;
	char c1, c2;
	stringstream ss(s);
	ss >> d >> c1 >> m >> c2 >> y;
	return m == 12 && y == 2024;
}

/*
	Hàm xuất các giao dịch trong tháng 12 năm 2024
	Input: Danh sách giao dịch hiện tại
	Output: Các giao dịch thuộc tháng 12 năm 2024
	Hướng giải thuật:
	- Duyệt danh sách giao dịch
	- Kiểm tra ngày giao dịch bằng hàm KTLaThang12_2024
	- Nếu đúng thì xuất thông tin giao dịch
	- Nếu không có giao dịch nào thì thông báo
*/
void QuanLyGD::XuatGDCua12_2024() {
	int s = -1;
	for (int i = 0;i < n;i++) {
		if (KTLaThang12_2024(a[i]->LayNgayGD())) {
			if (s == -1) {
				cout << "Giao dich cua thang 12 nam 2024:\n";
				s = 1;
			}
			a[i]->Xuat();
		}
	}
	if (s == -1) cout << "Khong co giao dich cua thang 12 nam 2024\n";
}