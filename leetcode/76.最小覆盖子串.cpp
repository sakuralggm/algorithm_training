/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> ms, mt;
        for (auto i : t) {
            mt[i]++;
        }
        bool found = false;
        int l = 0, mins = 2e9;
        string ans;
        for (int i = 0; i < s.size(); i++) {
            ms[s[i]]++;
            if (found == false) {
                bool cur = true;
                for (auto i : t) {
                    if (ms[i] < mt[i]) {
                        cur = false;
                        break;
                    }
                }
                if (cur == true) {
                    found = true;
                }
            }
            if (found) {
                while (!mt[s[l]] || ms[s[l]] - 1 >= mt[s[l]]) {
                    ms[s[l]]--;
                    l++;
                }
                if (i - l + 1 < mins) {
                    mins = i - l + 1;
                    ans = s.substr(l, i - l + 1);
                }
            }
        }
        if (found == false) {
            return string();
        } else {
            return ans;
        }
    }
};
// @lc code=end
