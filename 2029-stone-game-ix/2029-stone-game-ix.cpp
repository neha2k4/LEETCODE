class Solution {
public:
    bool stoneGameIX(vector<int>& s) {
        int cnt_rem_0,cnt_rem_1,cnt_rem_2;
        cnt_rem_1=cnt_rem_0=cnt_rem_2=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]%3==0)cnt_rem_0++;
            else if(s[i]%3==1)cnt_rem_1++;
            else cnt_rem_2++;
        }
        if(cnt_rem_1==0 && cnt_rem_2==0){
            return false;
        }
        else{
            int max_rem_cnt,min_rem_cnt;
            int ans=0;
            max_rem_cnt=max(cnt_rem_1,cnt_rem_2);
            min_rem_cnt=min(cnt_rem_1,cnt_rem_2);
            
            if(max_rem_cnt==1){
              ans= cnt_rem_0+1;
                if(ans%2==0 || (ans%2==1 && ans==n))return false;
                else return true;
            }
            else{
                if(min_rem_cnt>=2 && (min_rem_cnt+ min_rem_cnt-1 +cnt_rem_0)%2==1){
                    return true;
                }
                else if(min_rem_cnt==1 && (min_rem_cnt+cnt_rem_0)%2==1 && min_rem_cnt+cnt_rem_0!= n)return true;
                else{
                    if(max_rem_cnt==min_rem_cnt){
                        if( (max_rem_cnt+min_rem_cnt-1+cnt_rem_0)%2==1)return true;
                        else return false;
                    }
                    else if(max_rem_cnt-min_rem_cnt==1){
                        if((max_rem_cnt+min_rem_cnt+cnt_rem_0)%2==1 && (max_rem_cnt+min_rem_cnt+cnt_rem_0)!=n)return true;
                        else return false;
                    }
                    else{
                        if((2*min_rem_cnt +2 +cnt_rem_0)%2==1 && (2*min_rem_cnt+2+cnt_rem_0)!=n)return true;
                        else return false;
                    }
                }
                    
                }
            }
        return true;
    }
};