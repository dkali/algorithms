// https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/

// There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

// You want to determine if there is a valid path that exists from vertex source to vertex destination.

// Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 
// Example 1:
// Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
// Output: true
// Explanation: There are two paths from vertex 0 to vertex 2:
// - 0 → 1 → 2
// - 0 → 2

// Example 2:
// Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
// Output: false
// Explanation: There is no path from vertex 0 to vertex 5.

public class Solution
{
    public bool ValidPath(int n, int[][] edges, int start, int end)
    {
        if (start == end)
            return true;

        Dictionary<int, HashSet<int>> data = new Dictionary<int, HashSet<int>>();

        for (int ind = 0; ind < edges.Length; ind++)
        {
            AddNode(data, edges[ind][0], edges[ind][1]);
            AddNode(data, edges[ind][1], edges[ind][0]);
        }

        Queue<int> myQueue = new Queue<int>();
        myQueue.Enqueue(start);
        HashSet<int> visitedNodes = new HashSet<int>(start);

        while (myQueue.Count != 0)
        {
            int current = myQueue.Dequeue();
            foreach (int nextNode in data[current])
            {
                if (nextNode == end)
                    return true;

                if (!visitedNodes.Contains(nextNode))
                {
                    visitedNodes.Add(nextNode);
                    myQueue.Enqueue(nextNode);
                }
            }
        }

        return false;
    }

    void AddNode(Dictionary<int, HashSet<int>> data, int from, int to)
    {
        if (!data.ContainsKey(from))
            data[from] = new HashSet<int>();
        data[from].Add(to);
    }
}