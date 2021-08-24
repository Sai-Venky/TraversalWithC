// https://leetcode.com/problems/k-empty-slots/

/*
    You have n bulbs in a row numbered from 1 to n. Initially, all the bulbs are turned off. We turn on exactly one bulb every day until all bulbs are on after n days.

    You are given an array bulbs of length n where bulbs[i] = x means that on the (i+1)th day, we will turn on the bulb at position x where i is 0-indexed and x is 1-indexed.

    Given an integer k, return the minimum day number such that there exists two turned on bulbs that have exactly k bulbs between them that are all turned off. If there isn't such day, return -1.
    Input: bulbs = [1,3,2], k = 1
    Output: 2
    Explanation:
        On the first day: bulbs[0] = 1, first bulb is turned on: [1,0,0]
        On the second day: bulbs[1] = 3, third bulb is turned on: [1,0,1]
        On the third day: bulbs[2] = 2, second bulb is turned on: [1,1,1]
        We return 2 because on the second day, there were two on bulbs with one off bulb between them.
*/

/*
    For example, if [j, i] is the current candidate range, 
    min is the position corresponding to the minimum blooming day d_min in the queue such that d_min < days[j], 
    then all candidate ranges [j', i'] with j < j' < min can be skipped, because the blooming day of the left boundary days[j'] will always be greater than d_min and thus cannot be valid ranges.
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for(int i=0; i<flowers.size();i++)days[flowers[i] - 1] = i + 1;
        int left = 0, right = k + 1, res = INT_MAX;
        for(int i = 0; right < days.size(); i++){
            if(days[i] < days[left] || days[i] <= days[right]){   
                if(i == right)res = min(res, max(days[left], days[right]));    //we get a valid subarray. Using max here since both slots have to be ready. 
                left = i, right = k + 1 + i;
            }
        }
        return (res == INT_MAX)?-1:res;
    }
*/

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        
        set<int> s;
        
        for(int i=0;i<bulbs.size(); i++) {
            s.insert(bulbs[i]);
            int prev=bulbs[i]-k-1;
            int next=bulbs[i]+k+1;
            if(s.count(prev)>0) {
                auto itr=s.lower_bound(prev+1);
                if(itr != s.end() && *itr==bulbs[i]) return i+1;
            }
            if(s.count(next)>0) {
                auto itr=s.lower_bound(bulbs[i]+1);
                if(itr != s.end() && *itr==next) return i+1;
            }
        }

        return -1;
    }
};