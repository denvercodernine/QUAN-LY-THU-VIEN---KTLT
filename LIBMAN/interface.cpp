#include "pch.h"
using namespace std;

void menu(user &currentUser) {
	while (1) {
		system("cls");
		switch (currentUser.permissionLevel)
		{
		case PERM_ADMIN:
		{
			cout << "1. QUAN LY NGUOI DUNG" << endl;
			cout << "2. QUAN LY DOC GIA" << endl;
			cout << "3. QUAN LY SACH" << endl;
			cout << "4. QUAN LY MUON TRA SACH" << endl;
			cout << "5. THONG KE" << endl;
			cout << "0. DANG XUAT" << endl;
			cout << "HAY CHON CONG VIEC: ";
			int choose = 0;
			cin >> choose;
			switch (choose)
			{
			case 1: funcUser(currentUser); break;
			case 2: funcSubscriber(currentUser); break;
			case 3: funcBook(currentUser); break;
			case 4: funcLending(currentUser); break;
			case 5: funcReport(currentUser); break;
			case 0: cout << "CHUONG TRINH SE THOAT" << endl; exit(0); break;
			default: break;
			}
		}
			break;
		case PERM_MANAGER:
		{
			cout << "1. QUAN LY NGUOI DUNG" << endl;
			cout << "2. QUAN LY DOC GIA" << endl;
			cout << "3. QUAN LY SACH" << endl;
			cout << "4. QUAN LY MUON TRA SACH" << endl;
			cout << "5. THONG KE" << endl;
			cout << "0. DANG XUAT" << endl;
			cout << "HAY CHON CONG VIEC: ";
			int choose = 0;
			cin >> choose;
			switch (choose)
			{
			case 1: funcUserLimited(currentUser); break;
			case 2: funcSubscriber(currentUser); break;
			case 3: funcBook(currentUser); break;
			case 4: funcLending(currentUser); break;
			case 5: funcReport(currentUser); break;
			case 0: cout << "CHUONG TRINH SE THOAT" << endl; exit; break;
			default: break;
			}
		}
			break;
		case PERM_OPERATOR:
		{
			cout << "1. QUAN LY NGUOI DUNG" << endl;
			cout << "2. QUAN LY DOC GIA" << endl;
			cout << "3. QUAN LY SACH" << endl;
			cout << "4. QUAN LY MUON TRA SACH" << endl;
			cout << "5. THONG KE" << endl;
			cout << "0. DANG XUAT" << endl;
			cout << "HAY CHON CONG VIEC: ";
			int choose = 0;
			cin >> choose;
			switch (choose)
			{
			case 1: funcUserLimited(currentUser); break;
			case 2: funcSubscriberLimited(currentUser); break;
			case 3: funcBookLimited(currentUser); break;
			case 4: funcLending(currentUser); break;
			case 5: funcReportLimited(currentUser); break;
			case 0: cout << "CHUONG TRINH SE THOAT" << endl; exit; break;
			default: break;
			}
		}
			break;
		default:
			break;
		}
	}
}

//1.1,1.2,1.3,1.4
void funcUserLimited(user &currentUser) {
	system("cls");
	cout << "1. THAY DOI MAT KHAU" << endl;
	cout << "2. CAP NHAT THONG TIN CA NHAN" << endl;
	cout << "0. THOAT" << endl;
	cout << "HAY CHON CONG VIEC: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1: changePassword(currentUser); break;
	case 2: updateUserInfo(currentUser); break;
	case 0:
		std::cout << "CHUONG TRINH SE THOAT" << std::endl; pause;
		break;
	default: break;
	}
};

//1.
void funcUser(user &currentUser) {
	system("cls");
	cout << "1. THAY DOI MAT KHAU" << endl;
	cout << "2. CAP NHAT THONG TIN CA NHAN" << endl;
	cout << "3. TAO NGUOI DUNG" << endl;
	cout << "4. PHAN QUYEN NGUOI DUNG" << endl;
	cout << "0. THOAT" << endl;
	cout << "HAY CHON CONG VIEC: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1: changePassword(currentUser); break;
	case 2: updateUserInfo(currentUser); break;
	case 3: userRegister(); break;
	case 4: changePermissions(); break;
	case 0:
		std::cout << "CHUONG TRINH SE THOAT" << std::endl; pause;
		break;
	default: break;
	}
};

//2.
void funcSubscriber(user &currentUser) {
	system("cls");
	cout << "1. XEM DANH SACH DOC GIA" << endl;
	cout << "2. THEM DOC GIA" << endl;
	cout << "3. CHINH SUA THONG TIN DOC GIA" << endl;
	cout << "4. TIM KIEM DOC GIA" << endl;
	cout << "5. XOA DOC GIA" << endl;
	cout << "0. THOAT" << endl;
	cout << "HAY CHON CONG VIEC: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1: subscriberList(); break;
	case 2: addsubscriber(); break;
	case 3: updatesubscriberInfo(); break;
	case 4: searchsubscriber(); break;
	case 5: deletesubscriber(); break;
	case 0:
		std::cout << "CHUONG TRINH SE THOAT" << std::endl; pause;
		break;
	default: break;
	}
};

//2.1,2.2,2.3,2.5,2.6
void funcSubscriberLimited(user &currentUser) {
	system("cls");
	cout << "1. XEM DANH SACH DOC GIA" << endl;
	cout << "2. THEM DOC GIA" << endl;
	cout << "3. CHINH SUA THONG TIN DOC GIA" << endl;
	cout << "4. TIM KIEM DOC GIA" << endl;
	cout << "0. THOAT" << endl;
	cout << "HAY CHON CONG VIEC: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1: subscriberList(); break;
	case 2: addsubscriber(); break;
	case 3: updatesubscriberInfo(); break;
	case 4: searchsubscriber(); break;
	case 0:
		std::cout << "CHUONG TRINH SE THOAT" << std::endl; pause;
		break;
	default: break;
	}
};

//3.
void funcBook(user &currentUser) {
	system("cls");
	cout << "1. XEM DANH SACH CAC SACH TRONG THU VIEN" << endl;
	cout << "2. THEM SACH" << endl;
	cout << "3. CHINH SUA THONG TIN SACH" << endl;
	cout << "4. TIM KIEM SACH" << endl;
	cout << "5. XOA SACH" << endl;
	cout << "0. THOAT" << endl;
	cout << "HAY CHON CONG VIEC: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1: bookList(); break;
	case 2: addBook(); break;
	case 3: updateBookInfo(); break;
	case 4: searchBook(); break;
	case 5: deleteBook(); break;
	case 0:
		std::cout << "CHUONG TRINH SE THOAT" << std::endl; pause;
		break;
	default: break;
	}
};

//3.5,3.6
void funcBookLimited(user &currentUser) {
	system("cls");
	cout << "1. TIM KIEM SACH" << endl;
	cout << "0. THOAT" << endl;
	cout << "HAY CHON CONG VIEC: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1: searchBook(); break;
	case 0:
		std::cout << "CHUONG TRINH SE THOAT" << std::endl; pause;
		break;
	default: break;
	}
};

//4.,5.
void funcLending(user &currentUser) {
	system("cls");
	cout << "1. LAP PHIEU MUON SACH" << endl;
	cout << "2. LAP PHIEU TRA SACH (CHUC NANG CHUA SU DUNG DUOC):" << endl;
	cout << "0. THOAT" << endl;
	cout << "HAY CHON CONG VIEC: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1: issueBook(); break;
	case 0:
		std::cout << "CHUONG TRINH SE THOAT" << std::endl; pause;
		break;
	default: break;
	}
};

//6.
void funcReport(user &currentUser) {
	system("cls");
	cout << "1. SO LUONG SACH TRONG THU VIEN:" << endl;
	cout << "2. SO LUONG SACH THEO THE LOAI" << endl;
	cout << "3. SO LUONG DOC GIA" << endl;
	cout << "4. SO LUONG DOC GIA THEO GIOI TINH" << endl;
	cout << "5. SO SACH DANG DUOC MUON" << endl;
	cout << "6. DANH SACH DOC GIA TRE HAN (CHUA DUNG DUOC)" << endl;
	cout << "0. THOAT" << endl;
	cout << "HAY CHON CONG VIEC: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1: numofbook(); break;
	case 2: numofbook_gerne(); break;
	case 3: numofsubscriber(); break;
	case 4: numofsubs_gender(); break;
	case 5: Numofbook_lend(); break;
	case 0:
		std::cout << "CHUONG TRINH SE THOAT" << std::endl; pause;
		break;
	default: break;
	}
};

//6.5,6.6
void funcReportLimited(user &currentUser) {
	system("cls");
	cout << "1. SO SACH DANG DUOC MUON" << endl;
	cout << "2. DANH SACH DOC GIA TRE HAN (CHUA DUNG DUOC)" << endl;
	cout << "0. THOAT" << endl;
	cout << "HAY CHON CONG VIEC: ";
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1: Numofbook_lend(); break;
	case 0:
		std::cout << "CHUONG TRINH SE THOAT" << std::endl; pause;
		break;
	default: break;
	}
};

