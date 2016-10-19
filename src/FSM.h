//
//  FSM.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__FSM__
#define __FiniteStateMachine__FSM__

#include <stdio.h>
#include "FSMParser.h"
class FSM{
    typedef map< string, int > variables;
    typedef map<string, vector< Actions* > > Action;
public:
    //Constructor takes the path of the file. The parsing functions are read in the constructor
    FSM();
    FSM(string,string);
    ~FSM();
    void startFSM();
    void assignVar(variables&);
private:
    void runFSM(); //Function that loops over the action of every state
    string state; //variable to indicate the current state being executed
    string name2;
    bool endfsm = false; //Boolen that ends the FSM machine
    Transitions t; //Object of type transition used to store the transitions
    Action St;//map used to store the states. Action* pointer is used to store the Action obj. in every state
    variables V; //Map used to store the variables and its values
    variables *sharedV;string path;
};

#endif /* defined(__FiniteStateMachine__FSM__) */
