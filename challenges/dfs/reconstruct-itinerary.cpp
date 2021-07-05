// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
    unordered_map<string, vector<string>> graph;
    vector<string> route;
    int numTickets = 0;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		numTickets = tickets.size();
        
        if (numTickets == 0){
			return route;
		}
        
        // Construct the node and assign outgoing edges
		for (auto& eachTicket : tickets){
			graph[eachTicket[0]].push_back(eachTicket[1]);
		}
        
        // Sort vertices in the adjacency list by lexical order
        for (auto& edges : graph) {
            sort(edges.second.begin(), edges.second.end());
        }
        
        vector<string> temp;
        dfsRoute("JFK", temp);
        return route;
    }
    
    void dfsRoute(string fromAirport, vector<string>& temp) {
        temp.push_back(fromAirport);
        
        // we have used all tickets, this is a valid path return the result
        if (temp.size() == numTickets+1) {
            route = temp;
            return;
        }
        
        vector<string>& neighbors = graph[fromAirport];
        
        // at the current layer, try its neighbors in the sorted order
        for(int i =0; route.empty() &&i< neighbors.size(); i++) {
            string toAirport = neighbors[i];
            
            // remove ticket(route) from graph so that it won't be reused 
            neighbors.erase(neighbors.begin()+i);
            dfsRoute(toAirport, temp);
            // if the current path is invalid, restore the current ticket
            neighbors.insert(neighbors.begin()+i, toAirport);            
        }
        
        // remove the current vertice
        temp.pop_back();
    }
};