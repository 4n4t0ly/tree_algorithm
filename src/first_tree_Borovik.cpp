/*Izveidot BMK, realizējot darbības:

    Koka saknes veidošana un izvadīšana.
    Elementa pievienošana.
    Elementa meklēšana.
    Elementa dzēšana.
    Koka izdrukāšana.
    Koka apstaigāšana (preorder, inorder, postorder).
    Elementu skaita noteikšana.
    Koka pagriešana.*/
#include<cstdlib>
#include "funkcijas_tree.h"
int main(){
    programGreatingsInfo();
    int action;
    bool exitOrContinue=false;
    Node *root=nullptr;
    do{
        action=TextOutput();
        exitOrContinue=InputProcessing(action, root);
    }while(exitOrContinue);
    system("pause>nul");
    return 0;
}