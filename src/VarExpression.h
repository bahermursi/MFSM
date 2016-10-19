//
//  VarExpression.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 5/4/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef FiniteStateMachine_VarExpression_h
#define FiniteStateMachine_VarExpression_h
#include <string>
using namespace std;

//Class that stores the the expression action's data
class VarExpression{
    
public:
    VarExpression(){};
    ~VarExpression(){};
    //Function to set the first expression
    void setExp1(string e) {
        exp1 = e;
    };
    //Function to set the second expression
    void setExp2(string e){
        exp2 = e;
    };
    //Function to set the third expression
    void  setExp3(string e){
        exp3 = e;
    };
     //Function to get the first expression
    string getExp1() const{
        return exp1;
    };
     //Function to get the second expression
    string getExp2()const{
        return exp2;
    };
     //Function to set the third expression
    string  getExp3()const{
        return exp3;
    };
    
private:
    string exp1,exp2,exp3;
};

#endif
