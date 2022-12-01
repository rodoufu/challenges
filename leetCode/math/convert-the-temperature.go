//https://leetcode.com/problems/convert-the-temperature/
func convertTemperature(celsius float64) []float64 {
    return []float64{ celsius + 273.15, celsius * 1.8 + 32 }
}
