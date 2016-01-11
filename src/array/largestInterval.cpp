
/*

Solution for : 

Given an array of integers. Return the size of largest interval of increasing sequence of integers.
*/


int func(vector < int > scores) {
    size_t sz = scores.size();

    if (!sz)
	return 0;
    int lrun = 1;
    int crun = 1;
    for (size_t i = 1 ; i < sz ; i++) {
	if (scores[i] > scores[i-1]) {
	    crun++;
	} else {
	    if (crun > lrun)
		lrun = crun;
	    crun = 1;
	}
    }
    if (crun > lrun)
	lrun = crun;
    std::cout << lrun << endl;
    return lrun;
}
