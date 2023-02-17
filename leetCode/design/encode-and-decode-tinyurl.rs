// https://leetcode.com/problems/encode-and-decode-tinyurl/
use std::collections::HashMap;
use std::collections::hash_map::DefaultHasher;
use std::hash::{Hash, Hasher};

//#[derive(Debug)]
struct Codec {
	encoded: HashMap<String, HashMap<String, String>>,
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
    fn new() -> Self {
        Self {
            encoded: Default::default(),
        }
    }
	
    // Encodes a URL to a shortened URL.
    fn encode(&mut self, longURL: String) -> String {
        //println!("{:?} - encode: {}", self, longURL);
        let mut hasher = DefaultHasher::new();
        longURL.hash(&mut hasher);
        let resp = format!("{:x}", hasher.finish());

        let mut val = self.encoded.entry(resp[..6].to_string()).or_insert(Default::default());
        let resp_len = resp.len();
        for i in 6..resp_len {
            let resp_i = resp[..i].to_string();
            if !val.contains_key(&resp_i) {
                val.insert(resp_i.clone(), longURL);

                return format!("http://tinyurl.com/{}", resp_i);
            }
        }

        resp
    }
	
    // Decodes a shortened URL to its original URL.
    fn decode(&self, shortURL: String) -> String {
        let key = shortURL[19..].to_string();
        let key_6 = key[..6].to_string();
        //println!("{:?} decode -> shortURL: {}, key_6: {}, key: {}", self, shortURL, key_6, key);

        let val = &self.encoded[&key_6];
        val[&key].clone()
    }
}

/**
 * Your Codec object will be instantiated and called as such:
 * let obj = Codec::new();
 * let s: String = obj.encode(strs);
 * let ans: VecVec<String> = obj.decode(s);
 */
 
