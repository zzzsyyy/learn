# Bubble Sort
## Def
> 1. 比较相邻的元素。如果第一个比第二个大，就交换它们两个。
> 
> 2. 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。
> 
> 3. 针对所有的元素重复以上的步骤，除了最后一个。
> 
> 4. 持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

## Code

<details>
<summary>Rust</summary>

```rust
pub fn bubble_sort<T:Ord + Debug>(a: &mut [T]){
    for i in 0..a.len() {
        for j in i..a.len() {
            if a[i] > a[j] {
                a.swap(i, j);
            }
        }
    }
}
```
</details>
<details>
<summary>C++</summary>

```c++
#include<iostream>
using namespace std;
template<typename T>

void bubble_sort(T arr[], int len) {
    int i, j;
    for (i=0;i<len-1;i++){
        for (j=0;j<len-1-i;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
```
</details>



## 算法改进

### 设置标志变量

> 用于记录每趟冒泡排序是否发生数据元素位置交换。如果没有发生交换，说明序列已经有序了，不必继续进行下去了。

C++
```c++
void bubble_sort(T arr[], int len) {
    int i, j， changed = 1;
    for (i=0;i<len-1 && changed!=0;i++){
        changed = 0;
        for (j=0;j<len-1-i;j++){
            if (arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                changed = 1；
            }
        }
    }
}

```

### 鸡尾酒排序

从两个方向进行排序

C++
```c++
template<typename T>
void cocktail_sort(T arr[], int len) {
	int j, left = 0, right = len - 1;
	while (left < right) {
		for (j = left; j < right; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		right--;
		for (j = right; j > left; j--)
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
		left++;
	}
}
```
