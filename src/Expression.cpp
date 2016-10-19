//
//  Expression.cpp
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#include "Expression.h"
#include <iostream>
Expression:: Expression(){
}
Expression:: ~Expression(){
}
//Funciton that handles the extraction of data from the sent expression.
void Expression::parse(string z){
    string e1,e2,e3;
    getExpr(z, e1, e2, e3);
    ( *container ).insertExp(e1, e2, e3);
}
//Funciton for dividing each expression
void Expression::getExpr(string str, string& s,string& y, string& z){
    s = str.substr(0 ,str.find('='));
    y = str.substr( str.find('=') + 1, str.find('+') - s.length() - 1);
    z = str.substr( str.find('+') + 1);
}
//Funciton that handles the sequence of the expressions and checking if it is a common variables or not, and the variables are dited accordingly.
void Expression:: run(){
    string e1,e2,e3;
    bool isE2_Number=true;
    bool isE3_Number=true;
    
    (*container).getExp(e1,e2,e3);
    DataContainer *data = NULL;
    //Check if the variable used is a shared variable or not
    bool isShared = ( *sharedContainer ).isShared(e1);
    if (isShared)
        data = sharedContainer;
    else
        data = container;
    
    for (int i = 0; i < e2.length() && isE2_Number; ++i) {
        isE2_Number = isdigit(e2[i]);
    }
    
    for (int i = 0; i < e3.length() && isE3_Number; ++i) {
        isE3_Number = isdigit(e3[ i ]);
    }
    //For handles this expression, X = const + const
    if (isE2_Number && isE3_Number) {
        int x = NULL;
        x = ( *data ).getVariables(e1);
        x = ( *data ).stringToInt(e2) + ( *data ).stringToInt(e3);
        ( *data ).updateVariables(e1, x);
    }
    //For handles this expression, X = const + Expression
    else if (isE2_Number && !isE3_Number){
        int x = ( *data ).getVariables(e1);
        x = ( *data ).stringToInt(e2) + ( *data ).getVariables(e3);
        ( *data ).updateVariables(e1, x);
    }
       //For handles this expression, X = Expr + const
    else if (isE3_Number && !isE2_Number){
        int x = ( *data ).getVariables(e1);
        x = ( *data ).stringToInt(e3) + ( *data ).getVariables(e2);
        ( *data ).updateVariables(e1, x);
    }
     //For handles this expression, X = Expr + Expr
    else if (!isE3_Number && !isE2_Number){
      int  x = ( *data ).getVariables(e1) + ( *data ).getVariables(e2);
        ( *data ).updateVariables(e1, x);
    }
    
}
