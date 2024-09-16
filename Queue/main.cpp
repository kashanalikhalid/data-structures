#include <iostream>
using namespace std;

 class queue
        {
    int queuee[20];
    int front=0,rear=-1;
        public:
            bool isfull()
            {
                if (rear==(19))
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
                if (rear==-1){return true;}
                else{return false;}
            }

            int dequeue()
            {
                if(!isempty())
                { int temp=queuee[front];
                queuee[front]=NULL;
                front=front+1;
                    return temp;
                }
                else return -1;
            }
            void enqueue(int value)
            {
                if(!isfull())
                {
                    queuee[++rear]=value;
                }
            }

            void printqueue()
            {
                while(rear>=front)
                {
                    cout<<queuee[rear];
                    rear--;
                }
            }



        };


int main() {
    std::cout << "Hello, World!" << std::endl;
    queue *array= new queue();
    array->enqueue(3);
    array->enqueue(4);
    array->enqueue(5);
    array->enqueue(6);
   cout<< array->dequeue(); cout<<endl;
    array->printqueue();
}