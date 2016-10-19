//
//  FSMParser.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__FSMParser__
#define __FiniteStateMachine__FSMParser__

#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include "Actions.h"
#include "DataContainer.h"
#include "Transitions.h"
#include "ActionFactory.h"
using namespace std;
class FSMParser{
    enum section{FSM,VAR,STATE,TRANSITION};
    typedef map< string, int > variables;
    typedef map<string, vector< Actions* > > Action;
public:
    //Constructor gets a reference of the transition table, path of the file, reference of the boolean to end the FSM machine, and reference of the map of variables.
    FSMParser(Transitions&, string,bool&,variables&, variables*, string);
    ~FSMParser(); //destructor
    void run(); //Function that calls 4 parsing fuctions
    void splitData();//Function used to call the parsing function based an enum value
    bool isVAR(string);//Function that check if a string is "VAR"
    bool isTrans(string);//Function that check if a string is "Transitions:"
    bool isFSM(string);//Function that check if a string is "FSM"
    bool isState(string);//Function that check if a string is "States:"
    void setSection(string);//Function that assigns the enum of the current section to be read
    string split(string); //Function that extracts the data from every action
    void getName(); //Function to parse the FSM machine name
    void gettVar(); //Function to parse the Variables
    void getState(); //Function to parse the states
    void getTrans(); //Function to parse the transitions
    void getExpr(string,string&,string&,string&); //Function tp parse and split the action expression
    void sendState(Action&); //function used to assign the a map of states to the main FSM map.
    
private:
    ActionFactory myActions; //Object used to create the actions
    Actions *pActions; //Action pointer to recieve the object returned from ActionFactory
    vector< Actions* > A; //vector used to store the actions of the fsm.
    vector < string > actionTypes;
    Action Sts;
    variables *V; //map pointer to the FSM map pf variables
    variables *sharedV; //Map to store the mfsm shared variables
    DataContainer *container;//Pointer to the data table to be assigned to every state
    DataContainer *sharedContainer;
    Transitions *Tcontainer;////Pointer to the transition table
    bool *endfsm; //boolean pointer used to end the FSM machine
    string name;
    string name2;
    string content;
    int findVar;
    int findState;
    int findTrans;
    int findName;
    queue< string > data; //queue used to store the data read from the file while parsing
    ifstream fsmFile; //File input stream
    section sec; //Enum variable used in deciding the current enum being parsed
    
};
#endif /* defined(__FiniteStateMachine__FSMParser__) */
