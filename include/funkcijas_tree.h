#pragma once

struct Node {
    int data;
    Node* left;
    Node* right;
};
int valueInput(bool forSearch);
void programGreatingsInfo();
Node* CreateNode(int value);
template<typename Func>
void Preorder(Node* root, Func action);
template<typename Func>
void Inorder(Node* root, Func action);
template<typename Func>
void Postorder(Node* root, Func action);
void PrintTree(Node* root);
int Count(Node* root);
void Insert(Node*& root, int value);
void Visualisation(Node* node, int indent = 0);
void AddElement(Node*& root);
Node* Search(Node* root, int value);
Node* FindMin(Node* root);
Node* Delete(Node* root, int value);
Node* RotateRight(Node* root);
Node* RotateLeft(Node* root);
int TextOutput();
int InputProcessing(int input, Node*& root);