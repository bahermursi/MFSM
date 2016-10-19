//
//  Run.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "Run.h"
#include "FSM.h"
#include <sstream>
Run:: Run(){
}
Run:: ~Run(){
}
//Function used to get the name of the fsm 
void Run::parse(string s){
    name = split(s);
}
//Function used to get the data from the passed string
string Run:: split(string s){
    stringstream str(s);
    str >> s; getline(str , s);
    if(s[ 0 ] == ' ') s.erase(0, 1);
    return s;
}
//Function that gets the source name of the previous fsm and assings it to the fsm constructor to be known where this fsm was called from
void Run:: run(){
    string name2 = ( *container ).getSourceName();
    FSM fsm(name + ".fsm",name2);
    fsm.startFSM();
}
