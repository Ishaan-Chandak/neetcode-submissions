class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(int i=0; i<strs.size(); i++){
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while (i < s.size()) {
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i, j-i));
            string str = s.substr(j+1, len);
            result.push_back(str);
            i = j + 1 + len;
        }

        return result;
    }
};
