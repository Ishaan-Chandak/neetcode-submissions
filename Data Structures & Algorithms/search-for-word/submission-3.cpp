class Solution {
public:

    bool backtrack(vector<vector<bool>> visited, vector<vector<char>>& board, string& word, int& n, int& m, int index, int i, int j) {
        
        // cout << "inside backtrack for " << i << " " << j << " with index " << index << endl;

        if(index == word.size() - 1) return true;

        visited[i][j] = true;

        bool curr = false;

        if(i + 1 < n and index + 1 < word.size() and visited[i+1][j] == false) {
            if(board[i+1][j] == word[index+1]) {
                curr = curr or backtrack(visited, board, word, n, m, index+1, i+1, j);
            }
        }
        if(i - 1 >= 0 and index + 1 < word.size() and visited[i-1][j] == false) {
            if(board[i - 1][j] == word[index+1]) {
                curr = curr or backtrack(visited, board, word, n, m, index+1, i-1, j);
            }
        }
        if(j + 1 < m and index + 1 < word.size() and visited[i][j+1] == false) {
            if(board[i][j + 1] == word[index+1]) {
                curr = curr or backtrack(visited, board, word, n, m, index+1, i, j+1);
            }
        }
        if(j - 1 >= 0 and index + 1 < word.size() and visited[i][j-1] == false) {
            if(board[i][j - 1] == word[index+1]) {
                curr = curr or backtrack(visited, board, word, n, m, index+1, i, j-1);
            }
        }

        return curr;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();  
        set<pair<int, int>> s;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]) s.insert({i, j});
            }
        }

        bool ans = false;

        for(auto p : s) {
            // cout << "calling backtrack" << endl;
            vector<vector<bool>> visited(n+1, vector<bool>(m+1, false));  
            ans = ans or backtrack(visited, board, word, n, m, 0, p.first, p.second);
            if(ans == true) break;
        }

        return ans;
    }
    
};
