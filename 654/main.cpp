#include "pch.h"
#include <iostream>
extern "C" char* strptime(const char* s, const char* f, struct tm* tm) {
	std::istringstream input(s);
	input.imbue(std::locale(setlocale(LC_ALL, nullptr)));
	input >> std::get_time(tm, f);
	if (input.fail()) {
		return nullptr;
	}
	return (char*)(s + input.tellg());
}
int main()
{
	DIR *app, *borrowFolder, *returnFolder;
	app = opendir(APP_DIRECTORY);
	while(!app)
	{
		std::cout << "TAO THU MUC UNG DUNG MOI O %APPDATA%" << std::endl;
		system(CREATE_APP_DIRECTORY);
	}
	borrowFolder = opendir(BORROW_FOLDER);
	while (!borrowFolder)
	{
		std::cout << "TAO THU MUC MUON SACH MOI O %APPDATA%" << std::endl;
		system(CREATE_BORROW_DIRECTORY);
	}
	returnFolder = opendir(RETURN_FOLDER);
	while (!borrowFolder)
	{
		std::cout << "TAO THU MUC TRA SACH MOI O %APPDATA%" << std::endl;
		system(CREATE_RETURN_DIRECTORY);
	}
	closedir(app);
	closedir(borrowFolder);
	closedir(returnFolder);
	//user currentUser;
	//while (!login(currentUser)) {};
	//addBook();

}
