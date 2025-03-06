#include <bits/stdc++.h>
using namespace std;
template<typename T>

class Graph{
    public:
    unordered_map<T, list<int> > adjList;
    void addEdge(T u, T v, bool direction){
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

    // for weighted graph
    // public:
    // unordered_map<int, list<pair<int, int> >> adjList;
    // void addEdge(int u, int v,int w, bool directed){
    //     // make an edge from source to destinatiomn
    //     adjList[u].push_back({v, w});
    //     if(!directed) adjList[v].push_back({u,w});
    // }
    
    // void printAdjList(){
    //     for(auto node: adjList){
    //         cout<<"Node "<< node.first<<" is connected to ";
    //         for(auto neighbour : node.second){
    //             cout<<"{ "<<neighbour.first<<" "<<neighbour.second<<" }  ";
    //         }
    //         cout<<endl;
    //     }
    // }

};


int main() {
    // int n;
    // cout<<"enter the number of nodes: ";
    // cin>>n;
    
    // int e;
    // cout<<"enter the number of edges: ";
    // cin>>e;
    
    // undirected graph
    Graph<char> g;
    g.addEdge('0','1',1);
    g.addEdge('1','2',1);
    g.addEdge('0','2',0);

    cout<<"Adjacency list is :"<<endl;
    g.printAdjList();

    // //for weighted 
    // Graph g;
    // g.addEdge(1,2,4,0);
    // g.addEdge(1,4,5,0);
    // g.addEdge(1,3,2,0);
    // g.addEdge(3,4,1,1);
    // g.addEdge(4,5,4,0);
    // g.addEdge(2,4,1,1);
    // g.addEdge(2,5,2,0);
    
    // cout<<"Printing your adj list"<<endl;
    // g.printAdjList();
    return 0;
}
    