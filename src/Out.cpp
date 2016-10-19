//
//  Out.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "Out.h"
#include "MFSM.h"
#include <iostream>
#include <sstream>

//Class that handles printing the strings and expressions.
Out:: Out(){
  }
Out:: ~Out(){
}
//Function parse is used to insert the data in the Action data container
void Out::parse(string str){
    ( *container ).insertString(split(str));
}
//Function used to get the data from the passed string
string Out:: split(string s){
    stringstream str(s);
    str >> s; getline(str , s);
    if(s[ 0 ] == ' ') s.erase(0, 1);
    return s;
}

void Out:: run(){
    m.lock();
    cout << (*container).getSourceName() << ":: " <<( *container).getString() << endl;
    m.unlock();
}
