def solution(s: str) -> str:
    # Edit your code here
    if '.' in s:
        s, decimal = s.split('.')
    else:
        decimal = ''
    # or 是一个逻辑运算符，用于返回第一个为真的值。如果第一个值为假，返回第二个值。
    # 这行代码确保了即使原始字符串 s 全部由 '0' 组成，最终结果也不会是空字符串，而是 '0'。
    s = s.lstrip('0') or '0' 
    s = s[::-1]
    s = ','.join([s[i:i+3] for i in range(0, len(s), 3)])
    return s[::-1] + ('.' + decimal if decimal else '')

if __name__ == '__main__':
    print(solution("1294512.12412") == '1,294,512.12412')
    print(solution("0000123456789.99") == '123,456,789.99')
    print(solution("987654321") == '987,654,321')
    print(solution("0.000") == '0.000')