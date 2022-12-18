# You are given an undirected graph consisting of N vertices, numbered from 1
# to N, and M edges.
# The graph is described by two arrays, A and B, both of length M. A pair (A[K],B[K]), for K from 0 to M-1, describes an edge between vertex A[K] and vertex B[K].

# Your task is to check whether the given graph contains a path from vertex 1
# to vertex N going through all of the vertices, one by one, in increasing order
# of their numbers. All connections on the path should be direct.

# Write a function:
# def solution (N, A, B)
# that, given an integer N and two arrays A and B of M integers each, returns
# True if there exists a path from vertex 1 to N going through all vertices, one
# by one, in increasing order, or False otherwise.
# Examples:
# 1. Given N = 4, A = [1,2,4,4,3] and B = [2,3,1,3,1], the function should
# return True. There is a path (1234) using edges (1, 2), (2, 3) and (4,
# 3)

def solution(N, A, B):
    # make the graph using the entries in A and B
    graph = {}
    for i in range(len(A)):
        if A[i] in graph:
            graph[A[i]].append(B[i])
        else:
            graph[A[i]] = [B[i]]
        if B[i] in graph:
            graph[B[i]].append(A[i])
        else:
            graph[B[i]] = [A[i]]
    # if the graph is not connected, return False
    if len(graph) != N:
        return False
    # get all the paths from 1 to N
    paths = []
    def get_paths(graph, start, end, path=[]):
        path = path + [start]
        if start == end:
            paths.append(path)
        for node in graph[start]:
            if node not in path:
                get_paths(graph, node, end, path)
    get_paths(graph, 1, N)

    # check if any path is going through all the vertices one by one in increasing order
    for path in paths:
        if path == list(range(1, N+1)):
            return True
    return False


