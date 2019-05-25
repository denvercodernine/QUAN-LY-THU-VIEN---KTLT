#include "pch.h"
void issueBook()
{
	system("cls");
	while (1)
	{
		system("cls");
		subscriber s, temps;
		while (getchar() != '\n');
		FILE *f = fopen(SUBSCRIBER_STORAGE, "wb");
		printf("Ma doc gia                 : ");
		gets_s(s.memberID);


		int i = 1; bool found = false;
		struct stat st;
		stat(SUBSCRIBER_STORAGE, &st);


		while ((!feof(f)) && (st.st_size != 0)) {
			fread(&temps, sizeof(subscriber)*i, 1, f);
			if (strcmp(temps.memberID, s.memberID) == 0) {
				found = true;
				s = temps;
				printf("Ten doc gia                  : %s\n", s.info.name);
				//handle borrow list
				{
					DIR *d;
					struct dirent *dir;
					d = opendir(BORROW_FOLDER);
					bool userNotReturned = false;
					while ((dir = readdir(d)) != NULL)
					{
						if (strcmp(dir->d_name, s.memberID)) {
							std::cout << "DOC GIA CHUA TRA SACH!" << std::endl;
							userNotReturned = true; system("PAUSE");
							//thoat ra lai menu
							break;
						}
					}
					closedir(d);
					if (!userNotReturned) {
						//tao thu muc memberID
						char tempStr[27 + MEMBER_ID_LENGTH];
						strcpy(tempStr, BORROW_FOLDER_C);
						strcat(tempStr, s.memberID);
						CreateDirectoryA(tempStr, NULL);
						//lay thong tin quyen sach muon
						int count = 0;
						while (count > 0 && count < 3) {
							std::cout << "Nhap so luong sach can muon (max 3): ";
							std::cin >> count;
						}
						//dem so sach da tao
						FILE *f = fopen(BOOK_STORAGE,"r+b");
						book b, tempb; bool found = false;
						for (int i = 0; i < count; i++) {
							//check xem con sach de muon khong
							std::cout << "----- SACH THU " << i + 1 << " -----" << std::endl;
							printf("Nhap ma so ISBN sach: ");
							while (getchar() != '\n');
							gets_s(b.ISBN);
							int j = 1;
							while (!feof(f)) {
								fread(&tempb, sizeof(book)*j, 1, f);
								if (strcmp(tempb.ISBN, b.ISBN) == 0) {
									found = true;
									printBookInfo(tempb);
									if (b.count>b.issued)
									{
										//tao file isbn.bin cho tung sach
										char isbnStr[27 + 13 + 2 + 4 + MEMBER_ID_LENGTH];
										strcpy(isbnStr, tempStr);
										strcat(isbnStr, SLASH);
										strcat(isbnStr, b.ISBN);
										strcat(isbnStr, BIN);
										wchar_t wtext[27 + 13 + 2 + 4 + MEMBER_ID_LENGTH];
										mbstowcs(wtext, isbnStr, strlen(isbnStr) + 1);
										LPWSTR ptrisbn = wtext;
										HANDLE h2 = CreateFile(ptrisbn, 0, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
										CloseHandle(h2);
										b.issued++;
										fseek(f, -(int)sizeof(book), SEEK_CUR);
										fwrite(&b, sizeof(book), 1, f);
										printf("Cho muon thanh cong\n");
									}
									break;
								}
								else {
									j++;
								}
							}
							if (!found) {
								std::cout << "Ma so sach khong ton tai!" << std::endl;
							}
							found = false;
							rewind(f);
						}
						//ghi ngay muon, ngay tra du kien va so luong sach vao file data.bin
						bookSlip bs;
						bs.amountBorrowed = count;
						char * issue = new char(10);
						printf("Ngay muon (dd/mm/yyyy)  :");
						gets_s(issue, 10);
						strptime(issue, "%d/%m/%Y", &bs.issue);
						char bsStr[27 + 6 + 4 + MEMBER_ID_LENGTH];
						strcpy(bsStr, BORROW_FOLDER_C);
						strcat(bsStr, s.memberID);
						strcat(bsStr, "\\data.bin");
						FILE *fbs = fopen(bsStr, "r+b");
						if (fbs != NULL) {
							fwrite(&bs, sizeof(bookSlip), 1, fbs);
						}
						else {
							std::cout << "error" << std::endl;
						}
					}
				}
			}
			else {
				i++;
			}
		}
		if (!found) {
			std::cout << "Ma doc gia khong ton tai!" << std::endl;
		}
		printf("Bam 'y' de tiep tuc, bam phim khac bat ki de huy!\n");
		if (_getch() == 'y') {
			break;
		}
	}

}
//INCOMPLETE
/*
void returnBook()
{
	system("cls");
	while (1)
	{
		system("cls");
		subscriber s, temps;
		while (getchar() != '\n');
		FILE *f = fopen(SUBSCRIBER_STORAGE, "wb");
		printf("Ma doc gia                 : ");
		gets_s(s.memberID);


		int i = 1; bool found = false;
		struct stat st;
		stat(SUBSCRIBER_STORAGE, &st);


		while ((!feof(f)) && (st.st_size != 0)) {
			fread(&temps, sizeof(subscriber)*i, 1, f);
			if (strcmp(temps.memberID, s.memberID) == 0) {
				found = true;
				s = temps;
				//handle borrow list
				{
					DIR *d;
					struct dirent *dir;
					d = opendir(BORROW_FOLDER);
					bool userTest = true;
					while ((dir = readdir(d)) != NULL)
					{
						if (strcmp(dir->d_name, s.memberID)) {
							userTest = false;
							//HANDLE RETURN
							char tempStr[27 + MEMBER_ID_LENGTH];
							strcpy(tempStr, BORROW_FOLDER_C);
							strcat(tempStr, s.memberID);
							//READ NUMBER OF BOOKS BORROWED
							char bsStr[27 + 6 + 4 + MEMBER_ID_LENGTH];
							strcpy(bsStr, BORROW_FOLDER_C);
							strcat(bsStr, s.memberID);
							strcat(bsStr, "\\data.bin");
							FILE *fbs = fopen(bsStr, "rb");
							bookSlip bs;
							fread(&bs, sizeof(bookSlip), 1, fbs);
							for (int i = 0; i < bs.amountBorrowed, i++;) {
								//
								DIR *dir2;
								struct dirent *ent2;
								if ((dir2 = opendir(tempStr)) != NULL) {
									while ((ent2 = readdir(dir2)) != NULL) {
										printf("%s\n", ent2->d_name);
									}
									closedir(dir2);
								}
								else {
									perror("");
									return;
								}
								//list books in directory

								//check thoi gian muon
								//tinh tien phat
							//viet reportID.txt trong thu muc return
							//xoa thu muc memberID
							}
						}
					}
					closedir(d);
					if (userTest) {
						//BAO LOI DOC GIA KHONG CO MUON SACH
						std::cout << "DOC GIA KHONG MUON SACH!" << std::endl;
					}
				}
			}
			else {
				i++;
			}
		}
		if (!found) {
			std::cout << "Ma doc gia khong ton tai!" << std::endl;
		}
		printf("Bam 'y' de tiep tuc, bam phim khac bat ki de huy!\n");
		if (_getch() == 'y') {
			break;
		}
	}
}
*/