//https://leetcode.com/problems/gas-station/

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


