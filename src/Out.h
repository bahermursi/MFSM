//
//  Out.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__Out__
#define __FiniteStateMachine__Out__

#include <stdio.h>
#include "Actions.h"
#include "DataContainer.h"
//class that inheris from class Actions, used to handle the out actions of string and variables
class Out: public Actions
{
public:
    //constructor that takes pointer of type DataContainer to access the FSM Data
    Out();
    ~Out();
    virtual void run(); //overridden function that extracts the current string to be printed
  //  void setData(DataContainer*,DataContainer*,string);
    void parse(string);
    string split(string s);
private:
    string fsmname;
};

#endif /* defined(__FiniteStateMachine__Out__) */
