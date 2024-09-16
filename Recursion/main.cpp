#include <iostream>
using namespace std;
class node{
public:
    int data;
    node *next;
    node *prev;
};
class linkedlist {
public:
    node *start;
    node *loc;
    node *ploc=NULL;

    bool isempty() {
        if (start == NULL) { return true; }
        else { return false; }
    }

    void printlist() {
        if (isempty() != true) {
            node *temp = start;
            while (temp != NULL) {
                cout << temp->data;
                temp = temp->next;
            }
        }
    }

    void insertatfront(int value) {
        node *temp = new node();
        temp->data = value;
        temp->next = start;
        start = temp;

    }

    void search(int value) {
        ploc = NULL;
        loc = start;
        while (loc != NULL && loc->data < value) {
            ploc = loc;
            loc = loc->next;
        }
        if (loc != NULL && loc->data != value) {
            loc = NULL;
        }

    }

    void insertsorted(int value) {
        search(value);
        if (loc != NULL) { cout << "Value already exists"; }
        else {
            if (ploc == NULL) { insertatfront(value); }
            else {
                node *temp = new node();
                temp->data = value;
                temp->next = ploc->next;
                ploc->next = temp;
            }
        }
    }


    void deletevalue(int value) {
        search(value);
        if (loc = NULL) { cout << "Value does not exist"; }
        else if (ploc = NULL) {
            node *temp = start;
            start = start->next;
            delete temp;
        }
    }

    void destroylist() {
        while (start != NULL) {
            node *temp = start;
            start = start->next;
            delete temp;

        }
    }

   bool searchRecursive(int value, node*ptr)

    {
        if(ptr==NULL)
        {
            return false;
        }
        else if(ptr->data==value)
        {
            return true;
        }
        else
        {

            return searchRecursive(value, ptr->next);

        }


    }


  void revPrint(node* ptr)
  {
      if (ptr->next==NULL)
      {
          cout<<ptr->data;

      }
      else
          {
          revPrint(ptr->next);
          cout<<ptr->data;
          }
  }


    void evenReverseOdd(node *ptr)
    {
        if(ptr!=NULL)
        {
            if (ptr->data%2==0)
            {
                cout<<ptr->data;
                evenReverseOdd(ptr->next);
            }
            else
            {
                evenReverseOdd(ptr->next);
                cout<<ptr->data;
            }

        }


    }
    bool reverse(node* curr, node* prev, node* succ)
    {
        if(succ==NULL)
        {
            curr->next=prev;
            prev=curr;
            start=prev;
            cout<<"list is reversed";
            return true;
        }
        else{
            curr->next=prev;
            prev=curr;
            curr=succ;
            succ=succ->next;
            //  cout<<"reverse is called"<<endl;
            return  reverse(curr, prev, succ);
        }
    }


};
////Rccursion for doubly linked list

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

    void insert(int value)
    {

        if(!isEmpty())
        {
            node *temp= new node;
            temp->data=value;
            temp->next=NULL;
            temp->prev=last;
            last->next=temp;
            last=temp;
        } else
            insertAtFront(value);
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


    int palindrome(node *first ,node *lastt)
    {
        if(first==lastt || first->next==lastt)
        {
            cout<<"List is palindrome";
            return 1;
        }
        else if(first->data!=lastt->data)
        {
            cout<<"list is not palindrome";
            return 0;
        }

        else
            {
                return palindrome(first->next, lastt->prev);
            }
    }

};



    int factorial(int x) {

        if (x == 0) {
            cout << "base case for " << x << endl;
            return 1;

        } else {
            cout << "calling funcion for " << x << endl;
            return x * factorial(x - 1);

        }
    }

    int fibonacciSingle(int a) {
        if (a == 0 || a == 1) {
            return 1;
        } else {

            return fibonacciSingle(a - 1) + fibonacciSingle(a - 2);
        }
    }

    void fibonacci(int b) {
        if (b == 1) {
            cout << "1";
        }
        if (b == 2) {
            cout << "1" << " 1";
        } else {
            cout << "1" << " 1";
            for (int i = 3; i <= b; i++) {
                cout << " " << fibonacciSingle(i);
            }
        }
    }

    int power(int num, int pwr) {
        if (pwr == 0) {
            return 1;
        }
        return num * power(num, pwr - 1);
    }

    void print(string x, int n) {
        if (n == 1) {
            cout << x << endl;
        } else {
            cout << x << endl;
            print(x, n - 1);
        }
    }

    int mystery1(int n) {
        if (n < 10) {
            return n;
        } else {
            int a = n / 10;
            int b = n % 10;
            return mystery1(a + b);
        }
    }


    int main()
    {
        ///cout<<factorial(4);
        ///fibonacci(5);
        ///cout<<power(2,3);
        ///print("moiz bitch", 3);
        ///cout << mystery1(648);
        linkedlist *list= new linkedlist();
        list->insertsorted(1);
        list->insertsorted(2);
        list->insertsorted(3);
        list->insertsorted(4);
        list->insertsorted(5);
        //list->printlist();
        cout<<list->searchRecursive(2,list->start);
        list->revPrint(list->start);cout<<endl;
        list->searchRecursive(0,list->start);
        list->evenReverseOdd(list->start);
        list->ploc=NULL;
        list->reverse( list->start,list->ploc,list->start->next);cout<<endl;
        list->printlist();



        DoublyList *dbly= new DoublyList;
       dbly->insertAtFront(1);
        dbly->insert(2);
        dbly->insert(3);
        dbly->insert(4);
        dbly->insert(4);
        dbly->insert(3);
        dbly->insert(2);
        dbly->insert(1);
        dbly->printlist();
        dbly->palindrome(dbly->start, dbly->last);



    }
