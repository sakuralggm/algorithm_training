def solution(expression):
    def precedence(op):
        if op == '+' or op == '-':
            return 1
        if op == '*' or op == '/':
            return 2
        return 0

    def apply_op(a, b, op):
        if op == '+':
            return a + b
        if op == '-':
            return a - b
        if op == '*':
            return a * b
        if op == '/':
            return a // b

    def evaluate(tokens):
        values = []
        ops = []
        i = 0

        while i < len(tokens):
            if tokens[i] == ' ':
                i += 1
                continue

            if tokens[i] == '(':
                ops.append(tokens[i])

            elif tokens[i].isdigit():
                val = 0
                while (i < len(tokens) and tokens[i].isdigit()):
                    val = (val * 10) + int(tokens[i])
                    i += 1
                values.append(val)
                i -= 1

            elif tokens[i] == ')':
                while len(ops) != 0 and ops[-1] != '(':
                    val2 = values.pop()
                    val1 = values.pop()
                    op = ops.pop()
                    values.append(apply_op(val1, val2, op))
                ops.pop()

            else:
                while (len(ops) != 0 and precedence(ops[-1]) >= precedence(tokens[i])):
                    val2 = values.pop()
                    val1 = values.pop()
                    op = ops.pop()
                    values.append(apply_op(val1, val2, op))
                ops.append(tokens[i])
            i += 1

        while len(ops) != 0:
            val2 = values.pop()
            val1 = values.pop()
            op = ops.pop()
            values.append(apply_op(val1, val2, op))

        return values[-1]

    return evaluate(expression)

if __name__ == "__main__":
    #  You can add more test cases here
    print(solution("1+1") == 2)
    print(solution("3+4*5/(3+2)") == 7)
    print(solution("4+2*5-2/1") == 12)
    print(solution("(1+(4+5+2)-3)+(6+8)") == 23)