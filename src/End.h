//
//  End.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__End__
#define __FiniteStateMachine__End__

#include <stdio.h>
#include "Actions.h"
#include "DataContainer.h"
//class that inheris from class Actions, used to handle the wait actions
class End: public Actions
{
public:
    End(); //constructor that takes a pointer of the boolean variable of the FSM machine
    ~End();//destructor used to reinitialize the endFSM boolean to its initial value
    virtual void run(); //overridden function that changes the boolen variable endFSM to end the machine
  //  void setData(bool*);
     void parse(string);
private:
    bool *endFsm; //boolean pointer that is used to end the FSM machine
};
#endif /* defined(__FiniteStateMachine__End__) */
