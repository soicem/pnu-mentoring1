/*
TC1 - general case 1
Input: [[1,3], [2, 9]]

TC2 - general case 2
Input: [[1,5], [2, 4]]

Approach 1.
- two pointers 사용
- right increment, right++;

- Time Complexity: O(N), N: a size of intervals
- Space Complexity: O(1)


Java, kotlin, sql

- 1정규화, 2정규화, 3정규화, boycodd 
- DML, DDL
- collation, charset
- log
- replication
- spring에서 db 연결

- MySQL (Relational DB), PostgreSQL, RDS
- MongoDB (NoSQL)
- HBase


*/

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    int N = intervals.size();
    
    // sort, priority_queue
    
    sort(intervals.begin(), intervals.end()); // quick sort
    
    int left = 0, right = 0;
    
    while(left <= right && right < N) {
        int currStart = intervals[left][0];
        int currEnd = intervals[left][1];
        
        while(right < N) {
            int nextStart = intervals[right][0];
            int nextEnd = intervals[right][1];
            
            if(currEnd >= nextStart) {
                currEnd = max(currEnd, nextEnd);
            } else {
                break;
            }
            right++;
        }
        
        ans.push_back( {currStart, currEnd} );
        left = right;
    }
    
    return ans;
}
