#include "AVLTree.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//COLLAB WITH JONAS SEGUNDO

AVLTree::AVLTree(){
    root = nullptr;
}
Node* AVLTree::findUnbalancedNode(Node* node){
    if(node == nullptr){
        return nullptr;
    }
    if(balanceFactor(node)== -2 || balanceFactor(node) == 2){
        return node;
    }
    else{
        return findUnbalancedNode(node->parent);
    }
}
//given
void AVLTree::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
//given
void AVLTree::visualizeTree(ofstream & outFS, Node *n){
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS<<n->data <<" -> " <<n->left->data<<";"<<endl;
        }

        if(n->right){
            visualizeTree(outFS,n->right);
            outFS<<n->data <<" -> " <<n->right->data<<";"<<endl;
        }
    }
}

void AVLTree::insert(const string & v){
    Node* node = root;
    if( root == nullptr){
        root = new Node(v);
    }
    else{
        while(node != nullptr){
            if(node->data > v){
                if(node->left == nullptr){
                    node->left = new Node(v);
                    node->left->parent = node;
                    if(node->parent == root){
                        rotate(root);
                        return;
                    }
                    Node* nB = findUnbalancedNode(node);
                    if (nB){
                        rotate(nB);
                    }
                    return;
                }
                else{
                    node = node->left;
                }
            }

            else if(node->data < v){
                if(node->right == nullptr){
                    node->right = new Node(v);
                    node->right->parent = node;
                    if(node->parent == root){
                        rotate(root);
                        return;
                    }
                    Node* nB = findUnbalancedNode(node);
                    if (nB){
                        rotate(nB);
                    }
                    return;
                }
                else{
                    node = node->right;
                }

            }
            else{
                return;
            }
        }
    }
}
//wonky
int AVLTree::balanceFactor(Node* node){
    if(node == nullptr){
        return 0;
    }
    int r = height(node->right);
    int l = height(node->left);
    return l-r;
}
//works
void AVLTree::printBalanceFactors(){
    printBalanceFactors(root);
}
//From BST
int AVLTree::height(Node* v) const{
    if(v == nullptr){
        return -1;
    }
    int left;
    int right;
    left = height(v->left);
    right = height(v->right);
    if(left > right){
        return 1 + left;
    }
    else{
        return 1+ right;
    }
}
// Works but balance factor wrong
void AVLTree::printBalanceFactors(Node * node){
    if(node == nullptr){
        return;
    }
    printBalanceFactors(node->left);
    cout << node->data << "(" << balanceFactor(node) << "), ";
    printBalanceFactors(node->right);
}

Node* AVLTree::rotateLeft(Node* n){
    Node* temp = n->right;
    if( n == root){
        Node* ptr = root;
        if(temp->left !=  nullptr){
            if(temp->left->data > ptr->data){
                ptr->right = temp->left;
            }
            else{
                ptr->left = temp->left;
            }
        }
        else{
            ptr->right = nullptr;
        }
        temp->left = ptr;
        ptr->parent = temp;
        root = temp;
        temp->parent = nullptr;
        return temp;
    }
    if(n == n->parent->right){
        Node* p = n->parent;
        n->right = temp->left;
        temp->left = n;
        //  temp->parent = n->parent;
        n->parent->right = temp;
        temp->left->parent = temp;
        temp->parent = p;
        return temp;
    }
    else{
        Node* p = n->parent;
        n->right = temp->left;
        temp->left = n;
        //  temp->parent = n->parent;
        n->parent->left = temp;
        temp->left->parent = temp;
        temp->parent = p;
        return temp;
    }
}
Node* AVLTree::rotateRight(Node* n){
    Node* temp = n->left;
    if(n == root){
        Node* ptr = root;
        if(temp->right !=  nullptr){
            if(temp->right->data < ptr->data){
                ptr->left = temp->right;
            }
            else{
                ptr->right = temp->right;
            }
        }
        else{
            ptr->left = nullptr;
        }
        temp->right = ptr;
        ptr->parent = temp;
        root = temp;
        temp->parent = nullptr;
        return temp;
    }
    if(n == n->parent->left){
        Node* p = n->parent;
        n->left = temp->right;
        temp->right = n;
        //    temp->parent = n->parent;
        n->parent->left = temp;
        temp->right->parent = temp;
        temp->parent = p;
        return temp;
    }
    else{
        Node* p = n->parent;
        n->left = temp->right;
        temp->right = n;
        //  temp->parent = n->parent;
        n->parent->right = temp;
        temp->right->parent = temp;
        temp->parent = p;
        return temp;
    }
}

void AVLTree::rotate(Node* g){
    if(balanceFactor(g) == 2 && balanceFactor(g->left) == 1){
        rotateRight(g);
    }
    else if(balanceFactor(g) == -2 && balanceFactor(g->right) == -1){
        rotateLeft(g);
    }
    else if(balanceFactor(g) == 2 && balanceFactor(g->left) == -1){
        rotateLeft(g->left);
        rotateRight(g);
    }
    else if(balanceFactor(g) == -2 && balanceFactor(g->right) == 1){
        rotateRight(g->right);
        rotateLeft(g);
    }
    else{
        return;
    }
    return;
}
