class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs){
            return lhs.front() < rhs.front();
        });

        std::vector<std::vector<int>> res;
        res.push_back({intervals.front().front(),intervals.front().back()});
        for(const auto& interval : intervals){
            if(interval.front() <= res.back().back()){
                res.back().back() = std::max(interval.back(), res.back().back());
            }else{
                res.push_back({interval.front(),interval.back()});
            }
        }

        return res;
    }
};