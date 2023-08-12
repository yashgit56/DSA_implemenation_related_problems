#include <bits/stdc++.h>
using namespace std ;

vector<int> visited ;
vector<vector<int>> graph ;

bool checkForCycle(int src , int parent = -1){
    queue<pair<int,int>> q ;

    visited[src] = 1 ;
    q.push({src,parent});

    while(!q.empty()){
        int node = q.front().first ;
        int par = q.front().second ;
        q.pop() ;

        for(auto i : graph[node]){
            if(!visited[i]){
                visited[i] = 1 ;
                q.push({i,node}) ;
            }
            else if(par != i ){
                return true ;
            }
        }
    }
    return false ;
}



using namespace std ;
int main() {
    int n ;
    cout << "enter number of nodes:" ;
    cin >> n ; 

    visited.assign(n+1,0) ;
    graph.resize(n+1) ;

    for(int i = 1 ; i < n ; i++){
        int u ,v ;
        cin >> u >> v ;

        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }
    bool possible = false ;
    for(int i = 1 ;i <= n ; i++){
        if(!visited[i]){
            if(checkForCycle(i))
                possible = true ;
        }
    }
    if(possible)
        cout <<"Cycle detection found" << endl ;
    else
        cout << "Cycle detection not found" << endl ;    



}