#include <iostream>
using namespace std;

class node
        {
        public:
            int data;
            node *Rchild=NULL;
            node *Lchild=NULL;
        };

class trees
        {
        public:

            node * root=NULL;
            node *ploc=NULL;
            node *loc=NULL;

            bool isempty()
            {
                return root==NULL;
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

                if(value>ploc->data)
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
            }



            void deleteValue( int value)
            {
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

            node* deleteLeaf(node *temp)
            {
                bool isleaf= false;
                if(temp!=NULL)
                {
                    if(temp->Rchild==NULL && temp->Lchild==NULL)
                    {
                        isleaf=true;
                    }
                    temp->Lchild=deleteLeaf(temp->Lchild);
                    temp->Rchild=deleteLeaf(temp->Rchild);
                    if(isleaf)
                    {
                        delete temp;
                        return NULL;
                    } else
                    {
                        return temp;
                    }
                }
                else
                {
                    return NULL;
                }
            }

            void destroyTree(node * temp)
            {
               if(temp!=NULL)
               {
                   destroyTree(temp->Lchild);
                   destroyTree(temp->Rchild);
                   free(temp);
               }
            }

         int calculateDepth(node *temp, int depth )
            {
               if(temp!=NULL)
                {
                    int ld=calculateDepth(temp->Lchild,depth+1);
                    int Rd= calculateDepth(temp->Rchild,depth+1);
                    return max(ld,Rd);
                }
                else
                   return depth;
            }

         void depth()
            {
                int dep=calculateDepth(root,-1);
                cout<<"Depth of tree is "<< dep;

            }

         void Height()
            {
                cout <<" height of tree is "<<calheight(root);
            }


         int calheight(node *temp)
            {
                if(temp!=NULL)
                {
                    return 1+max(calheight(temp->Rchild),calheight(temp->Lchild));
                }
                else return 0;
            }


            void Mystery(node *temp, int k)
            {
                int c=0;
                enigma(root,k,c);
            }

            void enigma(node *root , int k, int &c)
            {
                if (root ==NULL || c>=k)
                {
                    return;
                }
                enigma(root->Rchild ,k,c);
                c++;
                if(c==k)
                {
                    cout<< root->data<<endl;
                    return;
                }
                enigma(root->Lchild,k,c);
            }

        };



int main() {

    trees *NN= new trees();
    int b=100;
    NN->insert(50);
    NN->insert(28);
    NN->insert(20);
    NN->insert(40);
    NN->insert(70);
    NN->insert(60);
    NN->insert(80);
    NN->Mystery(NN->root,3);

  /* int array [7]={10,20,30,40,50,25};
    for(int i=0; i<7; i++)
    {
     NN->insert(array[i]);
    }*/
    //NN->preOrder(NN->root); cout<<endl;
   // NN->deleteValue(23);
    //NN->preOrder(NN->root);
    //NN->deleteLeaf(NN->root);
    //NN->preOrder(NN->root);
    //NN->destroyTree(NN->root);
    //NN->root=NULL;
    //NN->deleteValue(50);
   // NN->depth();
    //NN->Height();
    //NN->deleteValue(10);
    //NN->Height();
  // NN->deleteValue(7);
    //NN->preOrder(NN->root);
    //write a function that prints only leaf nodes
    // print only nodes with left subChild

}