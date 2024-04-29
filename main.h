#pragma once


#include <list>


#include "DelegateBase.h"


class TaskManager
{
private:
	static std::list<DelegateBase*> m_EventList;

public:
	static void Action(void)
	{
		for (auto var : m_EventList)
		{
			if (((*var)(var->m_time)))
			{
				if (var->m_loop)
				{
					var->m_Destory = true;
				}
			}
		}

		m_EventList.remove_if([](DelegateBase* a) {return a->m_Destory; });
	}

	static void Add(DelegateBase* task)
	{
		m_EventList.emplace_back(task);
	}



//public:
//	typedef void (T::*EventFunc)(int);
//
//	struct EventInfo
//	{
//		T* object;
//		EventFunc func;
//	};
//
//
//	// イベント登録
//	void SetAddEvent(T* obj, EventFunc eventFunc)
//	{
//		EventInfo eventInfo;
//		eventInfo.objct = obj;
//		eventInfo.func = eventFunc;
//		m_EventList.push_Back(eventInfo);
//
//	}
//
//	// イベントのフラグ更新
//	void Update(void)
//	{
//		for (auto it = 0; it != m_EventList.end(); it++)
//		{
//			T* obj = it->object;
//			EventFunc func = it->func;
//
//			(obj->*func)(0);
//		}
//	}
//
//private:
//	std::list<EventInfo> m_EventList;

};
//__interface IAction
//{
//
//};
