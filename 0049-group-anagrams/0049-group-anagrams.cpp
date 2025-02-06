class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          vector<vector<string>>s;
          vector<string>v;
          vector<pair<string,string>>p;
        for(int i=0;i<strs.size();i++){
            string x=strs[i];
            sort(x.begin(),x.end());
            p.push_back({x,strs[i]});
        }
        sort(p.begin(),p.end());
        p.push_back({"0","0"});
        v.push_back(p[0].second);
        for(int i=1;i<p.size();i++){
            string x=v[v.size()-1];
            sort(x.begin(),x.end());
            if(x==p[i].first){
                v.push_back(p[i].second);
            }
            else{
                s.push_back(v);
                v.clear();
                v.push_back(p[i].second);
            }
        }
        return s;
    }
};