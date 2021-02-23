# （C++）STL基础入门

​																																				*--LiBinnn*

## STL与algorithm头文件

STL是一些容器的集合

algorithm是对容器继承的一些算法函数

**sort()**

```c++
#inclide <algorithm>
int arr[] = {1,4,32,4,6};
sort(arr.begin(),arr.end());
//第三个位置还能传入比较器
```



## string

- 获取一行数据

  ```c++
  string s;
  getline(cin,s);
  ```

  

- += 重载拼接

- 排序

  ```c++
  string s = "12543321";
  sort(s.begin(),s.end());
  ```

  

- 删除

  ```c++
  s.erase(s.begin());
  s.erase(--s.end());
  ```

  

- substr

  ```
  s.substr(1,3);
  s.substr(2,1);
  //第一个是参数是index，第二个参数是截断（几个）
  ```

  

- 循环

  ```c++
  for(int i=0;i<s.length(),i++) cout<<s[i];
  
  for(string::iterator it=s.begin();it!=s.end();it++) cout<<*it;
  
  for(auto it=s.length();it!=s.end();it++) cout<<*it;
  
  for(auto x:s) cout<<x;
  ```

  

## vector

- 定义

  ```c++
  #include <vector>
  vector<int> v1;
  vector<int> v2(5);
  vector<int> v3(5,0);//大小为5默认值为0
  vector<int> v4 {1,2,3,4};
  ```

  

- 查

  ```c++
  v[3];
  
  v.at(3);
  ```

  

- 追加

  ```c++
  v.push_back(4);
  ```

  

- 重置大小

  ```c++
  v.resize(10);
  ```

  

- 第一个、最后一个

  ```c++
  v.front();
  v.back();
  ```

  

- 排序

  ```c++
  vector<int> v {1,4,2,6,7};
  sort(v.begin(),v.end());//从小到大
  sort(v.begin(),v.end(),greater<int>);//从大到小
  ```



## sack

栈：先进后出的数据结构

```c++
#include <stack>
stack<int> s;
s.push(4);
s.push(7);
s.top();//取栈顶，有返回值，不删除
s.pop();//无返回值，删除
s.size();
```

- 逆序单词*

  ```c++
  #include <iostream>
  #include <sstream>
  #include <stack>
  using namespace std;
  int main(){
      stack<string> s;
      string str;
      getline(cin,str);
      stringstream ss;
      ss<<str;
      while(ss>>str){//分词
          s.push(str);
      }
      while(!s.empty()){
          cout<<s.top()<<" ";
          s.pop();
      }
      return 0;
  }
  ```

  

- 进制转换

  ```C++
  #include <iostream>
  #include <stack>
  using namespace std;
  int main(){
      stack<int> s; int res=0;
      int dec;
      cin>>dec;
      while(dec!=0){
          s.push(dec%2);
          dec/=2;
      }
      while(!s.empty()){
          res = res*10+s.top();
          s.pop();
      }
      cout<<res<<endl;
      return 0;
  }
  ```

  

- 字符串转数字

  ```c++
  //1流
  stringstream ss;
  int i;
  string str = "123";
  ss<<str;
  ss>>i;
  cout<<i<<endl;
  
  //2
  int n = stoi("123");
  ```

  

- 数字转字符串

  ```java
  //1流
  stringstream ss;
  int a = 123;
  string str;
  ss<<a;
  ss>>str;
  cout<<str<<endl;
  
  //2(C++11)
  string s = to_string(123);
  ```



## queue

队列：先进先出

```C++
#include <queue>
queue<int> q;
q.push(5);
q.front();//队头，不删除，有返回值
q.pop();//删除对头，无返回值
q.size();
```



## deque

双端队列:自由度高，可排序

```C++
#include <deque>
deque<int> d;
d.push_back(2);
d.push_front(1);
d.pop_front();
d.pop_back();
d.at(7);
c.front();
c.back();
```



## map

映射map

```c++
#include <map>
map<int,int> m;
m[6] = 3;
m[3] = 4;
//K -- V
```



- 循环

```C++
for(auto it=m.begin();it!=m.end();it++){
	cout<<it->first<<" "<<it->second<<end;;
}

for(auto tmp : m){
  cout<<tmp.first<<" "<<tmp.second<<endl;
}
```



- map排序，不能直接排序可以转换为向量

```c++
bool cmp(pair<int,int> a,pair<int,int> b){
  return a.first>b.first;
}

vector<pair<int,int>> v(m.begin(),m.end());
sort(v.begin(),v.end(),cmp);
```



## auto关键字：for(auto &i:s)和for(auto i:s)

- for(auto &i:s)

```c++
#include<iostream>
#include<string>
using namespace std;
string s = "hello";
for (auto &i : s )
i = toupper(i); //改变成大写，影响s的值
cout<<s<<endl; //s的值是 HELLO
```

- for(auto i:s)

```c++
#include<iostream>
#include<string>
using namespace std;
string s = "hello";
for (auto i : s )
i = toupper(i); //改变成大写，不影响s的值
cout<<s<<endl; //s的值是 hello
```

**&会改变引用的值！**



## array

array<T,N> 模板定义了一种相当于标准数组的容器类型。

它是一个有 N 个 T 类型元素的固定序列。

除了需要指定元素的类型和个数之外，它和常规数组没有太大的差别。显然，不能增加或删除元素。

```c++
array<double,100> data;

array<double, 10> values {0.5, 1.0, 1.5, 2.0};

values.fill(3.1415926);

values[4] = values[3] + 2.O*values[1];

values.at (4) = values.at(3) + 2.O*values.at(1);
```



## cctype头文件

是返回非零，不是返回零

- isalpha()字母
- islower()小写
- isupper()大写
- isdigit()数字



## getline

- 第一个参数：流
- 第二个参数：流到哪
- 第三个参数：指定结束符（默认为'\n'）

**getline前面有cin时**

> getline()会把进行cin输入时行末丢弃的换行符读入，从而要在两者之间加个getchar（）

## stringstream

头文件 sstream



## C++ 风格的复制操作

### 使用STL中的copy算法

```
int a[] = {1,2,3,4,5};
int b[5];
std::copy(std::begin(a),std::end(a),std::begin(b));
for(auto e:b) cout<<e<<" ";     // 输出 1,2,3,4,5
```

上述程序中，copy算法将数组a区间中的数复制到以begin(b)开始的区间中去.

### 使用array容器 (C++11)

```
std::array<int,5> arr = {1,2,3,4,5};
std::array<int,5> copy;
copy = arr;      // 将arr中的元素复制到copy中
arr[0] = 100;
for(auto e:copy) cout<<e<<" ";      //输出 1,2,3,4,5
```



## C 风格的复制操作

### 使用memcpy()

```c++
int arr[] = {1,2,3,4,5};
int copy[5];
int len = sizeof(arr) / sizeof(arr[0]);
memcpy(copy,arr,len*sizeof(int));   // 输出 1,2,3,4,5
for(auto e:copy) cout<<e<<" ";
```

注意：memcpy()函数的第三个参数表示的是要复制的字节数，而不是要复制的元素数目。至于这样做的原因，可以先来看memcpy()的原型:
`void* memcpy(void* destination,const void* source,size_t num);`

由memcpy()的函数原型可以看到，该函数的前两个参数的类型是void*类型，这样做是为了使memcpy()可以作用于任何类型的指针。

但这样做又导致了一个问题，即memcpy()不知道传入数组的每个元素用多少字节来表示。也正是因为这个原因，使得memcpy()的第三个参数不能是要复制的元素个数，而是要复制的字节数。

### 使用memmove()

该函数与memcpy()类似，只是memmove允许目的位置和源位置重叠，示例如下:

```c++
int arr[] = {1,2,3,4,5,6,7,8};
memmove(arr+3,arr+1,sizeof(int)*5);
for(auto e:arr) cout<<e<<" ";       // 输出 1,2,3,2,3,4,5,6
```

注意：上面的程序中，如果将memmove()换作memcpy()可能也会正常工作，但是这种行为是不可预计的，当目的位置与源位置存在重叠时，应当使用memmove()。

### 测试实例

```c++
#include <iostream>

using namespace std;
int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int b[10] = { 0 };
    int c[10] = { 0 };
    //copy
    copy(begin(a), end(a), begin(b));
    for (auto i : b)
        cout << i << " ";
    cout << endl;
    //memcpy
    memcpy(c, a, sizeof(a));
    for (auto i : c)
        cout << i << " ";
    cout << endl;
    //memmove 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    memmove(arr + 3, arr + 1, sizeof(int)* 5);
    for (auto e : arr) 
        cout << e << " ";
    cout << endl;
    system("pause");
    return 0;
}
```



## C++中的string



头文件<string>

### 一

```C++
string str = "hello world";

cout<<str.at(index)<<endl;
cout<<str[index]<<endl;

cout<<str.front()<<endl;
cout<<str.back()<<endl;

for(int i=0;i<str.size();i++){
    cout<<str[i]<<" ";
}
for(string::iterator it=string.begin();it! = str.end();it++){//迭代器
    cout<<*it<<" ";
}

str.size();
str.capacity();//容量

str.resize();//短就截取，长就用第二个参数填充

str.clear();

str.empty();
```

### 二

```C++
//string 的修改
string a="111";
string b="222";

cout<<a+b<<endl;
//a=a+b 等同于 a.append(b);

a.append(b);
a.append(b,index,length);//索引，长度

a.push_back();

a.assign(b);//把b命名为a,高效
a.assign(b,index,length);

a.insert(index,"内容");
a.insert(index1,"内容",index2,length);

a.replace(index,length,"内容");//索引开始，长度，替换成内容

a.swap(b);//交换

a.erase(index,length);//内容换为空,length默认为1

a.pop_back();//去掉最后一个
```

### 三

```c++
//字符串转数组
string num = "2020";
int a = atoi(num.c_str());
cout<<a<<endl;

int found = a.find(b);//第一次位置出现的索引
if(found!=string::npos){
    cout<<"first:"<<found<<endl;
}
int found = a.find(b,found+1);//第二个参数是开始找的位置
if(found!=string::npos){
    cout<<"second:"<<found<<endl;
}

//rfind();反过来找

a.substr(6);//切片，不改变自身
b = a.substr(index,length);

a.compare(b);//比较
a.compare(index,length,b);
```

### 四

```C++
getline(cin,str);
```

