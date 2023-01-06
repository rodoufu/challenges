// https://leetcode.com/problems/truncate-sentence/
import "strings"
func truncateSentence(s string, k int) string {
    ws := strings.Split(s, " ")
    return strings.Join(ws[:k], " ")
}
