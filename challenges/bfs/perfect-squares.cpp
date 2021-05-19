// https://leetcode.com/problems/perfect-squares

/*
    Important to note that all possible initial values are pushed first. 
    Based on that next state is calculated and so on. 
    Restriction also is done based on this
*/

class Solution {
public:
    int numSquares(int n) {
        
        unordered_set<int>  visited;
        queue<int>          q;
        vector<int>         vec; 
        int                 step = 1;
        
        for(int i = 1; i*i <= n; i++ )
        {
            if( i*i == n) return step;
            q.push(i*i);
            visited.insert(i*i); 
            vec.push_back(i*i);
        }                
           
        while( !q.empty() )
        {
            step += 1;
            int size = q.size();
            for (int i = 0 ; i < size; i++) 
            {            
                int num = q.front();                 
                for (auto key : vec) 
                { 
                    int sum = num + key;
                    if( sum == n) return step;
                    if( sum < n && !visited.count(sum) )
                    {                        
                        q.push(sum);
                        visited.insert(sum);                         
                    }
                } 
                q.pop();
            }
        }
        return -1;        
    }
};