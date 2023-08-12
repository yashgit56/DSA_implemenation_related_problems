#include<iostream>
#include<stack>

using namespace std ;

struct Node {
    int data ;
    struct Node *left ;
    struct Node *right ;
};

Node * create_node(int value) {
    Node *node = new Node() ;
    node->data = value ;
    node->left = NULL ;
    node->right = NULL ;
    return node ;
}

void inorder_iterative(Node *root){
    if(root == NULL){
        cout << "Empty Binary Tree" << endl ;
        return ;
    }
    stack<Node*> st ;
    Node *p = root ;

    while(true){
        if(p != NULL){
            st.push(p) ;
            p = p->left ;
        }
        else{
            if(st.empty())
                break ;
            p = st.top() ;
            st.pop() ;
            cout << p->data << " " ;
            p = p->right ;     
        }
    }
}

int main(){
    // creating all nodes of binary tree 
    Node * p1 = create_node(1) ;
    Node * p2 = create_node(7) ;
    Node * p3 = create_node(9) ;
    Node * p4 = create_node(2) ;
    Node * p5= create_node(6) ;
    Node * p6 = create_node(9) ;
    Node * p7= create_node(5) ;
    Node * p8= create_node(11) ;
    Node * p9 = create_node(5) ;

    // make connections between all binary tree nodes
    p1->left = p2 ;
    p1->right = p3 ;

    p2->left = p4 ;
    p2->right = p5 ;

    p5->left = p7 ;
    p5->right = p8 ;

    p3->right = p6 ;
    p6->left = p9 ;

    inorder_iterative(p1) ;


    return 0 ;
}