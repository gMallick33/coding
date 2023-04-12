class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stringstream ss(path);
        string str;
        vector<string> answer;
        while(getline(ss, str, '/')){
            if(!answer.empty() && str == "..") answer.pop_back();
            else if(str != "." && str != "" && str != "..") answer.push_back(str);
        }
        string simplified_path = "";
        for(int i = 0; i < answer.size(); i++){
            simplified_path += '/' + answer[i];
        }

        if(simplified_path == "") return "/";
        else return simplified_path;
    }
};