#include<iostream>
#include<cstdlib>
#include<limits>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
};
int valueInput(bool forSearch){
    int value;
    if(forSearch)
        cout<<"\nEnter the value of the element to search: ";
    else
        cout<<"\nEnter the value of the element: ";
    cin>>value;
    if(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}
void programGreatingsInfo(){
    cout<<"\nČao kokao!\n";
    cout<<"\nŠī programma ļauj veikt šādas darbības ar kokiem:\n";
        cout<<"\tKoka saknes veidošana un izvadīšana;\n";
        cout<<"\tElementa pievienošana;\n";
        cout<<"\tElementa meklēšana;\n";
        cout<<"\tElementa dzēšana;\n";
        cout<<"\tKoka izdrukāšana;\n";
        cout<<"\tKoka apstaigāšana (preorder, inorder, postorder);\n";
        cout<<"\tElementu skaita noteikšana;\n";
        cout<<"\tKoka pagriešana.\n";
    cout<<"\nProgrammas autors: Anatoly Borovik 2.kursa students, 2025.g.\n";
}
Node *CreateNode(){
    Node *NewNode;
    NewNode=new Node;
    int x=valueInput(false);
    NewNode->data=x;
    NewNode->left=nullptr;
    NewNode->right=nullptr;
    return NewNode;
}
void PrintTree(Node *current){
    if(!current) return;
    PrintTree(current->left);
    cout<<current->data<<" ";
    PrintTree(current->right);
}
void Inorder(Node* root){

}
void Preorder(Node* root){

}
void Postorder(Node* root){
    
}
int Count(Node *root){
    if(!root) return 0;
    return 1 + Count(root->left) + Count(root->right);
}
int TextOutput(){
    int action;
    cout<<"\n1. Add Element to Tree";
    cout<<"\n2. Search Element in Tree";
    cout<<"\n3. Delete Element from Tree";
    cout<<"\n4. Element Count in Tree";
    cout<<"\n5. Exit";
    cout<<"\nChoose an action: ";
    cin>>action;
    if(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return action;
}
void Insert(Node *&root, int value){
    if(!root){
        root=CreateNode();
        root->data=value;
        return;
    }
    if(value<root->data)
        Insert(root->left,value);
    else
        Insert(root->right,value);
}
void AddElement(Node *&root){
    int n, value;
    cout<<"\nEnter a number of elements to add: ";
    cin>>n;
    if(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    for(int i=0; i<n; i++){
        value=valueInput(false);
        Insert(root, value);
    }
}
Node* Search(Node *root, int value){
    if(!root || root->data==value)
        return root;
    if(value<root->data)
        return Search(root->left, value);
    else
        return Search(root->right, value);
}
bool InputProcessing(int action, Node *&root){
    return true;
}