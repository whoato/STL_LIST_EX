#include "StudentList.h"

StudentList::StudentList()
{
	iTerPos = students.begin();
	iTerEnd = students.end();
}


StudentList::~StudentList()
{

}


int StudentList::Menu()
{
	cout << "Ű�� �Է��ϼ���." << endl;
	cout << "m = �޴�, a = �л� �߰�, c = ���� ���� ���" << endl;
	cout << "i = Ư�� ��ġ �л� �߰�, l = ��� �л� ���" << endl;
	cout << "s = �л� �˻�, d = �л� ����, e = ���α׷� ����" << endl;

	int num = 0;
	int num2 = 0;
	int classID = 0;
	char str[100];

	switch (_stateID)
	{
	case IDS_MENU:
		
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

	return 0;
}

void StudentList::Add(check _check)
{
	if (_check != Front && _check != Back)
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
		return;
	}

	Student newST("", 0, 0);

	char str[100];
	cout << "�̸��� �Է��ϼ���." << endl;
	cin >> str;
	newST.userName = new char[strlen(str)];
	strcpy(newST.userName, str);

	cout << "���� ������ �Է��ϼ���." << endl;
	cin >> newST.iKor;
	cout << "���� ������ �Է��ϼ���." << endl;
	cin >> newST.iEng;

	switch (_check)
	{
	case Front:
		students.push_front(newST);
		break;
	case Back:
		students.push_back(newST);
		break;
	}

	StateID = IDS_MENU;
}

void StudentList::ChoiceClass(CLASSID _class)
{
	if (_class != CID_KOR && _class != CID_ENG)
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
		return;
	}

	iTerEnd = students.end();
	SetTextColor(�������);
	cout << "���� ����" << endl << endl;
	for (iTerPos = students.begin(); iTerPos != iTerEnd; iTerPos++)
	{
		cout << "�̸� : " << iTerPos->userName << endl;
		switch (_class)
		{
		case CID_KOR:
			cout << "���� : " << iTerPos->iKor << endl;
			break;
		case CID_ENG:
			cout << "���� : " << iTerPos->iEng << endl;
			break;
		}
	}
}

void StudentList::Insert(int _where)
{
	int totalSize = students.size();
	if (_where > totalSize || _where < 0)
	{
		cout << "�� ��ġ�� �߰��� �� �����ϴ�." << endl;
		return;
	}

	Student newST("", 0, 0);

	char str[100];
	cout << "�̸��� �Է��ϼ���." << endl;
	cin >> str;
	strcpy(newST.userName, str);

	cout << "���� ������ �Է��ϼ���." << endl;
	cin >> newST.iKor;
	cout << "���� ������ �Է��ϼ���." << endl;
	cin >> newST.iEng;

	iTerPos = students.begin();
	for (int i = 0; i < _where; i++)
		iTerPos++;
	students.insert(iTerPos, newST);

	cout << "�л��� �߰��߽��ϴ�." << endl;

	StateID = IDS_MENU;
}

void StudentList::Alllist()
{
	iTerEnd = students.end();
	SetTextColor(�������);
	cout << "��ü �л� ����" << endl << endl;
	for (iTerPos = students.begin(); iTerPos != iTerEnd; iTerPos++)
	{
		cout << "�̸� : " << iTerPos->userName << endl;
		cout << "���� ���� : " << iTerPos->iKor << endl;
		cout << "���� ���� : " << iTerPos->iEng << endl;
	}
}

void StudentList::Search(char* name)
{
	iTerEnd = students.end();
	for (iTerPos = students.begin(); iTerPos != iTerEnd; iTerPos++)
	{
		if (!strcmp(iTerPos->userName, name))
			break;
	}

	cout << "�˻��� �л� ����" << endl << endl;
	cout << "�̸� : " << iTerPos->userName << endl;
	cout << "���� ���� : " << iTerPos->iKor << endl;
	cout << "���� ���� : " << iTerPos->iEng << endl;
}

void StudentList::Delete(char* name)
{
	iTerEnd = students.end();
	for (iTerPos = students.begin(); iTerPos != iTerEnd; iTerPos++)
	{
		if (!strcmp(iTerPos->userName, name))
		{
			students.erase(iTerPos);
			SetTextColor(���ѳ����);
			cout << "�����Ǿ����ϴ�." << endl;
			StateID = IDS_MENU;
			return;
		}
	}
}

void StudentList::Exit()
{
	cout << "���α׷��� �����մϴ�." << endl;
	students.clear();

	exit(NULL);
}