#include <iostream>
using namespace std;

int E(int n,int m)
{
if(n==0)
{
    return 1;
}
else if(m==0)
{
    return 1;
}
else
    return min(E(n-1,m-1)+1,E(n-1,m)+1,E(n,m-1)+1);
};

int mindistance(string word, string word2)
{
int len= E(word.length(), word2.length());
return len;
};

int main() {
    cout<<mindistance("kashan","ali");
}
