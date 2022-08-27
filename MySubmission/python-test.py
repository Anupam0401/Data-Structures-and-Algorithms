
def maxSubArraySum(a,size):
    # print(a)
    max_so_far = -10**6
    max_ending_here = 0
      
    for i in range(0, size):
        max_ending_here = max_ending_here + a[i]
        if (max_so_far < max_ending_here):
            max_so_far = max_ending_here
 
        if max_ending_here < 0:
            max_ending_here = 0  
    return max_so_far

n = int(input())
k = int(input())
# assign minimum value to ans
ans =  -10**6
# take input arr of size n
arr = list(map(int, input().split()))
# loop through arr and take maximum sum leaving a sliding window of size k
start = 1
end = k
while end <= n-2:
    leftSum  = maxSubArraySum(arr[0:start], start)
    # leftSum = 0
    rightSum = maxSubArraySum(arr[end+1:],n-end-1)
    # rightSum = 0
    ans = max(ans,leftSum + rightSum)
    # ans = max(ans, maxSubArraySum(arr[start-1:end], k))
    start += 1
    end += 1
    
print(ans)