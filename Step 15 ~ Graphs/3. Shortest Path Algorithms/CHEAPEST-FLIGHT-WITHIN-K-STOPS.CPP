#include <bits/stdc++.h>
using namespace std;

// [HARD]

// we should not give priority to cost rather we should give priority to number of stops (which is clear though by reading ques only) but I tried and it failed at this case
/*
5 6
0 1 5
1 2 5
0 3 2
3 1 2
1 4 1
4 2 1
0 = src
2 = dst
2 = K

Output : 9
Desired O/p = 7
*/

// Wrong Approach
class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // Code here

        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
        }

        // apply normal djisktra's algorithm
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<int> cost(n, 1e9); // distance array for djikstra algo

        pq.push({0, {-1, src}}); // {cost , {stops, node}}
        cost[src] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currCost = it.first, stops = it.second.first, node = it.second.second;

            if (node == dst and stops <= K)
            {
                return currCost;
            }

            if (stops + 1 <= K)
            {

                for (auto it : adj[node])
                {
                    int v = it.first, wt = it.second;

                    if (currCost + wt < cost[v])
                    {
                        cost[v] = currCost + wt;
                        pq.push({cost[v], {stops + 1, v}});
                    }
                }
            }
        }

        // if we cant reach the destination then return -1 ;
        return -1;
    }
};

// Explanation: Now, if we store the elements in the priority queue with the priority given to the minimum distance first, then after a few iterations we would realize that the Algorithm will halt when the number of stops would exceed. This may result in a wrong answer as it would not allow us to explore those paths which have more cost but fewer stops than the current answer. To tackle this issue, we store the elements in terms of the minimum number of stops in the priority queue so that when the algorithm halts, we can get the minimum cost within limits.

// Correct Approach

// Also, a point to note here is that do we really need a priority queue for carrying out the algorithm? The answer for that is No because when we are storing everything in terms of a number of stops, the stops are increasing monotonically which means that the number of sops is increasing by 1 and when we pop an element out of the queue, we are always popping the element with a lesser number of stops first. Replacing the priority queue with a simple queue will let us eliminate an extra log(N) of the complexity of insertion-deletion in a priority queue which would in turn make our algorithm a lot faster.

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // Code here

        // step 1 --> we need to create an adjacency list

        vector<pair<int, int>> adj[n]; // since we have n cities

        for (auto x : flights)
        {
            int from = x[0], to = x[1], cost = x[2];
            adj[from].push_back({to, cost});
        }

        vector<int> distance(n, 1e9); // normal djikstra's algo requirement

        queue<pair<int, pair<int, int>>> q; // {stops , {node , cost}}

        q.push({0, {src, 0}});

        while (!q.empty())
        {

            auto temp = q.front();
            q.pop();

            int stops = temp.first;
            int curr = temp.second.first;
            int dist = temp.second.second;

            if (curr == dst and stops == K + 1)
            {

                return dist;
            }

            for (auto x : adj[curr])
            {

                int node = x.first, weight = x.second;

                if (dist + weight < distance[node] and stops <= K)
                {
                    distance[node] = dist + weight;
                    q.push({stops + 1, {x.first, dist + x.second}});
                }
            }
        }

        return -1;
    }
};
