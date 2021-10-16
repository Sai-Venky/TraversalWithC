// https://leetcode.com/problems/evaluate-division/

// Using floyd algorithm Note the *

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& values, vector<vector<string>>& queries) {
      
      vector<double> out;
      unordered_map<string, unordered_map<string, double>> mp;

      for(int i=0;i<eqs.size();i++) {
        mp[eqs[i][0]][eqs[i][1]] = values[i];
        mp[eqs[i][1]][eqs[i][0]] = 1/values[i];
        mp[eqs[i][0]][eqs[i][0]] = 1;
        mp[eqs[i][1]][eqs[i][1]] = 1;
      }      
      
      for(auto val3:mp) {
        for(auto val1:mp) {
          for(auto val2:mp) {
            if(mp[val1.first][val2.first] == 0 && mp[val1.first][val3.first] !=0 && mp[val3.first][val2.first] !=0) {
                mp[val1.first][val2.first] = mp[val1.first][val3.first] * mp[val3.first][val2.first];              
            }
          }
        }
      }
      for(auto q:queries) {
        out.push_back(mp[q[0]][q[1]]==0?-1:mp[q[0]][q[1]]);
      }
      
      return out;
    }
};

// DFS Solution
// Complexity is K * O(N + M) where N and M are the number of nodes and edges, and K is the number of queries. 
// How many nodes can we have? It's 2 * E, where E is the number of equations (2 different nodes per each equation). 
// We can have at most E edges in the graph.
// So total complexity is O(K * E), with O(E) additional space for the graph.

class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> children;                               // adjacency list
    
    pair<bool, double> search(string& a, string& b, unordered_set<string>& visited, double val) {
        if (visited.count(a) == 0) {
            visited.insert(a);                                                                  // mark a as visited
            for (auto p : children[a]) {
                double temp = val * p.second;                                                   // potential result
                if (p.first == b) { return make_pair(true, temp); }                             // found result
                
                auto result = search(p.first, b, visited, temp);
                if (result.first) { return result; }
            }
        }
        return make_pair(false, -1.0);
    }
    
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        
        for (int i = 0; i < equations.size(); i++) {
            children[equations[i].first].push_back(make_pair(equations[i].second, values[i]));      // build graph list a->b
            children[equations[i].second].push_back(make_pair(equations[i].first, 1.0 / values[i]));// build graph list b->a
        }
        
        for (auto p : queries) {
            unordered_set<string> visited;                                                          // to record visited nodes
            // p.first == p.second is special case
            ans.push_back(p.first == p.second && children.count(p.first) ? 1.0 : search(p.first, p.second, visited, 1.0).second);
        }
        
        return ans;
    }
};

// BFS

class Solution {
    
    double evaluate(unordered_map<string, vector<pair<string, double>>> &graph, vector<string> &query) {
        auto startNode = query[0];
        auto endNode = query[1];
        
        if (graph.find(startNode) == graph.end()) {
            return -1;
        }
        
        if (graph.find(endNode) == graph.end()) {
            return -1;
        }
        
        queue<pair<string, double>> que;
        unordered_set<string> visited;
        
        que.push({startNode, 1});
        visited.insert(startNode);
        
        while (!que.empty()) {
            auto frontItem = que.front();
            que.pop();
            
            auto currNode = frontItem.first;
            auto currValue = frontItem.second;
            
            if (currNode == endNode) {
                return currValue;
            }
            
            for (auto nodeObj: graph[currNode]) {
                auto node = nodeObj.first;
                auto weight = nodeObj.second;
                if (visited.insert(node).second) {
                    que.push({node, currValue * weight});
                }
            }
        }
        
        return -1;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            auto fromNode = equations[i][0];
            auto toNode = equations[i][1];
            double weight = values[i];
            
            graph[fromNode].push_back({toNode, weight});
            graph[toNode].push_back({fromNode, 1 / weight});
        }
        
        vector<double> answers;
        
        for (auto query: queries) {
            answers.push_back(evaluate(graph, query));
        }
        
        return answers;
    }
};

// Union Find

public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        double[] res = new double[queries.size()];
        UF uf = new UF();
        for (int i = 0; i < values.length ; ++i )
            uf.union(equations.get(i).get(0), equations.get(i).get(1), values[i]);
        for (int i = 0; i < queries.size(); ++i) {
            String x = queries.get(i).get(0), y = queries.get(i).get(1);
            res[i] = (uf.parents.containsKey(x) && uf.parents.containsKey(y) && uf.find(x) == uf.find(y)) ? uf.vals.get(x) / uf.vals.get(y) : -1.0;
        }
        return res;
    }
    
    class UF {
    	/**
         * parents: (x, root(x)), vals:(x, x/root(x)), for example, a / b = 2.0, we will have parents(a, b), vals(a, 2.0), both parents and vals have the numerator (which is 'a' here)
         * so that we can search for it and get the value a / parents(a) = vals.get(a) which is a / b = 2.0.
         */
        Map<String, String> parents;
        Map<String, Double> vals;
        UF() {
            parents = new HashMap<>();
            vals = new HashMap<>();
        }
        
        public void add(String x) {
            if (parents.containsKey(x)) return;
            parents.put(x, x);
            vals.put(x, 1.0);
        }

        /**
         * find the root
         * parents(x, p) = vals(x), x / p = vals(x), parents(p, pp) = vals(p), p / pp = vals(pp), when we are looking for the root, we are doing a path compression here
         * parents(x, pp)  = vals(x) / vals(pp) =  (x / p) * (p / pp) = vals(x) * vals(p)
         * For example, a / b = 2.0, b / c = 3.0,  parents(a, b) = 2.0,  parents(b, c) = 3.0, parents(a, c) = 2.0 * 3.0 = 6.0, now vals(a) = 6.0
         * So along the way, we get all the value of a / x where x is the parent of x all the way to root. In the end, only a / root(x) is saved. This is path compression.
         * It's like putting a directly under the root(x)
         */
        public String find(String x) {
            String p = parents.getOrDefault(x, x);
            if (x != p) {
                String pp = find(p);
                vals.put(x, vals.get(x) * vals.get(p));
                parents.put(x, pp);
            }
            return parents.getOrDefault(x, x);
        }

        /**
         * x / px = vals.get(x), y / py = vals.get(y), so px / py =  v * vals.get(y) / vals.get(x)
         */
        public void union(String x, String y, double v) {
            add(x); add(y);
            String px = find(x), py = find(y);
            parents.put(px, py);
            vals.put(px, v * vals.get(y) / vals.get(x));
        }

    }
'''