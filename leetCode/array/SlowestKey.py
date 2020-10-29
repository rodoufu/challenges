# https://leetcode.com/problems/slowest-key/
class Solution:
    def slowestKey(self, releaseTimes: List[int], keysPressed: str) -> str:
        if not releaseTimes:
            return ""

        duration = {}
        last_time = 0
        for i in range(len(releaseTimes)):
            key_duration = releaseTimes[i]
            if i > 0:
                key_duration = releaseTimes[i] - releaseTimes[i - 1]
            duration[keysPressed[i]] = max(duration.get(keysPressed[i], 0), key_duration)
            
        max_key = keysPressed[0]
        for key, key_dur in duration.items():
            if key_dur > duration[max_key] or (key_dur == duration[max_key] and ord(key[0]) > ord(max_key)):
                max_key = key
                
        return max_key
