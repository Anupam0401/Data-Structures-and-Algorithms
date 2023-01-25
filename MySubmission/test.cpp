public class Solution {
    public int gcd(int A, int B) {
        if (A == 0)
            return B;
        return gcd(B % A, A);
    }
    public ArrayList < Integer > solve(ArrayList < Integer > A) {
        ArrayList < Integer > ans = new ArrayList < Integer > ();
        Collections.sort(A, Collections.reverseOrder());
        HashMap < Integer, Integer > mp = new HashMap < Integer, Integer > ();
        // mp stores the count of A[i]'s that are to be deleted from the array
        for (int i = 0; i < A.size(); i++) {
            int x = A.get(i);
            if (mp.containsKey(x) && mp.get(x) > 0)
                mp.put(x, mp.get(x) - 1);
            else {
                for (int j = 0; j < ans.size(); j++) {
                    int g = gcd(ans.get(j), x);

                    if (mp.containsKey(g))
                        mp.put(g, mp.get(g) + 2);
                    else
                        mp.put(g, 2);
                        
                    // we are adding 2 to the mp as there will 2 pairs gcd(ans[j],A[i]) and gcd(A[i],ans[j])
                }
                ans.add(x);
            }
        }
        return ans;
    }
}
