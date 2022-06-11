// A password is said to be strong if it satisfies all the following criteria:

// It has at least 8 characters.
// It contains at least one lowercase letter.
// It contains at least one uppercase letter.
// It contains at least one digit.
// It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
// It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
// Given a string password, return true if it is a strong password. Otherwise, return false.

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.length();
        if(n<8) return false;
        int countUpper = 0,countLower=0,countDigit=0,countSpecial=0;
        for(int i=0;i<n;i++){
            if(isupper(password[i])) countUpper++;
            else if(islower(password[i])) countLower++;
            else if(isdigit(password[i])) countDigit++;
            else countSpecial++;
        }
        // check if the string contains the same characters in adjacent positions
        for(int i=0;i<n-1;i++){
            if(password[i]==password[i+1]){
                return fasle;
            }
        }
        if(countUpper>=1&&countLower>=1&&countDigit>=1&&countSpecial>=1)    return true;
        else return false;
    }
};