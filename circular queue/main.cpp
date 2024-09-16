#include <iostream>
using namespace std;
class Circularqueue
{
    int queuee[5];
    int front=0,rear=-1,count=1;
public:
    bool isfull()
    {
        if (count==6)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isempty()
    {
        if (count==0){return true;}
        else{return false;}
    }

    int dequeue()
    {
        if(!isempty() )
        {
            if(front==5)
            {
            front=0;
            }
         int temp=queuee[front];
            queuee[front]=0;
            front=front+1;
            count--;
            return temp;

        }
        else return -1;
    }
    void enqueue(int value)
    {
        if(!isfull())
        {
            if(rear==4)
            {
                rear=-1;
            }
            rear=rear+1;
            queuee[rear]=value;

            count++;
        }
    }

    void printqueue()
    {int temp=count;
        while(count>=2)
        {if(front==5){front=0;}
            cout<<queuee[front];
            front++;
            count--;
        }
        count= temp;
    }



};


int main() {
    std::cout << "Hello, World!" << std::endl;
    Circularqueue *q= new Circularqueue;
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->printqueue();cout<<endl;
    cout<<q->dequeue(); cout<<endl;
    cout<<q->dequeue();cout<<endl;
    cout<<q->dequeue();cout<<endl;
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->printqueue();
}