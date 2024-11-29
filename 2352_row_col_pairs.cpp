class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
    map<string, int> rows;
    map<string, int> columns;
    for (int i = 0; i<grid.size(); i++){
        string row = "";
        for (auto it: grid[i])
            row+= (to_string(it)+";");
        rows[row]++;
        string column = "";
        for (int j = 0; j<grid.size(); j++)
            column+= (to_string(grid[j][i])+";");
        columns[column]++;
    }
    int pairs = 0;
    for (auto it: rows)
        if (columns[it.first]!= 0)
            pairs+=(columns[it.first]*it.second);
    return pairs;
}
};
