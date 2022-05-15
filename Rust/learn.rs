#![allow(dead_code)]

fn main() {
    let n = expressions_matter(1,2,3);
    println!("{}", n);
}

fn ans(name: &str) -> String {
    match &name[0..1] {
        // 这里一些要使用&
        "R" | "r" => format!("{} play banjo", name), //match 使用 一个|
        _ => format!("{} does not play banjo", name),
    }
}

fn arr(n: usize) -> Vec<u32> {
    (0..n as u32).collect() //range to vec
}

fn enough(cap: i32, on: i32, wait: i32) -> i32 {
    (on + wait - cap).max(0) //返回和0比较的最大值
}

fn expressions_matter(a: u64, b: u64, c: u64) -> u64 {
    *[a + b + c, a * (b + c), (a + b) * c, a * b * c].iter().max().unwrap();//or
    match (a, b, c) {
        (1, _, 1) => a + b + c,
        (1, _, _) => (a + b) * c,
        (_, 1, 1) => a * (b + c),
        (_, 1, _) => std::cmp::max((a + b) * c, a * (b + c)),
        (_, _, 1) => a * (b + c),
        (_, _, _) => a * b * c,
    }
}
