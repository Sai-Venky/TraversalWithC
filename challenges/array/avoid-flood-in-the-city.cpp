// https://leetcode.com/problems/avoid-flood-in-the-city

/*
    Note the use of lower bound in set to calculate the dry day just after the first appearance of wet day
*/

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans; 
        int n = rains.size(); 
        unordered_map<int, int> fulllakes; 
        set<int> drydays;     
      
        for (int i=0; i<n; i++) {  
            if (rains[i] == 0) {  
                drydays.insert(i);                
                ans.push_back(1);                        
            } else { 
                int lake = rains[i]; 
                if (fulllakes.find(lake) != fulllakes.end()) { 
                    auto it = drydays.lower_bound(fulllakes[lake]);
                    if (it == drydays.end()) {                           
                        return {}; 
                    }
                    int dryday = *it; 
                    ans[dryday] = lake; 
                    drydays.erase(dryday);                           
                }
                fulllakes[lake] = i; 
                ans.push_back(-1); 
            }
        }
        return ans; 
    }
};