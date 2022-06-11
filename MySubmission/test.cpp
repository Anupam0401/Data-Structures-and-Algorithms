// Given a string find all the substrings of the given string
// check if the substrings have capital letters more than small letters

class Solution
{
    public:
    //Function to return the sorted array.
    bool isGood(string s){
        //count the number of uppercase letter
        int uppercase = 0;
        //count the number of lowercase letter
        int lowercase = 0;
        for(int i=0; i<s.length(); i++){
            if(isupper(s[i])) uppercase++;
            else lowercase++;
        }
        return uppercase>lowercase;
    }
    int numberOf(string str){
        //find all the substrings of the given string
        int n = str.length();
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                string sub = str.substr(i,j-i+1);
                //check if the substrings have capital letters more than small letters
                if(isGood(sub)) count++;
            }
        }
        return count;
    }
};