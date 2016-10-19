//
//  ActionFactory.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 5/4/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef FiniteStateMachine_ActionFactory_h
#define FiniteStateMachine_ActionFactory_h

#include "Actions.h"
#include "Out.h"
#include "Sleep.h"
#include "Run.h"
#include "Wait.h"
#include "End.h"
#include "Expression.h"
//Class responsible for creating the fsm actions.
class ActionFactory{
    
public:
    //Function that returns an fsm action based on a string containing the action parsed from the fsm parser.
    Actions* createAction(string act){
        if (act == "out") return new Out();
        else if (act == "sleep") return new Sleep();
        else if (act == "run") return new Run();
        else if (act == "wait") return new Wait();
         else if (act == "end") return new End();
        else return new Expression();
        
    }
    
};
#endif
