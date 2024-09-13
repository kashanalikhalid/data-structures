#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>


class node
{
public:
    int data;
    node *Rchild=NULL;
    node *Lchild=NULL;
};

 class Unbalanced
 {
 public:
     string balance;
     node *data=NULL;
 };

class AVL
{
public:
    node *root=NULL;
    node *loc=NULL;
    node *ploc=NULL;
    Unbalanced *NN=NULL;


    bool isempty()
    {
        if(root==NULL)
        {
            return true;
        }
        else return false;
    }


    void insert(int value)
    {
        ploc=NULL;
        loc=root;
        if(isempty())
        {
            node *temp= new node;
            temp->data=value;
            temp->Rchild=NULL;
            temp->Lchild=NULL;
            root=temp;
        }
        else
        {
            node *temp=root;
            while(temp!=NULL)
            {
                if(value>=temp->data)
                {

                    ploc=loc;
                    loc=loc->Rchild;
                    temp=loc;

                }
                else
                {

                    ploc=loc;
                    loc=loc->Lchild;
                    temp=loc;
                }
            }

            if(value>=ploc->data)
            {
                node * temp= new node;
                temp->data=value;
                ploc->Rchild=temp;
            }
            else
            {
                node *temp= new node;
                temp->data= value;
                ploc->Lchild= temp;
            }
        }
        cout<<"Num is "<<value<<endl;
        cout<<"before balancing the tree: ";
        preOrder(root);
        BalanceTheTree();
        cout<<endl;
        cout<<"after balancing the tree: ";
        preOrder(root);
        cout<<endl;
    }
    void deleteValue( int value)
    {
        //cout << "called delete function for "<< value;
        if(!isempty()) {
            ploc = NULL;
            loc = root;

            while(loc!=NULL && loc->data!=value)
            {
                if(value>loc->data)
                {

                    ploc=loc;
                    loc=loc->Rchild;
                }
                else
                {
                    ploc=loc;
                    loc=loc->Lchild;
                }
            }
            if(loc==NULL)
            {
                cout<<"Value not found";
            }

            if(loc->data==value && loc->Rchild==NULL && loc->Lchild==NULL)
            { if(loc !=root)
                {
                    node *temp = loc;
                    if (ploc->Rchild == loc)
                    {
                        ploc->Rchild = NULL;
                    } else
                    {
                        ploc->Lchild = NULL;
                    }
                    delete temp;
                }
                else
                {
                    node * temp=loc;
                    root=NULL;
                    delete temp;
                }

            }

            if(loc->data==value && loc->Rchild==NULL && loc->Lchild!=NULL)
            {if(loc!=root) {
                    if (ploc->Lchild == loc) {
                        node *temp = loc;
                        ploc->Lchild = loc->Lchild;
                        delete temp;
                    } else {
                        node *temp = loc;
                        ploc->Rchild = loc->Lchild;
                        delete temp;
                    }
                }
                else
                {
                    node *temp=loc;
                    root=loc->Lchild;
                    delete temp;
                }
            }
            else if(loc->data==value && loc->Rchild!=NULL && loc->Lchild==NULL)
            {
                if(loc!=root) {
                    if (ploc->Lchild == loc) {
                        node *temp = loc;
                        ploc->Lchild = loc->Rchild;
                        delete temp;
                    } else {
                        node *temp = loc;
                        ploc->Rchild = loc->Rchild;
                        delete temp;
                    }
                }
                else
                {
                    node *temp=loc;
                    root=loc->Rchild;
                    delete temp;
                }
            }

            if(loc->Rchild!=NULL && loc->Lchild!=NULL && loc->data==value)
            {
                node *findd=loc;
                node *succ= findMin(loc);
                int found= succ->data;
                deleteValue(succ->data);
                findd->data=found;

            }

        }
        //cout<< "before order "; preOrder(root); cout<<endl;
        BalanceTheTree();
        //cout<< "after order "; preOrder(root); cout<<endl;



    }


    node * findMin(node *temp) //finds minimum value which is on the left
    {
        node * curr= temp->Lchild;
        while(curr->Rchild!=NULL)
        {
            curr=curr->Rchild;

        }
        return curr;
    }

    void preOrder(node * temp)
    {
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            preOrder(temp->Lchild);
            preOrder(temp->Rchild);


        }
    }



 int calheight(node *temp)
    {
        if(temp!=NULL)
        {
            return 1+max(calheight(temp->Rchild),calheight(temp->Lchild));
        }
        else return 0;
    }



    int RightHeight(node *temp)
    
    {
        temp=temp->Rchild;
        return calheight(temp);
    }

    int LeftHeight(node *temp)
    {
        temp=temp->Lchild;
        return calheight(temp);
    }


    void Findbalance(node * temp)
    {
        if(temp!=NULL) {
            Findbalance(temp->Lchild);
            Findbalance(temp->Rchild);
            int LH= LeftHeight(temp);
            int RH= RightHeight(temp);
            if(NN==NULL)
            {

                if (RH - LH < -1 && LH > RH)
                {
                    Unbalanced *fill = new Unbalanced;
                    fill->balance = "R";
                    fill->data = temp;
                    NN = fill;
                }
                else if (RH - LH > 1 && RH > LH)
                {
                    Unbalanced *fill = new Unbalanced;
                    fill->balance = "L";
                    fill->data = temp;
                    NN = fill;

                }
            }
        }



    }



    void BalanceTheTree()
    {
            NN = NULL;
            Findbalance(root);

            while (NN != NULL)
            {
                //cout<<NN->data->data<<NN->balance;
                if (NN->balance == "R" || NN->balance == "r")
                {
                    if(difference(NN->data->Lchild)<0)
                    {
                        cout<<"one";
                        leftRotate(NN->data->Lchild);
                        RightRotate(NN->data);

                    }
                    else

                    {
                        cout<<"two";
                        RightRotate(NN->data);
                    }
                }
                else if(NN->balance=="L" || NN->balance=="l")
                    {
                    if(difference(NN->data->Rchild)>0)
                    {
                        cout<<" Three";
                        RightRotate(NN->data->Rchild);
                        leftRotate(NN->data);
                    }
                    else
                    {
                        cout<<" four";
                        leftRotate(NN->data);
                    }
                    }

                NN = NULL;
                Findbalance(root);
            }
        }


        int difference(node *temp)
        {
        int LH= calheight(temp->Lchild);
        int Rh= calheight(temp->Rchild);
            return LH-Rh;
        }



    void leftRotate(node *temp)
    {
        cout<<temp->data;
            node *y = temp->Rchild;
            node *Y2 = y->Lchild;

            y->Lchild = temp;
            temp->Rchild = Y2;
            if (temp==root)
            {
                root = y;
            }
            else
                {
                parent(temp,root);
                if(loc->Rchild==temp)
                {

                    loc->Rchild=y;
                }
                else if(loc->Lchild==temp)
                    {

                    loc->Lchild=y;
                }
                //cout<<loc->Lchild->Lchild->data;

            }

    }

    void RightRotate( node *temp)
    {


            node *y = temp->Lchild;
            node *y2 = y->Rchild;

            y->Rchild = temp;
            temp->Lchild = y2;

            if (temp==root) {
                root = y;

            }
            else{

                parent(temp,root);
                if(loc->Rchild==temp)
                {
                    loc->Rchild=y;
                }
                else{
                    loc->Lchild=y;
                }
            }

    }




    void parent (node *find , node *temp)
    {
        if(temp!=NULL && temp->Rchild!=find && temp->Lchild!=find)
        {
            if(temp->Lchild!=find && temp->Lchild!=NULL && temp->Rchild==NULL)
            {
                     parent(find, temp->Lchild);
            }
            else if(temp->Rchild!=find && temp->Lchild==NULL & temp->Rchild!=NULL)
            {
                     parent(find, temp->Rchild);
            }
            else if(temp->Rchild!=NULL && temp->Lchild!=NULL && temp->Lchild!=find && temp->Rchild!=find)
            {
                      parent(find, temp->Rchild);
                     parent(find, temp->Lchild);
            }

        }
        else loc=temp;
    }
    void search(int value)
    {

    }

};

int main() {
    AVL *tree= new AVL();
   tree->insert(1);
    tree->insert(2019);
    tree->insert(2019);
    tree->insert(2018);
    tree->insert(2019);
    tree->insert(2017);
    tree->insert(1998);
    tree->insert(2020);
    tree->insert(2050);
    //tree->insert(6);
    //tree->insert(7);
    //tree->insert(2);
    //tree->insert(10);
     //tree->insert(9);
    //int b=1;
   // for(int i=1; i<150; i++ )
    //{
    //    tree->insert(int((rand() % 150) + 1));
    //}


   //cout<<tree->loc->data;

   // tree->deleteValue(10);
    //tree->deleteValue(9);
   // tree->deleteValue(7);
    //tree->deleteValue(3);
    //tree->deleteValue(6);
    tree->preOrder(tree->root);
}