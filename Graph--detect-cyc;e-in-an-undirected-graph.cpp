#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
bool cyclicUtil(int v,bool visited[],vector<int> adj[],int parent){
    visited[v]=true;
    vector<int>::iterator i;
    for(i=adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]) {
            if(cyclicUtil(*i,visited,adj,v)) 
                return true;
        }
        else if(*i!=parent) return true;
    }
    return false;
}

bool isCyclic( vector<int> adj[],int V)
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++) visited[i]=false;
    for(int i=0;i<V;i++) 
        if(!visited[i]) 
            if(cyclicUtil(i,visited,adj,-1)) 
                return true;
    return false;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
