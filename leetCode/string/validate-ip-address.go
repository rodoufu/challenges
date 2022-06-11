// https://leetcode.com/problems/validate-ip-address/
func isIPv4(queryIP string) bool {
    groups := strings.Split(queryIP, ".")
    if len(groups) != 4 {
        return false
    }
    
    for _, group := range groups {
        if len(group) == 0 || (len(group) > 1 && group[0] == '0') {
            return false
        }
        for _, x := range group {
            if !unicode.IsDigit(x) {
                return false
            }
        }
        intVar, err := strconv.Atoi(group)
        if err != nil || intVar < 0 || intVar > 255{
            return false
        }
    }
    
    return true
}

func isIPv6(queryIP string) bool {
    groups := strings.Split(queryIP, ":")
    if len(groups) != 8 {
        return false
    }
    
    for _, group := range groups {
        if len(group) < 1 || len(group) > 4 {
            return false
        }
        for _, x := range group {
            if !(unicode.IsDigit(x) || (int(x) >= int('a') && int(x) <= int('f')) || (int(x) >= int('A') && int(x) <= int('F'))) {
                return false
            }
        }
    }
    
    return true
}

func validIPAddress(queryIP string) string {
    if isIPv4(queryIP) {
        return "IPv4"
    } else if isIPv6(queryIP) {
        return "IPv6"
    } else {
        return "Neither"
    }
}
