package main

import "fmt"

func FizzBuzz(n int) {
	switch {
	case n%15 == 0:
		fmt.Println("FizzBuzz")
	case n%5 == 0:
		fmt.Println("Buzz")
	case n%3 == 0:
		fmt.Println("Fizz")
	default:
		fmt.Println(n)
	}
}

func main() {
	for i := 1; i <= 100; i++ {
		FizzBuzz(i)
	}
}
