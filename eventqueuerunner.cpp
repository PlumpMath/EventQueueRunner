#ifdef __WAND__
target[name[eventqueuerunner.o] type[object]]
#endif

#include "eventqueuerunner.h"
#include <herbs/timer.h>
#include <herbs/eventqueue.h>
#include <cstdio>

int EventQueueRunner::run()
	{
	Herbs::EventQueue::Entry e=q.entryNext();
	uintmax_t time=0;
	while(!m_stop)
		{
		if(e.m_delay)
			{
			--e.m_delay;
			++time;
			m_timer.wait();
			}
		else
			{
			if(!e.m_event.expire(time))
				{return STATUS_ABORT;}
			e=q.entryNext();
			}
		}
	return STATUS_OK;
	}
