//
//  MFSM.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/25/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__MFSM__
#define __FiniteStateMachine__MFSM__

#include <stdio.h>
#include <string>
#include <map>
#include <vector>
#include <mutex>
#include <thread>
using namespace std;
extern mutex m;

class MFSM{
typedef map< string, int > variables;
public:
    MFSM(string);
    ~MFSM();
private:
    void runMFSM(); //Contructor of the MFSM object that calls the function mfsm parser
    variables sharedData; //map for the fsm shared variables
    vector< thread > mThread; //vector to store a thread containg a new fsm
    vector< string > nMachines; //vector of machine names
   
    
    
};
#endif /* defined(__FiniteStateMachine__MFSM__) */
