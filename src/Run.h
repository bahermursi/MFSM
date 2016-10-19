//
//  Run.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__Run__
#define __FiniteStateMachine__Run__

#include <stdio.h>
#include "Actions.h"
#include "DataContainer.h"
//class that inheris from class Actions, used to handle the Sleep action
class Run: public Actions
{
public:
    Run(); //Constructor takes the name of the fsm to be runned
    ~Run();
    virtual void run(); //overriden function that is used to call an FSM object based on the name sent from the constructor
    string split(string);
    void parse(string);
private:
    string name;
};

#endif /* defined(__FiniteStateMachine__Run__) */
