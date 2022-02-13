// https://leetcode.com/problems/reorder-data-in-log-files/
func isDigitLog(log string) bool {
    for i := len(log) - 1; i >= 0; i-- {
        if !unicode.IsSpace(rune(log[i])) {
            return unicode.IsDigit(rune(log[i]))
        }
    }
    return false
}

func reorderLogFiles(logs []string) []string {
    var digitLog []string
    var letterLog []string
    for _, log := range logs {
        if isDigitLog(log) {
            digitLog = append(digitLog, log)
        } else {
            letterLog = append(letterLog, log)
        }
    }
    sort.Slice(letterLog, func(i, j int) bool {
        iNonSpace := 1
        lenI := len(letterLog[i])
        for k := 1; k < lenI; k++ {
            if unicode.IsSpace(rune(letterLog[i][k])) {
                iNonSpace = k + 1
                break
            }
        }
        jNonSpace := 1
        lenJ := len(letterLog[j])
        for k := 1; k < lenJ; k++ {
            if unicode.IsSpace(rune(letterLog[j][k])) {
                jNonSpace = k + 1
                break
            }
        }
        for ; iNonSpace < lenI && jNonSpace < lenJ; {
            if letterLog[i][iNonSpace] == letterLog[j][jNonSpace] {
                iNonSpace++
                jNonSpace++
                continue
            }
            return letterLog[i][iNonSpace] < letterLog[j][jNonSpace]
        }
        
        if iNonSpace == lenI && jNonSpace == lenJ {
            iNonSpace = 0
            jNonSpace = 0
            for ; iNonSpace < lenI && jNonSpace < lenJ; {
                if unicode.IsSpace(rune(letterLog[i][iNonSpace])) || unicode.IsSpace(rune(letterLog[j][jNonSpace])) {
                    break
                }
                if letterLog[i][iNonSpace] == letterLog[j][jNonSpace] {
                    iNonSpace++
                    jNonSpace++
                    continue
                }
                return letterLog[i][iNonSpace] < letterLog[j][jNonSpace]
            }
            return i < j
        }
        
        return lenI < lenJ
    })
    return append(letterLog, digitLog...)
}

