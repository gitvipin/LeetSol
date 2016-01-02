/*
Solution for : https://leetcode.com/problems/gas-station/
*/


/*
Compute the net gain of gas at every station. Net gain is amount of gas you receive at this station - amount of gas you need for moving
to next station. 

1) To complete the circle, you need to have sum of all these next gains to be positive. If this sum is negative, there is no solution.

HELP: http://stackoverflow.com/questions/2286849/algorithm-for-truck-moving-around-a-circle-of-gas-stations
2) You pick the station next to the station which has the smallest Sum of net positive ( net gain ).
*/

/*
POOR: Following solution is poor one and exhaustive one. It is O(n*2) . It is checking condition (1) as an early check and then trying
to find from possible stations if a circle is possible (extremely poor).

*/
int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    unsigned count = gas.size();
    if (count != cost.size())
        return -1;
    else if (count == 1) {
        if (gas[0] >= cost[0])
            return 0;
        else
            return -1;
    }
    std::vector<int> adv;
    // find the max gain starting point.
    int max = gas[0] - cost[0];
    adv.push_back(max);
    unsigned x = 0;
    for (unsigned  i = 1 ; i < count; i++) {
        int net = gas[i] - cost[i];
        if (net > max) {
            x = i;
            max = net;
        }
        adv.push_back(net);
    }

    // no station gives +ve advantage.
    if (max < 0)
        return -1;

    // Identify complete iteration by i = count
    for (unsigned k = 0; k < count ; k++) {
        if (adv[k] < 0)
            continue;
        int net = 0;
        x = k;
        unsigned int i  =0;
        for (; i < count; i++) {
            net += adv[x];
            if (net < 0) {// couldn't finish
                if ( k < x) k = x;
                break;
            }
            x = (x+1) %count;
        }
        if (i == count && net >= 0)
            return x;
    }

    return -1;
}


