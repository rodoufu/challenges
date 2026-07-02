# https://app.codility.com/programmers/lessons/7-stacks_and_queues/brackets/
def solution(S):
    checking = []

    for letter in S:
        if letter == '[' or letter == '{' or letter == '(':
            checking.append(letter)
        else:
            if len(checking) == 0:
                return 0
            poped = checking.pop()
            if poped == '[' and letter != ']':
                return 0
            if poped == '{' and letter != '}':
                return 0
            if poped == '(' and letter != ')':
                return 0

    return 1 if len(checking) == 0 else 0
