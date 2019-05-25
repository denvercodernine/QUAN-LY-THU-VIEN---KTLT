#include "pch.h"
void bookList()
{
	system("cls");
	FILE *f = fopen(BOOK_STORAGE, "rb");
	if (f == NULL)
	{
		printf("Chua co du lieu!\n");
	}
	else
	{
		book b;
		while (fread(&b, sizeof(book), 1, f))
			if (strcmp(b.ISBN, "")) {
				std::cout << "--------------------" << std::endl;
				printBookInfo(b);
			}
	}
	if (f) {
		fclose(f);
	}
	system("PAUSE");
}
void searchBook()
{
	system("cls");
	FILE *f = fopen(BOOK_STORAGE, "rb");
	if (f == NULL)
	{
		printf("Chua co du lieu!\n");
	}
	else
	{
		printf(">1. Tim kiem bang ISBN\n");
		printf(">2. Tim kiem bang ten sach\n");
		int choose = 0;
		do
		{
			printf("Chon : ");
			scanf("%d", &choose);
		} while (choose < 1 || choose > 2);
		book b, tempb; bool found = false;
		if (choose == 1)
		{
			printf("Nhap ma so sach ISBN: ");
			while (getchar() != '\n');
			gets_s(b.ISBN);
			int i = 1;
			while (!feof(f)) {
				fread(&tempb, sizeof(book)*i, 1, f);
				if (strcmp(tempb.ISBN, b.ISBN) == 0) {
					found = true;
					printBookInfo(tempb);
					break;
				}
				else {
					i++;
				}
			}
		}
		else if (choose == 2)
		{
			printf("Nhap ten sach: ");
			while (getchar() != '\n');
			gets_s(b.title);
			int i = 1;
			while (!feof(f)) {
				fread(&tempb, sizeof(book)*i, 1, f);
				if (strcmp(tempb.title, b.title) == 0) {
					found = true;
					printBookInfo(tempb);
					break;
				}
				else {
					i++;
				}
			}
		}
		if (!found)
		{
			printf("Sach khong ton tai!\n");
		}
	}
	if (f != NULL) {
		fclose(f);
	}
	system("PAUSE");
}
void addBook()
{
	while (1)
	{
		system("cls");
		FILE *f = fopen(BOOK_STORAGE, "wb");
		book b, tempb;
		while (getchar() != '\n');
		printf("Ma so sach       : ");
		gets_s(b.ISBN);
		int i = 1;
		struct stat st;
		stat(BOOK_STORAGE, &st);
		while ((!feof(f)) && (st.st_size!=0)) {
			fread(&tempb, sizeof(book)*i, 1, f);
			if (strcmp(tempb.ISBN, b.ISBN) == 0) {
				std::cout << "Ma so sach da ton tai!" << std::endl;
				system("PAUSE");
				fclose(f);
				return;
			}
			else {
				i++;
			}
		}
		printf("Ten sach         : ");
		gets_s(b.title);
		printf("Tac gia          : ");
		gets_s(b.author);
		printf("Nha xuat ban     : ");
		gets_s(b.publisher);
		printf("Nam xuat ban     : ");
		scanf("%i", &b.year);
		while (getchar() != '\n');
		printf("The loai         : ");
		gets_s(b.gerne);
		printf("Gia sach         : ");
		gets_s(b.rack);
		printf("So luong         : ");
		scanf("%d", &b.count);
		b.issued = 0;

		fseek(f, 0, SEEK_END);
		fwrite(&b, sizeof(book), 1, f);

		printf("Them sach thanh cong!\n");
		fclose(f);
		printf("Bam 'y' de tiep tuc them sach, bam phim khac bat ki de tro ve!\n");
		if (_getch() != 'y')
			return;
	}
}
void deleteBook()
{
	system("cls");
	book b, tempb;
	FILE *f = fopen(BOOK_STORAGE, "rb");
	if (f == NULL)
	{
		printf("Chua co du lieu!\n");
		return;
	}
	while (1) {
		printf("Nhap ma so sach: ");
		while (getchar() != '\n');
		gets_s(b.ISBN);
		int i = 1; bool found = false;
		while (!feof(f)) {
			fread(&tempb, sizeof(book)*i, 1, f);
			if (strcmp(tempb.ISBN, b.ISBN) == 0) {
				b = tempb; found = true;
				break;
			}
			else {
				i++;
			}
		}
		if (!found) {
			fclose(f);
			std::cout << "Khong tim thay sach! An Y de tim lai hoac an phim khac de tro ve." << std::endl;
			if (_getch() != 'y')
				return;
			continue;
		}
		printBookInfo(b);
		if (b.issued > 0) {
			printf("Sach nay dang co doc gia muon!");
		}
		printf("Bam 'y' de xac nhan xoa, bam phim khac bat ki de huy!\n");
		if (_getch() == 'y') {
			strcpy(b.ISBN, "");
			fseek(f, -(int)sizeof(book), SEEK_CUR);
			fwrite(&b, sizeof(book), 1, f);
			printf("Xoa thanh cong!\n");
		}
		else {
			printf("Thao tac xoa da bi huy!\n");
		}
		fclose(f);
	}
}
void updateBookInfo()
{
	system("cls");
	book b, tempb;
	FILE *f = fopen(BOOK_STORAGE, "rb+");
	if (f == NULL)
	{
		printf("Chua co du lieu!\n");
		return;
	}
	while (1) {
		printf("Nhap ma so sach: ");
		while (getchar() != '\n');
		gets_s(b.ISBN);
		int i = 1; bool found = false;
		while (!feof(f)) {
			fread(&tempb, sizeof(book)*i, 1, f);
			if (strcmp(tempb.ISBN, b.ISBN) == 0) {
				b = tempb; found = true;
				break;
			}
			else {
				i++;
			}
		}
		if (!found) {
			fclose(f);
			std::cout << "Khong tim thay sach! An Y de tim lai hoac an phim khac de tro ve." << std::endl;
			if (_getch() != 'y')
				return;
			continue;
		}
		printf("Cap nhat ten sach     : ");
		gets_s(b.title);
		printf("Cap nhat tac gia      : ");
		gets_s(b.author);
		printf("Cap nhat nha xuat ban : ");
		gets_s(b.publisher);
		printf("Cap nhat nam xuat ban : ");
		scanf("%d", &b.year);
		while (getchar() != '\n');
		printf("Cap nhat the loai     : ");
		gets_s(b.gerne);
		printf("Cap nhat so luong     : ");
		scanf("%d", &b.count);
		printf("Bam 'y' de xac nhan cap nhat, bam phim bat ky khac de huy!\n");
		if (_getch() == 'y')
		{
			fseek(f, -(int)sizeof(book), SEEK_CUR);
			fwrite(&b, sizeof(book), 1, f);
			printf("Cap nhat thong tin thanh cong!\n");
		}
		else
			printf("Thao tac cap nhat da bi huy!\n");
		fclose(f);
	}
}
void printBookInfo(book b) {
	printf("ISBN                    :");
	puts(b.ISBN);
	printf("Ten sach                :");
	puts(b.title);
	printf("Tac gia                 :");
	puts(b.author);
	printf("Ten NXB                 :");
	puts(b.publisher);
	printf("Nam XB                  :");
	printf("%d \n",b.year);
	printf("The loai                :");
	puts(b.gerne);
	printf("Gia                     :");
	puts(b.rack);
	printf("So luong                :");
	printf("%d \n", b.count);
}