// https://leetcode.com/problems/group-anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            mp[strSort(s)].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
private:
    string strSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> out;
        unordered_map<string, vector<string>> m;

        for(int i=0;i<strs.size();i++) {
            
            vector<int> helper(26, 0);
            for(char c:strs[i]) {
                helper[c-'a']++;
            }
            string out="";
            for(int j=0;j<26;j++) {
                out += to_string(helper[j]) + ' ';
            }
            m[out].push_back(strs[i]);
        }

        for(auto val:m) {
            out.push_back(val.second);
        }

        return out;
    }
};