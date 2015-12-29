/*
Solution for : https://leetcode.com/problems/permutations/
*/

void swap(vector<int> &nums, int a, int b) {
    if ( a == b ||  nums[a] == nums[b])
	return;
    int x = nums[a];
    nums[a] = nums[b];
    nums[b] = x;
}

void permuteR(vector<int>& nums, int start, int end, vector<vector<int>> &perms) {
    if (start == end) {
	perms.push_back(nums);
	return;
    }

    for (int i = start; i <= end; i++) {
	swap(nums, start, i);
	permuteR(nums, start+1,end, perms);
	swap(nums, start, i);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> perms;
    size_t sz = nums.size();
    if (sz)
	permuteR(nums, 0, sz-1, perms);
    return perms;
}
