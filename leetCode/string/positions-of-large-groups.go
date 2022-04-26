// https://leetcode.com/problems/positions-of-large-groups/
//import "slice"

type Group struct {
    begin int
    end int
}
func (g *Group) String() string {
    return fmt.Sprintf("[%v,%v]", g.begin, g.end)
}

type Groups []*Group
func (g Groups) Len() int           { return len(g) }
func (g Groups) Swap(i, j int)      { g[i], g[j] = g[j], g[i] }
func (g Groups) Less(i, j int) bool { return g[i].begin < g[j].begin }

func largeGroupPositions(s string) [][]int {
    var groups []*Group
    
    letter := rune('1')
    begin := -1
    for i, it := range s {
        if it != letter {
            if i - begin >= 3 {
                groups = append(groups, &Group{
                    begin: begin,
                    end: i - 1,
                })
            }
            begin = i
            letter = it
        }
    }
    i := len(s)
    if i - begin >= 3 {
        groups = append(groups, &Group{
            begin: begin,
            end: i - 1,
        })
    }
    
    //fmt.Printf("groups: %v\n", groups)
    
    if len(groups) > 0 {
        /*slice.Sort(groups[:], func(i, j int) bool {
            return groups[i].begin < groups[j].begin
        })*/
        sort.Sort(Groups(groups))
    }
    //fmt.Printf("groups: %v\n", groups)
    
    var resp [][]int
    for _, group := range groups {
        resp = append(resp, []int{group.begin, group.end})
    }
    return resp
}
