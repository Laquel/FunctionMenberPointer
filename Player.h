#pragma once


#include "GameObject.h"

class Player : public GameObject
{
public:
	bool Print(int cout) override
	{
		bool flag = false;
		if (m_Count == cout)
		{
			std::cout << "プレイヤーが実行" << std::endl;
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

