//
//  FSM.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "FSM.h"
#include <iostream>
#include "FSMParser.h"
FSM:: FSM(string s, string n2){
    path = s;
    name2 = n2;
}
FSM:: ~FSM(){
}
//Function that starts the fsm parser and runs the FSM machines after parsing
void FSM:: startFSM(){
    FSMParser fsmParser(t, path, endfsm, V, sharedV,name2);
    fsmParser.sendState(St);
    state = t.returnInitialState();
    runFSM();

}
//Function used to assign the fsm's map of variables with the mfsm shared variables.
void FSM::assignVar(variables& data){
    sharedV = &data;
}
//Function that handles the running of the fsm machine
void FSM:: runFSM(){
    while (!endfsm) {
        auto myState = St.find(state);
        for (size_t i = 0; i < myState -> second.size(); ++i) {
            myState->second[ i ] -> run();
        }
        state = t.returnState();
    }
}
