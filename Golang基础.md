# Golang基础（Libinnn）

## 00 Hello world

### go语言的特点

- 从C继承了很多理念，包括表达式语法，控制结构，基础数据类型，调用参数传值，指针等，也保留了C语言一样的编译执行方式及弱化指针
- 引入包的概念，用于组织程序结构，Go语言的一个文件都要归属于一个包，而不能单独存在
- 垃圾回收机制，内存自动回收，不需要开发人员管理
- 天然并发
  - 从语言层面支持并发，实现简单
  - goroutine，轻量级线程，可实现大并发处理，高效利用多核
  - 基于CPS并发模型实现
- 吸收管道通信机制
- 函数可以返回多个值
- 新的创新：比如切片slice、延时执行defer等

```go
package main

//导入语句
import "fmt"

//函数外只能放置标识符（变量、常量、函数、类型）的声明

//程序的入口
func main() {
	fmt.Println("Hello world!")
}

```

## 01 变量和常量

### 标识符和关键字

- go语言有25个关键字
- go语言有37个保留字

### 变量

go语言的变量必须先声明

变量声明

```go
/*标准声明*/
var s1 string //声明一个保存string的s1
var name string
var age int
var isOk bool

/*批量声明*/
var (
	name string		//""
    var age int		//0
    var isOk bool	//false
)
```

```go
package main

import "fmt"

var (
	name string
	age  int
	isOk bool
)

func main() {
	name = "golang"
	age = 16
	isOk = true
	fmt.Printf("name:%s\n", name)
	fmt.Println(age)
	fmt.Print(isOk)
}
```

 

```go
//声明变量同时赋值
var s1 string = "web"

//类型推导
var s2 = "web"

//简短变量声明法
s3 := "hahaha"
```

匿名变量用一个下划线表示_，接受无用变量

注：

- go语言推荐使用驼峰命名
- 声明的全局变量可以不进行使用
- 主函数内声明的变量需要使用（temp declared but not used）
- 声明全局变量用批量声明
- 函数内使用简短变量声明
- 函数外的每个语句必须以关键字开始（var、const、func等）
- := 不能在函数外使用
- _用于占位，表示忽略该值
- 同一个作用域不能重复声明

### 常量

在程序运行期间值不发生变化

常量定义以后不能进行改变

```go
const pi = 3.1415
const e = 2.182

//批量常量声明
const (
	pi = 3.1415
	e = 2.182
)
```

```go
//批量常量声明
const (
	AAA = 200
    BBB = 404
    CCC = 500
)

//如果批量常量声明没有赋值，默认和上面一致
const (
	AAA = 200	//200
    BBB			//200
    CCC			//200
)
```

### iota

iota是go语言的常量计数器

const每新增一行变量声明，iota计数一次

iota的一些笔试题

```go
const (
	a1 = iota	//0
	a2			//1
	a3			//2
)
```

```go
const (
	a1 = iota	//0
	a2 = iota	//1
	a3 = iota	//2
)
```

```go
const (
	a1 = iota //0
	a2        //1
	_         //2
	a4        //3
)
```

```go
const (
	a1 = iota 	//0
	a2 = 100  	//100
	a3  		//100
	a4  		//100
)
```

```go
const (
	a1 = iota //0
	a2 = 100  //100
	a3 = iota //2 const每新增一“行”变量声明，iota计数一次
	a4        //3
)
```

```go
//多个常量在一行
const (
	a1, a2 = iota + 1, iota + 2 //0+1	0+2
	a3, a4 = iota + 1, iota + 2 //1+1	1+2
)
```

定义数量级

```go
const (
	_  = iota
	KB = 1 << (10 * iota) //左移10位 2^10
	MB = 1 << (10 * iota)
	GB = 1 << (10 * iota)
	TB = 1 << (10 * iota)
	PB = 1 << (10 * iota)
)
```

## 02 基本数据类型

### 整形

八进制&十六进制

```go
package main

import "fmt"

func main() {
	//十进制->二进制
	var a int = 10
	fmt.Printf("%d -> %b\n", a, a)

	//八进制 以0开头
	var b int = 077
	fmt.Printf("%o\n", b)

	//十六进制 以0x开头
	var c int = 0xff
	fmt.Printf("%x\n", c)
	fmt.Printf("%X\n", c)
}

/*
10 -> 1010
77
ff
FF
*/
```

### 浮点型

```go
package main

import (
	"fmt"
)

func main() {
	f1 := 1.23456
	fmt.Printf("%T\n", f1)
}
//默认是float64
```

float32和float64是两个不同的类型不可以相互赋值

### 复数

complex64和complex128

### 布尔值

- 默认为false
- golang不能被整形强转
- 布尔无法参与数值运算，也无法相互转换

### 字符串

转义符

| 转义符 | 含义   |
| ------ | ------ |
| \r     | 回车   |
| \n     | 换行   |
| \\'    | ‘      |
| \\"    | “      |
| \t     | 制表符 |
| \\\    | 反斜杠 |

定义多行字符串（反引号）

```go
s2:=`
	多行
	字符串
`
```

字符串长度

```go
fmt.Println(len(s1))
```

字符串拼接

```go
name := "小明"
world := "db"

ss := name + world	//拼接
ss1 := fmt.Sprintf("%s%s",name,world)	//拼接
```

分割

```go
ret1 := strings.Split(s3,"\\") //需要转义
```

是否包含

```go
ret := strings.Contains(ss,"理想")//返回布尔
```

前缀后缀

```go
ret := strings.HasPrefix(ss,"理想")
ret := strings.HasSuffix(ss,"理想")
```

返回字串索引

```go
ret := strings.Index(ss,"abc")
ret := strings.LastIndex(ss,"abc")
```

拼接

```go
ret := strings.Join(ret1,'+')
```

遍历

```go
for _,c := rangs s {
    fmt.Printf("%c\n",c)
}
```

修改（是不能修改的需要强转）

```go
s2 := "白萝卜"
s3 := []rune(s2)	//把字符串强制转换成了一个rune切片
s3[0] = '红'
fmt.Println(string(s3))	//把rune切片强制转换成字符串


```

### 类型转换

T( )

### fmt.Printf

```go
fmt.Printf("%T",n)	//类型
fmt.Printf("%v",n)	//所有类型
fmt.Printf("%#v",n)
fmt.Printf("%b",n)	//二进制
fmt.Printf("%d",n)	//十进制
fmt.Printf("%o",n)	//八进制
fmt.Printf("%x",n)	//十六进制
fmt.Printf("%s",n)	//字符
```

##  03 流程控制

### if

```go
	age := 19
	if age > 18 {
		fmt.Println("111")
	} else if age < 16 {
		fmt.Println("222")
	} else {
		fmt.Println("333")
	}
//=========================
	if age := 19 ; age > 18 {
		fmt.Println("111")
	} else if age < 16 {
		fmt.Println("222")
	} else {
		fmt.Println("333")
	}
	fmt.Println(age)//错误，作用域在if内，执行完销毁
```

### for

```go
break		//跳出for
continue	//跳过本次循环
//=========================
func main(){
    for i:= 0;i < 10; i++ {
        fmt.Println(i)
    }
}
//=========================
func main(){
    var i= 0
    for ;i < 10; i++ {
        fmt.Println(i)
    }
}
//=========================
func main(){
    for i < 10 {
        fmt.Println(i)
        i++
    }
}
//=========================
func main(){
    for{
        fmt.Println("无限循环")
    }
}
```

### for range(键值循环)

Go语言中可以使用for range遍历数组、切片、字符串、map及通道( channel)。

通过for range遍历的返回值

有以下规律:

- 数组、切片、字符串返回索引和值。
- map返回键和值。
- 通道( channel )只返回通道内的值。

```go
s := "hello world"
for i,v := range s {
    fmt.Printf("%d %c\n",i,v)
}
```

### switch

```go
switch n := 3, n {
    case 1:
    	fmt.Println(1)
    case 2:
    	fmt.Println(2)
    case 3:
    	fmt.Println(3)
    default:
    	fmt.Println("nil")
}
//==================
n := 3,
switch n {
    case 1:
    	fmt.Println(1)
    case 2:
    	fmt.Println(2)
    case 3:
    	fmt.Println(3)
    default:
    	fmt.Println("nil")
}
//==================
n := 3,
switch n {
    case 1,4:
    	fmt.Println(1)
    case 2,5:
    	fmt.Println(2)
    case 3,6:
    	fmt.Println(3)
    default:
    	fmt.Println("nil")
}
//==================
n := 3,
switch n {
    case n < 3:
    	fmt.Println(1)
    case n < 8:
    	fmt.Println(2)
    case n < 19:
    	fmt.Println(3)
    default:
    	fmt.Println("nil")
}
//==================
n := 3,
switch n {
    case n < 3:
    	fmt.Println(1)
    	fallthrough//可以执行下一个case
    case n < 8:
    	fmt.Println(2)
    case n < 19:
    	fmt.Println(3)
    default:
    	fmt.Println("nil")
}
```

### goto(不推荐)

```go
func main() {
	fori:e;i<10;1++{
		forj:0;j<10;j++{
            if j==2 {
                goto breakTag
            }
            fmt.Printf("%v-%v\n", 1, j)
   	 	}   
	}
breakTag:
	fmt .PrintIn("结束for循环")
}
```

## 04 运算符

- 算数运算符
- 逻辑运算符
-  位运算符

## 05 复杂数据类型

### 数组

### 切片

切片的本质

append和copy

### 指针

golang不存在指针操作，只需要记住两个符号

- &：取地址
- *：根据地址取值

```go
package main

import "fmt"

func main() {
	//1.&取地址
	n := 18
	fmt.Println(&n)

	//2.*根据地址取值
	p := &n
	fmt.Println(*p)
	fmt.Printf("%T\n", p)
	m := *p
	fmt.Println(m)
	fmt.Printf("%T\n", m)
}

/*
0xc0000180c0
18
*int
18
int
*/
```

### make和new

#### new

```go
//错误写法（a空的指针）
//invalid memory address or nil pointer dereference
	var a *int
	*a = 100
	fmt.Println(*a)

//正确写法
	var a = new(int)
	*a = 100
	fmt.Println(*a)
```

#### make

make也是分配内存的，不过他只作用于slice、map、以及chan的内存创建，返回的类型就是类型本身，而不是他们的指针类型，因为这三种就是引用类型

*问题：make和new的区别？*

1. make和new都是用来申请内存的
2. new很少用，一般用来给基本数据类型申请内存，返回对应类型的指针
3. make使用来给slice、map、chan申请内存的，make函数返回的是对应的三个类型本身（引用类型）

### map

映射关系，内部使用哈希实现

```go
//错误:assignment to entry in nil map
//没在内存中开辟空间

var m1 map[string]int
m1["理想"] = 18
m1["三旬"] = 22
fmt.Println(m1)
```

#### 初始化

```go
package main

import "fmt"

func main() {
	var m1 map[string]int
	m1 = make(map[string]int, 10) //支持自动扩容
	//提前估算好，避免运行时扩容
	m1["理想"] = 18
	m1["三旬"] = 22
	fmt.Println(m1)
	v, ok := m1["XXX"]
	if !ok {
		fmt.Println("无此key")
	} else {
		fmt.Println(v)
	}
}
//map[三旬:22 理想:18]
//无此key
```

#### map的遍历

```go
for k, val := range m1 {
	fmt.Println(k, val)
}

for k := range m1 {
	fmt.Println(k)
}

for _, val := range m1 {
	fmt.Println(val)
}
```

#### map删除

```go
	delete(m1, "理想")
	fmt.Println(m1)
	delete(m1, "OOO") //不存在无操作
	fmt.Println(m1)
```

#### 按照指定顺序遍历map

1. 取出map中所有的key存入切片keys
2. 对切片进行排序sort.String(keys)
3. 按照排序后的keys遍历map

```go
package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func main() {
	
	rand.Seed(time.Now().UnixNano()) //初始化随机种子

	var scoreMap = make(map[string]int, 200)

	for i := 0; i < 100; i++ {
		key := fmt.Sprintf("stu%02d", i)
		value := rand.Intn(100)
		scoreMap[key] = value
	}
	//取出map中所有的key存入keys
	var keys = make([]string, 0, 100)
	for key := range scoreMap {
		keys = append(keys, key)
	}
	//对切片进行排序
	sort.Strings(keys)
	//按照排序后的key遍历map
	for _, key := range keys {
		fmt.Println(key, scoreMap[key])
	}
}
```

#### 元素为map类型的切片和值为切片的map

```go
package main

import "fmt"

//map和slice组合

func main() {
	//元素类型为map的切片
	var s1 = make([]map[int]string, 10, 10)
	//没有对内部的map做初始化
	s1[0] = make(map[int]string, 1)
	s1[0][10] = "沙河"
	fmt.Println(s1)
	//[map[10:沙河] map[] map[] map[] map[] map[] map[] map[] map[] map[]]
	
	//值为切片类型的map
	var m1 = make(map[string][]int, 10)
	m1["沙河"] = []int{10, 20, 30}
	fmt.Println(m1)
	//map[沙河:[10 20 30]]

}
```

## 06 函数

### 基础

函数存在的意义？

- 函数是一段代码的封装
- 把一段逻辑抽象出来封装到一个函数中，给他起个名字，每次用到就调用
- 使用函数能够让代码结构更清晰简洁

```go
//函数的定义
func sum(a int, b int) (ret int) {
	return a + b
}

//没有返回值
func f1(x int, y int) {
	fmt.Println(x, y)
}

//无参无返回值
func f2() {
	fmt.Println("func")
}

//无参有返回值
func f3() int {
	return 3
}

//参数可命名可不命名
//命名返回值就相当于声明变量
func f4(x int, y int) (ret int) {
	ret = x + y
	return
	//等同 return ret
}

//多个返回值
func f5() (int, string) {
	return 1, "func"
}

//参数的类型简写
//
func f6(x, y int, m, n string) int {
	return 1
}

//可变长参数
//可变长参数必须放在参数的最后
func f7(x string, y ...int) {
	fmt.Println(x)
	fmt.Println(y)//y的类型是切片
}

//goland没有默认参数这个概念

```

### 进阶

#### 变量作用域

- 全局变量
- 局部变量
- 语句块作用域

函数查找变量的顺序

1. 先在内部查找
2. 再到外边找，一直找到全局

#### 函数类型和变量

可作为参数或者返回值

```go
package main

import "fmt"

func f1() {
	fmt.Println("hello")
}

func f2() int {
	return 1
}

//函数作为参数
func f3(x func() int) {
	ret := x()
	fmt.Println(ret)
}

func f4(x, y int) int {
	return x + y
}

func ff(a, b int) int {
	return a + b
}

//函数作为返回值
func f5(x func() int) func(int, int) int {
	return ff
}

func main() {
	a := f1
	fmt.Printf("%T\n", a)
	b := f2
	fmt.Printf("%T\n", b)
	f3(b)
	f7 := f5(f2)
	fmt.Printf("%T\n", f7)
}

```

#### 匿名函数

```go
package main

import "fmt"

//匿名函数
//因为函数内部不能再定义函数
//可以用匿名函数
var f1 = func(x, y int) {
	fmt.Println(x + y)
}

func main() {
	f1(10, 20)

	//只用一次的函数，立即执行函数
	func() {
		fmt.Println("匿名函数")
	}()
}

```



## 07defer语句

Go语言中的defer语句会将其后面跟随的语句进行延迟处理。在defer归属的函数即将返回时,将延迟处理的语句按defer定义的逆序进行执行,也就是说,先被defer的语句最后被执行,最后被defer的语句最先被执行。

### 先进后出

```go
package main

import "fmt"

func deferDemo() {
	fmt.Println("start")
	defer fmt.Println("hahahha111")
	defer fmt.Println("hahahha222")
	defer fmt.Println("hahahha333")
	//defer把后面的语句延迟处理，在将要返回的时候执行
	//最后用于释放资源
	fmt.Println("end")
}

func main() {
	deferDemo()
	//start
	//end
	//hahahha333
	//hahahha222

}
```

### defer的执行时机

1. 返回值=x
2. 运行defer
3. return指令

### 经典问题

```go
package main

import "fmt"

// Go语言中函数的"return"不是原子操作，在底层是分为两步来执行
//第一步:返回值赋值
//第二步:真正的RET返回
//函数中如果存在defer,那么defer执行的时机是在第一步和第二步之间

//5
func f1() int {
	x := 5
	defer func() {
		x++ //修改的是x，不是返回值
	}()
	return x
}

//6
func f2() (x int) {
	defer func() {
		x++ //修改的是x，不是返回值
	}()
	return 5 //是return分两步
}

//5
func f3() (y int) {
	x := 5
	defer func() {
		x++ //修改的是x，不是返回值
	}()
	return x //返回值=y=x
}

//5
func f4() (x int) {
	defer func(x int) {
		x++ //值传递，改变函数内的副本
	}(x)
	return 5 //返回值=x=5
}

func main() {
	fmt.Println(f1())
	fmt.Println(f2())
	fmt.Println(f3())
	fmt.Println(f4())
}

```

## 08 闭包

闭包是什么？

- 闭包是一个函数，这个函数包含了它外部作用域的一个变量

底层原理

- 函数可以作为返回值
- 函数内部查找变量的顺序

```go
package main

import "fmt"

//闭包

func f1(f func()) {
	fmt.Println("this is f1")
	f()
}

func f2(x, y int) {
	fmt.Println("this is f2")
	fmt.Println(x + y)
}

//定义一个函数对f2进行包装
func f() func() {
	tmp := func() {
		fmt.Println("hell0")
	}
	return tmp
}

//改一下，把f2传进去，返回一个无返回值无参数的函数
func f3(f func(int, int), x int, y int) func() {
	tmp := func() {
		f(x, y)
	}
	return tmp
}

func main() {
	ret := f3(f2, 100, 200)
	ret()
}
```

## 09 内置函数


| 内置函数       | 介绍                 |
| -------------- | -------------------- |
| close          | 关闭channel          |
| len            | 求长度               |
| new            | 分配内存（值类型）   |
| make           | 分配内存（引用类型） |
| append         | 追加元素到数组、切片 |
| panic和recover | 错误处理、           |

Go语言中目前( 是没有异常机制,使用panic/recover 模式来处理错误。
panic可以在任何地方引发，但recover只有在defer 调用的函数中有效。

```go
package main

import "fmt"

func fa() {
	fmt.Println("a")
}
func fb() {
	defer func() {
		err := recover()//恢复一下，继续执行
		fmt.Println(err)
		fmt.Println("释放资源")
	}()
	panic("出现严重错误") //程序崩溃退出
	fmt.Println("b")
}
func fc() {
	fmt.Println("c")
}

func main() {
	fa()
	fb()
	fc()
	
	/*
	a
	出现严重错误
	释放资源
	c
	*/
}
```

注：

- recover()必须搭配defer使用
- defer一定要在可能引发panic的语句以前使用



## 10 fmt标准库

### 向外输出

- Print
- Printf
- Println

### 获取输入

- Scan
- Scanf
- Scanln

### 拼接

- Sprint
- Sprintf
- Sprintln

## 11 递归

阶乘   5！=5x4x3x2x1

```go
package main

import "fmt"

//递归
//就是自己调用自己
//阶乘   5！=5x4x3x2x1

func f1(n uint64) uint64 {
	if n <= 0 {
		return 1
	}
	return n * f1(n-1)
}

func main() {
	ret := f1(5)
	fmt.Println(ret)
}

```

- 一定要有明确的递归条件

- 适合处理问题规模越来越小的问题



上台阶问题

n个台阶, 一次可以走1步,也可以走2步,有多少种走法。

```go
package main

import "fmt"

func taijie(n uint64) uint64 {
	if n == 1 {
		//就一种走法
		return 1
	}
	if n == 2 {
		//两种走法
		return 2
	}
	return taijie(n-1) + taijie(n-2)
}

func main() {
	ret := taijie(3)
	fmt.Println(ret)
}

```



## 12  自定义类型和类型别名

```go
package main

import "fmt"

//自定义类型和类型别名

//type后面跟的是类型
type myInt int     //自定义类型
type yourInt = int //类型别名

func main() {
	var n myInt
	n = 100
	fmt.Println(n)
	fmt.Printf("%T\n", n)

	var m yourInt
	m = 200
	fmt.Println(m)
	fmt.Printf("%T", m)
	/*
		100
		main.myInt
		200
		int
	*/
}
```

rune 就是int32，就是类型别名

- 自定义类型在编译的时候保留
- 类型别名不保留

## 13 结构体

### 结构体定义

```go
package main

import "fmt"

//结构体

type person struct {
	name   string
	age    int
	gender string
	hobby  []string
}

func main() {
	//声明变量
	var zh person
	//通过字段赋值
	zh.name = "姓名"
	zh.age = 18
	zh.gender = "男"
	zh.hobby = []string{"唱", "跳", "rap"}
	fmt.Println(zh)
	//访问字段
	fmt.Println(zh.name)
    
    
    //匿名结构体
    //多用于临时场景
    var s struct{
        x string
        y int
    }
    s.x = "111"
    s.y = 100
    fmt.Println(s)
        
}
```

### 结构体是值类型和地址类型

```go
package main

import "fmt"

//结构体是值类型和地址类型

type person struct {
	name, gender string
}

//go语言函数传参永远是拷贝
func f(x person) {
	x.gender = "女"
}

func fp(x *person) {
	(*x).gender = "女"
}

func main() {
	var p person
	p.name = "cai"
	p.gender = "nan"
	f(p)
	fmt.Println(p) //{cai nan}

	fp(&p)
	fmt.Println(p) //{cai 女}

}
```

### go语言语法糖

```go
(*x).gender = "女"
//就等价于
x.gender = "女"
//因为go不支持对指针操作
```

### 创建指针类型结构体

```go
var p2 = new(person)
//p2就是一个指针
```

```go
//key value初始化
var p3 = person{
    name:"xing"
    gender:"nan"
}
var p3 = &person{
    name:"xing"
    gender:"nan"
}

//列表初始化，顺序必须一致
p4 := person{
	"小",
    "da"
}
p4 := &person{
	"小",
    "da"
}
```

### 结构体占用一段连续内存

- 结构体的内部字段是连续的
- 内存对齐

### 自写构造函数实现面向对象

new___

```go
package main

import "fmt"

type person struct {
	name string
	age  int
}

//什么时候返回结构体
//什么时候返回结构体指针
//是一个需要考量的问题
//结构体比较大的时候用地址
//减少开销
//new开头的函数时构造函数（默认）
func newPerson(name string, age int) person {
	return person{
		name: name,
		age:  age,
	}
}

func main() {
	p1 := newPerson("111", 111)
	fmt.Println(p1)
}

```

### 方法和接收者

```go
func (接收者变量 接收者类型) 方法名 (参数列表) (返回参数) {
    函数体
}
```

方法：指定于特定类型的函数

*只能给自己定义的类型写方法*

```go
package main

import "fmt"

type dog struct {
	name string
}

//构造函数
func newDog(name string) dog {
	return dog{
		name: name,
	}
}

//函数名前时*接收者*
func (d dog) wang() {
	fmt.Println(d.name)
}

func main() {
	d1 := newDog("222")
	d1.wang()
}

```

**标识符首字母大写就表示对外部可见**

**golang要求这样的标识符上都要加上注释**

```go
//Dog 是对外部可见的
type Dog struct {
    name string
}
```

### 结构体遇到的问题



接收者分为：

- 值接收者
- 指针接收者（改变值时）

```go
//改变值
func (p *dog) bian() {
	p.name = "000"
}
func main() {
	d1 := newDog("222")
    d1.bian()	//语法糖	(*d1).bian()
	fmt.Println(d1.name)
}
```

### 结构体的匿名字段

```go
package main

import "fmt"

//匿名字段
type person struct {
	string
	int
}

func main() {
	p1 := person{
		"string",
		123,
	}
	//变成唯一的了
	//花里胡哨不常用
	fmt.Println(p1.string)
	fmt.Println(p1.int)
}

```

### 结构体嵌套

```go
package main

import "fmt"

type address struct {
	add1 string
	add2 string
}

type person struct {
	name string
	age  int
	add  address
}

type comp struct {
	name    string
	address //匿名嵌套->语法糖：可以直接访问p2.add1
}

func main() {
	p1 := person{
		name: "111",
		age:  111,
		add: address{
			add1: "111",
			add2: "111",
		},
	}
	fmt.Println(p1)
}

```

### 结构体的模拟“继承”

```go
package main

import "fmt"

//结构体模拟实现其他语言的继承

type animal struct {
	name string
}

func (a animal) move() {
	fmt.Printf("%s 会动\n", a.name)
}

type dog struct {
	feet uint8
	animal
}

func (d dog) wang() {
	fmt.Printf("%swangwangwang!", d.name)
}

func main() {
	d1 := dog{
		feet: 4,
		animal: animal{
			name: "dog",
		},
	}
	fmt.Printf("%v\ns", d1)
	d1.wang()
	fmt.Println()
	d1.move()
}

```

## 14 JSON与结构体

- 序列化 struct -> json		
- 反序列化  json -> struct

```go
//序列化
p, err := json.Marshal(p1)
//反序列化
json.Unmarshal([]byte(str), &pp)
```



```go
package main

import (
	"encoding/json"
	"fmt"
)

//结构体与json
//1 go的结构体->json		序列化
//2 json->结构体			反序列化

//结构体字段的可见性，字段需要大写！！！

type person struct {
	Name string `json:"name"` //前端说你必须是name（小写）这样
	Age  int
}

func main() {
	/*序列化*/
	p1 := person{
		Name: "姓名",
		Age:  123,
	}
	p, err := json.Marshal(p1)
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%#v\n", string(p))
	//"{\"name\":\"姓名\",\"Age\":123}"

	
	/*反序列化*/
	str := `{"name":"123","age":"18"}`
	var pp person
	json.Unmarshal([]byte(str), &pp)
	fmt.Printf("%v", pp)
	//{123 0}

}

```

## 15 接口(interface)

### 接口是一种类型

特殊类型，它规定了变量有哪些方法

在编程中会遇到以下场景：不关心一个变量时什么类型，只关心它调用的方法

每个接口由数个方法组成

```go
package main

import "fmt"

//引出接口的实例
//非侵入性接口
//只要实现了speak()方法都实现了接口

type speaker interface {
	speak()
}

type cat struct {
}

type dog struct {
}

type person struct {
}

func (p person) speak() {
	fmt.Println("我是人")
}

func (c cat) speak() {
	fmt.Println("我是猫")
}

func (d dog) speak() {
	fmt.Println("我是狗")
}

func da(x speaker) {
	x.speak()
}

func main() {
	var c1 cat
	var d1 dog
	var p1 person
	da(c1)
	da(d1)
	da(p1)
}

```

### interface实例

```go
package main

import "fmt"

//接口示例
//不管什么牌子都能跑

type car interface {
	run()
}

type falali struct {
	brand string
}

type baoshijie struct {
	brand string
}

func (f falali) run() {
	fmt.Println(f.brand, "FFF")
}

func (b baoshijie) run() {
	fmt.Println(b.brand, "BBB")
}

func drive(c car) {
	c.run()
}

func main() {
	var f1 = falali{
		"FFF",
	}
	var b1 = baoshijie{
		"BBB",
	}
	drive(f1)
	drive(b1)
}
```

### 接口的定义

```go
type 接口名 interface{
	方法名
}
```



接口的保存分为两个部分（引用类型）

- 动态类型
- 动态值

这样就实现了接口变量能够存不同的值

### 接口类型变量

接口=接口实现的类

### 值接收者和指针接收者实现接口的区别

- 使用值接收者实现接口，结构体类型和结构体指针类型的变量都能存.
- 指针接收者实现接口只能存结构体指针类型的变量.

```go
package main

import "fmt"

//使用值接收者和指针接收者的区别

type animal interface {
	move()
	eat(string)
}

type cat struct {
	name string
	feet int8
}

////方法使用值接收者 start
//func (c cat) move() {
//	fmt.Println("猫走路")
//}
//
//func (c cat) eat(s string) {
//	fmt.Println(s)
//}
////方法使用值接收者 end

//方法使用指针接收者 start
func (c *cat) move() {
	fmt.Println("猫走路")
}

func (c *cat) eat(s string) {
	fmt.Println(s)
}

//方法使用指针接收者 end

func main() {
	var aa animal
	c1 := cat{"tom", 4}
	c2 := &cat{"aaa", 2}
	aa = &c1
	aa = c2
	fmt.Println(aa)
}

```

同一个结构体可以实现多个接口

### 空接口

```go
interface{}
```

#### 空接口的应用

```go
package main

import "fmt"

func main() {
	var m1 map[string]interface{}
	m1 = make(map[string]interface{}, 16)
	m1["name"] = "string"
	m1["age"] = 18
	m1["merried"] = true
	fmt.Println(m1)
}

```

还可以作为函数参数

#### 类型断言

```go
package main

import "fmt"

//类型断言
func assign(a interface{}) {
	fmt.Printf("%T\n", a)
	str, ok := a.(string)
	if !ok {
		fmt.Println("断言错误")
	}
	fmt.Println(str)
}

func main() {
	assign(`100`)
}

//str := a.(type)
//str 就是值类型
```

不要为了写接口而写接口

## 16 包(package)

包名中的标识符如果是小写的，表示私有，只能在这个包中使用

首字母大写的标识符可以被外部的包调用

可以起别名

导入语句自动触发init()函数

## 17 文件操作

### 打开和关闭文件

```go
package main

import (
	"fmt"
	"os"
)

//打开文件

func main() {
	fileObj, err := os.Open("./demo.txt")
	if err != nil {
		fmt.Println("打开文件失败", err)
		return
	}
	defer fileObj.Close()
	//读文件
	var tmp = make([]byte, 128) //指定的长度
	n, err := fileObj.Read(tmp[:])
	if err != nil {
		fmt.Println("打开失败")
		return
	}
	fmt.Printf("读了 %d 个字节", n)
	fmt.Println(string(tmp[:n]))
}

```

### bufio一行一行的读

```go
package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func readFromFileBufio() {
	fileObj, err := os.Open("./main.go")
	if err != nil {
		fmt.Printf("打开失败")
		return
	}
	defer fileObj.Close()
	reader := bufio.NewReader(fileObj)
	line, err := reader.ReadString('\n')
	if err == io.EOF {
		return
	}
	if err != nil {
		fmt.Printf("%v", err)
		return
	}
	fmt.Println(line)
}

func main() {
	readFromFileBufio()
}

```

### 文件写入

```go
os.OpenFile(name string ,flag int ,perm FileMode)
//flag:打开模式
//per:文件权限(linux)
```

#### 二进制的用途

```go
package main

import "fmt"

const (
	eat   int = 4
	sleep int = 2
	da    int = 1
)

func f(arg int) {
	fmt.Printf("%b\n", arg)
}

func main() {
	f(eat | da)
 	//101   
}
```

#### Write和WriteString

```go
package main

import (
	"fmt"
	"os"
)

func main() {
	fileObj, err := os.OpenFile("./yy.txt", os.O_APPEND|os.O_CREATE, 0644)
	if err != nil {
		fmt.Printf("失败")
	}
	defer fileObj.Close()
	//Write
	fileObj.Write([]byte("我是写入的内容fileObj.Write\n"))
	//WriteString
	fileObj.WriteString("我是写入的内容fileObj.WriteString")
}
```

#### bufio.NewWriter和ioutil.WriteFile

```go
package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
)

//bufio.NewWriter
func writeDemo01() {
	fileObj, err := os.OpenFile("./zz.txt", os.O_APPEND|os.O_CREATE, 0644)
	if err != nil {
		fmt.Printf("失败")
		return
	}
	defer fileObj.Close()
	wr := bufio.NewWriter(fileObj)
	wr.WriteString("你好呀！\n") //写入缓存
	wr.Flush()               //将缓存写入文件
}

//ioutil.WriteFile
func writeDemo02() {
	str := "112233"
	err := ioutil.WriteFile("./xx/txt", []byte(str), 0666)
	if err != nil {
		fmt.Println(err)
		return
	}
}

func main() {
	
}
```

### 标准输入空格的问题

```go
package main

import (
	"bufio"
	"fmt"
	"os"
)

//获取用户输入时如果有空格

func useScanf() {
	var s string
	fmt.Scanln(&s)
	fmt.Println(s)
}

func useBufio() {
	var s string
	reader := bufio.NewReader(os.Stdin)
	s, _ = reader.ReadString('\n')
	fmt.Println(s)
}

func main() {
	useScanf() //空格就截止了
	useBufio()
}

```



## 99 单元测试

`开发需要重视 注释/日志/单元测试`

开发给自己的代码写测试

- golang中依赖`go test`
- 测试为`_test.go`为后缀名
- `在*_test.go`中有三种类型的函数：单元测试函数、基准测试函数、示例函数

| 类型     | 格式(前缀) | 作用             |
| -------- | ---------- | ---------------- |
| 测试函数 | Test       | 测试逻辑是否正确 |
| 基准函数 | Benchmark  | 测试函数性能     |
| 示例函数 | Example    | 提供示例文档     |

### 测试函数

功能函数

```go
package split_string

import "strings"

// 切割字符串
// abc b
//'a','c'

func Split(str string, sep string) []string {
	var ret []string
	index := strings.Index(str, sep)
	for index >= 0 {
		ret = append(ret, str[:index])
		str = str[index+1:]
		index = strings.Index(str, sep)
	}
	ret = append(ret, str)
	return ret
}

```

单元测试

```go
package split_string

import (
	"reflect"
	"testing"
)

func TestSplit(t *testing.T) { //必须Test开头
	got := Split("babbcbef", "b")            //得到数据
	want := []string{"", "a", "", "c", "ef"} //期望数据
	if !reflect.DeepEqual(got, want) {       //比较切片使用反射包内reflect.DeepEqual(A,B)
		//测试失败
		t.Errorf("want:%v,but got:%v\n", want, got)
	}
}

```



- 测试组
- 子测试



### 基准测试



## 99 pprof调试工具





















---



# golang基础练习

 ## 练习01

- 汉字数量
- 统计单词

```go
package main

import (
	"fmt"
	"strings"
	"unicode"
)

func main() {
	//判断字符串中汉字的数量
	//难点是判断一个字符是否是字符
	s1 := "hllo沙河"
	conut := 0
	for _, c := range s1 {
		if unicode.Is(unicode.Han, c) {
			conut++
		}
	}
	println(conut)

	//统计单词的数量
	s2 := "how do you do"
	s3 := strings.Split(s2, " ")
	m1 := make(map[string]int, 10)
	for _, w := range s3 {
		if _, ok := m1[w]; !ok {
			m1[w] = 1
		} else {
			m1[w]++
		}
	}
	for key, value := range m1 {
		fmt.Println(key, value)
	}

}
```

- 回文判断

```go
package main

import "fmt"

func main() {
	//回文判断
	ss := "山西运煤车煤运西山"
	//把字符串的字符拿出来放在[]rune
	r := make([]rune, 0, len(ss))	//注意0
	for _, c := range ss {
		r = append(r, c)
	}
	for i := 0; i < len(r)/2; i++ {
		if r[i] != r[len(r)-1-i] {
			fmt.Println("不是回文")
			return
		}
	}
	fmt.Println("是回文")
}

```

## 练习02

- 分金币问题

```go
package main

import "fmt"

var (
	coins = 5000
	users = []string{
		"qwe", "esdasd", "asdfd", "asda", "weqw", "fgdf", "fsdcbgl", "kjhkj", "lohgfnb", "hkhgj", "gbfcoo",
	}
	distribution = make(map[string]int, len(users))
)

func dispatchCion() (left int) {
	for _, name := range users {
		for _, c := range name {
			switch c {
			case 'e', 'E':
				distribution[name]++
			case 'i', 'I':
				distribution[name] += 2
			case 'o', 'O':
				distribution[name] += 3
			}
		}
	}
	return
}

func main() {
	left := dispatchCion()
	fmt.Println("剩下", left)
}

```

## 函数版学生管理系统

```go
package main

import (
	"fmt"
	"os"
)

/*
	函数版学生管理系统
	查看、新增、删除学生
*/

type student struct {
	id   int64
	name string
}

func newStudent(id int64, name string) *student {
	return &student{
		id:   id,
		name: name,
	}
}

var (
	allstudent map[int64]*student
)

func display() {
	for k, v := range allstudent {
		fmt.Printf("学号：%V,姓名：%V\n", k, v.name)
	}
}

func add() {
	var (
		id   int64
		name string
	)
	fmt.Scanln(&id)
	fmt.Scanln(&name)
	fmt.Println("输入学号和姓名")
	newstu := newStudent(id, name)
	allstudent[id] = newstu
}

func delete1() {
	var (
		deletedId int64
	)
	fmt.Scanln(&deletedId)
	delete(allstudent, deletedId)

}

func main() {
	allstudent = make(map[int64]*student, 48) //开辟内存

	//执行相应函数
	for {
		//打印菜单
		fmt.Println("函数版学生管理系统start")
		fmt.Println(`
		1.查看所有学生
		2.新增学生
		3.删除学生`)
		fmt.Print("等待输入: ")

		//等待用户选择
		var chice int
		fmt.Scanln(&chice)

		switch chice {
		case 1:
			display()
		case 2:
			add()
		case 3:
			delete1()
		default:
			os.Exit(1) //退出
		}
	}
}
```

## 结构体版学生管理系统

```go
package main

import "fmt"

//有一个物件：保存了一些物件，有三个功能

type student struct {
	id   int64
	name string
}

//造一个管理者
type studentMgr struct {
	allStudent map[int64]student
}

//查看学生
func (s studentMgr) showStudents() {
	for _, stu := range s.allStudent {
		fmt.Printf("%d -> %s\n", stu.id, stu.name)
	}
}

//添加学生
func (s studentMgr) addStudent() {
	var (
		id   int64
		name string
	)
	fmt.Scanln(&id)
	fmt.Scanln(&name)
	newStu := student{
		name: name,
		id:   id,
	}
	s.allStudent[id] = newStu
}

//修改学生
func (s studentMgr) editStudent() {
	var stuId int64
	fmt.Scanln(&stuId)
	stuObj, ok := s.allStudent[stuId]
	if !ok {
		fmt.Println("查无此人")
	}
	var newName string
	fmt.Scanln(&newName)
	stuObj.name = newName
	s.allStudent[stuId] = stuObj
}

//删除学生
func (s studentMgr) deleteStudent() {
	var stuId int64
	_, ok := s.allStudent[stuId]
	if !ok {
		fmt.Println("查无此人")
		return
	}
	delete(s.allStudent, stuId)
	fmt.Println("删除成功")
}

```

```go
package main

import "fmt"

//面向对象
//学生管理系统

var smr = studentMgr{
	allStudent: make(map[int64]student),
}

//菜单函数
func showMenu() {
	fmt.Println("welcome sms!")
}

func main() {

	for {
		showMenu()
		fmt.Print(`请输入:`)
		var choice int
		fmt.Scanln(&choice)
		switch choice {
		case 1:
			smr.showStudents()
		case 2:
			smr.addStudent()
		case 3:
			smr.deleteStudent()
		case 4:
			smr.editStudent()
		}
	}

}
```

