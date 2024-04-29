#pragma once

#include <iostream>

class GameObject
{
protected:
	int m_Count = 0;
public:
	virtual bool Print(int cout) = 0;
};

