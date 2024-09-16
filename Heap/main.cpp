#include <iostream>
using namespace std;
class heap
        {
        public:
            //int array[10]={0,0,0,0,0,0,0,0,0,0};
            int array[10];
            int current=0;
            void swap(int a, int b)
            {
                int val= array[a];
                array[a]= array[b];
                array[b]=val;
            }
            bool isempty()
            {
                if (current==0)
                {
                    return true;
                }
                else return false;

            }

            int findparent(int index)
            {
                if (index!=1)
                {
                    return index / 2;
                }
                else
                {
                    return 1;
                }
            }

            int rightPos( int index)
            {
                return 2*index+1;
            }

            int leftPos(int index)
            {
                return 2*index;

            }

            void heapify(int index)
            {
                if(array[index]<array[findparent(index)] || index==1)
                {
                    return;
                }
                else
                    {
                    swap(index,findparent(index));
                    heapify(findparent(index));
                    }

            }


            void insert( int value)
            {
                if(isempty())
                {
                    array[1]=value;
                    current=1;

                }
                else
                {
                    current++;
                    array[current]=value;
                    heapify(current);


                }

            }

           void printArray()
            {
                for(int i=1; i<=current; i++)
                {
                    cout<<array[i] <<" ";
                }

            }



            void Delete()
            {

                array[1]=array[current];
                array[current]=0;
                current--;

                heapifyDown(1);

            }

            void heapifyDown(int index) {

                int right = array[rightPos(index)];
                int left = array[leftPos(index)];
                int value = array[index];
               // cout<< left<< right;
                if (value > right && value > left || rightPos(index)>current && leftPos(index)> current)
                {

                    return;
                }
                else {
                    if (value < right && value < left)
                    {
                        if(right>left)
                        {
                         swap(index,rightPos(index));
                         heapifyDown(rightPos(index));
                        }
                        else if(left>right)
                        {
                         swap(index, leftPos(index));
                         heapifyDown(leftPos(index));
                        }

                    }
                    else if(right>value)
                    {
                        swap(index, rightPos(index));
                        heapifyDown(rightPos(index));
                    }
                    else if( left>value)
                    {
                        //cout<<" hi";
                        swap(index,leftPos(index));
                        heapifyDown(leftPos(index));
                    }
                }
            }

        };
int main() {
heap *hp= new heap;
hp->insert(55);
hp->insert(21);
hp->insert(60);
hp->insert(70);
//hp->insert(100);
hp->insert(88);

//hp->insert(90);
hp->Delete();
//hp->array[1];
//hp->Delete();
//hp->Delete();
//hp->Delete();
/*hp->Delete();
hp->Delete();
hp->Delete();*/
    //cout<<hp->current;
hp->printArray();
}