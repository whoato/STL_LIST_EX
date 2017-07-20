#pragma once
void SetCursorHandle();
void SetTextColor(int _index);
void GotoXY(int _ix, int _iy);
void PrintText(int _ix, int _iy, char* _string, int _color = Èò»ö);
void PrintText(int _ix, int _iy, int _index, int _color = Èò»ö);
void CheckState();

void SetCursorHandle()
{
	HANDLE HCursor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO Info;
	Info.dwSize = 100;
	Info.bVisible = FALSE;
	SetConsoleCursorInfo(HCursor, &Info);
}
void SetTextColor(int _index)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _index);
}
void GotoXY(int _ix, int _iy)
{
	COORD CursorPosition;

	CursorPosition.X = _ix;
	CursorPosition.Y = _iy;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CursorPosition);
}
void PrintText(int _ix, int _iy, char * _string, int _color)
{
	DWORD dw;

	GotoXY(_ix, _iy);
	SetTextColor(_color);

	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), _string, strlen(_string), &dw, NULL);
}
void PrintText(int _ix, int _iy, int _index, int _color)
{
	DWORD dw;

	GotoXY(_ix, _iy);
	SetTextColor(_color);

	char str[128];
	char* pstr = itoa(_index, str, 10);
	WriteFile(GetStdHandle(STD_OUTPUT_HANDLE), pstr, strlen(pstr), &dw, NULL);
}
void CheckState()
{
	int getkey = getch();

	switch (getkey)
	{
	case 'm':
		StateID = IDS_MENU;
		break;
	case 'a':
		StateID = IDS_ADD;
		break;
	case 'c':
		StateID = IDS_CHOICE;
		break;
	case 'i':
		StateID = IDS_INSERT;
		break;
	case 'l':
		StateID = IDS_ALLLIST;
		break;
	case 's':
		StateID = IDS_SEARCH;
		break;
	case 'd':
		StateID = IDS_DELETE;
		break;
	case 'e':
		StateID = IDS_EXIT;
		break;
	default:
		StateID = IDS_MENU;
		break;
	}
}