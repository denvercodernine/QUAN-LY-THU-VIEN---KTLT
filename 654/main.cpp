#include "pch.h"
#include <iostream>
extern "C" char* strptime(const char* s,
	const char* f,
	struct tm* tm) {
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
	//user currentUser;
	//while (!login(currentUser)) {};
	addBook();
}
