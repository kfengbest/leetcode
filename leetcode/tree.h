//
//  tree.h
//  leetcode
//
//  Created by fengka on 8/2/18.
//  Copyright © 2018 fengka. All rights reserved.
//

#ifndef tree_h
#define tree_h
#include <iostream>

namespace tree {
    
    struct Node{
        char data;
        Node* left;
        Node* right;
        
        Node(char c) : data(c) { }
    };
    
    void preOrder(Node* head){
        if(!head)
            return;
        
        std::cout << head->data << " ";
        
        preOrder(head->left);
        
        preOrder(head->right);
    }
    
    void inOrder(Node* head){
        if(!head)
            return;
        
        inOrder(head->left);
        
        std::cout << head->data << " ";
        
        inOrder(head->right);
    }
    
    void postOrder(Node* head){
        if(!head)
            return;
        
        inOrder(head->left);
        
        inOrder(head->right);
        
        std::cout << head->data << " ";
    }
    
    void levelVisit(Node* head){
        
    }
    
    void test(){
        
        Node* head = new Node('A');
        Node* b = new Node('B');
        Node* c = new Node('C');
        head->left = b;
        head->right = c;
        
        Node* d = new Node('D');
        b->left = d;
        Node* e = new Node('E');
        c->right = e;
        
        preOrder(head);
        std::cout << std::endl;
        
        inOrder(head);
        std::cout << std::endl;

        postOrder(head);
    }
    
}


#endif /* tree_h */
