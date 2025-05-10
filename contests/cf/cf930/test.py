def min_lexicographically_string(grid, n):
    dp = [[None] * (n + 1) for _ in range(3)]
    count = [[0] * (n + 1) for _ in range(3)]

    for j in range(1, n + 1):
        if grid[0][j] == "1":
            dp[1][j] = "1" * j
            count[1][j] = 1
        else:
            dp[1][j] = "0" * j
            count[1][j] = 1

    for i in range(2, 3):
        for j in range(1, n + 1):
            if grid[i - 1][j] == "1":
                dp[i][j] = min(dp[i - 1][j] + "1", dp[i][j - 1] + "1")
            else:
                dp[i][j] = min(dp[i - 1][j] + "0", dp[i][j - 1] + "0")
            if dp[i][j] == dp[i - 1][j] + grid[i - 1][j] or dp[i][j] == dp[i][j - 1] + grid[i - 1][j]:
                count[i][j] = count[i - 1][j] + count[i][j - 1]
            else:
                count[i][j] = count[i - 1][j] if dp[i][j] == dp[i - 1][j] else count[i][j - 1]

    return dp[2][n], count[2][n]

# Input number of test cases
t = int(input().strip())

# Iterate through each test case
for _ in range(t):
    # Input length of the array
    n = int(input().strip())
    
    # Input the grid
    grid = []
    for _ in range(2):
        row = input().strip()
        grid.append(row)
    
    # Find the lexicographically smallest string and the number of paths
    smallest_string, num_paths = min_lexicographically_string(grid, n)
    
    # Output the lexicographically smallest string and the number of paths
    print(smallest_string)
    print(num_paths)
