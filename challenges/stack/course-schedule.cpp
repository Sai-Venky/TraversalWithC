// https://leetcode.com/problems/course-schedule

bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
    
class Solution {
public:
    
    struct Node {          
        vector<int> neighbour;
        vector<bool> visited;
    };
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int prerequisitesSize = prerequisites.size();

        if(prerequisitesSize == 0 || prerequisitesSize == 1) {
            return true;
        }
        
        map<vector<int>, bool> visited;
        map<vector<int>, bool> tracked;
        stack<int> st;
        
        for(int i=0; i<prerequisitesSize; i++) {
            visited[prerequisites[i]] = false;            
            tracked[prerequisites[i]] = false;      
            st.push(prerequisites[i][0]);   
        }
        
        while(st.size()!=0) {
            int element = st.top(), i;
            
            for(i=0; i<prerequisitesSize; ++i) {

                if(element == prerequisites[i][0]) {
                    if(visited[prerequisites[i]] == true) {
                        if(tracked[prerequisites[i]] == true) {
                            continue;
                        }
                       return false;
                    } else {
                        break;
                    }         
                }
            }
            
            if(i < prerequisitesSize) {
                st.push(prerequisites[i][1]);
                visited[prerequisites[i]] = true;            
            } else {
                st.pop();
                if(st.size() != 0)  {
                    int nextElement = st.top();
                    for(i=0; i<prerequisitesSize; i++) {
                        if(nextElement == prerequisites[i][0] && element == prerequisites[i][1]) {
                            tracked[prerequisites[i]] = true;
                            break;
                        }
                    }
                }
            }
            
        }
        
        return true;
    }
};