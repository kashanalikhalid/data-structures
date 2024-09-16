#include <iostream>
using namespace std;
class array {
public:
    int array[7] = {12, 4, 13, 5, 6, 9, 20};
    int a1= sizeof(array);
    int a2= sizeof(array[0]);
    int len= a1/a2;

    int FindMin( int start)
    {
        int min= array[start];
        int minindex=start;
        for (int i = start; i < len+1; i++)
        {
            if(array[i]<min)
            {
             min=array[i];
             minindex=i;
            }
        }
        return minindex;
    }

    void swap(int min, int max)
    {
        int temp=array[max];
        array[max]=array[min];
        array[min]=temp;

    }
    void SelectionSort()
    {
        for(int i=0; i<len; i++)
        {
            swap(FindMin(i),i);
        }
    }
    void printList()
    {
        for(int i=0; i<len; i++)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }



    void merge(int leftFirst, int leftLast, int rightFirst, int rightLast)
    {

        int save=leftFirst;
        int index=leftFirst;
        int temp[len];
        while((leftFirst<=leftLast) && (rightFirst<=rightLast))
        {
            if (leftFirst>rightFirst)
            {
                temp[index]=array[rightFirst];
                index++;
                rightFirst++;
            }
            else
            {
                temp[index]=array[leftFirst];
                index++;
                leftFirst++;
            }

        }
        while(rightFirst<=rightLast)
        {
            temp[index]= array[rightFirst];
            index++;
            rightFirst++;
        }


        while(leftFirst<=leftLast)
        {
            temp[index]=array[leftFirst];
            leftFirst++;
            index++;
        }


        for(index=save; index<=rightLast; index++)
        {
            array[index]= temp[index];
        }
    }

    void mergesort(int first, int last)
    {
        if(first<last)
        {
            int middle = (first + last) / 2;
            mergesort(first, middle);
            mergesort(middle + 1, last);
            merge(first, middle, middle + 1, last);
        }
    }

    void bubbleSort()
    {
            for(int i=0; i<len-1; i++)
            {
                int shortt=0;
                for(int j=len-1; j>i; j--)
                {
                    if(array[j]<array[j-1])
                    {
                        int temp=array[j-1];
                        array[j-1]=array[j];
                        array[j]=temp;
                        shortt++;

                    }
                }
                if(shortt==0){break;}
            }
    }

    void insertionSort()
    {int start=2;
    bool moreswap=true;

    for(int i=2; i<len-1; i++)
    {
        int current=i;
        moreswap= true;
        while(moreswap== true && current!=0 )
        {
            if(array[current]<array[current-1])
            {
                int temp=array[current-1];
                array[current-1]=array[current];
                array[current]=temp;
                current--;
            }
            else{moreswap=false;}
        }

    }

    }

    void quicSort(int left, int right)
    {

    }

};

int main() {

    array *a1= new array;
    //a1->SelectionSort();
   // a1->printList();
    //a1->mergesort(0,6);
   // a1->bubbleSort();
   a1->SelectionSort();
    a1->printList();

    return 0;
}