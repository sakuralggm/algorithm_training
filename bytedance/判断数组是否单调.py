def solution(nums: list) -> bool:
    # 非常优雅！
    is_increasing = all(nums[i] <= nums[i + 1] for i in range(len(nums) - 1))
    is_decreasing = all(nums[i] >= nums[i + 1] for i in range(len(nums) - 1))
    return is_increasing or is_decreasing

if __name__ == '__main__':
    print(solution(nums=[1, 2, 2, 3]) == True)
    print(solution(nums=[6, 5, 4, 4]) == True)
    print(solution(nums=[1, 3, 2, 4, 5]) == False)