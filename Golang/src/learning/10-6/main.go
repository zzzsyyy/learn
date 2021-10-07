package main

func main() {
	n := 1000000000000
	tri(n)
}

func tri(n int) {
	ret1 := 0
	for i := 1; i <= n; i++ {
		ret1 += n*(n-1) + 2*i - 1
	}
	if ret1 == n*n*n {
		print(n)
		print("okk")
	}
}
