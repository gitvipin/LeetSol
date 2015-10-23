/*
Solution for : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

/*
This solution is based on DFS traversal of tree. 
Here, for any given node, a connection between children left->next = right is 
established. At the same time, the 'peripheral' connection between the child
sub trees is also established by traversing the whole depth of tree for the 
periphery. 

NOTE : This implementation is quite poor in runtime. Perhaps, because, pointers are
being accessed quite unevenly. i.e. Same pointers are being accessed/processed multiple
times so it will give poor cache performance.
*/
void connect(TreeLinkNode *root) {
        if (!root)
            return;
        TreeLinkNode *cl = root->left;
        TreeLinkNode *cr = root->right;
        while (cl && cr) {
            cl->next = cr;
            cl = cl->right;
            cr = cr->left;
        }
        connect(root->left);
        connect(root->right);
        
    }
    
/*
This solution is based on BFS traversal of tree. It basically simply collects all the node
at same level in the order left to right and makes connection between them through next
pointers. While making the next connection at one level it also collects the child pointers
at the next level in the same order.
*/
    void connect1(TreeLinkNode *root) {
        if (!root)
            return;
        else if (!root->left && !root->right) {
            root->next = NULL;
            return;
        }
            
        std::list<TreeLinkNode*> queue;
        queue.push_back(root);
        
        while(!queue.empty()) {
            std::list<TreeLinkNode*> level;
            std::list<TreeLinkNode*>::iterator iter;
            for (iter = queue.begin(); iter != queue.end();) {
                TreeLinkNode *curr = *iter++;
                curr->next = (iter == queue.end()) ? NULL : *iter;
                if (curr->left)
                    level.push_back(curr->left);
                if (curr->right)
                    level.push_back(curr->right);
            }
            queue.clear();
            queue.insert(queue.begin(), level.begin(), level.end());
        }
    }
