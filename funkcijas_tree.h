#include<iostream>
#include<cstdlib>
using namespace std;
struct Node{
    int data;
    Node *left, *right;
};
int value_input(){
    int value;
    cout<<"\nEnter the value of the element: ";
    cin>>value;
    return value;
}
void program_greatings_info(){
    cout<<"\nČao kokao!\n";
    cout<<"\nŠī programma ļauj veikt šādas darbības ar kokiem:\n";
        cout<<"\t- Elementa pievienošana;\n";
        cout<<"\t- Elementa dzēšana;\n";
        cout<<"\t- Saraksta izvade;\n";
        cout<<"\t- Elementu skaita noteikšana sarakstā;\n";
        cout<<"\t- Visa saraksta dzēšana.\n";
    cout<<"\nProgrammas autors: Anatoly Borovik 2.kursa students, 2025.g.\n";
}
Node *CreateNode(){
    Node *NewNode;
    NewNode=new Node;
    int x=value_input();
    NewNode->data=x;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}
void PrintTree(Node *root){
    if(!root) return;
    PrintTree(root->left);
    cout<<root->data<<" ";
    PrintTree(root->right);
}
Node *AddNode(Node *root){
    Node *newNode, *current;
    newNode=CreateNode();
    if(!root) root=newNode;
    else{
        current=root;
        while(current->left!=NULL || current->right!=NULL){
            while(current->left!=NULL && current->data > newNode->data)
                current=current->left;
            while(current->right!=NULL && current->data < newNode->data)
                current=current->right;
        }
        if(current->left==NULL && current->data > newNode->data)
            current->left=newNode;
        if(current->right==NULL && current->data <= newNode->data)
            current->right=newNode;
    }
    return root;
}
void action_selection(int action, Node *root){
    if(action==1) root=CreateNode();
    else if(action==2) PrintTree(root);
    else if(action==3);
    else if(action==8) exit(0);
    else{
        cerr<<"\nWrong action!";
        exit(0);
    }
}