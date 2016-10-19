//
//  Expression.h
//  FiniteStateMachine
//
//  Created by Baher Mursi on 4/3/16.
//  Copyright (c) 2016 Baher Mursi. All rights reserved.
//

#ifndef __FiniteStateMachine__Expression__
#define __FiniteStateMachine__Expression__

#include <stdio.h>
#include "DataContainer.h"
#include "Actions.h"
//class that inheris from class Actions, used to handle the Expression actions
class Expression: public Actions
{
public:
    //constructor that takes pointer of type DataContainer to access the FSM Data
    Expression();
    ~Expression();
    virtual void run(); //overridden function that handles the expressions
    //void setData(DataContainer*, DataContainer*);
    void parse(string);
    void getExpr(string, string&,string&, string&);

};
#endif /* defined(__FiniteStateMachine__Expression__) */
