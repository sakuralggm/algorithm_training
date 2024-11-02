import itertools
import random

def generate_random_numbers(n):
    return [random.randint(1, 100) for _ in range(n)]

def calculate_c_sum(permutation):
    c_sum = 0
    for i in range(1, len(permutation) + 1):
        subsequence = permutation[:i]
        c_sum += max(subsequence) - min(subsequence)
    return c_sum

def main():
    n = int(input("请输入要生成的随机数个数n: "))
    random_numbers = generate_random_numbers(n)
    
    print(f"产生的{n}个随机数是: {random_numbers}")
    
    permutations = list(itertools.permutations(random_numbers))
    results = []
    
    for perm in permutations:
        c_sum = calculate_c_sum(perm)
        results.append((perm, c_sum))
        print(f"排列: {perm}, 计算结果: {c_sum}")
    
    min_result = min(results, key=lambda x: x[1])
    print(f"计算结果最小的排列及其结果: {min_result[0]}, 结果: {min_result[1]}")

if __name__ == "__main__":
    main()