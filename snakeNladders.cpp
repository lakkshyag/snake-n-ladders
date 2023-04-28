#include <iostream>
#include "linkedListOperations.cpp"
using namespace std;

int main()
{
    node* head = new node(1);
    node* tail = board::creator(head);

    node* top = board::addressRetrieve(head, 98);
    node* bottom = board::addressRetrieve(head, 9);
    (*top).extra = bottom;                              // 98 - 9 snake

    top = board::addressRetrieve(head, 95);
    bottom = board::addressRetrieve(head, 72);
    (*top).extra = bottom;                              // 95 - 72 snake

    top = board::addressRetrieve(head, 78);
    bottom = board::addressRetrieve(head, 34);
    (*top).extra = bottom;                              // 78 - 34 snake


    top = board::addressRetrieve(head, 64);
    bottom = board::addressRetrieve(head, 51);
    (*top).extra = bottom;                              // 64 - 51 snake

    top = board::addressRetrieve(head, 63);
    bottom = board::addressRetrieve(head, 47);
    (*top).extra = bottom;                              // 63 - 47 snake
    
    top = board::addressRetrieve(head, 55);
    bottom = board::addressRetrieve(head, 34);
    (*top).extra = bottom;                              // 55 - 34 snake

    top = board::addressRetrieve(head, 42);
    bottom = board::addressRetrieve(head, 22);
    (*top).extra = bottom;                              // 42 - 22 snake

    top = board::addressRetrieve(head, 30);
    bottom = board::addressRetrieve(head, 2);
    (*top).extra = bottom;                              // 30 - 2 snake

    top = board::addressRetrieve(head, 19);
    bottom = board::addressRetrieve(head, 8);
    (*top).extra = bottom;                              // 19 - 8 snake

    top = board::addressRetrieve(head, 12);
    bottom = board::addressRetrieve(head, 4);
    (*top).extra = bottom;                              // 12 - 4 snake


    bottom = board::addressRetrieve(head, 5);
    top = board::addressRetrieve(head, 13);
    (*bottom).extra = top;                              // 5 - 13 ladder

    bottom = board::addressRetrieve(head, 14);
    top = board::addressRetrieve(head, 31);
    (*bottom).extra = top;                              // 14 - 31 ladder

    bottom = board::addressRetrieve(head, 18);
    top = board::addressRetrieve(head, 38);
    (*bottom).extra = top;                              // 18 - 38 ladder

    bottom = board::addressRetrieve(head, 28);
    top = board::addressRetrieve(head, 94);
    (*bottom).extra = top;                              // 28 - 94 ladder

    bottom = board::addressRetrieve(head, 45);
    top = board::addressRetrieve(head, 54);
    (*bottom).extra = top;                              // 45 - 54 ladder

    bottom = board::addressRetrieve(head, 62);
    top = board::addressRetrieve(head, 66);
    (*bottom).extra = top;                              // 62 - 66 ladder

    bottom = board::addressRetrieve(head, 69);
    top = board::addressRetrieve(head, 99);
    (*bottom).extra = top;                              // 69 - 99 ladder

    bottom = board::addressRetrieve(head, 75);
    top = board::addressRetrieve(head, 84);
    (*bottom).extra = top;                              // 75 - 85 ladder

    bottom = board::addressRetrieve(head, 80);
    top = board::addressRetrieve(head, 90);
    (*bottom).extra = top;                              // 80 - 90 ladder


    cout<<"------------------------------------------ Snake & Ladders ------------------------------------------"<<endl<<endl;
    cout<<"Instructions: "<<endl;
    cout<<"1) Objective of this game is to reach the final (100) tile first. Both players will start from 1."<<endl;
    cout<<"2) A player will roll a die to determine their move. Rolling a 6 will allow for another roll."<<endl;
    cout<<"3) Three 6s in a roll will make the player's turn void."<<endl;
    cout<<"4) Only 6 tiles ahead of the player's current tile will be visible - this is will be called as the 'Path'."<<endl;
    cout<<"5) Snake / Ladder bonuses will be applied at the complete end of the turn."<<endl<<endl;


    cout<<"Enter player 1 name: ";
    string p1Name;
    cin>>p1Name;
    cout<<endl;
    
    cout<<"Enter player 2 name: ";
    string p2Name;
    cin>>p2Name;
    cout<<endl;
    

    node* p1 = head;
    node* p2 = head;
    cout<<"Starting path: "<<endl;
    board::printPath(head);
    cout<<endl<<endl;
    cout<<"------------------------------------------ Game Starting! ------------------------------------------"<<endl<<endl;

    while ( (*p1).data < 100 && (*p2).data < 100 )
    {
        cout<<p1Name<<" is currently on [ "<<(*p1).data<<" ]"<<endl;
        int move = roll(p1, p1Name);
        p1 = board::movePlayer(p1, move);
        cout<<p1Name<<", you landed on [ "<<(*p1).data<<" ]"<<endl;
        cout<<endl;
        cout<<"------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<p2Name<<" is currently on [ "<<(*p2).data<<" ]"<<endl;
        move = roll(p2, p2Name);
        p2 = board::movePlayer(p2, move);
        cout<<p2Name<<", you landed on [ "<<(*p2).data<<" ]"<<endl;
        cout<<endl;

        cout<<"------------------------------------------ Round Over ------------------------------------------"<<endl<<endl;
    }


    cout<<endl<<endl;
    cout<<"------------------------------------------ Game Over! ------------------------------------------"<<endl<<endl;
    if ( (*p1).data == 100 )
    {
        cout<<p1Name<<" won the game!";
    }
    else
    {
        cout<<p2Name<<" won the game!";
    }
    cout<<endl;

    linkedList::purge(head);
    return 0;
}