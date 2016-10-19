//
//  MFSMParser.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/25/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__MFSMParser__
#define __FiniteStateMachine__MFSMParser__

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
using namespace std;
class MFSMParser{
    enum section{MFSM,COMVAR,MACHINES}; //Enum to indicate the mfsm keywords
    typedef map< string, int > variables;
    
public:
    MFSMParser(string, vector< string >&, variables&);
    ~MFSMParser();
    string mfsmName()const;
private:
    void run(); //Function to stare the parser
    void splitData();//Function the split the sections when parsing
    void getComVar();//Funciton to parse the common varibales.
    void getName();//Funciton to parse the name of the machine.
    void  getMachines();//Funciton to parse the name of the machine.
    bool isCOMVAR(string s); //Funciton to check the syntax ofCOMVAR keyword is correct
    bool isMachines(string s);//Funciton to check the syntax of machine keyword is correct
    bool isMFSM(string s); //Funciton to check the syntax of MFSM keyword is correct
    void setSection(string); //Funciton to set the sections for parsing
    string split(string); ////Function the split the data from a given string
    queue< string > data; //queue that stores the file as strings
    vector< string > *machines; //Pointer to a string vector for filling the vector with the fsm names.
    ifstream mfsmFile;
    variables *sharedV; //Map of shared variables
    section sec;
    string mName;
};

#endif /* defined(__FiniteStateMachine__MFSMParser__) */
