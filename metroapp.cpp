#include<iostream>
#include <vector>
#include<string>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

void dijkstra(vector<vector<string>> &edge, int vertices, int edges, string source, unordered_map<string,pair<int,string>>& ans) {

    unordered_map<string, list<pair<string, int>>> mp;
    for (int i = 0; i < edges; i++) {
        int w = stoi(edge[i][2]);
        mp[edge[i][0]].push_back({edge[i][1],w});
        mp[edge[i][1]].push_back({edge[i][0],w});
    }
  
    set<pair<int,string>> s;
    s.insert({0, source});
    ans[source] = {0,""};

    while (!s.empty()) {
        auto topElement = *(s.begin());
        int dist = topElement.first;
        string ele = topElement.second;
        s.erase(s.begin()); // Remove the processed node from the set

        for (auto i : mp[ele]) {
            if (ans.find(i.first) == ans.end() || ans[i.first].first > dist + i.second) {
                auto it = s.find({ans[i.first].first, i.first});
                if (it != s.end()) {
                    s.erase(it);
                }
                ans[i.first] = {(dist + i.second), ele};
                s.insert({dist + i.second, i.first});
            }
        }
    }

}

int main() {
    vector<vector<string>> metroData;

    metroData.push_back({"Noida Sector 62~B", "Botanical Garden~B", "8"});
    metroData.push_back({"Botanical Garden~B", "Yamuna Bank~B", "10"});
    metroData.push_back({"Yamuna Bank~B", "Vaishali~B", "8"});
    metroData.push_back({"Yamuna Bank~B", "Rajiv Chowk~BY", "6"});
    metroData.push_back({"Rajiv Chowk~BY", "Moti Nagar~B", "9"});
    metroData.push_back({"Moti Nagar~B", "Janak Puri West~BO", "7"});
    metroData.push_back({"Janak Puri West~BO", "Dwarka Sector 21~B", "6"});
    metroData.push_back({"Huda City Center~Y", "Saket~Y", "15"});
    metroData.push_back({"Saket~Y", "AIIMS~Y", "6"});
    metroData.push_back({"AIIMS~Y", "Rajiv Chowk~BY", "7"});
    metroData.push_back({"Rajiv Chowk~BY", "New Delhi~YO", "1"});
    metroData.push_back({"New Delhi~YO", "Chandni Chowk~Y", "2"});
    metroData.push_back({"Chandni Chowk~Y", "Vishwavidyalaya~Y", "5"});
    metroData.push_back({"New Delhi~YO", "Shivaji Stadium~O", "2"});
    metroData.push_back({"Shivaji Stadium~O", "DDS Campus~O", "7"});
    metroData.push_back({"DDS Campus~O", "IGI Airport~O", "8"});
    metroData.push_back({"Moti Nagar~B", "Rajouri Garden~BP", "2"});
    metroData.push_back({"Punjabi Bagh West~P", "Rajouri Garden~BP", "2"});
    metroData.push_back({"Punjabi Bagh West~P", "Netaji Subhash Place~PR", "3"});
   
    unordered_map<string,pair<int,string>> ans;
    string source = "Noida Sector 62~B";
    string destination = "Vaishali~B";
    dijkstra(metroData, 4, 5, source, ans);
    cout << "Distance to " << destination << ": " << ans[destination].first << endl;
    cout << "Previous station on the shortest path: " << ans[destination].second << endl;
    cout << "Order of stations:" << endl;

    vector<string> path;
    string curr = destination;
    while (curr != source) {
        path.push_back(curr);
        curr = ans[curr].second;
    }
    path.push_back(source);
    
    for (auto i=path.size()-1;i>0;--i) {
           cout<<path[i];
           if(i>0)
            cout << " -> ";
    }
    cout<<destination;
    
    return 0;
}
