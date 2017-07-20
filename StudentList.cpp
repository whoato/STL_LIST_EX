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
	cout << "키를 입력하세요." << endl;
	cout << "m = 메뉴, a = 학생 추가, c = 과목 선택 출력" << endl;
	cout << "i = 특정 위치 학생 추가, l = 모든 학생 출력" << endl;
	cout << "s = 학생 검색, d = 학생 삭제, e = 프로그램 종료" << endl;

	int num = 0;
	int num2 = 0;
	int classID = 0;
	char str[100];

	switch (_stateID)
	{
	case IDS_MENU:
		
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

	return 0;
}

void StudentList::Add(check _check)
{
	if (_check != Front && _check != Back)
	{
		cout << "잘못된 입력입니다." << endl;
		return;
	}

	Student newST("", 0, 0);

	char str[100];
	cout << "이름을 입력하세요." << endl;
	cin >> str;
	newST.userName = new char[strlen(str)];
	strcpy(newST.userName, str);

	cout << "국어 점수를 입력하세요." << endl;
	cin >> newST.iKor;
	cout << "영어 점수를 입력하세요." << endl;
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
		cout << "잘못된 입력입니다." << endl;
		return;
	}

	iTerEnd = students.end();
	SetTextColor(진한흰색);
	cout << "과목 정보" << endl << endl;
	for (iTerPos = students.begin(); iTerPos != iTerEnd; iTerPos++)
	{
		cout << "이름 : " << iTerPos->userName << endl;
		switch (_class)
		{
		case CID_KOR:
			cout << "점수 : " << iTerPos->iKor << endl;
			break;
		case CID_ENG:
			cout << "점수 : " << iTerPos->iEng << endl;
			break;
		}
	}
}

void StudentList::Insert(int _where)
{
	int totalSize = students.size();
	if (_where > totalSize || _where < 0)
	{
		cout << "그 위치에 추가할 수 없습니다." << endl;
		return;
	}

	Student newST("", 0, 0);

	char str[100];
	cout << "이름을 입력하세요." << endl;
	cin >> str;
	strcpy(newST.userName, str);

	cout << "국어 점수를 입력하세요." << endl;
	cin >> newST.iKor;
	cout << "영어 점수를 입력하세요." << endl;
	cin >> newST.iEng;

	iTerPos = students.begin();
	for (int i = 0; i < _where; i++)
		iTerPos++;
	students.insert(iTerPos, newST);

	cout << "학생을 추가했습니다." << endl;

	StateID = IDS_MENU;
}

void StudentList::Alllist()
{
	iTerEnd = students.end();
	SetTextColor(진한흰색);
	cout << "전체 학생 정보" << endl << endl;
	for (iTerPos = students.begin(); iTerPos != iTerEnd; iTerPos++)
	{
		cout << "이름 : " << iTerPos->userName << endl;
		cout << "국어 점수 : " << iTerPos->iKor << endl;
		cout << "영어 점수 : " << iTerPos->iEng << endl;
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

	cout << "검색한 학생 정보" << endl << endl;
	cout << "이름 : " << iTerPos->userName << endl;
	cout << "국어 점수 : " << iTerPos->iKor << endl;
	cout << "영어 점수 : " << iTerPos->iEng << endl;
}

void StudentList::Delete(char* name)
{
	iTerEnd = students.end();
	for (iTerPos = students.begin(); iTerPos != iTerEnd; iTerPos++)
	{
		if (!strcmp(iTerPos->userName, name))
		{
			students.erase(iTerPos);
			SetTextColor(연한노란색);
			cout << "삭제되었습니다." << endl;
			StateID = IDS_MENU;
			return;
		}
	}
}

void StudentList::Exit()
{
	cout << "프로그램을 종료합니다." << endl;
	students.clear();

	exit(NULL);
}