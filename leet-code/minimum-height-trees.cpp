// https://leetcode.com/problems/minimum-height-trees

class Solution { 
public:
    
    void traverseNodesOfTree(int element, vector<bool> visited, int height, vector<int> *adj, int *maxHeight, int *end) {
        
        visited[element] = true;
        for (auto ir = adj[element].begin(); ir != adj[element].end(); ++ir)  {
            
            if(visited[*ir] != true) {
                traverseNodesOfTree(*ir, visited, height + 1, adj, maxHeight, end);
                if(height > *maxHeight) {
                    *maxHeight = height;   
                    *end = *ir;
                }
            }

        }
    }
    
    void findElements(int element, vector<bool> visited, int height, vector<int> *adj, int maxHeight, vector<int> &minHeightNodes, int end, bool *found, bool *set) {
        
        visited[element] = true;
        
       if(end == element) {
           *found = true;
           return;
       }
    
        for (auto ir = adj[element].begin(); ir != adj[element].end(); ++ir)  {
            
            if(visited[*ir] != true) {
                findElements(*ir, visited, height + 1, adj, maxHeight, minHeightNodes, end, found, set);

                if(*set == true) {
                    return;
                }
                if(*found == true) {                  

                    if(height == maxHeight/2 && maxHeight%2 == 0) {                                 
                        minHeightNodes.push_back(*ir);
                       *set = true; 
                    } else if(height == ((maxHeight/2)+1) && maxHeight%2 != 0){
                        minHeightNodes.push_back(element);                                      
                        minHeightNodes.push_back(*ir);
                        *set = true;                            
                    }
                }
 
            }
        }
    }    
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
	    vector<int> adj[n], minHeightNodes; 
        vector<bool> visited(n, false);
        int maxHeight = 0, end, start;
        bool found = false, set = false;

        for (int i=0; i<edges.size(); i++) {  
            int first = edges[i].at(0);
            int second = edges[i].at(1);
            adj[second].push_back(first);
            adj[first].push_back(second);
        }
        if(n == 1) {
            minHeightNodes.push_back(0);
            return minHeightNodes;    
        }
        traverseNodesOfTree(0, visited, 1, adj, &maxHeight, &start);
        maxHeight = 0;
        traverseNodesOfTree(start, visited, 1, adj, &maxHeight, &end);
        findElements(start, visited, 1, adj, maxHeight, minHeightNodes, end, &found, &set);

        return minHeightNodes;
    }
};