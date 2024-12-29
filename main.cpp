#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph(n);
        for(int i=0; i<n-1; i++){
            graph[i].push_back(i+1);
        }
        vector<int> ans;

        for(auto& query: queries){
            int u=query[0];
            int v=query[1];
            graph[u].push_back(v);
            vector<bool> visited(n, false);
            queue<pair<int,int>> q; //node, dist
            q.push({0,0});
            visited[0]=true;
            int shortestPath=n-1;

            while(!q.empty()){
                auto[node, dist]=q.front();
                q.pop();
                if(node==n-1){
                    shortestPath=dist;
                    break;
                }
                for(int neighbor: graph[node]){
                    if(!visited[neighbor]){
                        visited[neighbor]=true;
                        q.push({neighbor, dist+1});
                    }
                }
            }
            ans.push_back(shortestPath);
        }
        return ans;
    }
};

int main(){
    return 0;
}