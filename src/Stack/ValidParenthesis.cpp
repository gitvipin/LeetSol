
/*
Solution for : https://leetcode.com/problems/valid-parentheses/
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
