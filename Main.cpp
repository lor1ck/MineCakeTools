#include "Func.h"
#include <sstream>

#pragma warning(disable : 4996)
#pragma warning(disable : 4101)
#define _CRT_SECURE_NO_WARNINGS



const char* AsciiArt =
R"(
 __  __ _             _____      _     _______          _
|  \/  (_)           / ____|    | |   |__   __|        | |
| \  / |_ _ __   ___| |     __ _| | _____| | ___   ___ | |___
| |\/| | | '_ \ / _ \ |    / _` | |/ / _ \ |/ _ \ / _ \| / __|
| |  | | | | | |  __/ |___| (_| |   <  __/ | (_) | (_) | \__ \
|_|  |_|_|_| |_|\___|\_____\__,_|_|\_\___|_|\___/ \___/|_|___/
)";





int main()
{
	SetConsoleTitleA("MineCake Tools v1.0.3");
	setlocale(LC_ALL, "Rus");


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf(AsciiArt);
		printf("\nУправление: \nF4 - Выход\nC - Автокликер/Стрельба без прицела\nV - FastZoom\nУдержание R - Перезарядка (полезно для снайперских винтовок по типу мосины)\nАвтобег F5/F6\n");
}


void func()
{

	if (GetKeyState(VK_INSERT))
	{
		while (1)

		{
			GetProcessList();
			Sleep(15);
		}
	}

	else
	{
		return func();
	}
}