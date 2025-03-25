

class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    int subarrayGCD(vector<int> &nums, int k)
    {
        int count = 0, i = 0, curr_gcd;
		// consider every element as a starting point 
        for (int i = 0; i < nums.size(); i++)
        {
			// since gcd of nums[i] is nums[i] itself we initialize curr_gcd with 0 
            curr_gcd = 0;
			// from the given point try all the subarrays 
            for (int j = i; j < nums.size(); j++)
            {
				// keep updating the curr_gcd
                curr_gcd = gcd(curr_gcd, nums[j]);
				// if equal to k increment
                count += (curr_gcd == k);
            }
        }
        return count;
    }
};