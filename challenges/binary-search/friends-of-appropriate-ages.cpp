// https://leetcode.com/problems/friends-of-appropriate-ages


/*
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int map[121] = { 0 };
        int minage = 0, ans = 0, group = 0;
        
        for (auto a : ages)
            map[a]++;
        
        for (int i = 1; i < 121; ++i)
            map[i] += map[i-1];
        
        for (int i = 15; i < 121; ++i) {
            minage = (i/2 + 7);
            group = map[i]-map[i-1];
            ans += group * (map[i] - map[minage] - 1); 
        }
        return ans;
    }
};
*/

class Solution {
public:
    unordered_map <int,int> map; // key: age, val: FriendRequestCount. 
    
    int findRequests (vector<int> & ages, int index) {
        
        if (map.find(ages[index]) != map.end()) {
            return map[ages[index]];
        }
        
        int left = 0;
        int right = index-1;
        double target = (double) (0.5*ages[index]) + 7; // find ages >= target.
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (ages[mid] <= target) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        
        map[ages[index]] = index-left;
        return index-left; // len between index-1 and left. 
    }
    
    int numFriendRequests(vector<int>& ages) {
        
        sort (ages.begin(), ages.end());
        
        int count = 0;
        
        for (int i = ages.size()-1; i >= 0 ; i--) {
            count += findRequests (ages, i);
        }
        return count;
    }
};