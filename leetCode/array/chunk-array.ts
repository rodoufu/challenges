// https://leetcode.com/problems/chunk-array/
function chunk(arr: any[], size: number): any[][] {
    let resp = [];

    let current = [];
    let count = 0;

    for (const it of arr) {
        if (count == size) {
            count = 0;
            resp.push(current);
            current = [];
        }
        current.push(it);
        count++;
    }
    if (count > 0) {
        resp.push(current);
    }

    return resp;
};
