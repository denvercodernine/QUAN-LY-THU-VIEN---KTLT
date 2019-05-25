#include "pch.h"
void getPassword(char *pw)
{
	char c, password[PASSWORD_LENGTH];
	int i = 0;
	while (((c = _getch()) != 13) && (i < PASSWORD_LENGTH)) {
		password[i] = c;
		printf("*");
		i++;
	}
	password[i] = '\0';
	strcpy(pw, password); printf("\n");
}
void getUsername(char *user)
{
	char c, username[USERNAME_LENGTH];
	int i = 0;
	while (((c = _getch()) != 13) && (i < USERNAME_LENGTH)) {
		username[i] = c;
		printf("%c", c);
		i++;
	}
	username[i] = '\0';
	strcpy(user, username); printf("\n");
}
int login(user &user){
	system("CLS");
	char *username = new char(USERNAME_LENGTH);
	char *password = new char(PASSWORD_LENGTH);
	printf("Nhap username: ");
	getUsername(username);
	printf("Nhap mat khau: ");
	getPassword(password);
	switch (authenticate(user, username, password))
	{
		case 1:
			return 1;
			break;
		default: // failed to login
			break;
	}
	system("PAUSE");
	return 0;
}
int authenticate(user &currentUser, char *username, char *password) {
	FILE *f = fopen(USER_STORAGE, "rb");
	if (f == NULL)
	{
		printf("Loi cap nhat!!!"); exit(1);
	}
	else
	{
		int i = 1;
		while (!feof(f)) {
			fread(&currentUser, sizeof(user)*i, 1, f);
			if (strcmp(currentUser.username, username) == 0) {
				if (strcmp(currentUser.password, password) == 0) {
					if (!currentUser.activationStatus) {
						std::cout << "Tai khoan dang bi block, lien he admin de giai quyet" << std::endl;
						fclose(f);
						return currentUser.activationStatus;
					}
					else {
						fclose(f);
						return currentUser.activationStatus;
					}
				}
				std::cout << "MAT KHAU SAI" << std::endl;
				fclose(f);
				return 0;
			}
			else {
				i++;
			}
		}
		std::cout << "KHONG TIM THAY TEN DANG NHAP" << std::endl;
	}
	std::cout << "DANG NHAP THAT BAI. AN BAT KI NUT NAO DE THU LAI." << std::endl;
	system("PAUSE");
}