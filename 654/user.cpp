#include "pch.h"
using namespace std;
void userRegister() {
	system("CLS");
	user u; initUser(u);
	char tempPass[PASSWORD_LENGTH];
	fflush(stdin);
	std::cout << "Nhap username: " ;
	getUsername(u.username);
	std::cout << "Nhap password: ";
	getPassword(tempPass);
	std::cout << "Xac nhan lai: ";
	getPassword(u.password);
	if (!strcmp(tempPass, u.password))
	{
		FILE *f = fopen(USER_STORAGE, "ab");
		fseek(f, 0, SEEK_END);
		fwrite(&u, sizeof(user), 1, f);
		printf("Dang ky thanh cong, tai khoan dang bi block, lien he admin de cap quyen\n");
		fclose(f);
	}
	else {
		std::cout << "Sai mat khau xac nhan!" << std::endl;
	}
	pause;
}
void changePassword(user &u)
{
	user tempUser; initUser(tempUser);
	system("cls");
	char a[PASSWORD_LENGTH];
	fflush(stdin);
	printf("Nhap mat khau hien tai: ");
	getPassword(a);
	if (!strcmp(a, u.password))
	{
		char b[PASSWORD_LENGTH], c[PASSWORD_LENGTH];
		printf("Nhap mat khau thay moi     : ");
		getPassword(b);
		printf("Xac nhan mat khau vua nhap : ");
		getPassword(c);
		if (!strcmp(b, c))
		{
			strcpy(u.password, b);
			FILE *f = fopen(USER_STORAGE, "rb+");
			if (f == NULL)
			{
				printf("Loi cap nhat!!!"); exit(1);
			}
			else
			{
				int i = 1;
				while (!feof(f)) {
					fread(&tempUser, sizeof(user)*i, 1, f);
					if (strcmp(tempUser.username, u.username)==0) {
						fseek(f, -(int)sizeof(user),SEEK_CUR);
						fwrite(&u, sizeof(user), 1, f);
					}
					else {
						i++;
					}
				}
			}
			system("PAUSE");
		}
	}
	else
	printf("Nhap sai mat khau!\n");
	system("PAUSE");
}
void updateUserInfo(user &u) {
	system("cls");
	cout << "Cap nhat ho ten: " << endl;
	gets_s(u.info.name);
	cout << "Cap nhat gioi tinh ( Nam 1 / Nu 0 )" << endl;
	cin >> u.info.gender;
	char * dob = new char(10);
	printf("Ngay sinh (dd/mm/yyyy)  :");
	gets_s(dob, 10);
	strptime(dob, "%d/%m/%Y", &u.info.dateOfBirth);
	printf("Cap nhat cmnd                      : ");
	gets_s(u.info.cmnd);
	printf("Cap nhat dia chi                   : ");
	gets_s(u.info.address);
	user tempUser;
	while (1)
	{
		char a[30];
		fflush(stdin);
		printf("Nhap mat khau xac nhan             : ");
		gets_s(a);
		if (strcmp(a, u.password)==0)
		{
			FILE *f = fopen(USER_STORAGE, "r+b");
			int i = 1;
			while (!feof(f)) {
				fread(&tempUser, sizeof(user)*i, 1, f);
				if (strcmp(tempUser.username, u.username) == 0) {
					fseek(f, -(int)sizeof(user), SEEK_CUR);
					fwrite(&u, sizeof(user), 1, f);
				}
				else {
					i++;
				}
			}
			printf("Cap nhat thong tin thanh cong!\n");
			fclose(f);
			break;
		}
		else
		{
			printf("Sai mat khau!\nBam phim 'y' de nhap lai, bam phim bat ki khac de huy!\n");
			if (_getch() != 'y')
			{
				printf("Thao tac cap nhat da bi huy!\n");
				break;
			}
			printf("\r\t\t\t\t\t\t\t\t\t\t\r");
		}
	}
	system("PAUSE");
}
void initPerson(person &initTarget) {
	strcpy_s(initTarget.name, "");
	strcpy_s(initTarget.email, "");
	strcpy_s(initTarget.address, "");
	strcpy_s(initTarget.cmnd, "");
	initTarget.gender = 1;
	initTarget.dateOfBirth.tm_year = 0;
	initTarget.dateOfBirth.tm_yday = 0;
};
void initUser(user &initTarget) {
	initPerson(initTarget.info);
	initTarget.activationStatus = 0;
	initTarget.permissionLevel = 2;
};