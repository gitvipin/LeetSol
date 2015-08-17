/*
Solution for : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
*/

vector<vector<int>> levelOrderBottom(TreeNode* root) {
	std::vector<std::vector<int>> rslt;
	rslt.clear();

	if (!root)
		return rslt;

	std::vector<TreeNode*> curr, next;
	curr.push_back(root);

	while (!curr.empty()) {
		vector<int> values;
		vector<TreeNode*>::iterator iter = curr.begin();

		for (;iter != curr.end(); iter++) {
			TreeNode *node = *iter;
			values.push_back(node->val);
			if (node->left)
				next.push_back(node->left);
			if (node->right)
				next.push_back(node->right);
		} 

		rslt.insert(rslt.begin(), values);
		curr.clear();
		curr.insert(curr.begin(), next.begin(), next.end());
		next.clear();
	}

	return rslt;
}
