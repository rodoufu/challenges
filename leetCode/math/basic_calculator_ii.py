# https://leetcode.com/problems/basic-calculator-ii/
class Solution:
    def calculate(self, s: str) -> int:
        s = s.strip()+"+0"

        operations = {
            '-': 0,
            '+': 0,
            '/': 1,
            '*': 1,
        }
        
        current = ''
        expression = []

        def expression_to_print(expression: list):
            return "".join([item for row in map(lambda x: [str(x[0]), x[1]], expression) for item in row])[:-1]

        def calc(pilha_top_num: int, current: int, pilha_top_operator: str) -> int:
            if pilha_top_operator == '-':
                return pilha_top_num - current
            elif pilha_top_operator == '+':
                return pilha_top_num + current
            elif pilha_top_operator == '*':
                return pilha_top_num * current
            elif pilha_top_operator == '/':
                return pilha_top_num // current
            else:
                raise Exception(f"invalid operator {pilha_top_operator}")

        for idx in range(len(s)):
            letter = s[idx]
            if letter == " ":
                continue
            
            if letter in operations:
                expression.append((int(current), letter))
                
                current = ''
            else:
                current += letter
        
        current = 0
        operation = "+"

        pilha = expression
        while len(expression) > 1:
            pilha = []
            top_precedence = 0
            for _, it_operator in expression:
                it_precedence = operations[it_operator]
                if it_precedence > top_precedence:
                    top_precedence = it_precedence

            for it_num, it_operator in expression:
                if len(pilha) == 0:
                    pilha = [(it_num, it_operator)]
                else:
                    pilha_precedence = operations[pilha[-1][1]]
                    it_precedence = operations[it_operator]
                    if pilha_precedence >= it_precedence and pilha_precedence == top_precedence:
                        pilha_top_num, pilha_top_operation = pilha.pop()
                        pilha_top_num = calc(pilha_top_num, it_num, pilha_top_operation)
                        pilha.append((pilha_top_num, it_operator))
                    else:
                        pilha.append((it_num, it_operator))
            
            # print(f"pilha: {pilha}, expression: {expression_to_print(expression)}")
            expression = pilha

        return pilha[0][0]
