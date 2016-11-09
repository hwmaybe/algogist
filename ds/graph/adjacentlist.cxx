#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio>
#include <queue>
using namespace std; 

typedef vector<int> vi;
typedef vector<vi> vii;

class graph
{
    int v_;
    vii adjList_;


    void dfsRecur(int index, vi &visited);

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
    adjList_[j].push_back(i);
}

void graph::dfsRecur(int index, vi &visited)
{
    visited[index] = 1;
    cout<<index;
    for(int i  =0 ; i < adjList_[index].size(); i++)
    {
        int j = adjList_[index][i];
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

void graph::bfs(int index)
{
    vi visited(v_+1, 0);
    queue<int> q;
    q.push(index);
    visited[index] = 1;
    while(!q.empty())
    {
        int element  = q.front();
        q.pop();
        cout<<element<<"\t";
        for(int i  =0; i < adjList_[element].size(); i++)
        {
            if(!visited[adjList_[element][i]])
            {
                visited[adjList_[element][i]] = 1;
                q.push(adjList_[element][i]);
            }
        }
    }
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

    g.bfs(1);

    return 0;
}

