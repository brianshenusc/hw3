#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};
 
typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
    bool operator()(Event* e1, Event* e2) {
			// returns true if e1's time is less than or equal to e2's time, false otherwise
        if(e1->time <= e2->time) {
            return true;
        }
        return false;
        
    }
} EventLess;
	
#endif
