#include <iostream>
using namespace std;
    class node{
    public:
        string data;
        node* next;
    };

    class Stack {
    public:
        node *top=NULL;

        bool isempty() {
            return top == NULL;
        }


        void push(string value) {
                node *temp=new node();
                temp->data = value;
                temp->next = top;
                top = temp;
        }

        string pop()
        {
            string top_value=top->data;
            node *temp=top;
            top=top->next;
            delete temp;
            return  top_value;

        }


        void deleteValue(int value) {
            node *temp;
            temp = top->next;
            delete top;
            top = temp;

        }
        void printstack(){
            while (top!=NULL){
                cout<<pop();
            }
        }

        int ValueOfOperator(string k) {
            if (k == "^") {
                return 6;
            } else if (k == "/" || k == "*") {
                return 5;
            }  else if (k == "+" || k == "-") {
                return 4;}
              else return 0;
        }

        void PostFix(string value) {
            string stringvalue;
            string character;
            int checktop;
            string popp;

            int check;
            int len = value.length();
            for (int i = 0; i<len; i++) {
                character=value.substr(i,1);
                check = ValueOfOperator(character);

                if(check==0)
                {
                    stringvalue=stringvalue+character;
                }
                else
                    {
                    if (top == NULL) {
                        push(character);
                    }
                    else
                        {
                        checktop = ValueOfOperator(top->data);
                        while(checktop>=check && top!=NULL)
                        {
                            popp=pop();
                            stringvalue=stringvalue+popp;
                            //cout<<stringvalue<<endl;
                            if(!isempty()){
                            checktop = ValueOfOperator(top->data);}
                        }
                        push(character);

                        }
                    }
            }
            while(!isempty()){
                string popp=pop();
                stringvalue=stringvalue+popp;
            }
            cout<<stringvalue;
            exit(0);
        };

    };
    int main() {
        Stack *file= new Stack();
       file->PostFix("A-B-C-D");
        //file->push("t");
        //file->push("y");
        cout<<file->pop();
        //file->printstack();
        }
