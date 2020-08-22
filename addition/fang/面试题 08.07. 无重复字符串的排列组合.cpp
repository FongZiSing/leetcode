class Solution {
    void BackTrace(vector<string>& ans, deque<bool>& visited,
                   const string& S, const int& N, const string&& s, int n)
    {
        if (N == n) {
            ans.emplace_back(s);
            return;
        }

        for (int i = 0; i < N; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            BackTrace(ans, visited, S, N, s + S[i], n + 1);
            visited[i] = false;
        }
    }

public:
    vector<string> permutation(string S)
    {
        int n = S.length();
        deque<bool> visited(n, false);
        vector<string> ans;
        BackTrace(ans, visited, S, n, "", 0);
        return ans;
    }
};