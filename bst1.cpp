#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    node *left;
    node *right;
}node;
    node *newNode( int x ){
        node *temp = new node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    node *insert( node *t, int x ){
        if ( t == NULL ){
            node *temp = newNode(x);
            return temp;
        }
        else if (t->data < x){
            t->right = insert(t->right,x);
        }
        else t->left = insert(t->left,x);
        return t;
    }
    void PreOrder( node *t ){
        if ( t == NULL ) return;
        std::cout<<t->data<<" ";
        PreOrder(t->left);
        PreOrder(t->right);
    }
    node *MinNode ( node *t ){
        node *temp = t;
        while ( temp != NULL && temp->left != NULL ){
            temp = temp->left;
        }
        return temp;
    }
    node *DeleteNode( node *t, int x ){
        if ( t == NULL ) return t;
        if ( x < t->data ){
            t->left = DeleteNode(t->left,x);
        }
        else if ( x > t->data ){
            t->right = DeleteNode(t->right,x);
        }
        else {
            if (t->left == NULL){
                node *temp = t->right;
                delete(t);
                return temp;
            }
            if ( t->right == NULL ){
                node *temp = t->left;
                delete(t);
                return temp;
            }
            else{
                node *temp = MinNode(t->right);
                t->data = temp->data;
                t->right = DeleteNode(t->right,temp->data);
            }
        }
    }
    void DeleteNode1( node *t ){
        if ( t == NULL ) return;
        if ( t != NULL ){
        if ( t->left != NULL ) DeleteNode1(t->left);
        if ( t->right != NULL ) DeleteNode1(t->right);
        delete(t);
    }
    }
        node* DeleteNumber( node *t, int x ){
            if ( t == NULL ) return NULL;
            if ( t->data == x ){
                 DeleteNode1(t->left);
                 DeleteNode1(t->right);
                 t = NULL;
            }
            else if (t->data < x){
                 t->right = DeleteNumber(t->right,x);
            }
            else t->left = DeleteNumber(t->left,x);
            return t;
        }
        int main(){
            int n,x,temp;
            std::cin>>n;
            node *t = NULL;
            for ( int i = 0 ; i < n ; i++ ){
                std::cin>>x;
                t = insert(t,x);
            }
            cin>>x;
            DeleteNumber(t,x);
            if ( t == NULL ) std::cout<<"NULL";
            else PreOrder(t);
            return 0;
        }
        
    
