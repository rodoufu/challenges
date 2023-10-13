// https://leetcode.com/problems/filter-elements-from-array/
function filter(arr: number[], fn: (n: number, i: number) => any): number[] {
    let filteredArr = [];
    let len = arr.length;
    for (let i = 0; i < len; ++i) {
        if (fn(arr[i], i)) {
            filteredArr.push(arr[i]);
        }
    }
    return filteredArr;
};
