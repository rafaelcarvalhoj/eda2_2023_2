#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    //N = VERTICES, M = ARESTAS
    int graph[N][M];
  
    for(int i = 0 ; i < N ; i++) 
        cin >> graph[i][i];
  
    int i, j;
    for(int k = 0 ; k < M ; k++){
        cin >> i >> j;
        graph[i][j] = 1;
    }
  
    int good = 0;
  
    for(int k = 0 ; k < N ; k++){
        i = 0;

        for(j = 0; j < N ; j++){
            cout << k << " " << j << endl;
            if(graph[k][j] && (k!=j) && graph[k][k]<graph[j][j]){ 
                i++;
                break;
            }
        }

        if(!i) good++;
    }
    
    cout << good << endl;
}
