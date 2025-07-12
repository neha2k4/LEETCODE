class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int count = 0; 
        int i = n-1;
        
        while(i>=0 && s[i] == ' ') // for skip white spaces,  it point i to last charachter of string.
        {
            i--;
        }

        while(i>=0 && s[i]!=' ') // count the length of last word
        {
            count++;
            i--;
        }
        return count;
    }
};