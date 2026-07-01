// https://leetcode.com/problems/function-composition/
type F = (x: number) => number;

function compose(functions: F[]): F {
	return function(x) {
        let resp = x;
        for (let i = functions.length - 1; i >= 0 ; --i) {
            resp = (functions[i])(resp);
        }

        return resp;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
