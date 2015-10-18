/*
Solution for : https://leetcode.com/problems/spiral-matrix/
*/


vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> soln;
	int rf, rl, cf, cl, x;

	// initialization
	soln.clear();
	rf = cf = 0;
	rl = matrix.size();
	if (!rl)
		return soln;
	else
		rl--;
	cl = matrix[0].size()-1;

	//iteration and solution build up
	while (rf <= rl && cf <= cl) {
		x = cf;     while (x <= cl) soln.push_back(matrix[rf][x++]);
		x = rf +1;  while (x <= rl) soln.push_back(matrix[x++][cl]);
		x = cl -1;  if (rl != rf) while (x >= cf) soln.push_back(matrix[rl][x--]);
		x = rl -1;  if (cf != cl) while (x >= rf + 1) soln.push_back(matrix[x--][cf]);

		rf++; cf++; rl--; cl--;
	}

	return soln;
    }
