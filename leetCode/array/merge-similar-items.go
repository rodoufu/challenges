// https://leetcode.com/problems/merge-similar-items/
import (
    "sort"
)

func mergeSimilarItems(items1 [][]int, items2 [][]int) [][]int {
    valueWeight := map[int]int{}
    for _, it := range items1 {
        valueWeight[it[0]] += it[1]
    }
    for _, it := range items2 {
        valueWeight[it[0]] += it[1]
    }
    
    var resp [][]int
    for value, weight := range valueWeight {
        resp = append(resp, []int{value, weight})
    }
    
    sort.Slice(resp, func(i, j int) bool{
        return resp[i][0] < resp[j][0]
    })
    return resp
}
