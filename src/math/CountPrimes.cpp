
/*
Solution for : https://leetcode.com/problems/count-primes/
*/

 vector<int> primes;
    
    int countPrimes(int n) {
        
        if ( n == 0 || n == 1) 
            return 0;
        else if (n == 2 || n == 3)
            return n-2;
            
        primes.push_back(2);
        primes.push_back(3);
        
        // collect primes less than sqrt(n)
        for (int i = 4 ; i < n; i++) {
            bool isPrime = true;
            int x = sqrt(i)+1;
            for (int j = 0; j < primes.size(); j++) {
                if (!(i % primes[j])) {
                    isPrime = false;
                    break;
                }else if (primes[j] > x)
                    break;
            }
            if (isPrime)
                primes.push_back(i);
        }
        return primes.size();
    }
