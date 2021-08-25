from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prereqs: List[List[int]]) -> bool:
        adj = [ [] for _ in range(numCourses) ] # array to hold graph connections
        
        # parse given list for graph
        for item in prereqs:
            adj[item[0]].append(item[1])
            
        # parse graph array for each node's indegree
        indegree = [ 0 for _ in range(numCourses)]
        for node in adj:
            for edge in node:
                indegree[edge] += 1
        
        queue = deque()
        for i in range(numCourses):
            if (indegree[i] == 0):
                queue.append(i)
        
        visited = 0
        while(len(queue) > 0):
            node = queue.popleft()
            for n in adj[node]:
                indegree[n] -= 1
                if (indegree[n] == 0):
                    queue.append(n)
            visited += 1
            
        return (visited == numCourses)