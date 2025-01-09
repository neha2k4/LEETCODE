class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
    // initialize the prefix count `prefixCount` to 0
    int prefixCount = 0;

    // iterate through each word in the 'words' array
    for (string word : words) {
        // check if the current word is a prefix of 's'
        if (s.substr(0, word.size()) == word) {
            prefixCount++;
        }
    }

    // return the total count of prefixes
    return prefixCount;
}
};