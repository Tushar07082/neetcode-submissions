class Solution {
public:
    void pushAll(unordered_set<string>& ocean,
                 int i,
                 int j,
                 vector<vector<int>>& heights,
                 int last) {

        int n = heights.size();
        int m = heights[0].size();

        if (i < 0 || j < 0 ||
            i >= n || j >= m ||
            heights[i][j] < last) {
            return;
        }

        string cell = to_string(i) + " " + to_string(j);

        if (ocean.find(cell) != ocean.end()) {
            return;
        }

        ocean.insert(cell);

        int currentHeight = heights[i][j];

        pushAll(ocean, i + 1, j, heights, currentHeight);
        pushAll(ocean, i - 1, j, heights, currentHeight);
        pushAll(ocean, i, j + 1, heights, currentHeight);
        pushAll(ocean, i, j - 1, heights, currentHeight);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int n = heights.size();
        int m = heights[0].size();

        unordered_set<string> pacific;
        unordered_set<string> atlantic;

        // Left border -> Pacific
        // Right border -> Atlantic
        for (int i = 0; i < n; i++) {
            pushAll(pacific, i, 0, heights, 0);
            pushAll(atlantic, i, m - 1, heights, 0);
        }

        // Top border -> Pacific
        // Bottom border -> Atlantic
        for (int j = 0; j < m; j++) {
            pushAll(pacific, 0, j, heights, 0);
            pushAll(atlantic, n - 1, j, heights, 0);
        }

        vector<vector<int>> ans;

        for (const string& cell : pacific) {
            if (atlantic.find(cell) != atlantic.end()) {
                int separator = cell.find(' ');

                int i = stoi(cell.substr(0, separator));
                int j = stoi(cell.substr(separator + 1));

                ans.push_back({i, j});
            }
        }

        return ans;
    }
};