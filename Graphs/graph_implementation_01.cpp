#include <bits/stdc++.h>
using namespace std;

// BY ADJACENCY MATRIX
int main() {
    int n;
    cout<<"enter the number of nodes: ";
    cin>>n;
    
    int e;
    cout<<"enter the number of edges: ";
    cin>>e;
    
    vector<vector<int>> adj(n, vector<int>(n,0));
    
    for(int i=0; i<e; i++){
        int u,v;
        cout<<"enter connected nodes"<<endl;
        cin>>u >>v;
        //mark 1
        adj[u][v] = 1;
    }
    
    //printing
    cout<<"Your Adj matrix is: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<adj[i][j] <<" ";
        }
        cout<<endl;
    }
}
    