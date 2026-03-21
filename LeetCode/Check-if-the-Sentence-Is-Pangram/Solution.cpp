1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    bool checkIfPangram(string sentence) {
7        vector<bool> seen(26, false);
8
9        for(char c : sentence)
10            seen[c - 'a'] = true;
11
12        for(bool b : seen)
13            if(!b) return false;
14
15        return true;
16    }
17};