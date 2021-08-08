// https://leetcode.com/problems/count-good-meals/

// Note the traversal being done one at a time to ensure duplicates are not counted.
class Solution {
public:
    int countPairs(vector<int>& a) {
        unordered_map<int,int> lks;
        long long ans=0;
        for(int x : a){
            for(int i=1;i<=(1<<22);i*=2){
                if(lks.count(i-x)) ans+=lks[i-x];
            }
            lks[x]+=1;
        }
        return ans % (int)(1e9 + 7);
    }
};