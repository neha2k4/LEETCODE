class Solution {
public:
    bool isItPossible(string word1, string word2) {
        
        vector<int> vect1(26,0), vect2(26,0);//mapping vectors for word1 and word2 respectively
        int count1=0,count2=0;
        
        for(int i=0;i<word1.length();i++){
            if(vect1[word1[i]-'a']++ == 0)
                count1++;
        }
        for(int i=0;i<word2.length();i++){
            if(vect2[word2[i]-'a']++ == 0)
                count2++;
        }
        
        for(int i=0;i<26;i++){
            //if value is zero means word1 does not consist that alphabet how we will swap then\U0001f937‍♂️. So continue for next iteration
            if(vect1[i] == 0)
                continue;

            for(int j=0;j<26;j++){
                if(vect2[j]==0)
                    continue;

                //swapped ith character of word1 with jth character of word2
                if(--vect1[i] == 0)
                    count1--;
                if(++vect2[i] == 1)
                    count2++;
                if(--vect2[j] == 0)
                    count2--;
                if(++vect1[j] == 1)
                    count1++;

                if(count1 == count2)
                    return true;//function returned if condition satisfied

                //swap again to get original form as the last swap was invalid.
                if(++vect2[j] == 1)
                    count2++;
                if(--vect1[j] == 0)
                    count1--;
                if(++vect1[i] == 1)
                    count1++;
                if(--vect2[i] == 0)
                    count2--;
            }
            
        }
        return false; //returned false if not condition satisfied till last iteration
    }
};