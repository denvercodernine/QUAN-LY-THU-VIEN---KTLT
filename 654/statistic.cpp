#include "pch.h"
void numofbook()
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
		unsigned int N = 0; //so luong sach
		unsigned int Nissue = 0; //so sach da muon
		while (!feof(f))
		{
			fread(&b, sizeof(book), 1, f);
			N = N + b.count;
			Nissue = Nissue + b.issued;
		}
		printf("Tong so sach: %d cuon sach \n", N);
		printf("So sach hien co trong kho: %d cuon sach \n", N - Nissue);
	}
	if (f)
	{
		fclose(f);
	}
	system("PAUSE");
}
void numofbook_gerne()
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
		struct Gerne
		{
			char Gen[30];
			int Num;
		};
		unsigned int N_ofgerne = 0; //so luong the loai sach
		Gerne B[200]; // mang chua the loai kem so luong
		bool KT = false; //kiem tra xem the loai do co hay chua
		while (!feof(f))
		{

			fread(&b, sizeof(book), 1, f);
			KT = false;
			if (N_ofgerne == 0) //trong mang  chua co gi
			{
				KT = true;
				strcpy(B[0].Gen, b.gerne);
				B[0].Num = b.count;
				N_ofgerne++;
			}

			for (int i = 0; i < N_ofgerne; i++) // so sanh the loai sach voi cac the loai da co
			{
				if (strcmp(b.gerne, B[i].Gen) == 0)
				{
					KT = true;
					B[i].Num = B[i].Num + b.count;
					break;
				}
			}

			if (KT == false) // khong trung voi the loai co san
			{
				strcpy(B[N_ofgerne].Gen, b.gerne);
				B[N_ofgerne].Num = b.count;
				N_ofgerne++;
			}
		}
		for (int i = 0; i < N_ofgerne; i++) // in thong tin
		{
			printf("The loai %s co: %d cuon sach \n", B[i].Gen, B[i].Num);
		}
	}
	if (f)
	{
		fclose(f);
	}
	system("PAUSE");
}
void numofsubscriber()
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
		unsigned int Ns = 0; //so luong doc gia
		while (!feof(f))
		{
			fread(&s, sizeof(subscriber), 1, f);
			Ns = Ns + 1;
		}
		printf("So luong doc gia dang ki: %d nguoi \n", Ns);
	}
	if (f)
	{
		fclose(f);
	}
	system("PAUSE");
}
void numofsubs_gender()
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
		unsigned int Male = 0, FeMale = 0, Other = 0;
		while (!feof(f))
		{
			fread(&s, sizeof(subscriber), 1, f);
			if (s.info.gender == 1)
				Male++;
			else if (s.info.gender == 0)
				FeMale++;
			else
				Other++;
		}
		printf("So doc gia nam  : %d \n", Male);
		printf("So doc gia nu   : %d \n", FeMale);
		printf("So doc gia khac : %d \n", Other);
	}
	if (f)
	{
		fclose(f);
	}
	system("PAUSE");
}
void Numofbook_lend()
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

		unsigned int Nissue = 0; //so sach da muon
		while (!feof(f))
		{
			fread(&b, sizeof(book), 1, f);

			Nissue = Nissue + b.issued;
		}
		printf("Tong so sach dang duoc muon la: %d cuon sach \n", Nissue);

	}
	if (f)
	{
		fclose(f);
	}
	system("PAUSE");
}
//INCOMPLETE
/*
void Numofsubs_overdue()
{
	system("cls");
	bookSlip bs;
	unsigned int Num = 0;
	//lay borow slip
	{
		int Check_Overdue = (bs.returnDate.tm_year - bs.due.tm_year) * 365 + (bs.returnDate.tm_mon - bs.due.tm_mon) * 30 + (bs.returnDate.tm_mday - bs.due.tm_mday);
		if (Check_Overdue > 7)
			Num++;
	}
	printf("Tong so doc gia tre han la: %d cuon sach", Num);



	system("PAUSE");
}
*/
