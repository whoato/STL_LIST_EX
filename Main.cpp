#include "Include.h"
#include "StateMgr.h"

int main()
{
	SetCursorHandle();
	DWORD dwTime = GetTickCount();
	CStateMgr::GetInst()->SetScene(IDS_MENU);

	while (true)
	{
		if (dwTime + 200 < GetTickCount())
		{
			dwTime = GetTickCount();

			system("cls");

			CheckState();
		}
	}

	return 0;
}