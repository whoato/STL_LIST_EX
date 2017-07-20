#pragma once
#include "Include.h"
#include "StudentList.h"

class CStateMgr
{
private:
	static CStateMgr* m_pInst;
public:
	static CStateMgr* GetInst()
	{
		if (m_pInst == NULL)
			m_pInst = new CStateMgr;
		return m_pInst;
	}
private:
	STATEID m_StateID;
	StudentList m_stdList;
public:
	void SetScene(STATEID _stateid);
	void Progress();
	void Render();
	void Release();
public:
	CStateMgr();
	~CStateMgr();
};

