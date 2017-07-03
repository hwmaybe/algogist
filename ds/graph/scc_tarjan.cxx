#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <cstring> 
#include <climits> 
#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

typedef vector<int> vi;
typedef vector<vi> vii;

class graph
{
    int v_;
    vii adjList_;

    vector<int> parent;
    vector<int> dfs_num;
    vector<int> dfs_low;
    vector<int> visit;
    stack<int> st;

    void dfsRecur(int index, vi &visited);

    public:
    graph(int v);
    void addEdge(int i , int j);
    void dfs(int index);
    void bfs(int index);
    void scc(int index);
    void sccutil(int index, int iter);
};

graph::graph(int v):v_(v), adjList_(v+1, vi())
{
    parent.assign(v_, 0);
    dfs_num.assign(v_, 9999);
    dfs_low.assign(v_, 9999);
    visit.assign(v_, 0);
    stack<int> st;
}

int numscc =0;
void graph::sccutil(int u, int iter)
{
    dfs_low[u] = dfs_num[u] = iter++; 
    st.push(u);
    visit[u] = 1;

    for(int j = 0; j< adjList_[u].size(); j++)
    {
        int v = adjList_[u][j];
        if(dfs_num[v] == 9999)
        {
            sccutil(v,iter);
        }
        if(visit[v])
            dfs_low[u] = std::min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u])
    {
        cout<<numscc++<<" : ";
        while(1)
        {
            int v = st.top(); st.pop(); visit[v] = 0;
            printf(" %d", v);
            if (u == v) break; 
        }
            printf("\n");
    }
}
void graph::scc(int index)
{
    int iter = 0;
    sccutil(0, iter);
}
//! add edge i---j
void graph::addEdge(int i , int j)
{
    adjList_[i].push_back(j);
    //adjList_[j].push_back(i);
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
    graph g(8);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,7);
    g.addEdge(7,6);
    g.addEdge(6,4);
    g.addEdge(3,2);
    g.addEdge(2,1);
    g.scc(0);


    return 0;
}

