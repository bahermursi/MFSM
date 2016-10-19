//
//  End.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "End.h"
//#include "Simulator.h"
End:: End(){
}
End:: ~End(){
    *endFsm = false;
}
void End::parse(string){
}
//Function that sets the boolean of ending the machine to true while an end action was called
void End:: run(){
    endFsm = (*container).getEndVar();
    *endFsm = true;
}
