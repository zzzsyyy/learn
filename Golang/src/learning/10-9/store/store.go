/*编写一个程序，此程序使用自定义程序包来管理在线商店的帐户。 你的挑战包括以下四个要素：

1. 创建一个名为 Account 的自定义类型，此类型包含帐户所有者的名字和姓氏。 此类型还必须加入 ChangeName 的功能。

2. 创建另一个名为 Employee 的自定义类型，此类型包含用于将贷方数额存储为类型 float64 并嵌入 Account 对象的变量。 类型还必须包含 AddCredits、RemoveCredits 和 CheckCredits 的功能。 你需要展示你可以通过 Employee 对象更改帐户名称。

3. 将字符串方法写入 Account 对象，以便按包含名字和姓氏的格式打印 Employee 名称。

4. 最后，编写使用已创建程序包的程序，并测试此挑战中列出的所有功能。 也就是说，主程序应更改名称、打印名称、添加贷方、删除贷方以及检查余额。

*/

package store

import (
	"errors"
	"fmt"
)

type Account struct {
	FirstName string
	LastName  string
}

type Employee struct {
	Account
	Credits float64
}

func (a *Account) ChangeName(newname string) {
	a.FirstName = newname
}

func (e Employee) String() string {
	return fmt.Sprintf("Name: %s %s\nCredits: %.2f\n", e.FirstName, e.LastName, e.Credits)
}

func CreateEmployee(firstName, lastName string, credits float64) (*Employee, error) {
	return &Employee{Account{firstName, lastName}, credits}, nil
}

func (e *Employee) AddCredits(amount float64) (float64, error) {
	if amount > 0.0 {
		e.Credits += amount
		return e.Credits, nil
	}
	return 0.0, errors.New("Invalid credit amount.")
}

func (e *Employee) RemoveCredits(amount float64) (float64, error) {
	if amount > 0.0 {
		if amount <= e.Credits {
			e.Credits -= amount
			return e.Credits, nil
		}
		return 0.0, errors.New("You can't remove more credits than the account has.")
	}
	return 0.0, errors.New("You can't remove negative numbers.")
}

func (e *Employee) CheckCredits() float64 {
	return e.Credits
}
