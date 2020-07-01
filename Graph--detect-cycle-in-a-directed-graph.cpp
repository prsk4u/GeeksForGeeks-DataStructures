#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool cyclicUtil(int v,bool visited[],bool recStack[],vector<int> adj[]){
    if(!visited[v]){
        visited[v]=true;
        recStack[v]=true;
        vector<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++){
            if((!visited[*i])&&cyclicUtil(*i,visited,recStack,adj)) return true;
            else if(recStack[*i]) return true;
        }
    }
    recStack[v]=false;
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    bool *visited=new bool[V];
    bool *recStack=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
        recStack[i]=false;
    }
    for(int i=0;i<V;i++) if(cyclicUtil(i,visited,recStack,adj)) return true;
    return false;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
