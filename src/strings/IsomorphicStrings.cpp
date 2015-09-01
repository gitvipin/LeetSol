/*
Problem : https://leetcode.com/problems/isomorphic-strings/
*/

bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        else if (s.empty() && t.empty())
            return true;
            
        const char *ss = s.c_str();
        const char *tt = t.c_str();
        
        char  tbl[256] = {0};
        char  tblR[256] = {0};
        
        int i = 0;
        while (char cs = ss[i]) {
            char ct = tt[i];
            
            if (!tbl[cs] && !tblR[ct]) {
                tbl[cs] = ct;
                tblR[ct] = cs;
            } else if (tbl[cs] && tblR[ct]) {
                if (tbl[cs] != ct || tblR[ct] != cs)
                    return false;
            } else {
                return false;
            }
            i++;
        }
        return true;
    }
