/*
------------------------------------------------------------------------
https://leetcode.com/problems/valid-anagram/
------------------------------------------------------------------------
*/
bool isAnagram(string s, string t) {
    if (s.empty() && t.empty())
        return true;

    size_t sl = s.length();
    size_t tl = t.length();

    if (sl != tl)
        return false;

    std::map<char, int> smap, tmap;

    for (size_t i = 0; i < sl; i++) {
        char ch = s[i];
        if (smap.find(ch) == smap.end())
            smap[ch] = 1;
        else
            smap[ch]++;
    }

    for (size_t i = 0; i < tl; i++) {
        char ch = t[i];
        if (tmap.find(ch) == tmap.end())
            tmap[ch] = 1;
        else
            tmap[ch]++;
    }

    map<char, int>::iterator siter , titer;
    siter = smap.begin();
    titer = tmap.begin();

    for (; siter != smap.end() && titer != tmap.end();) {
        if (siter->first != titer->first)
            return true;
        if (siter->second != titer->second)
            return false;
        siter++;
        titer++;
    }

    if (siter == smap.end() &&  titer == tmap.end())
        return true;
    else
        return false;
}




