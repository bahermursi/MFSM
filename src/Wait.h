//
//  Wait.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__Wait__
#define __FiniteStateMachine__Wait__

#include <stdio.h>
#include "Actions.h"
#include "Transitions.h"
//class that inheris from class Actions, used to handle the wait actions
class Wait: public Actions
{
public:
     //constructor that takes pointer of type Transitions to access the FSM Data
    Wait();
    ~Wait();
  //  void setData(Transitions *p, string);
    virtual void run(); //overridden function that gets the input from the user and sets the new transitions
     void parse(string);
private:

};

#endif /* defined(__FiniteStateMachine__Wait__) */
