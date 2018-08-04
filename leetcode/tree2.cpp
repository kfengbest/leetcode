//
//  tree2.cpp
//  leetcode
//
//  Created by fengka on 8/3/18.
//  Copyright © 2018 fengka. All rights reserved.
//

#include <iostream>
#include "tree2.h"

using namespace Tree2;

Node::Node(const std::string& c)
: content(c)
, m_children()
{
}

void
Node::addChild(Node* child){
    m_children.push_back(child);
}

void
Node::accept(Visitor& visitor){
    visitor.push(this);
    
    for(auto child : m_children){
        child->accept(visitor);
    }
    
    visitor.pop(this);
}

void
Tester::test(){

    Node a("A");
    Node b("B");
    Node c("C");
    Node d("D");
    Node e("E");
    Node f("F");
    Node g("G");

    a.addChild(&b);
    a.addChild(&c);
    a.addChild(&d);
    b.addChild(&e);
    c.addChild(&f);
    c.addChild(&g);

    TopDownPrinter printer;
    a.accept(printer);  // A B E C F G D
    
    std::cout << std::endl;
    BottomUpPrinter buPrinter;
    a.accept(buPrinter); // E B F G C D A
}
