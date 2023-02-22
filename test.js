// Given an array of integers A and an integer B.

// Find the total number of subarrays having sum equals to B.


module.exports = { 
 //param A : array of integers
 //param B : integer
 //return an integer
    solve : function(A, B){
        // use hash map to store the sum of subarray
        // if the sum of subarray equals to B, then count++
        // if the sum of subarray - B equals to a value in the hash map, then count++
        // if the sum of subarray - B equals to 0, then count++

        let count = 0;
        let sum = 0;
        let map = {};
        map[0] = 1;
        for (let i = 0; i < A.length; i++) {
            sum += A[i];
            if (map[sum - B]) {
                count += map[sum - B];
            }
            if (map[sum]) {
                map[sum]++;
            } else {
                map[sum] = 1;
            }
        }
        return count;
    }
};
