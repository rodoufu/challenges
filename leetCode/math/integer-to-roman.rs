// https://leetcode.com/problems/integer-to-roman/
impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut resp = Vec::new();
        let mut num = num;
        
        while num > 999 {
            resp.push("M");
            num -= 1000;
        }
        //println!("{}", num);
        if num > 899 {
            resp.push("CM");
            num = num % 100;
        }
        //println!("{}", num);
        
        if num >= 500 {
            resp.push("D");
            num -= 500;
        }
        //println!("{}", num);
        if num > 399 {
            resp.push("CD");
            num %= 100;
        }
        //println!("{}", num);
        while num > 99 {
            resp.push("C");
            num -= 100;
        }
        //println!("{}", num);
        if num > 89 {
            resp.push("XC");
            num = num % 10;
        }
        //println!("{}", num);
        
        if num >= 50 {
            resp.push("L");
            num -= 50;
        }
        //println!("{}", num);
        if num > 39 {
            resp.push("XL");
            num %= 10;
        }
        
        //println!("{}", num);
        while num > 9 {
            resp.push("X");
            num -= 10;
        }
        //println!("{}", num);
        
        if num > 8 {
            resp.push("IX");
            num = num % 1;
        }
        if num >= 5 {
            resp.push("V");
            num -= 5;
        }
        //println!("{}", num);
        if num > 3 {
            resp.push("IV");
            num %= 1;
        }
        //println!("{}", num);
        while num > 0 {
            resp.push("I");
            num -= 1;
        }
        //println!("{}", num);
        
        resp.join("")
    }
}
