/*
Solution for : Best time to buy and sell stock.
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/


/*
The solution is simple Greedy programming based. Essentially it is
just trying to sum up increasing price sequences on stock graph.
That is if you plot the prices on graph and see only +ve slope (which
signifies the gain on stock prices), the solution below just sums up the
gains obtained on positive slopes.
*/
int maxProfit(vector<int>& prices) {
        size_t count = prices.size();
        if (count <= 1)
            return 0;
            
        int gain = prices[1] - prices[0];
        if (count == 2)
            return (gain > 0) ? gain : 0;
            
        int min = prices[0];
        gain = 0;
        /*
        for (size_t i = 1; i < count;) {
            int curr = prices[i++];
            if (curr >= prices[i-2]) { // increasing sequence 
                if (i == count || prices[i] < curr)
                    gain += curr - min;
            } else 
                min = curr;
        }
        */
        // Above for loop does the same thing but the following one is running faster on LeetCode servers
        // Perhaps optimization can happen better if [i-2] indices is not required to be accessed.
        for (size_t i = 1; i < count;i++) {
            int curr = prices[i];
            if (curr >= prices[i-1]) { // increasing sequence 
                if (i+1 == count || prices[i+1] < curr)
                    gain += curr - min;
            } else 
                min = curr;
        }
        return gain;
    }

/*
This is not the solution to original problem. But it is the solution to the same problem 
if it were modified slightly to allow only single transaction.

It is interesting to note that how the slight modification to problem changes the approach
for solution from Greedy Programming to Dynamic Programming.
*/
int SingleTrnxn(vector<int>& prices) {
        size_t count = prices.size();
        if (count <= 1)
            return 0;
        
        int min, gain;
        min = prices[0];
        gain = 0;
        for (size_t i = 1; i < count; i++) {
            int cost = prices[i];
            if (cost > min)
                gain = std::max(gain, cost - min);
            min = std::min(min, cost);
        }
        return gain;
    }


