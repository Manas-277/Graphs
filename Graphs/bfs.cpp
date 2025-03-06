#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int> > adjList;
    void addEdge(int u, int v, bool direction){
        //direction -> 0 ( undirected graph)
        //direction -> 1 (directed graph)
        adjList[u].push_back(v); // create an edge from u to v
        if(!direction) adjList[v].push_back(u); // creat ean edge from v to u
    }

    void printAdjList(){
        for(auto i:adjList){
            cout<<i.first<<" -> ";
            for(auto neighbour : i.second){
                cout<<neighbour<<" ";
            }
            cout<<endl;
        }
    }

    void bfs(int src, unordered_map<int , bool>&visited){
        queue<int> q;
        q.push(src);
        visited[src] = 1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<" ";

            for(auto neighbour : adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                }
            }
        }
    }

};


int main() {
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);

    cout<<"Adjacency list is :"<<endl;
    g.printAdjList();

    // g.bfs(0);
    unordered_map<int, bool> visited;
    for(int i=0; i<=7; i++){
        if(!visited[i]){
            g.bfs(i,visited);
        }
    }
    return 0;
}
    