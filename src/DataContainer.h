//
//  DataContainer.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__DataContainer__
#define __FiniteStateMachine__DataContainer__

#include <stdio.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include "VarExpression.h"
using namespace std;

class DataContainer{
    //Struct used in storing the expressions extracted from the FSM file
//    struct expContainer{
//        string variable;
//        string express1;
//        string express2;
//    };
    
public:
    typedef map< string, int > variables;
    DataContainer();
    ~DataContainer();
    void insertString(string); //Function used to insert the strings from the put action in a vector
    void insertVariables(string);//Function used to insert the variables in a map
    void updateVariables(string,int);//Function used to update the variables in the map
    void insertExp(string, string, string);////Function used to insert expressions in a vector
    void insertTime(string);//fucntion used to insert time values from sleep actions in a vector
    string getString();//function used to get the string to be printed
    int getVariables(string);//fucntion used to get the value of a needed FSM variable
    void getExp(string&, string&, string&);//function that gets the values of the expression from the expression action
    int getTime();//function used to return the time value for the sleeping action
    int stringToInt(string);//function used to convert a string an int
    void timeToBeg();//function to initialize the index of the currentTime to begining of vector
    void expToBeg();//function to initialize the expre of the currentExp to begining of vector
    void stringToBeg();//function to initialize the index of the currentString to begining of vector
    void varToBeg();//function to initialize the index of the currentVar to begining of vector
    void assignVar(variables&);//function used to assign the variables map the the FSM variables map of variables
    void assignSharedVar(variables*);
    void getSharedVar(variables&);
    void assignEnd(bool*);
    void setSourceName(string);
    void setFSMName(string);
    string getFSMName() const;
    string getSourceName() const;
    bool* getEndVar();
    bool isShared(string) ;
    bool empty() const;

private:
    vector < VarExpression > exp; //vector of type expContainter to store the string of expression action
    vector < string > strings; //Vector to store the string of the out action
    vector < int > sleepTime; //vector to store the time values
    const int INITIAL_VALUE = 0;
    int currentExp;//variable to indicate the expression to be returned
    int currentTime;//variable to indicate the current time value to be returned
    int currentString;//variable to indicate the current string to be returned
    int currentVar;//variable to indicate the current variable to be returned
    variables *V; //pointer of a map of the FSM variables
    variables *sharedVar;
    bool *endFsm;
    string sName;
    string fsmName;
    
    
};
#endif /* defined(__FiniteStateMachine__DataContainer__) */
