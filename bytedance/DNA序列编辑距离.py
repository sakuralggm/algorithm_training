def solution(dna1, dna2):
    dp = [[0 for _ in range(len(dna2) + 1)] for _ in range(len(dna1) + 1)]
    for i in range(1, len(dna1) + 1):
        dp[i][0] = i
    for i in range(1, len(dna2) + 1):
        dp[0][i] = i
    for i in range(1, len(dna1) + 1):
        for j in range(1, len(dna2) + 1):
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + (dna1[i - 1] != dna2[j - 1]))
    return dp[-1][-1]

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("AGCTTAGC", "AGCTAGCT") == 2 )
    print(solution("AGCCGAGC", "GCTAGCT") == 4)