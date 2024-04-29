#include "main.h"

#include "Player.h"
#include "Enemy.h"

#include "DelegateBase.h"
#include "Delegate.h"
std::list<DelegateBase*> TaskManager::m_EventList;

int main(void)
{
	Player p;
	Enemy e;

	DelegateBase* a = Delegate<Player>::CreateDelegator(&p, &Player::Print, 1000000, true);
	DelegateBase* b = Delegate<Enemy>::CreateDelegator(&e, &Enemy::Print, 1000000, false);

	//Task task;

	//task.AddEventHandler(a);
	//task.AddEventHandler(b);

	//int cout = 10000000;

	//TaskManager task;
	//task.Add(a);
	//task.Add(b);
	TaskManager::Add(a);
	TaskManager::Add(b);

	while (1)
	{
		TaskManager::Action();
	}
	//
	//while (1)
	//{
	//	task.Action();
	//}
	//while (1)
	//{
	//	(*a)(10000000);
	//	(*b)(10000000 / 2);
	//}


	return 0;
}