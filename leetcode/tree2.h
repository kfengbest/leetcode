//
//  tree2.h
//  leetcode
//
//  Created by fengka on 8/3/18.
//  Copyright © 2018 fengka. All rights reserved.
//

#ifndef tree2_h
#define tree2_h

#include <vector>
#include <iostream>
#include <string>

namespace Tree2{
  
    class Visitor;
    
    class Node{
    public:
        Node(const std::string& c);
        virtual ~Node(){}
        
    public:
        void accept(Visitor& visitor);
        void addChild(Node* child);
        std::string data(){return content;}
        
    private:
        std::vector<Node*> m_children;
        std::string content;
    };
    
    class Visitor{
        friend class Node;
    public:
        Visitor(){}
        virtual ~Visitor(){}
        
    protected:
        virtual void onPush(Node* node){}
        virtual void onPop(Node* node){}
        virtual void onVisit(Node* node){}
        void visit(Node* node){
            this->onVisit(node);
        }
    private:
        void push(Node* node){
            this->onPush(node);
        }
        void pop(Node* node){
            this->onPop(node);
        }
    };
    
    class TopDownVisitor : public Visitor{
    public:
        TopDownVisitor() : Visitor(){}
        
    protected:
        virtual void onPush(Node* node){
            this->visit(node);
        }
    };
    
    class BottomUpVisitor : public Visitor{
    protected:
        virtual void onPop(Node* node){
            this->visit(node);
        }
    };
    
    class TopDownPrinter : public TopDownVisitor{
    protected:
        virtual void onVisit(Node* node){
            std::cout<< node->data() << " ";
        }
    };
 
    class BottomUpPrinter : public BottomUpVisitor{
    protected:
        virtual void onVisit(Node* node){
            std::cout<< node->data() << " ";
        }
    };
    
    class Tester{
    public:
        void test();
    };
    
};
#endif /* tree2_h */
