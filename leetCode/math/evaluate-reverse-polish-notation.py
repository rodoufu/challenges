# https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        pilha = []

        for token in tokens:
            # print(f"token: {token}, pilha: {pilha}")
            token = token.strip()
            match token:
                case '+':
                    pilha.append(pilha.pop() + pilha.pop())
                case '-':
                    pilha.append(-pilha.pop() + pilha.pop())
                case '*':
                    pilha.append(pilha.pop() * pilha.pop())
                case '/':
                    b = pilha.pop()
                    a = pilha.pop()
                    pilha.append(int(a / b))
                case _:
                    pilha.append(int(token))
        
        # print(f"pilha: {pilha}")
        return sum(pilha)
