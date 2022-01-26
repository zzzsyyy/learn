use std::io; //标准输入输出

fn main() {
    println!("Guess the number!"); //带!的是宏

    println!("Please input your guess.");

    let mut guess = String::new();//mut-可变  

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");

    println!("You guessed: {}", guess);
}
