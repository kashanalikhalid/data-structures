#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node *prev;
};

class DoublyList {
public:
    node *start = NULL;
    node *loc = NULL;
    node *ploc = NULL;
    node *last = NULL;

    DoublyList() {
        start = NULL;
    }

    bool isEmpty() {
        return (start == NULL);
    }

    void insertAtFront(int value) {
        if (isEmpty()) {
            node *temp = new node;
            temp->data = value;
            temp->next = NULL;
            temp->prev = NULL;
            start = temp;
            last = temp;
        } else {
            node *temp = new node;
            temp->data = value;
            temp->next = start;
            temp->prev = NULL;
            start->next->prev = temp;
            start = temp;
        }
    }


    void printlist() {
        loc = start;
        ploc = NULL;
        while (loc != NULL) {
            cout << loc->data;
            ploc = loc;
            loc = loc->next;
        }
    }


    void search(int value) {
        if (!isEmpty()) {
            loc = start;
            ploc = NULL;
            while (loc != NULL && loc->data < value) {
                ploc = loc;
                loc = loc->next;
            }
            if (loc != NULL && loc->data != value) {
                loc = NULL;
            }
            // else{cout<<"value found";}

        }
    }

    void insertAtLast(int value) {
        if (!isEmpty()) {
            node *temp = new node;
            temp->data = value;
            temp->prev = last;
            last->next = temp;
            temp->next = NULL;
            last = temp;
        } else {
            cout << "List is empty,First enter node at the front";
        }
    }

    void insertsorted(int value) {
        search(value);
        if (loc == NULL & ploc != last) {
            node *temp = new node();
            temp->data = value;
            temp->next = ploc->next;
            ploc->next->prev = temp;
            ploc->next = temp;
            temp->prev = ploc;

        } else if (loc == NULL && ploc == last) {
            insertAtLast(value);
        } else {
            cout << "value already exists";
        }

    }

    void deleteValue(int value) {
        search(value);
        if (loc != NULL) {
            if (ploc == NULL) {
                node *temp = start;
                start->next->prev = NULL;
                start = start->next;
                delete temp;
            } else if (loc == last) {
                node *temp = last;
                ploc->next = NULL;
                last = ploc;
                delete temp;
            } else {
                ploc->next = loc->next;
                loc->next->prev = ploc;
                delete loc;
            }
        }
    }

    void destroylist() {
        while (start != NULL) {
            node *temp = start;
            start = start->next;
            delete temp;
        }
        cout << "list has been deleted";
    }


    void reverse()
    {
    node* start1=last;
    node *loc1=start1;
    loc=last->prev;
    while(loc!=NULL)
    {
     node *temp=new node;
     temp->data=loc->data;
     temp->next=NULL;
     temp->prev=loc1;
     loc1->next=temp;
     loc1=temp;
     loc=loc->prev;

    }
        node *temp=last;
        start=start1;
        last=loc1;
    }

    void swap(int a , int b)
    {
        search(a);
        node *loc1 = loc;
        node *ploc1 = ploc;

        search(b);
        node *loc2 = loc;
        node *ploc2 = ploc;

    }

    bool checkodd(int value)
    {
        if((value%2)==0)
        {
            return false;
        }
        else
            {
            return true;
            }
    }

    void deleteeven()
    {
         bool checkstart=checkodd(start->data);
         while(checkstart==true)
         {
          node *temp=start;
          start->next->prev=NULL;
          start=start->next;
          checkstart=checkodd(start->data);
         }
         loc=start->next;
         ploc=start;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    DoublyList *check= new DoublyList();
    check->insertAtFront(1);
    check->insertsorted(2);
    check->insertsorted(4);
    check->insertsorted(5);
    check->insertsorted(6);
    check->insertsorted(3);
    check->printlist(); cout <<endl;
    //check->deleteValue(4);
    check->printlist();cout<<endl;
    //check->destroylist();
    //check->printlist();cout<<endl;
    check->reverse();
    check->printlist();
   // check->search(1);
}