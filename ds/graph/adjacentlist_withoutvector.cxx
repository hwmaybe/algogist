#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio>
#include <list>
#include <queue>
using namespace std; 

typedef vector<int> vi;
typedef vector<vi> vii;

class graph
{
    int v_;
    list<int>* adjList_;


    void dfsRecur(int index, vi &visited);

    public:
    graph(int v);
    void addEdge(int i , int j);
    void dfs(int index);
};

graph::graph(int v):v_(v)
{
    adjList_ = new list<int>[v+1];

}
//! add edge i---j
void graph::addEdge(int i , int j)
{
    adjList_[i].push_back(j);
    adjList_[j].push_back(i);
}

void graph::dfsRecur(int index, vi &visited)
{
    visited[index] = 1;
    cout<<index;
    list<int>::iterator iter  = adjList_[index].begin();
    for(; iter not_eq adjList_[index].end() ; iter++)
    {
        int j = (*iter);
        if(!visited[j])
            dfsRecur(j, visited);
    }
    cout<<"\n";
}

void graph::dfs(int index)
{
    vi visited(v_+1, 0);
    dfsRecur(index, visited);
}
int main()
{
    graph g(5);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(5,1);
    g.dfs(1);

    return 0;
}

