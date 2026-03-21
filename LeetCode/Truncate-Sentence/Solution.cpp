1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    string truncateSentence(string s, int k) {
7        int count = 0;
8
9        for(int i = 0; i < s.size(); i++){
10            if(s[i] == ' ')
11                count++;
12
13            if(count == k)
14                return s.substr(0, i);
15        }
16
17        return s;
18    }
19};