//
//  Sleep.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__Sleep__
#define __FiniteStateMachine__Sleep__

#include <stdio.h>
#include "Actions.h"
#include "DataContainer.h"
//class that inheris from class Actions, used to handle the Sleep action
class Sleep: public Actions
{
public:
     //constructor that takes pointer of type DataContainer to access the FSM Data
    Sleep();
    ~Sleep();
    virtual void run(); //overridden function that extracts the sleeping time
    //void setData(DataContainer* p);
    void parse(string);
    string split(string);
private:
    int sleepTime;
};
#endif /* defined(__FiniteStateMachine__Sleep__) */
