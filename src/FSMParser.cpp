//
//  FSMParser.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "FSMParser.h"
#include <sstream>
#include <iostream>
//FSMParser constructor initializes the data members with the passed parameters.
FSMParser:: FSMParser(Transitions &t, string s, bool &x,variables &v,variables *sV, string n2){
    sec = FSM;
    Tcontainer = &t;
    name2 = n2;
    V = &v;
    sharedV = sV;
    sharedContainer = new DataContainer();
    (*sharedContainer).assignSharedVar(sV);
    (*sharedContainer).assignVar(v);
    try {
        fsmFile.open(s.c_str());
    } catch (...) {
        throw runtime_error("Failed to open file");
    }
    endfsm = &x;
    run();
}

FSMParser:: ~FSMParser(){
}
//function that loops through the whole fsm file
void FSMParser:: run(){
    while (!fsmFile.eof()) {
        string s;
        getline(fsmFile, s );
        data.push(s);
    }
    while (!data.empty()) {
        splitData();
    }
}
//Function used to split the sections of the file based on the fsm keywords
void FSMParser:: splitData(){
    if (sec == FSM) getName();
    else if (sec == VAR) gettVar();
    else if (sec == STATE) getState();
    else if (sec == TRANSITION) getTrans();
}
//Function used to extract the fsm name
void FSMParser:: getName(){
    string x,n;
    stringstream str ( data.front() );
    str >> x;
    setSection( x );
    if (sec == FSM){  if (data.front().length()-3 < 2) throw "FSM file syntax error, please check the declaration of the FSM object";
        stringstream str( data.front() );
        str >> x;
        str >> name;
        data.pop();
    }
    stringstream st (data.front());
    st >> x;
}
//Function to parse the variables of the fsm
void FSMParser:: gettVar(){
    string x;
    stringstream str( data.front() );
    getline( str, x, ' ' );
    while ( !str.eof() ) {
        str >> x;
        if (x.front() == ' ') x.erase(0, 1);
        if (x.back() == ';') x.pop_back();
       ( *V ).insert( make_pair(x, 0) );
    }
    //pop the string of the file after being parsed
    data.pop();
    setSection( data.front() );
}
//Function to parse the states of the fsm
void FSMParser:: getState(){
    if (!name2.empty()) name2 += "::";
    while (!isTrans( data.front() )) {
        setSection(data.front());
        data.pop();
        while (sec == STATE) {
            string x,y,z;
            stringstream str(data.front());
            getline(str, y, ':');
            while (!str.eof()) {
                //Creating a new container and assigning it with the fsm data.
                container = new DataContainer();
                (*container).assignVar( *V );
                (*container).setFSMName(name);
                (*container).setSourceName(name2 + name);
                (*container).assignEnd(endfsm);
                (*container).assignSharedVar(sharedV);
                
                getline(str, z, ';');
                if (z.front() == ' ') z.erase(0,1);
                if (z.back() == ';') z.pop_back();
                stringstream str(z);
                str >> x;
                
                //A new object of type Action* is being created based on the ActionFactory
                pActions = myActions.createAction(x);
                //The Action object is being initialized with its containers
                (*pActions).setDataContainer(container);
                (*pActions).setTransContainer(Tcontainer);
                (*pActions).setSharedContainer(sharedContainer);
                //Calling the vartual function overriden by actions to parse the data
                (*pActions).parse(z);
                A.push_back(pActions);
            }
            //Insert the state and the vetor of actions in a map of states
            Sts.insert(make_pair(y, A));
            A.erase(A.begin(),A.end());
            data.pop();
            setSection(data.front());
            
        }
    }
}

//Function to parse the transitions of the fsm
void FSMParser:: getTrans(){
    while (!data.empty()){
        if (isTrans(data.front())){setSection(data.front()); data.pop();}
        string x,y,z;
        stringstream str(data.front());
        //Seperating every transition from the other then store it in an object of type Transitions.
        while (!str.eof()) {
            getline(str, x, ';');
            if (x.front() == ' ') x.erase(0,1);
            if (x.back() == ';') x.pop_back();
            
            getline(str, y, ';');
            if (y.front() == ' ') y.erase(0,1);
            if (y.back() == ';') y.pop_back();
            
            getline(str, z, ';');
            if (z.front() == ' ') z.erase(0,1);
            if (z.back() == ';') z.pop_back();
        }
        (*Tcontainer).insertNewTran(x, z, y);
        data.pop();
    }
}

bool FSMParser:: isVAR(string s){
    return s == "VAR";
}
bool FSMParser:: isTrans(string s){
    return s == "Transitions:";
}
bool FSMParser:: isState(string s){
    return s == "States:";
}
bool FSMParser:: isFSM(string s){
    return s == "FSM";
}
//Function to set the section to be parsed
void FSMParser:: setSection(string s){
    if (isFSM(s)) sec = FSM;
    else if (isVAR(s)) sec = VAR;
    else if (isState(s)) sec = STATE;
    else if (isTrans(s)) sec = TRANSITION;
}
//Function used to split the expressions to extract the values.
void FSMParser:: getExpr(string str, string& s,string& y, string& z){
    s = str.substr(0,str.find('='));
    y = str.substr(str.find('=')+1,str.find('+') - s.length()-1);
    z = str.substr(str.find('+')+1);
}
//function used to send the states from the parser to the FSM object.
void FSMParser:: sendState(Action& s){
    s = Sts;
}

