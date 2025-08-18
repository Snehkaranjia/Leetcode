class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);
        for(int i=0; i<rowIndex; i++)
        {
            vector<int> newRow;
            newRow.push_back(1);
            for(int i=1; i<row.size(); i++)
                newRow.push_back(row[i] + row[i-1]);
            newRow.push_back(1);
            row = newRow;
        }
        return row;
    }
};