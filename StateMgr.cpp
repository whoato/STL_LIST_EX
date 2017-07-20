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
		cout << "������ �߰��ұ��? �ڷ� �߰��ұ��? �� : 1, �� : 2" << endl;
		cin >> num;
		num--;
		Add((check)num);
		break;
	case IDS_CHOICE:
		cout << "� ������ ����ұ��? ���� : 1, ���� : 2" << endl;
		cin >> classID;
		classID--;
		ChoiceClass((CLASSID)classID);
		break;
	case IDS_INSERT:
		num2 = 0;
		cout << "�� ��° ��ġ�� �߰��ұ��? ���ڸ� �Է��ϼ���. ex) ù��° = 1" << endl;
		cin >> num2;
		num--;
		Insert(num2);
		break;
	case IDS_ALLLIST:
		Alllist();
		break;
	case IDS_SEARCH:
		cout << "�̸��� �Է��ϼ���." << endl;
		cin >> str;
		Search(str);
		break;
	case IDS_DELETE:
		cout << "�̸��� �Է��ϼ���." << endl;
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