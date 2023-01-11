// We have a list A of points (x, y) on the plane. Find the B closest points to the origin (0, 0).

 

// Here, the distance between two points on a plane is the Euclidean distance.

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.)

// NOTE: Euclidean distance between two points P1(x1, y1) and P2(x2, y2) is sqrt( (x1-x2)2 + (y1-y2)2 ).

class Solution {
    public List<List<int>> solve(List<List<int>> A, int B) {
        int[] dist = new int[A.Count];
        for(int i=0; i<A.Count; i++){
            dist[i] = A[i][0]*A[i][0] + A[i][1]*A[i][1];
        }
        Array.Sort(dist);
        int limit = dist[B-1];
        List<List<int>> ans = new List<List<int>>();
        for(int i=0; i<A.Count; i++){
            int d = A[i][0]*A[i][0] + A[i][1]*A[i][1];
            if(d <= limit){
                ans.Add(A[i]);
            }
        }
        return ans;
    }
}