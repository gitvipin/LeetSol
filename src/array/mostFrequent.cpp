/*

Solution for : 

Given an array of integers, return the most frequent item. If there is a tie, return the element occurring first.
*/

int func(vector < int > items) {
    
    size_t sz = items.size();
    std::map <int, int> tbl;   
    
    for (size_t i = 0; i < sz ; i++) {
        tbl[items[i]]++;
    }
    int count = 0;
    int num;

    for (size_t i = 0; i < sz ; i++) {
        if (tbl[items[i]] > count) {
            num = items[i];
	    count = tbl[items[i]];
        }
    }
    std::cout << num << endl;
    return num;
}
