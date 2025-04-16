#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floyydWarshall(vector<vector<int>>&arr){
    int vertices = arr.size();
    for(int k=0;k<vertices;k++){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                if(arr[i][k] != INT_MAX && arr[k][j] != INT_MAX && arr[i][k]+arr[k][j]<arr[i][j]){
                    arr[i][j] = arr[i][k]+arr[k][j];
                }
            }
        }
    }
    return;
}
int main() {
    vector<vector<int>> graph = {
        {0,     5,     INT_MAX, 10},
        {INT_MAX, 0,     3,     INT_MAX},
        {INT_MAX, INT_MAX, 0,     1},
        {INT_MAX, INT_MAX, INT_MAX, 0}
    };

    floyydWarshall(graph);

    // Print shortest path matrix
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            if (graph[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}