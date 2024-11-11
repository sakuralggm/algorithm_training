def solution(n: int, nums: list) -> int:
    # nums 去重然后从大到小排序
    nums = list(set(nums))
    nums.sort(reverse=True)
    if len(nums) <= 2:
        return nums[0]
    else:
        return nums[2]

if __name__ == '__main__':
    print(solution(3, [3, 2, 1]) == 1)
    print(solution(2, [1, 2]) == 2)
    print(solution(4, [2, 2, 3, 1]) == 1)