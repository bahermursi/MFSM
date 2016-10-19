//
//  Actions.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef FiniteStateMachine_Actions_h
#define FiniteStateMachine_Actions_h
//Abstract class used for the the different actions in the states.
#include <string>
#include "DataContainer.h"
#include "Transitions.h"
#include <iostream>
using namespace std;
//Abstract class for the fsm actions.
class Actions{
public:
    Actions(){};
    ~Actions(){};
    virtual void run() = 0; //Pure virtual function
    virtual void parse(std::string) = 0; //Pure virtual function
    //Funcion to set each action's DataContainer pointer with the fsm's DataContainer.
    void setDataContainer(DataContainer *c){
        container = c;
    }
    //Funcion to set each action's SharedContainer pointer with the fsm's SharedContainer.
    void setSharedContainer(DataContainer *c){
        sharedContainer = c;
    }
    //Funcion to set each action's TransitionsContainer pointer with the fsm's TransitionsContainer.
    void setTransContainer(Transitions *c){
        Tcontainer = c;
    }
    
    DataContainer *container, *sharedContainer;
    Transitions *Tcontainer;
    
    
    
};
#endif
