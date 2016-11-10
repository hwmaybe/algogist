#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio>
#include <queue>
#include <iterator>
using namespace std; 

typedef vector<int> vi;
typedef vector<vi> vii;

class graph
{
    int v_;
    vii adjList_;


    public:
    graph(int v);
    void addEdge(int i , int j);
    bool findCycle();
    bool findCycleRecur(int index, vi &visited, vi &st);
};

graph::graph(int v):v_(v), adjList_(v+1, vi())
{
}
//! add edge i---j
void graph::addEdge(int i , int j)
{
    adjList_[i].push_back(j);
}

bool graph::findCycleRecur(int index, vi &visited, vi &st)
{
    visited[index] = 1;
    st[index] = 1;
    bool bRet = false;
    for(int i = 0 ; i < adjList_[index].size(); i++)
    {
        int j = adjList_[index][i];
        if(!st[j])
        {
            bRet |= findCycleRecur(j, visited, st);
        }
        else if(1 == st[j])
        {
            return true;
        }
    }
    st[index] = 0;
    return bRet;
}

bool graph::findCycle()
{
    vi visited(v_+1, 0);
    vi st(v_+1, 0);
    for(int i =0; i <= v_; i++)
    {
        if(0 == visited[i] and findCycleRecur(i, visited, st))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    //! make DAG graph.
    graph g(8);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(5,7);
    g.addEdge(4,7);
    g.addEdge(7,2);
    cout<<g.findCycle();

    graph gg(5);
    gg.addEdge(1,2);
    gg.addEdge(1,3);
    gg.addEdge(2,4);
    gg.addEdge(3,4);
    cout<<gg.findCycle();



    return 0;
}

