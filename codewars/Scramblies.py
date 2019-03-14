def scramble(s1, s2):
    m1 = {}
    m2 = {}
    for s in s1:
        if s not in m1:
            m1[s] = 0
        m1[s] += 1
    for s in s2:
        if s not in m2:
            m2[s] = 0
        m2[s] += 1
    
    for k,v in m2.items():
        if k not in m1:
            return False
        if m2[k] > m1[k]:
            return False
    
    return True
