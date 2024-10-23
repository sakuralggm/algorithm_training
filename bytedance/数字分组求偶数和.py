def solution(numbers):
    ans = 0
    def dfs(u, sum):
        if u == len(numbers):
            nonlocal ans
            if sum % 2 == 0:
                ans += 1
            return
        num = numbers[u]
        for i in range(len(str(num))):
            dfs(u + 1, sum + int(str(num)[i]))
    dfs(0, 0)
    return ans
        

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution([123, 456, 789]) == 14)
    print(solution([123456789]) == 4)
    print(solution([14329, 7568]) == 10)