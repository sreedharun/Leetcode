class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<int> se(s.begin(),s.end());
        return se.size();
    }
};