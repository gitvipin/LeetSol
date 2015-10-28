/*
Solution for : https://leetcode.com/problems/unique-binary-search-trees/
*/

// Solution using Dynamic Programming with Memoization
int numTreesR(int n, std::unordered_map<int, int> &soln) {
        if (n <=1)
            return 1;
        else if (soln.find(n) == soln.end()) {
            int sum = 0;
            for (int i = 1; i <= n; i++) {
                sum += numTreesR(i-1, soln) * numTreesR(n-i, soln);
            }
            soln[n] = sum;
        }
        return soln[n];
    }
    
    int numTrees(int n) {
        std::unordered_map<int, int> soln;
        return numTreesR(n,soln);
    }

#if 0
// Solution using Recursion. This one is runtime intensive like the Fibonacci series using recursion
int numTrees(int n) {
        if (n <=1)
            return 1;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += numTrees(i-1) * numTrees(n-i);
        }
        return sum;
    }
#endif
