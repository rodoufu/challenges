# https://leetcode.com/problems/count-items-matching-a-rule/
class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        if ruleKey == 'type':
            rule_idx = 0
        elif ruleKey == 'color':
            rule_idx = 1
        else:
            rule_idx = 2
        
        resp = 0
        for item in items:
            if item[rule_idx] == ruleValue:
                resp += 1
        return resp
