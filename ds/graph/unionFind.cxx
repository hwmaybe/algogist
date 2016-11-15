#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio> 
using namespace std; 

class UF{
    
    int v_;
    vector<int> vRank_;
    vector<int> vParent_;
    public:
        UF(int);
        int find(int);
        void join(int, int);
        bool isSameParent(int, int);

};

UF::UF(int v):v_(v)
{
    vRank_.assign(v, 0);
    vParent_.assign(v, 0);
    for(int i = 0 ; i < v ; i++)
    {
        vParent_[i] = i;
    }
}

int UF::find(int i)
{
    if(vParent_[i] == i)
        return i;
    return vParent_[i] = find(vParent_[i]);
}

void UF::join(int i , int j)
{
    if(isSameParent(i, j))
    {
        cout<<"Cycle~";
        return;
    }
    int x = find(i);
    int y = find(j);
    if(vRank_[x] > vRank_[y])
    {
        vParent_[y] = x;
    }
    else
    {
        vParent_[x] = y;
        if(vRank_[x] == vRank_[y])
        {
            vRank_[y]++;
        }
    }
}

bool UF::isSameParent(int i , int j)
{
    return (find(i) == find(j));
}


int main( )
{ 
    UF obj(7);
    obj.join(0,1);
    obj.join(0,2);
    obj.join(1,3);
    obj.join(1,4);
    obj.join(2,5);
    obj.join(2,6);
    obj.join(6,1);
}
