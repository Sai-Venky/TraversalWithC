// https://leetcode.com/problems/design-movie-rental-system

// Note the use of map and set here and thinking of the design. A good LLD question
// Also see the use of set<array> part to solve sorting instead of set<pair<int, pair<int, int>>> or set<tuple<int, int, int>> rented; 
// https://www.geeksforgeeks.org/priority-queue-of-vectors-in-c-stl-with-examples/?ref=rp

class MovieRentingSystem {
    public:
        unordered_map<int, unordered_map<int, int>> prices; // [shop][movie] : price
        unordered_map<int, set<pair<int, int>>> dropped; // [movie] : {price, shop}
        set<array<int, 3>> rented; // {price, shop, movie}

        MovieRentingSystem(int n, vector<vector<int>>& entries) {
            for (auto &e : entries) {
                dropped[e[1]].insert({e[2], e[0]});
                prices[e[0]][e[1]] = e[2];
            }
        }
        vector<int> search(int movie) {
            vector<int> res;
                for (auto &[price, shop] : dropped[movie]) {
                    res.push_back(shop);
                    if (res.size() == 5)
                        break;
                }
            return res;
        }
        void rent(int shop, int movie) {
            int price = prices[shop][movie];
            dropped[movie].erase(dropped[movie].find({price, shop}));
            rented.insert({price, shop, movie});
        }
        void drop(int shop, int movie) {
            int price = prices[shop][movie];
            rented.erase(rented.find({price, shop, movie}));
            dropped[movie].insert({price, shop});
        }
        vector<vector<int>> report() {
            vector<vector<int>> res;
            for (auto &[price, shop, movie] : rented) {
                res.push_back({shop, movie});
                if (res.size() == 5)
                    break;
            }
            return res;
        }
};