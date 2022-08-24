fn main() {
    let mut nums = vec![-1,-100,3,99];
    let k = 2_i32;

    let l = nums.len();
    let k = k as usize % l;
    let mut i = 2 * k % l;
    let mut tmp = nums[k];
    nums[k] = nums[0];
    while i != k {
        println!("把{}替换为{}", nums[i], tmp);
        let ttmp = nums[i];
        nums[i] = tmp;
        tmp = ttmp;
        i = (i + k) % l;
    }
    println!("{:?}", nums);
}
