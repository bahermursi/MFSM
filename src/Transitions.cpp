//
//  Transitions.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "Transitions.h"
Transitions:: Transitions(){
}
Transitions:: ~Transitions(){
}
//function used to insert the new transitions to map T
void Transitions:: insertNewTran(string init,string next,string input){
    T[ make_pair(init, next) ] = input;
}
//function used to change the current state of the machine
void Transitions:: changeState(string s){
    auto cState = T.find(make_pair(currentState,s));
    if (cState == T.end()) {
        throw out_of_range("INVALID INPUT\n");
    }
    currentState = cState -> second;
}
//function used to set the intial state of the machine
void Transitions:: setState(string s){
    currentState = s;
}//function used to return the current state of the machine
string Transitions:: returnState(){
    return currentState;
}
//function used to set the intial state of the machine
string Transitions:: returnInitialState(){
    auto st = T.begin();
    currentState = st -> first.first;
    return currentState;
}