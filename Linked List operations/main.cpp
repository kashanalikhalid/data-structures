#include <iostream>
using namespace std;
#include <cstdlib>

class node{
public:
    int data;
    node *next;
};
class linkedlist{
public:
    node *start;
    node *loc;
    node *ploc;

bool isempty(){
if (start==NULL){return true;}
else{return false;}
}
void printlist() {
    if (isempty() != true) {
        node *temp = start;
        while (temp != NULL) {
            cout << temp->data<< " ";
            temp = temp->next;
        }
    }
}
    void insertatfront(int value) {
        node *temp = new node();
        temp->data = value;
        temp->next=start;
        start=temp;

    }

    void search(int value) {
        ploc = NULL;
        loc = start;
        while(loc!=NULL && loc->data<value){
            ploc=loc;
            loc=loc->next;
        }
        if(loc!=NULL && loc->data!=value){
            loc=NULL;
        }

    }

    void insertsorted(int value){
        search(value);
        if(loc!= NULL)
            {cout<<"Value already exists";}
        else{
            if (ploc==NULL)
                {insertatfront(value);}
            else{
                node *temp = new node();
                temp->data=value;
                temp->next=ploc->next;
                ploc->next=temp;}
        }
}


void deletevalue(int value){
    search(value);
    if(loc=NULL){cout<<"Value does not exist";}
    else if(ploc=NULL){
        node *temp=start;
        start=start->next;
    delete temp; }
}
void destroylist() {
    while (start != NULL) {
        node *temp = start;
        start = start->next;
        delete temp;

    }
}
node* getbefore(int m){
    //this function returns the previous node of the value m is in.
    //star before function means function is pointer itself it returns pointer
    node *p= start;
    node *k = start;
while(p!=NULL && p->data!=m){
    k=p;
    p=p->next;
}
    return k;
}

void reverseprint(){
    gotolast();
    cout<< ploc->data;
    node *k;
    while(ploc!=start){
        k=getbefore(ploc->data);
        cout<<k->data;
        ploc=k;
    }
}

void gotolast(){
    loc=start;
    ploc=NULL;
        while(loc!=NULL){
            ploc=loc;
            loc=loc->next;
        }
    }

    void deleteodd(){
    int out=0;
    while(out==0) {
        if (ifodd(start->data) == true) {
            node *temp = new node;
            temp = start;
            start = start->next;
            delete temp;
        } else { out = 1; }
    }
        loc=start->next;
        ploc=start;
        while(loc!=NULL){
            if(ifodd(loc->data)==true){
                node *odd= new node;
                odd=loc;
                ploc->next=loc->next;
                loc=loc->next;
                delete odd;
            }
            else{
                ploc=loc;
                loc=loc->next;
            }
        }
    }
    bool ifodd(int value){
    value=double (value);
    if((value%2)==0){return false;}
    else{return true;}
}


void reverselist(){
        node *current = start;
        node *prev = NULL,
        *nextt = NULL;
        while(current!= NULL){
            nextt=current->next;
            current->next=prev;
            prev=current;
            current=nextt;
        }
        start=prev;
}


void EvenOddSort(){


    node *oddhead=NULL;
    node *oddloc=NULL;
    node *evenhead=NULL;
    node *evenloc=NULL;
    node *value = start;
    while (value != NULL) {
        bool check= ifodd(value->data);
        if(check== false){
            if(evenhead== NULL){
                evenhead=value;
                evenloc=evenhead;
            }
            else {
                node *temp= new node;
                temp=value;
                evenloc->next=temp;
                evenloc = evenloc->next;
            }
        }
        else{
            if(oddhead==NULL){
                oddhead=value;
                oddloc=oddhead;
            }
            else{
                node *temp=new node;
                temp=value;
                oddloc->next=temp;
                oddloc=oddloc->next;
            }

        }
        value=value->next;

        }
        evenloc->next=oddhead;
    oddloc->next=NULL;
    start=evenhead;
    }



    void swapnodes(int a, int b) {
        node *ploca = NULL;
        node *plocb = NULL;
        node *vala = NULL;
        node *valb = NULL;

        ploca = NULL;
        vala = start;
        while (vala != NULL && vala->data != a) {
            ploca = vala;
            vala = vala->next;
        }
        plocb = NULL;
        valb = start;
        while (valb != NULL && valb->data != b) {
            plocb = valb;
            valb = valb->next;
        }
        if (vala == plocb) {
            node *temp = new node;
            node *temp2 = new node;
            temp2->next = valb->next;
            temp->next = ploca->next;
            ploca->next = vala->next;
            valb->next = temp->next;
            vala->next = temp2->next;

        } else if (valb == ploca) {
            node *temp = new node;
            node *temp2 = new node;
            temp2->next = vala->next;
            temp->next = plocb->next;
            plocb->next = valb->next;
            vala->next = temp->next;
            valb->next = temp2->next;
        } else if (vala == start && vala == plocb) {
            node *temp = valb->next;
            valb->next = vala;
            vala->next = temp;
            valb = start;


            plocb->next = valb->next;
            valb->next = vala;
            start = valb;
            ploca = valb;
            plocb = NULL;
        } else if (valb == start && valb == ploca) {
            node *temp = valb;
            node *temp2 = new node;
            temp2->next = vala->next;
            start = vala;
            start->next = temp;
            valb->next = temp2->next;

        } else if (vala == start) {
            node *temp = new node;
            node *temp2 = new node;
            node *temp3 = new node;
            temp->next = start->next;
            temp2->next = valb->next;
            temp3 = start;
            start = plocb->next;
            plocb->next = temp3;
            plocb->next->next = temp2->next;
            start->next = temp->next;


        } else if (valb == start) {
            node *temp = new node;
            node *temp2 = new node;
            node *temp3 = new node;
            temp->next = start->next;
            temp2->next = vala->next;
            temp3 = start;
            start = ploca->next;
            ploca->next = temp3;
            ploca->next->next = temp2->next;
            start->next = temp->next;


        } else {
            node *temp = new node;
            node *temp2 = new node;
            node *temp3 = new node;
            temp->next = valb->next;
            temp2->next = vala->next;
            temp3->next = ploca->next;
            ploca->next = plocb->next;
            plocb->next = temp3->next;
            valb->next = temp2->next;
            vala->next = temp->next;

        }



}
    void insert(int value){
    if (ploc==NULL){insertatfront(value);
    }
    else{
        node *temp;
        temp->data=value;
        temp->next=NULL;
        ploc->next=temp;
    }
    }

void Palindrome(){
    node *current= start;
    gotolast();
    node *last=ploc;
        while(current->data==last->data){
            cout<<"checkk"<<endl;
        if(current==last || current->next==last){cout<<"list is palindrome";
            break;}
        else{
            current=current->next;
            last=getbefore(last->data);
            cout<<"check";
        }
        }


    }


void alternaive(){
    gotolast();
    node *last=ploc;

}


};

int main() {
    linkedlist *NN = new linkedlist();
    for (int i = 0; i < 150; i++)
    {
        NN->insert((rand() % 150)+1);
    }
    NN->printlist(); cout<<endl;
   // NN->Palindrome();
    //NN->swapnodes(1,5);
   // NN->printlist();
   /*NN->EvenOddSort();
    NN->printlist(); cout<<endl;
    NN->reverseprint();
    NN->deleteodd(); cout<<endl;
    NN->printlist();
    NN->reverselist(); cout<<endl;
    NN->printlist();cout<<endl;*/
}