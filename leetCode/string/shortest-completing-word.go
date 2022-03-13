// https://leetcode.com/problems/shortest-completing-word/
type composed struct {
    letterCount map[rune]int
}

func (c *composed) IsComposing(word string) bool {
    aux := NewComposed(word)
    //fmt.Printf("composedWord(%v): %v\n", word, aux)
    for letter, count := range c.letterCount {
        countWord, ok := aux.letterCount[letter]
        //fmt.Printf("letter: %v, count:%v, ok: %v, countWord: %v\n", string(letter), count, ok, countWord)
        if !ok || countWord < count {
            //fmt.Printf("end - letter: %v, count:%v, ok: %v, countWord: %v\n", string(letter), count, ok, countWord)
            return false
        }
    }
    return true
}

func (c *composed) String() string {
    var resp strings.Builder
    resp.WriteString("{\n")
    for letter, count := range c.letterCount {
        resp.WriteString(fmt.Sprintf("%v: %v,\n", string(letter), count))
    }
    resp.WriteString("}")
    return resp.String()
}

func NewComposed(word string) *composed {
    resp := &composed{
        letterCount: make(map[rune]int),
    }
    word = strings.ToLower(word)
    for _, letter := range word {
        if unicode.IsLetter(letter) {
            resp.letterCount[letter]++
        }
    }
    return resp
}

func shortestCompletingWord(licensePlate string, words []string) string {
    plate := NewComposed(licensePlate)
    //fmt.Printf("plate: %v\n", plate)
    resp := ""
    lenR := 10000
    for _, word := range words {
        lenW := len(word)
        if plate.IsComposing(word) && lenW < lenR {
            resp = word
            lenR = lenW
        }
    }
    return resp
}
