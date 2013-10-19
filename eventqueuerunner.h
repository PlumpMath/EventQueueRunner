#ifdef __WAND__
dependencies[eventqueuerunner.o]
target[name[eventqueuerunner.h] type[include]]
#endif

#ifndef EVENTQUEUERUNNER_H
#define EVENTQUEUERUNNER_H
#include <herbs/runnable.h>

namespace Herbs
	{
	class Timer;
	class EventQueue;
	}

class EventQueueRunner:public Herbs::Runnable
	{
	public:
		EventQueueRunner(Herbs::Timer& event_timer,Herbs::EventQueue& event_q):
			m_timer(event_timer),q(event_q)
			{}
		int run();
	
		void stop()
			{m_stop=1;}
		
	private:
		Herbs::Timer& m_timer;
		Herbs::EventQueue& q;
		bool m_stop;
	};

#endif
