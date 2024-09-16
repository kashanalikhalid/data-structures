#include <iostream>
#include <utility>
using namespace std;

void printarray( int a[], int b[])
{
    int n=5;
    cout << "a[] = ";
    for (int i=0; i<n; i++)
        cout << a[i] << ", ";
    cout << "\nb[] = ";
    for (int i=0; i<n; i++)
        cout << b[i] << ", ";
}

void inputarray()
{
    int a[5];
    int b[5];
    int size=5;
    int element1,element2;


    for (int i=0;i<5;i++)
    {
        cout<<"please Enter Element of The first array"<<endl;
        cin>>element1;
        cout<<"please Enter Element of The second array"<<endl;
        cin>>element2;
        a[i] = element1;
        b[i] = element2;
    }
    printarray(a,b);
    swap(a, b);
    printarray(a,b);
}



int main()
{
    inputarray();

    return 0;
}