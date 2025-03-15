class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> f1(26, 0), f2(26, 0);
        // Build frequency arrays for word1 and word2
        for (char c : word1) {
            f1[c - 'a']++;
        }
        for (char c : word2) {
            f2[c - 'a']++;
        }
        
        // Count the number of distinct letters in each word.
        int d1 = 0, d2 = 0;
        for (int i = 0; i < 26; i++) {
            if (f1[i] > 0) d1++;
            if (f2[i] > 0) d2++;
        }
        
        // If the distinct counts are already equal,
        // check if there is a common letter.
        // Swapping a common letter with itself is a valid move.
        if (d1 == d2) {
            for (int i = 0; i < 26; i++) {
                if (f1[i] > 0 && f2[i] > 0)
                    return true;
            }
        }
        
        // Try all possible swaps of different letters.
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) continue; // Same letter swap is already handled.
                if (f1[i] > 0 && f2[j] > 0) {  
                    int x1 = d1, x2 = d2;
                    
                    // Simulate removal of letter i from word1.
                    if (f1[i] == 1) x1--;
                    // Simulate addition of letter i to word2.
                    if (f2[i] == 0) x2++;
                    
                    // Simulate addition of letter j to word1.
                    if (f1[j] == 0) x1++;
                    // Simulate removal of letter j from word2.
                    if (f2[j] == 1) x2--;
                    
                    if (x1 == x2)
                        return true;
                }
            }
        }
        return false;
    }
};