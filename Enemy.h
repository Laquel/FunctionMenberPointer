#pragma once
#include "GameObject.h"
class Enemy : public GameObject
{
public:
	bool Print(int cout) override
	{
		bool flag = false;

		if (m_Count == cout)
		{
			std::cout << "�G�l�~�[�����s" << std::endl;
			m_Count = 0;
			flag = true;
		}
		else
		{
			m_Count++;
		}

		return flag;
	}
};

