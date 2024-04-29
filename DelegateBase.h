#pragma once
class DelegateBase 
{
public:
	DelegateBase() {}
	virtual ~DelegateBase() {};

	virtual bool operator() (int value) = 0;

	
	int m_time = 0;
	bool m_loop = false;
	bool m_Destory = false;
};