//
//  Transitions.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__Transitions__
#define __FiniteStateMachine__Transitions__

#include <stdio.h>
#include <string>
#include <map>
using namespace std;

class Transitions{
    typedef pair<string, string> stringPair;
public:
    Transitions();
    ~Transitions();
    void insertNewTran(string,string,string); //function used to insert the new transitions
    void changeState(string);//function used to change the current state of the machine
    void setState(string);//function used to set the intial state of the machine
    string returnState();//function used to return the current state of the machine
    string returnInitialState();//function used to return the initial state of the machine
private:
    map < stringPair, string > T;//map used to store the transitions as a pair of the current state and the input given by the user, and the next state
    string currentState; // variable used to indicate the current state of the machine.
};
#endif /* defined(__FiniteStateMachine__Transitions__) */
