
/*
Solution for : https://leetcode.com/problems/valid-parentheses/
*/

/*
Current solution is simple Stack based. 

TODO : Can we assign weights ( prime numbers ) to 
'(' - 2
'{' - 3
'{' - 5

and add corresponding weight in total sum when the opening brace comes and subtract the same weight when the closing brace comes. 
In the end, net sum should be zero. It solves the problem of 'presence' of matching parenthesis but it doesn't solve the problem
of right order between them. e.g ."(])[" . How can we solve the second part of this problem ? If we can solve the second part as 
well in this computation this solution will not require the O(n) space as in case of stack based solution. 
*/
bool isValid(string s) {
        std::stack<char> chk;
        const char *str = s.c_str();
        
        if (!*str)
            return true;
            while (char ch = *str++) {
            if ( ch == '(' || ch == '{' || ch == '[')
                chk.push(ch);
            else if (!chk.empty()){
                char pch = chk.top();
                switch (ch) {
                    case ')': if (pch != '(') return false; break;
                    case '}': if (pch != '{') return false; break;
                    case ']': if (pch != '[') return false; break;
                }
                chk.pop();
            } else
                return false;
        }
        return chk.empty();
    }
