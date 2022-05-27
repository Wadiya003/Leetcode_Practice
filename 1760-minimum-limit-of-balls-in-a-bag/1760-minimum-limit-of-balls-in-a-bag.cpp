class Solution {
public://similar to ship container prblm
    bool check(vector<int>& nums, int maxOperations,int penalty){
        
        int cnt=0;
        for(auto n : nums){
            int x = n / penalty;//tot ops required to bring n less than penalty
			if (n % penalty == 0) x--;
			cnt += x;
        }
        
        return cnt<=maxOperations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int start = 1, end = *max_element(nums.begin(), nums.end());
		int Penalty = end;
		while (start <= end) {
			int mid = start + (end-start)/2;
			if (check(nums, maxOperations, mid)){
			Penalty = mid; 
            end = mid-1;}
			else{
				start = mid+1;}
		}

		return Penalty;
    }
};