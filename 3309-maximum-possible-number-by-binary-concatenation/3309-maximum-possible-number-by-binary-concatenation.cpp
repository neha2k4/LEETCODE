class Solution {
public:
    // Num -> Binary
    string convert(int num) {
        if (num == 0) return "0";
        string binary = "";
        while (num > 0) {
            binary = (num%2 == 0 ? "0" : "1") + binary;
            num /= 2;
        }
        return binary;
    }

    // Binary -> int
    int decimal(string s){
        int res =0;
        for(int i=0; i < s.length(); i++) {
            res = res*2 + (s[i]-'0');
        }
        return res;
    }

    int maxGoodNumber(vector<int>& nums) {
        string a = convert(nums[0]);
        string b = convert(nums[1]);
        string c = convert(nums[2]);
        // Returning Max from all Permutations
        return max({
            decimal(a+b+c),
            decimal(a+c+b),
            decimal(b+a+c),
            decimal(b+c+a),
            decimal(c+a+b),
            decimal(c+b+a)
        });
    }
};

static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();