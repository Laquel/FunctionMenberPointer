#pragma once
#include "DelegateBase.h"



template <class T>
class Delegate : public DelegateBase
{
public:
	/// <summary>
	/// 汎化関数ポインター定義
	/// </summary>
	typedef bool (T::* EventFunc)(int);

private:
	T* m_obj;				// オブジェクト
	EventFunc m_func;		// 関数ポインタ

	 
	// イベント登録
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
	/// 戻り値：bool
	/// 引　数：int
	/// の関数呼び出し(今回は関数ポインタ)の演算子をオーバーライド
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

