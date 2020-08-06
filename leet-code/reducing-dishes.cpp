// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfactions) {
        
        sort(satisfactions.begin(), satisfactions.end());
        
        int gain = 0, maxGain = 0;
        int pos = satisfactions.size() - 1;
        
        for (; pos >= 0; pos--) {
            gain += satisfactions[pos];
            if(gain + maxGain > maxGain) { 
                maxGain += gain;
            } else {
                break;
            };
        }

        
        return maxGain;
    }
};