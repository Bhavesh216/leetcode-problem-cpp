#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <utility>   // for pair
#include <functional> // for hash

using namespace std;

// Custom hash for unordered_map with pair<int, int> as key
struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        // Combine hashes of both integers
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int main() {
    cout << "=== Initialization ===\n";

    // Declare and initialize unordered_map and map
    unordered_map<int, string> umap = {{1, "Alice"}, {2, "Bob"}};
    map<int, string> omap = {{1, "Alice"}, {2, "Bob"}};

    cout << "\n=== Insertion ===\n";

    // Insert using insert()
    umap.insert({3, "Charlie"});
    omap.insert({3, "Charlie"});

    // Insert using emplace()
    umap.emplace(4, "David");
    omap.emplace(4, "David");

    // Insert/update using operator[]
    umap[5] = "Eve";
    omap[5] = "Eve";

    // Update existing key
    umap[2] = "Bob Updated";
    omap[2] = "Bob Updated";

    cout << "\n=== Accessing Elements ===\n";

    // Access using at()
    try {
        cout << "umap.at(3) = " << umap.at(3) << endl;
        cout << "omap.at(3) = " << omap.at(3) << endl;

        // Access missing key using at() throws exception
        cout << "umap.at(10) = " << umap.at(10) << endl; // Will throw
    }
    catch (out_of_range& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // Access using operator[]
    cout << "umap[1] = " << umap[1] << endl;
    cout << "omap[1] = " << omap[1] << endl;

    // operator[] creates default value if key not present
    cout << "umap[10] (before assignment) = " << umap[10] << endl; // inserts key 10 with empty string
    cout << "omap[10] (before assignment) = " << omap[10] << endl;

    // Safe access using find()
    if (umap.find(20) != umap.end())
        cout << "Found key 20 in umap\n";
    else
        cout << "Key 20 not found in umap\n";

    if (omap.find(20) != omap.end())
        cout << "Found key 20 in omap\n";
    else
        cout << "Key 20 not found in omap\n";

    cout << "\n=== Deletion ===\n";

    // Remove key 5
    umap.erase(5);
    omap.erase(5);

    cout << "After erase(5), umap contains:\n";
    for (auto& p : umap) cout << p.first << ": " << p.second << "\n";

    cout << "After erase(5), omap contains:\n";
    for (auto& p : omap) cout << p.first << ": " << p.second << "\n";

    // Clear both maps
    umap.clear();
    omap.clear();

    cout << "After clear(), umap size: " << umap.size() << endl;
    cout << "After clear(), omap size: " << omap.size() << endl;

    cout << "\n=== Reinserting for Iteration ===\n";
    umap = {{1, "One"}, {2, "Two"}, {3, "Three"}};
    omap = {{1, "One"}, {2, "Two"}, {3, "Three"}};

    cout << "\nRange-based for loop:\n";
    for (auto& p : umap) cout << p.first << ": " << p.second << "\n";
    for (auto& p : omap) cout << p.first << ": " << p.second << "\n";

    cout << "\nIterator loop:\n";
    for (auto it = umap.begin(); it != umap.end(); ++it)
        cout << it->first << ": " << it->second << "\n";

    for (auto it = omap.begin(); it != omap.end(); ++it)
        cout << it->first << ": " << it->second << "\n";

    cout << "\nReverse iteration in map (ordered):\n";
    for (auto rit = omap.rbegin(); rit != omap.rend(); ++rit)
        cout << rit->first << ": " << rit->second << "\n";

    cout << "\n=== Lookup & Queries ===\n";

    cout << "Check if key 2 exists:\n";
    cout << "umap.count(2) = " << umap.count(2) << "\n"; // 0 or 1
    cout << "omap.count(2) = " << omap.count(2) << "\n";

    cout << "Find key 4:\n";
    cout << (umap.find(4) == umap.end() ? "Not found" : "Found") << "\n";
    cout << (omap.find(4) == omap.end() ? "Not found" : "Found") << "\n";

    cout << "\n=== Advanced Operations ===\n";

    // Extract a node (C++17)
    umap.emplace(10, "Ten");
    omap.emplace(10, "Ten");

    cout << "Before extract, umap contains key 10: " << umap[10] << endl;
    cout << "Before extract, omap contains key 10: " << omap[10] << endl;

    // Extract key 10 node from umap and omap
    auto node1 = umap.extract(10);
    auto node2 = omap.extract(10);

    cout << "After extract, umap contains key 10? " << (umap.find(10) == umap.end() ? "No" : "Yes") << endl;
    cout << "After extract, omap contains key 10? " << (omap.find(10) == omap.end() ? "No" : "Yes") << endl;

    // Insert node back
    umap.insert(move(node1));
    omap.insert(move(node2));

    cout << "After re-insert, umap[10]: " << umap[10] << endl;
    cout << "After re-insert, omap[10]: " << omap[10] << endl;

    // Merge two maps
    unordered_map<int, string> umap2 = {{20, "Twenty"}, {30, "Thirty"}};
    map<int, string> omap2 = {{20, "Twenty"}, {30, "Thirty"}};

    cout << "\nBefore merge, umap size: " << umap.size() << endl;
    cout << "Before merge, omap size: " << omap.size() << endl;

    umap.merge(umap2);
    omap.merge(omap2);

    cout << "After merge, umap size: " << umap.size() << endl;
    cout << "After merge, omap size: " << omap.size() << endl;

    cout << "\n=== Custom hash for unordered_map with pair<int, int> keys ===\n";

    unordered_map<pair<int,int>, string, pair_hash> pair_map;

    pair_map[{1,2}] = "One-Two";
    pair_map.emplace(make_pair(3,4), "Three-Four");

    for (auto& p : pair_map) {
        cout << "(" << p.first.first << "," << p.first.second << ") : " << p.second << "\n";
    }

    return 0;
}


 unordered_map<char, int> map;
    for(int i=0;i<str.size();i++){
        map[str[i]]++;
    }

// to check size of hashmap
map.size();