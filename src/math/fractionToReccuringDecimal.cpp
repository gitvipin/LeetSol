/*
Solution for : https://leetcode.com/problems/fraction-to-recurring-decimal/
*/


#define int long int
void normalize(bool &neg, int &n, int &d) {
    neg = false;
    if ( n < 0 || d <0) {
	neg = (n * d < 0) ? true :false;
	if (n <0)
	    n *= -1;
	if (d<0)
	    d *= -1;
    }
}

string fractionToDecimal(int numerator, int denominator) {
    bool isNeg;
    stringstream ans, frac;        

    normalize(isNeg, numerator, denominator);        
    if (isNeg)
	ans << "-";

    int dec = numerator / denominator;
    int rem = numerator % denominator;

    ans << dec;

    if (!rem)
	return ans.str();

    std::map<int, int> remTbl;        
    bool recurr = false;
    int  pos = 0;	

    while (rem) {
	rem = rem*10;

	// check if recurring
	if (remTbl.find(rem) != remTbl.end()) {
	    recurr = true;
	    break;
	} else {
	    frac << rem / denominator;
	    remTbl[rem] = pos++;
	}            
	rem = rem % denominator;            
    }

    string str = frac.str();
    ans << ".";
    if (recurr) {	    
	str.insert(remTbl[rem], 1, '(');
	str += ")";
    }

    ans << str;
    return string(ans.str());
}
