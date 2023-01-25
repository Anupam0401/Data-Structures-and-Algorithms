// Given an array A of N integers.

// Find the count of the subarrays in the array which sums to zero. Since the answer can be very large, return the remainder on dividing the result with 109+7

public class Solution {
    public int solve(int[] A) {
        int n=A.length;
        //pf array
        long [] pf=new long[n];
        pf[0]=A[0];
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+A[i];
        }
        
        //int sum=pf[0];
        double count=0;
        HashMap<Long, Integer> map = new HashMap<>();
        for(int i=0;i<n;i++){
        
        if (map.containsKey(pf[i])) {
            map.put(pf[i],map.get(pf[i])+1);
        }
        else
            map.put(pf[i],1);
        
        
        if(pf[i]==0)
        count++;
        }

        //if pf array elements are repeating thn there exist an subarray with sum=0
       // or pf[i]==0 thn there exist an subarray with sum=0

       // int count=0;
        // Getting an iterator
        Iterator hmIterator = map.entrySet().iterator();

        // Iterating through Hashmap and
        
        while (hmIterator.hasNext()) {
            Map.Entry mapElement = (Map.Entry)hmIterator.next();
            int val = ((int)mapElement.getValue());
            count+=((val*(val-1))/2);
        }

       return (int) count % 1000000007;

 
    }
}