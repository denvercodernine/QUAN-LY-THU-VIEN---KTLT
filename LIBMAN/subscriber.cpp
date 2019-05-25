
#include "pch.h"
int LastChar(char c)
{
	return (c == '\n' || c == EOF || c == ',' || c == ';');
}
char *readString(FILE *f, char *line)
{
	char c;
	int i = 0;
	while (!LastChar(c = fgetc(f)))
		line[i++] = c;
	line[i] = 0;
	return line;
}
void subscriberList()
{
	system("cls");
	FILE *f = fopen(SUBSCRIBER_STORAGE, "rb");
	if (f == NULL)
	{
		printf("Chua co du lieu!\n");
	}
	else
	{
		subscriber s;
		while (fread(&s, sizeof(subscriber), 1, f))
			if (strcmp(s.memberID, "")) {
				printSubscriberInfo(s);
			}
	}
	if (f) {
		fclose(f);
	}
	system("PAUSE");
}
void addsubscriber()
{
	while (1) {
		system("cls");
		subscriber s, temps;
		while (getchar() != '\n');
		FILE *f = fopen(SUBSCRIBER_STORAGE, "wb");
		std::cout << "Ma doc gia (toi da " << MEMBER_ID_LENGTH - 1 << " ki tu): " << std::endl;
		gets_s(s.memberID);
		int i = 1;
		struct stat st;
		stat(SUBSCRIBER_STORAGE, &st);
		while ((!feof(f)) && (st.st_size != 0)) {
			fread(&temps, sizeof(subscriber)*i, 1, f);
			if (strcmp(temps.memberID, s.memberID) == 0) {
				std::cout << "Ma so thanh vien da ton tai!" << std::endl;
				system("PAUSE");
				fclose(f);
				return;
			}
			else {
				i++;
			}
		}
		std::cout << "Ho ten (toi da " << NAME_LENGTH - 1 << " ki tu): " << std::endl;
		gets_s(s.info.name);
		std::cout << "So cmnd (toi da " << CMND_LENGTH - 1 << " ki tu): " << std::endl;
		gets_s(s.info.cmnd);
		printf("Ngay sinh (dd/mm/yyyy)     : ");
		char dateBuffer[11];
		gets_s(dateBuffer);
		strptime(dateBuffer, "%d/%m/%Y", &s.info.dateOfBirth);
		printf("Gioi tinh(Nam: 1 / Nu: 0)    : ");
		scanf("%d", &s.info.gender);
		while (getchar() != '\n');
		std::cout << "Email (toi da " << EMAIL_LENGTH - 1 << " ki tu): " << std::endl;
		gets_s(s.info.email);
		std::cout << "Dia chi (toi da " << ADDRESS_LENGTH - 1 << " ki tu): " << std::endl;
		gets_s(s.info.address);
		printf("Ngay lap the (dd/mm/yyyy)  : ");
		gets_s(dateBuffer);
		strptime(dateBuffer, "%d/%m/%Y", &s.startDate);
		s.expiryDate = s.startDate;
		s.expiryDate.tm_year = s.expiryDate.tm_year + 2;
		fclose(f);
		FILE *fm = fopen(SUBSCRIBER_STORAGE, "rb+");
		fseek(fm, 0, SEEK_END);
		fwrite(&s, sizeof(subscriber), 1, fm);
		printf("Dang ky thanh cong!\n");
		fclose(fm);
		std::cout << "An Y de thuc hien lai hoac an phim khac de tro ve." << std::endl;
		if (_getch() != 'y') {
			return;
		}
	}
}
void deletesubscriber()
{
	system("cls");
	FILE *f = fopen(SUBSCRIBER_STORAGE, "rb");
	if (f == NULL)
	{
		printf("Chua co du lieu!\n");
		return;
	}
	subscriber s, temps;
	while (1) {
		printf("Nhap ma doc gia: ");
		while (getchar() != '\n');
		gets_s(s.memberID);
		int i = 1; bool found = false;
		while (!feof(f)) {
			fread(&temps, sizeof(subscriber)*i, 1, f);
			if (strcmp(temps.memberID, s.memberID) == 0) {
				s = temps; found = true;
				break;
			}
			else {
				i++;
			}
		}
		if (!found) {
			fclose(f);
			std::cout << "Khong tim thay doc gia! An Y de tim lai hoac an phim khac de tro ve." << std::endl;
			if (_getch() != 'y')
				return;
			continue;
		}
		printSubscriberInfo(s);
		/*
		bookSlip bi;
		FILE *f = fopen("borrowList.csv", "r+t");
		while (!feof(f))
		{
			fscanf(f, "%d,", &bi.returned);
			if (!bi.returned)
				if (!strcmp(s.memberID, readString(f, bi.memberID)))
				{
					printf("Doc gia dang co sach muon!\n");
					break;
				}
			fscanf(f, "%*[^\n]\n", NULL);
		}
		*/
		printf("Bam 'y' de xac nhan xoa, bam phim khac bat ki de huy!\n");
		if (_getch() == 'y') {
			strcpy(s.memberID, "");
			fseek(f, -(int)sizeof(subscriber), SEEK_CUR);
			fwrite(&s, sizeof(subscriber), 1, f);
			printf("Xoa thanh cong!\n");
		}
		else {
			printf("Thao tac xoa da bi huy!\n");
		}
		fclose(f);
	}
}
void updatesubscriberInfo()
{
	system("cls");
	FILE *f = fopen(SUBSCRIBER_STORAGE, "rb+");
	if (f == NULL)
	{
		printf("Chua co du lieu!\n");
		return;
	}
	subscriber s,temps;
	while(1) {
		printf("Nhap ma doc gia: ");
		while (getchar() != '\n');
		gets_s(s.memberID);
		int i = 1; bool found = false;
		struct stat st;
		stat(SUBSCRIBER_STORAGE, &st);
		while ((!feof(f)) && (st.st_size != 0)) {
			fread(&temps, sizeof(subscriber)*i, 1, f);
			if (strcmp(temps.memberID, s.memberID) == 0) {
				s=temps; found = true;
				break;
			}
			else {
				i++;
			}
		}
		if (!found) {
			fclose(f);
			std::cout << "Khong tim thay doc gia! An Y de tim lai hoac an phim khac de tro ve." << std::endl;
			if (_getch() != 'y') {
				return;
			}
			continue;
		}
		printSubscriberInfo(s);
		printf("Ho ten moi                 : ");
		gets_s(s.info.name);
		printf("So cmnd moi                : ");
		gets_s(s.info.cmnd);
		printf("Ngay sinh (dd/mm/yyyy)     : ");
		char dateBuffer[11];
		gets_s(dateBuffer);
		strptime(dateBuffer, "%d/%m/%Y", &s.info.dateOfBirth);
		printf("Gioi tinh (Nam: 1 / Nu: 0)    : ");
		scanf("%d", &s.info.gender);
		while (getchar() != '\n');
		printf("Email moi                  : ");
		gets_s(s.info.email);
		printf("Dia chi moi                : ");
		gets_s(s.info.address);
		printf("Bam 'y' de xac nhan cap nhat, bam phim bat ky khac de huy!\n");
		if (_getch() == 'y')
		{
			fseek(f, -(int)sizeof(subscriber), SEEK_CUR);
			fwrite(&s, sizeof(subscriber), 1, f);
			printf("Cap nhat thong tin thanh cong!\n");
		}
		else
			printf("Thao tac cap nhat da bi huy!\n");
		fclose(f);
	}
}
void searchsubscriber()
{
	system("cls");
	FILE *f = fopen(SUBSCRIBER_STORAGE, "rb");
	if (f == NULL)
	{
		printf("Chua co du lieu!\n");
	}
	else
	{
		printf(">1. Tim kiem bang ma doc gia\n");
		printf(">2. Tim kiem bang so cmnd\n");
		printf(">3. Tim kiem bang ho ten\n");
		int choose = 0;
		do
		{
			printf("Chon : ");
			scanf("%d", &choose);
		} while (choose < 1 || choose > 3);
		subscriber s, temps; bool found = false;
		if (choose == 1)
		{
			printf("Nhap ma doc gia: ");
			while (getchar() != '\n');
			gets_s(s.memberID);
			int i = 1;
			while (!feof(f)) {
				fread(&temps, sizeof(subscriber)*i, 1, f);
				if (strcmp(temps.memberID, s.memberID) == 0) {
					found = true;
					printSubscriberInfo(temps);
					break;
				}
				else {
					i++;
				}
			}
		}
		else if (choose == 2)
		{
			printf("Nhap so cmnd: ");
			while (getchar() != '\n');
			gets_s(s.info.cmnd);
			int i = 1;
			while (!feof(f)) {
				fread(&temps, sizeof(subscriber)*i, 1, f);
				if (strcmp(temps.info.cmnd, s.info.cmnd) == 0) {
					found = true;
					printSubscriberInfo(temps);
					break;
				}
				else {
					i++;
				}
			}
		}
		else if (choose == 3)
		{
			printf("Nhap ho ten: ");
			while (getchar() != '\n');
			gets_s(s.info.name);
			int i = 1;
			while (!feof(f)) {
				fread(&temps, sizeof(subscriber)*i, 1, f);
				if (strcmp(temps.info.name, s.info.name) == 0) {
					found = true;
					printSubscriberInfo(temps);
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
void printSubscriberInfo(subscriber s) {
	printf("memberID                :");
	puts(s.memberID);
	printPersonInfo(s.info);
	printf("Ngay dang ki            :");
	char timeBuffer[11];
	strftime(timeBuffer, 10, "%d/%m/%Y", &s.startDate);
	puts(timeBuffer);
	printf("Ngay het han            :");
	strftime(timeBuffer, 10, "%d/%m/%Y", &s.expiryDate);
	puts(timeBuffer);
}
void printPersonInfo(person p) {
	printf("Ten                     :");
	puts(p.name);
	printf("Gioi tinh               :");
	printf("%d \n", (p.gender==1) ? "Nam" : "Nu");
	printf("Email                   :");
	puts(p.email);
	printf("Dia chi                 :");
	puts(p.address);
	printf("CMND                    :");
	puts(p.cmnd);
	printf("Ngay thang nam sinh     :");
	char timeBuffer[11];
	strftime(timeBuffer, 10, "%d/%m/%Y", &p.dateOfBirth);
	puts(timeBuffer);
}