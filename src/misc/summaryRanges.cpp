/*
https://leetcode.com/problems/summary-ranges/
*/
string itoa1(int val) {
	ostringstream ss;
	ss << val;
	return ss.str();
}
    vector<string> summaryRanges(vector<int>& nums) {
	vector<string> range;
	size_t count = nums.size();

	if (!count)
		range;

	string str;
	size_t rsi = 0; // range start index
	for ( size_t i = 0 ; i < count ; i++) {
		// process first element differently
		if ( i == 0) {
			str = itoa1(nums[i]);
			rsi = i;
		}
		
		if (i &&  nums[i] != nums[i-1] +1) {
			if (rsi != i-1) str = str + "->" + itoa1(nums[i-1]);
			range.push_back(str);
			str = "";
			str = itoa1(nums[i]);
			rsi = i;
		}
		
		// if we are in last element mode
		if (i == count -1) {
			if ( rsi != i) {
				str = str + "->" + itoa1(nums[i]);
			}
			range.push_back(str);
			str = "";
		}
	}
	return range;
}
