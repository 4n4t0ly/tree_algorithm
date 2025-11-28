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
template<typename Func>
void Preorder(Node* root, Func action){
    if(!root) return;
    action(root->data);
    Preorder(root->left, action);
    Preorder(root->right, action);
}
template<typename Func>
void Inorder(Node* root, Func action){
    if(!root) return;
    Inorder(root->left, action);
    action(root->data);
    Inorder(root->right, action);
}
template<typename Func>
void Postorder(Node* root, Func action){
    if (!root) return;
    Postorder(root->left, action);
    Postorder(root->right, action);
    action(root->data);
}
void PrintTree(Node *root){
    cout<<"\n\tPreorder: ";
    Preorder(root, [](int data){ cout<<data<<" "; });
    cout<<endl;
    cout<<"\n\tInorder: ";
    Inorder(root, [](int data){ cout<<data<<" "; });
    cout<<endl;
    cout<<"\n\tPostorder: ";
    Postorder(root, [](int data){ cout<<data<<" "; });
    cout<<endl;
}
int Count(Node *root){
    if(!root) return 0;
    return 1 + Count(root->left) + Count(root->right);
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
Node* FindMin(Node* root){
    if(!root) return nullptr;
    if(!root->left) return root;
    return FindMin(root->left);
}
Node *Delete(Node* root, int value){
    if(!root) return root;
     if(value<root->data)
        root->left=Delete(root->left, value);
    else if(value > root->data)
        root->right=Delete(root->right, value);
    else{
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        if(!root->left){
            Node* rightChild=root->right;
            delete root;
            return rightChild;
        }
        if(!root->right){
            Node* leftChild=root->left;
            delete root;
            return leftChild;
        }
        Node* successor=FindMin(root->right);
        root->data=successor->data;
        root->right=Delete(root->right, successor->data);  
    }
    return root;
}
Node* RotateRight(Node* root){
    if(!root || !root->left) return root;
    Node* newRoot=root->left;
    root->left=newRoot->right;
    newRoot->right=root;
    return newRoot;
}
Node* RotateLeft(Node* root){
    if(!root || !root->right) return root;
    Node* newRoot=root->right;
    root->right=newRoot->left;
    newRoot->left=root;
    return newRoot;
}
int TextOutput(){
    int action;
    cout<<"\n1. Add Element to Tree";
    cout<<"\n2. Element Search in Tree";
    cout<<"\n3. Delete Element from Tree";
    cout<<"\n4. Element Count in Tree";
    cout<<"\n5. Tree rotation";
    cout<<"\n6. Tree walking (preorder, inorder, postorder)";
    cout<<"\n7. Exit";
    cout<<"\nChoose an action: ";
    cin>>action;
    if(!cin){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return action;
}
bool InputProcessing(int action, Node *&root){
    if(action==1)
        AddElement(root);
    else if(action==2){
        int value=valueInput(true);
        if(Search(root, value))
            cout<<"\nElement "<<value<<" found in the tree.";
        else
            cout<<"\nElement "<<value<<" not found in the tree.";
    }
    else if(action==3){
        int value=valueInput(false);
        root=Delete(root, value);
    }
    else if(action==4){
        int elementsCount=Count(root);
        cout<<"\n\tNumber of elements in the tree: "<<elementsCount<<endl;
    }
    else if(action==5){
        cout<<"\n1. Rotate Right\n2. Rotate Left\nChoose rotation type: ";
        int rotationType;
        cin>>rotationType;
        if(!cin){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\nInvalid input for rotation type!";
            return true;
        }
        if(rotationType==1)
            root=RotateRight(root);
        else if(rotationType==2)
            root=RotateLeft(root);
        else
            cout<<"\nInvalid rotation type selected!";
        return true;
    }
    else if(action==6)
        PrintTree(root);
    else if(action==7)
        return false;
    else
        cout<<"\nInvalid action selected!";
    return true;
}