#include <iostream>
using namespace std;

class node
{
    public:
    int data;    
    node* next;
    node* extra;

    node(int data)
    {
        (*this).data = data;
        next = NULL;
        extra = NULL;
    }
};

class linkedList
{
    public:

    static node* create()
    {
        int data;
        cin>>data;

        if ( data == -1 )
        {
            return NULL;
        }
        else
        {
            node* head = new node(data);
            node* nextNode = create();
            (*head).next = nextNode;
            return head;
        }
    }

    static void print(node* head)
    {
        if ( head == NULL || (*head).data == 101 )
        {
            cout<<endl;
            return;
        }
        else
        {
            cout<< (*head).data << " ";
            print((*head).next);
        }
    }

    static void append(node* head, int const &data)
    {
        if ( head == NULL )
        {
            return;
        }
        if ( (*head).next == NULL )
        {
            node* newNode = new node(data);
            (*head).next = newNode;
        }
        else
        {
            append((*head).next, data);
        }
    }

    static node* insert(node* head, int index, int const &data)
    {
        if ( index == 0 )
        {
            node* newNode = new node(data);
            (*newNode).next = head;
            return newNode;
        }
        if ( head == NULL )
        {
            return head;
        }
        else
        {
            node* nextNode = insert( (*head).next, index - 1, data);
            (*head).next = nextNode;
            return head;
        }
    }

    static node* remove(node* head, int const &value)
    {
        if ( head == NULL )
        {
            return head;
        }

        if ( (*head).data == value )
        {
            node* temp = (*head).next;
            delete head;
            head = temp;
            return head;
        }
        else
        {
            node* nextNode = remove( (*head).next, value );
            (*head).next = nextNode;
            return head;
        }
    }

    static bool search(node* head, int const &value)
    {
        if ( head == NULL )
        {
            return false;
        }

        if ( (*head).data == value )
        {
            return true;
        }
        else
        {
            bool smallerList = search((*head).next, value);
            return smallerList;
        }
    }

    static node* purge(node* head)
    {
        if ( head == NULL )
        {
            return NULL;
        }
        else
        {
            node* smallerList = purge((*head).next);
            (*head).next = smallerList;
            delete head;
            return NULL;
        }
    }
};

class board
{
    public:
    
    static node* creator(node* head)
    {
        int i=2;
        node* tail = head;
        while ( i <= 120 )
        {
            (*tail).next = new node(i);
            tail = (*tail).next;
            i++;
        }
        return tail;
    }

    static node* addressRetrieve(node* head, int x)
    {
        node* temp = head;
        while ( (*temp).data != x && (*temp).next != NULL )
        {
            temp = (*temp).next;
        }

        return temp;
    }
    
    static void printPath(node* player)
    {
        node* temp = player;
        int i=1;
        while ( i <= 7 && (*temp).data <= 100 )
        {
            cout <<"[ "<< (*temp).data <<" ";
            
            if ( (*temp).extra != NULL )
            {
                node* ex = (*temp).extra;
                if ( (*ex).data > (*temp).data )
                {
                    cout<<"Ladder to "<<(*ex).data<<" ]";
                }    
                else if ( (*ex).data < (*temp).data )
                {
                    cout<<"Snake to "<<(*ex).data<<" ]";
                }
            }
            else
            {
                cout<<"]";
            }
            cout<<"           ";
            temp = (*temp).next;
            i++;
        }
        cout<<endl;
    }

    static node* movePlayer(node* player, int roll)
    {
        node* temp = player;
        int i=1;

        while ( i <= roll )
        {
            temp = (*temp).next;
            i++;
        }

        if ( (*temp).extra != NULL )
        {
            node* ex = (*temp).extra;
            if ( (*ex).data > (*temp).data )
            {
                cout<<"You climbed a ladder to: "<<(*ex).data<<endl;
            }
            else
            {
                cout<<"You were bit by a snake to: "<<(*ex).data<<endl;
            }
            temp = (*temp).extra;
        }
        if ( (*temp).data > 100 )
        {
            cout<<"Over-roll. Move void."<<endl;
            return player;
        }
        return temp;
    }

};

int rollDie()
{
    srand(time(0));
    int roll;
    roll = rand()%(6) + 1;

    return roll;
}

node* moveTester(node* player, int x)
{
    int i=1;
    while ( i <= x )
    {
        player = (*player).next;
        i++;
    }
    return player;
}

int roll(node* player, string name)
{
    cout<<name<<"'s turn to roll die. The path in front of them: "<<endl;
    board::printPath(player);
    cout<<"Enter any character to roll die. "; 
    char pH;
    cin>>pH;

    int x = rollDie();
    cout<<"------------------------------------------ Current roll: "<<x<<" ------------------------------------------"<<endl;

    while ( x%6 == 0 )
    {
        int y = x;
        cout<<"You rolled a 6! The path which lies ahead: "<<endl;
        player = moveTester(player, y);
        board::printPath(player);
        
        cout<<"Enter any character to roll another die. ";
        cin>>pH;
        y = rollDie();
        cout<<"------------------------------------------ Die rolled: "<<y<<" ------------------------------------------"<<endl<<endl;
        x = x + y;
        cout<<"------------------------------------------ Total roll: "<<x<<" ------------------------------------------"<<endl<<endl;
        if ( x == 18 )
        {
            cout<<"Three consecutive 6 rolls, turn has been cancelled!"<<endl;
            return 0;
        }
    }
    return x;
}