/*
Solution for : https://leetcode.com/problems/longest-common-prefix/
*/

 string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return string("");
        
        size_t pos = strs[0].length();
        
        for (size_t i = 1; i < strs.size(); i++) {
            size_t firstDiff = 0;
            const char *p = strs[i].c_str();
            const char *q = strs[i-1].c_str();
            while (*p && *q && *p++ == *q++)
                firstDiff++;
            pos = std::min(pos, firstDiff);
        }
        
        return strs[0].substr(0, pos);
    }
