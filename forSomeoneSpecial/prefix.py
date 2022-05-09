# ALGORITHM
# 1. Initially reverse the expression given for the infix.
# 2. One by one scan of characters.
# 3. If a character is an operand, then copy it to the output of the prefix notation.
# 4. When the character is a parenthesis closing then push it to the stack.
# 5. If the character is an opening parenthesis, pop the elements in the stack till we find the
#  closing parenthesis that corresponds.
# 6. If a character scanned is an operator.
# 7. If the operator has greater or equal precedence than the top of the stack, push the
#  operator to the stack.
# 8. If the operator has less precedence than the top of the stack, pop the operator and
#  output it to the output of the prefix notation, then check the above condition with the new
#  top of the stack again.
# 9. After scanning all the characters, reverse the notation output for the prefix

OPERATORS = set(['+', '-', '*', '/', '(', ')'])
PRI = {'+': 1, '-': 1, '*': 2, '/': 2}


def infix_to_prefix(formula):
    op_stack = []
    exp_stack = []
    for ch in formula:
        if not ch in OPERATORS:
            exp_stack.append(ch)
        elif ch == '(':
            op_stack.append(ch)
        elif ch == ')':
            while op_stack[-1] != '(':
                op = op_stack.pop()
                a = exp_stack.pop()
                b = exp_stack.pop()
                exp_stack.append(op+b+a)
            op_stack.pop()
        else:
            while op_stack and op_stack[-1] != '(' and PRI[ch] <= PRI[op_stack[-1]]:
                op = op_stack.pop()
                a = exp_stack.pop()
                b = exp_stack.pop()
                exp_stack.append(op+b+a)
            op_stack.append(ch)

    while op_stack:
        op = op_stack.pop()
        a = exp_stack.pop()
        b = exp_stack.pop()
        exp_stack.append(op+b+a)
    print(f'PREFIX: {exp_stack[-1]}')
    return exp_stack[-1]


expres = input("INPUT THE EXPRESSION: ")
pre = infix_to_prefix(expres)
