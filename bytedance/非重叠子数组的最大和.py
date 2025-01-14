# 题解：https://bytedance.larkoffice.com/docx/EkpkdhVD4o23G4xJ70IcuFJcnTf
def solution(nums: list, firstLen: int, secondLen: int) -> int:
    def sum_subarray(nums, length):
        nums_sum = [0] * len(nums)
        current_sum = sum(nums[:length])
        nums_sum[length - 1] = current_sum
        for i in range(length, len(nums)):
            current_sum += nums[i] - nums[i - length]
            nums_sum[i] = current_sum
        return nums_sum
    def max_sum_subarray(arr, length):
        max_sum = [0] * len(arr)
        max_sum[length - 1] = arr[length - 1]
        for i in range(length, len(arr)):
            max_sum[i] = max(max_sum[i - 1], arr[i])
        return max_sum
    sumfirst = sum_subarray(nums, firstLen)
    sumsecond = sum_subarray(nums, secondLen)
    maxfirstleft = max_sum_subarray(sumfirst, firstLen)
    maxfirstright = max_sum_subarray(sumfirst[::-1], 1)[::-1]
    
    ans = 0
    for i in range(secondLen - 1, len(nums)):
        before = maxfirstleft[i - secondLen] if i - secondLen >= 0 else 0
        after = maxfirstright[i + firstLen] if i + firstLen < len(nums) else 0
        ans = max(ans, sumsecond[i] + max(before, after))
    
    return ans


if __name__ == "__main__":
    print(solution(nums=[0, 6, 5, 2, 2, 5, 1, 9, 4], firstLen=1, secondLen=2) == 20)
    print(solution(nums=[3, 8, 1, 3, 5, 2, 1, 0], firstLen=3, secondLen=2) == 21)
    print(solution(nums=[2, 1, 4, 3, 5, 9, 5, 0, 3, 8], firstLen=4, secondLen=3) == 33)
    print(solution(nums=[14, 8, 3, 9, 1, 9, 5, 11, 17, 4, 9, 16, 15, 13], firstLen=1, secondLen=12) == 126)
'''
def solution(nums: list, firstLen: int, secondLen: int) -> int:
    maxfirstleft = [0] * len(nums)
    maxfirstright = [0] * len(nums)
    sumfirst, sumsecond = [0] * len(nums), [0] * len(nums)
    left, right = 0, 0
    while left <= len(nums) - firstLen:
        sumfirst[left] += nums[right]
        right += 1
        if right - left == firstLen:
            maxfirstleft[left] = max(maxfirstleft[left - 1] if left > 0 else -2e9, sumfirst[left])
            left += 1
            if left < len(nums):
                sumfirst[left] = sumfirst[left - 1] - nums[left - 1]
    for i in range(len(nums) - firstLen, -1, -1):
        maxfirstright[i] = max(maxfirstright[i + 1] if i < len(nums) - firstLen else -2e9, sumfirst[i])
    left, right = 0, 0
    while left <= len(nums) - secondLen:
        sumsecond[left] += nums[right]
        right += 1
        if right - left == secondLen:
            left += 1
            if left < len(nums):
                sumsecond[left] = sumsecond[left - 1] - nums[left - 1]
    ans = -2e9
    for i in range(0, len(nums) - secondLen + 1):
        before = maxfirstleft[i - firstLen] if i - firstLen >= 0 else 0
        after = maxfirstright[i + secondLen] if i + secondLen < len(nums) else 0
        ans = max(ans, sumsecond[i] + max(before, after))
        # print(before, after, sumsecond[i], ans)
    # print(sumfirst, sumsecond, maxfirstleft, ans)
    return ans


if __name__ == "__main__":
    # print(solution(nums=[0, 6, 5, 2, 2, 5, 1, 9, 4], firstLen=1, secondLen=2) == 20)
    # print(solution(nums=[3, 8, 1, 3, 5, 2, 1, 0], firstLen=3, secondLen=2) == 21)
    # print(solution(nums=[2, 1, 4, 3, 5, 9, 5, 0, 3, 8], firstLen=4, secondLen=3) == 33)
    print(solution(nums=[14, 8, 3, 9, 1, 9, 5, 11, 17, 4, 9, 16, 15, 13], firstLen=1, secondLen=12) == 126)
'''