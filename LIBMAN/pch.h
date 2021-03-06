#define _XOPEN_SOURCE 700
#ifndef PCH_H
#define PCH_H
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define GENDER_MALE 1
#define GENDER_FEMALE 0
#define GENDER_OTHER 2
#define ACCOUNT_ACTIVATED 1
#define ACCOUNT_BLOCKED 0
#define PERM_ADMIN 0
#define PERM_OPERATOR 2
#define PERM_MANAGER 1
#define USER_STORAGE "user.bin"
#define SUBSCRIBER_STORAGE "subscriber.bin"
#define BOOK_STORAGE "book.bin"
#define BORROW_LIST "borrow_list.csv"
#define BORROW_FOLDER "BORROW"
#define BORROW_FOLDER_C "BORROW\\"
#define RETURN_FOLDER "RETURN\\"
//#define APP_DIRECTORY "%appdata%\\LIBRARY"
//#define CREATE_APP_DIRECTORY "mkdir %appdata%\\LIBRARY"
//#define CREATE_BORROW_DIRECTORY "mkdir %appdata%\\LIBRARY\\BORROW"
//#define CREATE_RETURN_DIRECTORY "mkdir %appdata%\\LIBRARY\\RETURN"
#define USERNAME_LENGTH 32+1
#define PASSWORD_LENGTH 32+1
#define NAME_LENGTH 32+1
#define CMND_LENGTH 12+1
#define EMAIL_LENGTH 64+1
#define ADDRESS_LENGTH 64+1
#define MEMBER_ID_LENGTH 8+1
#define SLASH "\\"
#define BIN ".bin"
#define pause system("PAUSE")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <sys/stat.h>
#include <sys/types.h>
#include <tchar.h>
#include "dirent.h"
#include <Windows.h>

extern "C" char* strptime(const char* s,
	const char* f,
	struct tm* tm);

struct person
{
	char name[NAME_LENGTH];
	int gender;
	char email[EMAIL_LENGTH];
	char address[ADDRESS_LENGTH];
	char cmnd[12];
	tm dateOfBirth;
};
struct user {
	char username[USERNAME_LENGTH];
	char password[PASSWORD_LENGTH];
	person info;
	int activationStatus;
	int permissionLevel;
};
struct subscriber {
	char memberID[MEMBER_ID_LENGTH];
	person info;
	tm startDate;
	tm expiryDate;
};
struct book {
	char ISBN[14];
	char title[60];
	char author[60];
	char publisher[60];
	unsigned int year;
	char gerne[30];
	char rack[30];
	unsigned int count;
	unsigned int issued;
};
struct bookSlip {
	//bool returned;
	//char memberID[MEMBER_ID_LENGTH];
	unsigned int amountBorrowed;
	tm issue;
	//tm due;
	//tm returnDate;
	//char ** list;
};
//LOGIN
void getPassword(char *pw);
void getUsername(char *user);
int login(user &user);
int authenticate(user &currentUser, char *username, char *password);
//USER
void userRegister();
void changePassword(user &u);
void updateUserInfo(user &u);
void changePermissions();
void initPerson(person &initTarget);
void initUser(user &initTarget);
//SUBSCRIBER
int LastChar(char c);
char *readString(FILE *f, char *line);
void subscriberList();
void addsubscriber();
void deletesubscriber();
void updatesubscriberInfo();
void searchsubscriber();
void printSubscriberInfo(subscriber s);
void printPersonInfo(person p);
//BOOK
void bookList();
void searchBook();
void addBook();
void deleteBook();
void updateBookInfo();
void printBookInfo(book b);
//INTERFACE
void menu(user &currentUser);
void funcUserLimited(user &currentUser);
void funcUser(user &currentUser);
void funcSubscriber(user &currentUser);
void funcSubscriberLimited(user &currentUser);
void funcBook(user &currentUser);
void funcBookLimited(user &currentUser);
void funcLending(user &currentUser);
void funcReport(user &currentUser);
void funcReportLimited(user &currentUser);
//LENDING
void issueBook();
//STATISTIC
void numofbook();
void numofbook_gerne();
void numofsubscriber();
void numofsubs_gender();
void Numofbook_lend();
#endif