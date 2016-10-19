//
//  MFSMParser.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/25/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "MFSMParser.h"
#include <sstream>
MFSMParser::MFSMParser(string path, vector< string >& m, variables& sV):sharedV(&sV),machines(&m){
    try {
        mfsmFile.open(path.c_str());
    } catch (...) {
        throw runtime_error("Failed to open file");
    }
    run();
}
MFSMParser:: ~MFSMParser(){}

//function that loops through the whole mfsm file
void MFSMParser:: run(){
    while (!mfsmFile.eof()) {
        string s;
        getline(mfsmFile, s );
        data.push(s);
    }
    while (!data.empty()) {
        splitData();
    }
}
//Function used to split the sections of the file based on the fsm keywords
void MFSMParser:: splitData(){
    if (sec == MFSM) getName();
    else if (sec == COMVAR) getComVar();
    else if (sec == MACHINES) getMachines();
}
//Function used to extract the mfsm name
void MFSMParser:: getName(){
    string x;
    stringstream str ( data.front() );
    str >> x;
    setSection( x );
    if (sec == MFSM){  if (data.front().length()-3 < 2) throw runtime_error("MFSM file syntax error, please check the declaration of the MFSM object");
        stringstream str( data.front() );
        str >> x;
        str >> mName;
        data.pop();
    }
    stringstream st (data.front());
    st >> x;
}
//Function to parse the common variables of the mfsm
void MFSMParser:: getComVar(){
    string x;
    stringstream str( data.front() );
    getline( str, x, ' ' );
    while ( !str.eof() ) {
        str >> x;
        if (x.front() == ' ') x.erase(0, 1);
        if (x.back() == ';') x.pop_back();
        ( *sharedV ).insert( make_pair(x, 0) );
    }
    data.pop();
    setSection( data.front() );
}
//Function to parse the machines of the mfsm
void MFSMParser:: getMachines(){
    while (!data.empty()){
        if (isMachines(data.front()))
        { setSection(data.front()); data.pop();}
       
        ( *machines ).push_back( data.front() );
        data.pop();
    }
}

bool MFSMParser:: isCOMVAR(string s){
    return s == "COMVAR";
}
bool MFSMParser:: isMachines(string s){
    return s == "machines:";
}
bool MFSMParser:: isMFSM(string s){
    return s == "MFSM";
}
//Funciton used to idnicate the section that will be parsed
void MFSMParser:: setSection(string s){
    if (isMFSM(s)) sec = MFSM;
    else if (isCOMVAR(s)) sec = COMVAR;
    else if (isMachines(s)) sec = MACHINES;
}
//funciton used to return the mfsm name
string MFSMParser:: mfsmName() const {
    return mName;
}
