//
//  MFSM.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/25/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "MFSM.h"
#include "FSM.h"
#include "MFSMParser.h"
mutex m;
//Contructor of the MFSM object that calls the function mfsm parser
MFSM::MFSM(string path){
    MFSMParser mfsmParser(path,nMachines,sharedData);
    runMFSM();
}
MFSM::~MFSM(){    
}
 //Function that push threads wit the fsm objects into vector of threads then calls the threads join function
void MFSM::runMFSM(){
    string s;
    for (int i = 0; i < nMachines.size(); ++i) {
        mThread.push_back(thread([ = ](){
            FSM fsm( nMachines[ i ] + ".fsm", "");
            fsm.assignVar(sharedData);
            fsm.startFSM();
            
        }));
    }
    
    for (int i = 0; i < mThread.size(); ++i) {
        mThread[ i ].join();
    }
}