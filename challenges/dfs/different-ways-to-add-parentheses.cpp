// https://leetcode.com/problems/different-ways-to-add-parentheses

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int size=input.size();
        vector<int> result;
        for(int i=0; i<size; i++){
            if(ispunct(input[i])){
                for(int a : diffWaysToCompute(input.substr(0, i)))
                    for(int b : diffWaysToCompute(input.substr(i+1))){
                        if(input[i]=='+')  result.push_back(a+b);
                        if(input[i]=='-')  result.push_back(a-b);
                        if(input[i]=='*')  result.push_back(a*b);
                    }
            }
        }
        /*** the base case is that there are no operator-char ***/
        /*** we return vector<int>{stoi(input)} when this happens ***/
        return result.size() ? result : vector<int>{stoi(input)};
    }
};