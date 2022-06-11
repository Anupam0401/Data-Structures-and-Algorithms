// You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

// You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

// Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int> products(n,0);
        sort(potions.begin(), potions.end());
        //O(nlog(n)) approach
        for(int i=0; i<n; i++){
            int low=0, high=m-1;
            while(low<=high){
                int mid=(low+high)/2;
                // if(mid<0||mid>=m)   break;
                long long x=(long long)spells[i]*potions[mid];
                if(x>=success){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            products[i]=m-low;
        }
        return products;
    }
};
