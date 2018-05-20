/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting
indices of substring(s) in s that is a concatenation of each word in words exactly once and without any
intervening characters.

Example 1:
Input:
        s = "barfoothefoobarman",
        words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
 */
#include <utils.h>

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        unordered_map<string, int> word_map;
        for (auto word:words) word_map[word]++;  // word有可能重复的

        int word_size = words[0].size(), words_size = words.size();
        for (int i = 0, j; i < s.size() - word_size * words_size + 1; i++) {
            unordered_map<string, int> m;
            for (j = 0; j < words_size; j++) {
                string w = s.substr(i + j * word_size, word_size);  // 由于每个word长度都一样,所以步长一致
                if (word_map.find(w) == word_map.end() || (word_map[w] <= m[w])) // 当不存在,或者大于要的个数时退出
                    break;
                m[w]++;
            }

            if (j == words_size) res.push_back(i);
        }

        return res;
    }
};

TEST(_0030, FindSubstring) {
    Solution s;

    string case0 = "barfoothefoobarman";
    vector<string> words0 = {"foo", "bar"};
    vector<int> cres0 = {0, 9};
    vector<int> res0 = s.findSubstring(case0, words0);
    ASSERT_TRUE(Check::check(res0, cres0));

    string case1 = "barfoobarthefoobarman";
    vector<string> words1 = {"foo", "bar", "bar"};
    vector<int> cres1 = {0};
    vector<int> res1 = s.findSubstring(case1, words1);
    ASSERT_TRUE(Check::check(res1, cres1));
}