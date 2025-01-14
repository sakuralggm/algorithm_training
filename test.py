def solution(n, b, sequence):
    prefix_sum = [0] * (n + 1)
    for i in range(1, n + 1):
        prefix_sum[i] = prefix_sum[i - 1] + sequence[i - 1]
    ans = 0
    remainder_count = {}
    
    for i in range(n + 1):
        remainder = prefix_sum[i] % b
        if remainder in remainder_count:
            ans += remainder_count[remainder]
            remainder_count[remainder] += 1
        else:
            remainder_count[remainder] = 1
    
    return ans
    
if __name__ == "__main__":
    # You can add more test cases here
    print(solution(3, 3, [1, 2, 3]) == 3)