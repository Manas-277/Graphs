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

    bool checkCyclicUsingDfs(int src, unordered_map<int, bool>&visited, unordered_map<int, int>&parent){
        visited[src] = 1;

        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                parent[nbr] = src;
                if(checkCyclicUsingDfs(nbr, visited, parent)) return true;
            }
            else if(visited[nbr] && parent[src] != nbr) return true;
        }
        return false;
    }

};


int main() {
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,1,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);
    int n = 7;
    cout<<"Adjacency list is :"<<endl;
    g.printAdjList();

    // g.bfs(0);
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    bool ans = false;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            parent[i] = -1;
            ans = g.checkCyclicUsingDfs(i,visited, parent);
            if(ans == true) break;
        }
    }
    if(ans) cout<<"cycle is present"<<endl;
    else cout<<"cycle is not present"<<endl;
    return 0;
}
    