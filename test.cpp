#ifdef __WAND__
target[name[test.exe] type[application]]
#endif

#include "eventqueuerunner.h"

#include <herbs/main.h>
#include <herbs/timer.h>
#include <herbs/eventqueue.h>
#include <cstdio>


bool expire(Herbs::EventQueue::Event& event, uintmax_t time_epoch)
	{
	printf("%llu Hello\n",time_epoch);
	return 1;
	};

int MAIN(int argc,charsys_t* argv[])
	{
	Herbs::Timer tic(Herbs::Timer::frequencyGet()*0.5);
	Herbs::EventQueue q;
	q.entryAdd(Herbs::EventQueue::Entry(0,Herbs::EventQueue::Event(expire)));
	q.entryAdd(Herbs::EventQueue::Entry(0,Herbs::EventQueue::Event(expire)));
	q.entryAdd(Herbs::EventQueue::Entry(0,Herbs::EventQueue::Event(expire)));
	q.entryAdd(Herbs::EventQueue::Entry(0,Herbs::EventQueue::Event(expire)));
	q.entryAdd(Herbs::EventQueue::Entry(1,Herbs::EventQueue::Event(expire)));
	q.entryAdd(Herbs::EventQueue::Entry(0,Herbs::EventQueue::Event(expire)));
	q.entryAdd(Herbs::EventQueue::Entry(0,Herbs::EventQueue::Event(expire)));
	q.entryAdd(Herbs::EventQueue::Entry(0,Herbs::EventQueue::Event(expire)));
	q.entryAdd(Herbs::EventQueue::Entry(0,Herbs::EventQueue::Event(expire)));
	EventQueueRunner runme(tic,q);
	runme.run();
	return 0;
	}
