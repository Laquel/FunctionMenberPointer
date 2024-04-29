#pragma once
#include "DelegateBase.h"



template <class T>
class Delegate : public DelegateBase
{
public:
	/// <summary>
	/// �ĉ��֐��|�C���^�[��`
	/// </summary>
	typedef bool (T::* EventFunc)(int);

private:
	T* m_obj;				// �I�u�W�F�N�g
	EventFunc m_func;		// �֐��|�C���^

	 
	// �C�x���g�o�^
	void SetAddEvent(T* obj, EventFunc eventFunc, int time, bool loop)
	{
		m_obj = obj;
		m_func = eventFunc;
		m_time = time;
		m_loop = loop;
	}
public:
	Delegate() {}
	virtual ~Delegate() {}

	/// <summary>
	/// �߂�l�Fbool
	/// ���@���Fint
	/// �̊֐��Ăяo��(����͊֐��|�C���^)�̉��Z�q���I�[�o�[���C�h
	/// </summary>
	/// <param name="value"></param>
	/// <returns></returns>
	virtual bool operator() (int value) override
	{
		return (m_obj->*m_func)(value);
	}



	static DelegateBase* CreateDelegator(T* obj, bool(T::* func)(int), int time, bool loop)
	{
		Delegate* dg = new Delegate;
		dg->SetAddEvent(obj, func, time, loop);
		return dg;
	}

};

