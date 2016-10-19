//
//  Wait.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "Wait.h"
#include "MFSM.h"
#include <iostream>
using namespace std;
Wait:: Wait(){
}
Wait:: ~Wait(){
}
void Wait::parse(string){
}

//Function that recieves input from the user and handles the new transitions based on the input
void Wait:: run(){
    m.lock();
    cout << (*container).getSourceName() << ":: "<< "Enter next transition: " ;
    string input; cin >> input;
    ( *Tcontainer).changeState(input);
    m.unlock();
}
