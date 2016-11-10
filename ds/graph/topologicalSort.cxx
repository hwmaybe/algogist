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

    void dfsRecur(int index, vi &visited, vi&);

    public:
    graph(int v);
    void addEdge(int i , int j);
    void dfs(int index);
    void bfs(int index);
};

graph::graph(int v):v_(v), adjList_(v+1, vi())
{
}
//! add edge i---j
void graph::addEdge(int i , int j)
{
    adjList_[i].push_back(j);
}

void graph::dfsRecur(int index, vi &visited, vi &order)
{
    visited[index] = 1;
    for(int i  =0 ; i < adjList_[index].size(); i++)
    {
        int j = adjList_[index][i];
        if(!visited[j])
            dfsRecur(j, visited, order);
    }
    //! Store vertex number after its dfs is complete.
    order.push_back(index);
}

void graph::dfs(int index)
{
    vi visited(v_+1, 0);
    vi order;
    dfsRecur(index, visited, order);
    //Print vector in reverse order.
    std::copy(order.rbegin(), order.rend(), 
            std::ostream_iterator<int>(cout, "\t"));
}

int main()
{
    //! make DAG graph.
    graph g(10);
    g.addEdge(1,5);
    g.addEdge(1,3);
    g.addEdge(5,6);
    g.addEdge(5,4);
    g.addEdge(6,7);
    g.addEdge(6,2);
    g.addEdge(4,2);
    g.addEdge(4,9);
    g.addEdge(6,7);
    g.addEdge(2,9);
    g.dfs(1);

    return 0;
}

