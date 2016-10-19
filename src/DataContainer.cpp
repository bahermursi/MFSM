//
//  DataContainer.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "DataContainer.h"
#include "MFSM.h"
#include <iostream>
//Constructor initialized data member with the initial value
DataContainer:: DataContainer(){
    currentExp = INITIAL_VALUE;
    currentTime = INITIAL_VALUE;
    currentString = INITIAL_VALUE;
    currentVar = INITIAL_VALUE;
};
DataContainer:: ~DataContainer(){}

//Function used to insert the strings from the put action in a the vector of strings
void DataContainer:: insertString(string s){
        auto check = (*V).find( s );
        if (check == (*V).end()) {
            s.erase(0,3);
            for (int i = 0; i < 3; i++)
                s.pop_back();
        }
    strings.push_back( s );
}
//Function used to insert the variables in a map
void DataContainer:: insertVariables(string s){
    (*V).insert(make_pair(s, INITIAL_VALUE));
}
//Function used to update the variables in the map
void DataContainer:: updateVariables(string s,int n){
    m.lock();
    variables* vrbl;
    if ((*sharedVar).find(s) != (*sharedVar).end())
        vrbl = sharedVar;
        else vrbl = V;
    
   ( *vrbl )[ s ] = n;
    m.unlock();
}
//Function used to insert expressions in a vector
void DataContainer:: insertExp(string e1,string e2,string e3){
    VarExpression expr;
    expr.setExp1(e1);
    expr.setExp2(e2);
    expr.setExp3(e3);
    exp.push_back(expr);
}
//fucntion used to insert time values from sleep actions in a vector
void DataContainer:: insertTime(string s){
    sleepTime.push_back( stringToInt( s ) );
}
//Funciton to convert the stringer to an int.
int  DataContainer:: stringToInt(string s) {
    return atoi( s.c_str() );
}
//function that returns true if the container is false;
bool DataContainer::empty() const{
    return (*V).empty();
}
//Function to check if the given variables in shared
bool DataContainer:: isShared(string x){
    bool b = (*sharedVar).find(x) != (*sharedVar).end();
    return b;
}

//function That gets the data to be printed
string DataContainer:: getString(){
    if (currentString == strings.size()) stringToBeg();
    string str = strings[ currentString++ ];
    auto check = (*V).find(str);
    if (check != (*V).end() ){
          auto check2 = (*sharedVar).find(str);
        if (check2 != (*sharedVar).end()){
            str = to_string(getVariables(check2->first));
            str = (*check2).first + " = " + str;
        }
        else { str = to_string(getVariables(check->first));
            str = (*check).first + " = " + str;}
    }
    return str;
}
//function that returns the values of the variables
int DataContainer:: getVariables(string s) {
    variables *vrbl;
    if ((*sharedVar).find(s) != (*sharedVar).end())
        vrbl = sharedVar;
    else vrbl = V;
    if (currentVar == (*V).size()) varToBeg();
    auto var = (*vrbl).find( s );
    if (var == (*vrbl).end()) throw runtime_error("Unrecognized Variable. Variables in Action expressions should match the variables previously stated in the FSM file.");
    return ( *var ).second;
}
//function that gets the expressions from the user then sets
void DataContainer:: getExp(string& e1, string& e2, string& e3){
    if (currentExp == exp.size()) expToBeg();
    VarExpression temp = exp[ currentExp++ ];
    e1 = temp.getExp1(); e2 = temp.getExp2(); e3 = temp.getExp3();
}
//funciton used to set the data member of type variables to the fsm variables
void DataContainer:: assignVar(variables& vars){
    V = &vars;
}
//function used to get time
int DataContainer:: getTime(){
    if (currentTime == sleepTime.size()) timeToBeg();
    return sleepTime[ currentTime++ ];
}
void DataContainer:: timeToBeg(){
    currentTime = INITIAL_VALUE;
}
void DataContainer:: expToBeg(){
    currentExp = INITIAL_VALUE;
}
void DataContainer:: stringToBeg(){
    currentString = INITIAL_VALUE;
}
void DataContainer:: varToBeg(){
    currentVar = INITIAL_VALUE;
}
//funciton used to data member with the fsm common variable  with of type variables to the fsm variables
void DataContainer::assignSharedVar(variables *common){
    sharedVar = common;
}
//function used to set the boolean responsible for the fsm main loop.
void DataContainer::assignEnd(bool* e){
    endFsm = e;
}

void DataContainer::getSharedVar(variables& c){
    c = *sharedVar;
}
bool* DataContainer::getEndVar(){
    return endFsm;
}
void DataContainer::setSourceName(string s){
    sName = s;
}
string DataContainer::getSourceName() const{
    return sName;
}
void DataContainer::setFSMName(string s){
    fsmName = s;
}
string DataContainer::getFSMName() const{
    return fsmName;
}
