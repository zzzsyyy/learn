fn main() {
    let x = define_x();
    println!("{}, world", x); 
}

fn define_x<'a>() -> &'a str {
    let x = "hello";
    x
}
