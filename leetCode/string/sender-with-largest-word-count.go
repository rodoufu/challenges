// https://leetcode.com/problems/sender-with-largest-word-count/
func largestWordCount(messages []string, senders []string) string {
    senderWords := map[string]int{}
    lenM := len(messages)
    for i := 0; i < lenM; i++ {
        count := 1
        for _, letter := range messages[i] {
            if letter == ' ' {
                count++
            }
        }
        senderWords[senders[i]] += count
    }
    
    sender := ""
    maxCount := 0
    for senderIt, count := range senderWords {
        if count > maxCount || (count == maxCount && senderIt > sender) {
            sender = senderIt
            maxCount = count
        }
    }
    //fmt.Printf("senderWords: %v\n", senderWords)
    return sender
}
