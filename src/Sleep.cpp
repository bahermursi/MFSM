//
//  Sleep.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "Sleep.h"
#include <sstream>
#include <thread>
using namespace std;
Sleep:: Sleep(){
}
Sleep:: ~Sleep(){
}
//Function parse is used to insert the data in the Action data container
void Sleep:: parse(string str){
    ( *container ).insertTime(split(str));
}
//Function used to get the data from the passed string
string Sleep:: split(string s){
    stringstream str(s);
    str >> s; getline(str , s);
    if(s[ 0 ] == ' ') s.erase(0, 1);
    return s;
}
//Function that gets the time to sleep, and performs the sleep action.
void Sleep:: run(){
    sleepTime = (*container).getTime();
    this_thread::sleep_for(chrono::seconds(sleepTime)); //Procedure of sleping for a cetain amount of time in seconds
}

