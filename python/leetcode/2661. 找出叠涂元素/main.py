class Solution(object):
    def firstCompleteIndex(self, arr, mat):
        """
        :type arr: List[int]
        :type mat: List[List[int]]
        :rtype: int
        """
        n, m = len(mat), len(mat[0])
        
        mp = {}
        for i in range(n):
            for j in range(m):
                mp[mat[i][j]] = [i, j]
        rowCnt, colCnt = [0] * n, [0] * m
        for i in range(len(arr)):
            p = arr[i]
            # p = [x,y]
            rowCnt[mp[p][0]] += 1
            
                
            colCnt[mp[p][1]] += 1
            if(rowCnt[mp[p][0]] == m or colCnt[mp[p][1]] == n):
                return i



        return -1