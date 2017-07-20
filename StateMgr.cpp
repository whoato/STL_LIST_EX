#include "StateMgr.h"

CStateMgr* CStateMgr::m_pInst = NULL;

CStateMgr::CStateMgr()
	:m_StateID(IDS_MENU)
{
}


CStateMgr::~CStateMgr()
{
}


void CStateMgr::SetScene(STATEID _stateid)
{
	switch (_stateid)
	{
	case IDS_MENU:
		m_stdList.Menu();
		break;
	case IDS_ADD:
		cout << "앞으로 추가할까요? 뒤로 추가할까요? 앞 : 1, 뒤 : 2" << endl;
		cin >> num;
		num--;
		Add((check)num);
		break;
	case IDS_CHOICE:
		cout << "어떤 과목을 출력할까요? 국어 : 1, 영어 : 2" << endl;
		cin >> classID;
		classID--;
		ChoiceClass((CLASSID)classID);
		break;
	case IDS_INSERT:
		num2 = 0;
		cout << "몇 번째 위치에 추가할까요? 숫자를 입력하세요. ex) 첫번째 = 1" << endl;
		cin >> num2;
		num--;
		Insert(num2);
		break;
	case IDS_ALLLIST:
		Alllist();
		break;
	case IDS_SEARCH:
		cout << "이름을 입력하세요." << endl;
		cin >> str;
		Search(str);
		break;
	case IDS_DELETE:
		cout << "이름을 입력하세요." << endl;
		cin >> str;
		Delete(str);
		break;
	case IDS_EXIT:
		Exit();
		break;
	default:
		Menu(_stateID);
	}
}

void CStateMgr::Progress()
{
}

void CStateMgr::Render()
{
}

void CStateMgr::Release()
{
}