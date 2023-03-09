class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        dp_table = [[0] * len(obstacleGrid[0]) for _ in obstacleGrid]
        dp_table[0][0] = 1 - obstacleGrid[0][0]

        for i, row in enumerate(obstacleGrid):
            for j, cell in enumerate(row):
                if i == 0 and j == 0:
                    continue

                if cell == 1:
                    dp_table[i][j] = 0
                else:
                    total = 0
                    if i > 0:
                        total += dp_table[i - 1][j]
                    if j > 0: 
                        total += dp_table[i][j - 1]

                    dp_table[i][j] = total

        return dp_table[-1][-1]

