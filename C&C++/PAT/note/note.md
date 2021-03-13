# PAT 刷题

## 基础语法

`#include <stdio.h>`和`#include <cstdio>`等价

`#include <math.h>`和`#include <cmath>`等价

`#include <string.h>`和`#include <cstring>`等价

### 数据类型和定义

int 型占 32bit，取值范围是（`(1<<31)-1`），绝对值在$10^9$范围以内的整数都可以定义成 int 型。

绝对值在$10^{18}$以内的可以用 long long 型来存放。long long 型如果赋大于 int 范围的初值，需要在初值后面加上 LL，否则会编译错误。

float 型的有效精度大概是 6~7 位；doule 型的有效精度大概是 15~16 位。因此对于浮点型来说，不要使用 float。

bool 型在 C++中可以直接使用，在 C 中必须添加 stdbool.h 头文件。

定义常量：

```cpp
 // 方法一：
 #define pi 3.14
 // 方法二：
 const double pi=3.14;
```

define 可以定义任何语句或片段：

```cpp
 #define ADD(a, b) ((a)+(b))
```

i++：先使用 i 再将 i 加 1

++i：先将 i 加 1 再使用 i

### new 数组 vs.静态数组

```c++
bool* array = new bool[10];   //未初始化
bool* array = new bool[10](); //初始化为0
string* str1 = new string[5]; //5个空string，string是对象，会调用其构造函数进行默认初始化
string* str2 = new string[5]();    //5个空string
string* ps3 = new string[5]{"a", "b", "c"}; //前3个进行列表初始化，后2个进行值初始化（为空）

// 释放空间：
delete p;    //p指向一个动态分配的对象（或空）
delete [] p; //p指向一个动态分配的数组（或空）
```

- 静态数据：数组的长度必须为常量。

 int a[10]；

 int a[]={1,2,3};

- 动态数组：数组的大小可以为变量。

 int len;

 int \*a=new int[len];

 delete a;

new 还需要你 delete，是在堆分配空间，效率较低；而[]直接在栈上分配，会自动释放，效率高，但是栈空间有限。

对静态数组名进行 sizeof 运算时，结果是整个数组占用空间的大小；

对动态数组名进行 sizeof 运算时，结果是数组地址占用空间的大小；

静态数组作为函数参数时，在函数内对数组名进行 sizeof 运算，结果为 4，因为此时数组名代表的指针即一个地址，占用 4 个字节的内存(因为在传递数组名的参数时，编译器对数组的长度不做检查)。对动态数组的函数名，无论何时进行 sizeof 运算，得到的结果都是 4.

函数声明的静态数组不可能通过函数返回，因为生存期的问题，函数调用完其内部变量占用的内存就被释放了。如果想通过函数返回一个数组，可以在函数中用 new 动态创建该数组，然后返回其首地址。

### I/O

scanf 的双引号的内容其实就是整个输入：

```cpp
 // 如果要输入12,18.23,t这种格式的数据：
 int a;
 double b;
 char c;
 scanf("%d,%lf,%c",&a,&b,&c);
 
 // 如果要输入3 4这种用空格隔开的两个数字，两个%d之间可以不加空格
 // 因为除非使用%c把空格按字符读入，scanf对其他格式符的输入是以空白符为结束判断标志的
 int a, b;
 scanf("%d%d", &a, &b);
```

- 三种实用的输出格式：
  1. `%[数字]d`：使不足 num 位的 int 型变量以 num 位进行右对齐输出，高位空格补齐；超过 num 位的保持原样
  2. `%0[数字]d`：使不足 num 位的 int 型变量以 num 位进行右对齐输出，高位用 0 补齐；超过 num 位的保持原样
  3. `%.[数字]f`：让浮点数保留 num 位小数输出

getchar()和 putchar()：getchar 可以识别换行符。

```cpp
 char c1, c2;
 c1 = getchar();
 c2 = getchar();
 putchar();
 putchar();
```

typedef：给复杂的数据类型起别名

```cpp
 typedef long long LL; // 给long long起个别名LL
```

常用 math 函数：

- fabs(double d)：取绝对值
- floor(double d)：向下取整
- ceil(double d)：向上取整
- pow(double r, double p)：返回$r^q$
- sqrt(double d)
- log(double d)：返回 d 的以自然对数为底的对数
- sin(),cos(),tan()：参数是弧度制
- asin,acos,atan
- round(double d)：四舍五入取整，但是返回类型是 double

如果数组大小较大（大概$10^6$级别），则需要将其定义在主函数外，否则会使程序异常退出，因为函数内部申请的局部变量来自系统栈，允许申请的空间较小；函数外部申请的全局变量来自静态存储区，允许申请的空间较大。

memset()：对数组中的每一个元素赋以相同的值。

- memset 是按字节赋值，即每个字节赋同样的值，所以赋值为-1 时数组是全-1，赋值为 0 时数组是全 0，但是其他值就不一定
- 格式：`memset(数组名, 值, sizeof(数组名));`
- 需要添加`<string.h>`头文件

### 输出浮点数

- 保留 n 位数：

  ```cpp
  #include <iomanip>

  double d=3.1415926;
  cout<<fixed<<setprecision(3)<<d;  // 保留3位小数（fix表示从小数点右边开始计数输入）
  cout<<setprecision(2)<<d;  // 保留3位有效位

  // 也可以先设置要输出的位数，后面直接cout就行
  cout<<fixed<<setprecision(3);
  cout<<d;
  ```

### 字符串(数组)操作

字符数组的输入输出：

1. scanf 输入，printf 输出

   ```cpp
    #include <stdio.h>
    
    int main(){
        char str[10];
        scanf("%s", str);
        printf("%s", str);
        return 0;
    }
   ```

2. getchar 输入，putchar 输出
3. gets 输入，puts 输出。gets 识别换行符作为输入结束，puts 输出字符串后会自动输出一个换行

因为字符数组的结束符`\0`，所以字符数组的长度一定要比实际存储字符串的长度至少多 1。

如果不是用 scanf 函数的%s 格式或 gets 函数输入字符串，那就一定要在输入的每个字符串后加入`\0`，否则 printf 和 puts 输出字符串会因无法识别字符串末尾而输出一大堆乱码。

sscanf 与 sprintf：

- scanf 和 printf 的输入和输出固定为屏幕
- sscanf 和 sprintf 可以指定为字符数组：

  ```cpp
   sscanf(str, "%d", &n); // 将str的内容以%d的形式写到n中
   sprintf(str, "%d", n); // 将n的内容以%d的形式写到str中
  ```

数组作为函数参数：

- 第一维不需要填大小，第二维需要填长度
- `void(int a[], int b[][5]);`

### 指针和引用

指针就是变量的地址，实际上是一个 unsigned 类型的整数，在变量前面加上&，就表示变量的地址。

指针变量：存放指针的变量。在某种数据类型后加星号来表示这是一个指针变量。

```cpp
 int* p;
 double* p;
 // 星号可以放在数据类型之后或变量名之前。C++习惯于放在数据类型之后。
 
 // 如果一次有好几个同种类型的指针变量要同时定义，星号只会结合第一个变量名
 int* p1, p2; // p2是int型
 int *p1, *p2;
```

两个 int 型的指针相减，等价于在求两个指针之间相差了几个 int。

**引用：**（C++语法）

- 引用不产生副本，只是给原变量起了个别名，对引用变量的操作就是对原变量的操作
- 不管是否使用引用，函数的参数名和实际传入的参数名可以不同
- 使用：在函数的参数类型后面加个&（一般写在变量前）
- 注意：

  - 引用不是取地址的意思。
  - 因为引用是产生变量的别名，所以常量不可使用引用。

  ```cpp
  #include <stdio.h>
  void change(int &x){
      x = 1;
  }
  int main(){
      int a = 10;
      change(a);
      printf("%d\n", x);
    return 0;
  }

  // 指针的引用
  void swap(int *&p1, int *&p2)
  {
      int *tmp = p1;
      p1 = p2;
      p2 = tmp;
  }

  int main()
  {
      int a = 1, b = 2;
      int *p1 = &a, *p2 = &b;
      swap(p1, p2);  // 这里不能写成swap(&a, &b)，因为常量不能使用引用
      printf("a = %d, b = %d", *p1, *p2); // a = 2, b = 1
      return 0;
  }
  ```

### 结构体

- 定义格式：

  ```cpp
  struct Name{
    // ...
  };
  struct student{
      // ...
  }Alice, Bob, stu[1000];
  ```

- 结构体内可以定义除了自己本身之外的任何数据类型（可以定义自身类型的指针变量）
- 访问格式：`.`操作和`>`操作

  ```cpp
  struct student{
      // ...
  }stu, *p;

  stu.name;
  p->name;
  ```

- 初始化：

  ```cpp
  // 使用构造函数：定义在结构体中，不需要写返回类型，函数名与结构体名相同
  struct studentInfo{
      int id;
      char gender;
      // 空参，如果不定义的话就不能不初始化就定义结构体变量。如果不定义构造函数的话会默认生成一个空参的构造函数
      studentInfo(){};
      // 写法1：
      studentInfo(int _id, char _gender) : id(_id), gender(_gender){};
      // 写法2：
      studentInfo(int _id, char _gender){
          id = _id;
          gender = _gender;
      }
  };
  ```

## 补充

### cin 与 cout

需要添加头文件`<iostream>`和`using namespace std;`才能使用。

- 输出：cin
- 输入：cout

  e.g.

  ```cpp
  int n;
  double d;
  cin >> n;
  cin >> n >> d;
  // 读入一整行
  char str[100];
  cin.getline(str, 100);

  // 使用string
  string str;
  getline(cin, str);

  cout << n << db << endl; // endl表示换行
  ```

### 浮点数的比较

因为浮点数在计算机中的存储不总是精确的，所以需要引入一个极小数 eps(eps=$10^{-8}$)来对这种误差进行修正。

```cpp
const double eps = 1e-8;
// 1. 等于
#define Equ(a, b) ((fabs((a)-(b)))<(eps))
// 2. 大于
#define More(a, b) (((a)-(b))>(eps))
// 3. 小于
#define Less(a, b) (((a)-(b))<(-eps))
// 4. 大于等于
#define MoreEqu(a, b) (((a)-(b))>(-eps))
// 5. 小于等于
#define LessEqu(a, b) (((a)-(b))<(eps))
```

## STL

C++标准模板库(Standard Template Library, STL)

- 反向迭代器遍历

  ```c++
  int arr[] = {1, 2, 3, 4, 5};
  vector<int> vi(arr, arr + 5);
  for (auto it = vi.rbegin(); it != vi.rend(); ++it)
       cout << *it << " "; // 5 4 3 2 1
  ```

### vector

```cpp
#include <vector>
using namespace std;

// 1. 定义
// 定义vector变量
vector<int> name;
vector<char> name;
vector<vector<int> > name; // 在>>符号之间加上空格，因为一些使用C++11之前标准的编译器会把它视为移位操作
// 定义vector数组
vector<int> arr[100];

// 2. 访问
	// 1. 通过下标访问
	vi[1];
	// 2. 通过迭代器访问：vector<typename>::iterator it;
	// it指向vi的首元素的地址
	vector<int>::iterator it = vi.begin();
	*(it+1); // 等价于vi[i]，即*(vi.begin()+i)
						// 除了vector和string之外的STL容器都不支持*(it+i)的访问方式
	for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++){
	    printf("%d ",*it);
	}

// 3. 常用函数：
vi.end();
vi.push_back(x); // 在vector后面添加一个元素x
vi.pop_back();   // 删除vector的尾元素
vi.size();       // 获得vector中元素的个数
vi.clear();      // 清空vector中的所有元素
vi.insert(it, x);// 向vector的任意迭代器it处插入一个元素x
vi.erase(it);    // 删除迭代器为it处的元素
vi.erase(first, last); // 删除[first, last)内的所有元素
```

### set

是一个内部自动有序且不含重复元素的容器。

```cpp
#include <set>
using namespace std;

// 1. 定义
set<int> name;
// 2. 访问：set只能通过迭代器访问
set<int>::iterator it;
for (set<int>::iterator it=st.begin(); it != st.end(); it++){
    printf("%d ", *it);
}

// 3. 函数
s.insert(x); // 将x插入set容器中，且自动递增排序和去重，时间复杂度O(logN)
s.find(x); // 返回set中对应值为x的迭代器，时间复杂度O(logN)
s.erase(it); // it为所需要删除元素的迭代器，O(1)
s.erase(x); // x为所需要的删除元素的值，O(logN)
s.erase(first, last); // 删除[first, last)内的所有元素（迭代器）
s.size();
s.clear();
```

multiset：处理不唯一的情况

unordered_set：只去重不排序，比 set 速度快

### string

```cpp
#include <string>
using namespace std;

// 1. 定义
string str = "abcd";

// 2. 访问
// 通过下标访问
str[1];
cout << str;    // 输出整个字符串
printf("%s", str.c_str());   // 用printf输出string类型
cin >> str;     // 输入整个字符串
// 通过迭代器访问
for(string::iterator it = str.begin(); it != str.end(); it++)
    printf("%c ", *it);
str.begin()+3; // 等价于str[3]

// 3. 函数
str3 = str1+str2; // 将str1和str2拼接，赋值给str3
str1 += str2;
str.length();
str.size();
str.insert(pos, string);  // 在pos位置插入字符串string
str.insert(it, it2, it3); // it为原字符串的欲插入位置，it2和it3位待插字符串的首位迭代器，即串[it2, it3)将被插在it的位置上
str.erase(it);          // 删除单个元素
str.erase(first, last); // 删除[first, lasr)（迭代器）
str.erase(pos, length); // 从pos位置开始删，一直删length个字符
str.clear();
str.substr(pos, len); // 返回从pos位置开始，长度为len的子串
str.find(str2);       // 返回str2在str中第一次出现的位置，如果没有返回string::npos
// string::npos是一个常数，值为-1，但本身是unsigned_int类型，所以也可以认为是unsigned_int类型的最大值。常用作find函数失配时的返回值
str.find(str2, pos); // 从str的pos位置开始匹配str2
str.replace(pos, len, str2); // 把str从pos位置开始，长度为len的子串替换为str2
str.replace(it1, it2, str2); // 把str迭代器[it1, it2)范围的子串替换为str2


// 4. 其他操作
1. 正则表达式替换
regex pattern("\\d");
str = regex_replace(str, pattern, ".");
2. 大小写转换
transform(str.begin(), str.end(), str.begin(), ::tolower)
四个输入参数
    1. str.begin()字符串的起始地址；
    2. str.end()字符串的终止地址；
    3. str.begin()是转换之后，输出到原str字符串的起始地址；
    4. 转换操作，可以选择toupper，tolower。
3. 字符串分割
vector<string> items;
stringstream input(str);    // 读取str到字符串流中
string i;
while (getline(input, i, ' '))  // 以空格为分界
    items.push_back(i);
4. 翻转字符串（algorithm中的reverse函数）
string s="abc";
reverse(s.begin(), s.end());
```

- printf 不能直接输出 string 类型变量：**[https://blog.csdn.net/cjolj/article/details/55267660](https://blog.csdn.net/cjolj/article/details/55267660)**

  ```cpp
  // 想要输出string类型变量可以进行如下操作：
  // 方法1：
  string s = “中国”;
  printf("%s", s.c_str()); // string中c_str()成员方法返回当前字符串的首字符地址
  // 方法2：
  cout<<s;
  ```

- 用 scanf 读取 string 类型数据：

  ```cpp
  string a, b, c, d;
  a.resize(6 0); // 需要预先分配空间
  scanf("%s", &a[0]);
  ```

- string 和其他类型转换：

  ```cpp
  string str = to_string(a);  // 将其他类型转换为string

  stoi(s,p,b);  // int
  stol(s,p,b);  // long
  stoul(s,p,b);  // unsigned long
  stoll(s,p,b);  // long long
  stoull(s,p,b);  // unsigned long long
  // 返回s的起始子串(表示整数内容的字符串)的数值
  // b表示转换所用的基数，默认为10(表示十进制)
  // p是size_t的指针，用来保存s中第一个非数值字符的下标，p默认为0，即函数不返回下标.

  stof(s, p); // float
  stod(s, p); // double
  stold(s, p); // long double
  // 返回s的起始子串(表示浮点数内容)的数值
  ```

### map

```cpp
1. 定义
map<type1,type2> mp;
2. 访问
	1. 下标访问
		mp['c'];
	2. 迭代器访问
		for(map<char,int>::iterator it = mp.begin(); it!=map.end(); it++)
				printf("%c %d\n",it->first, it->second);
3. 查找
mp.find(key);
4. 删除
mp.erase(it); // it为迭代器
mp.erase(key); // key为键
mp.erase(first,last); // first为起始迭代器，last为要杉树的区间的末尾迭代器的下一个地址
```

- multimap：一个键可以对应多个值
- unordered_map：可以只映射而不按 key 排序

### queue

```cpp
1. 定义
queue<type> q;
2. 访问
q.front(); // 访问队首元素
q.back();  // 访问队尾元素
3. 操作
q.push(x); // 将x入队
q.pop();   // 令队首元素出队
q.empty(); // 检测queue是否为空，通常在使用front()和pop()前，都要判断一下
q.size();
```

- deque：双端队列

### priority_queue

```cpp
1. 定义
priority_queue<type> q;
2. 操作
q.top(); 	 // 返回队首元素（优先级最高的元素）
q.push(x);	 // 令x入队
q.pop(); 	 // 令队首元素出队
q.empty();	 // 使用top()前，应用empty判断是否为空
q.size()
3. 设置优先级
	3.1 基本数据类型的优先级
			对于int、double、char等，一般数字大的优先级越高，对于基本类型来说，下面两种定义是等价的：
			priority_queue<int> q;
			priority_queue<int,vector<int>,less<int> >q;
				// vector<int>表示承载底层数据结构堆的容器；
				// less<int>是对第一个参数的比较类，less<int>表示数字大的优先级越高，greater<int>表示数字小的优先级越大
	3.2 结构体的优先级：
		1. 在结构体中重载小于号<（不能重载大于号，会编译错误）
		struct fruit{
			string name;
			int price;
			friend bool operator < (fruit f1, fruit f2){
				return f1.price<f2.price; // 价格高的优先级高
			}
		};
		priority_queue<fruit> q;
		2. 在结构体外重载
		struct cpm{
			bool operator () (fruit f1, fruit f2){
				return f1.price>f2.price;
			}
		};
		priority_queue<fruit, vector<fruit>, cmp> q;
		若结构体内的数据较为庞大（出现了字符串or数组），建议使用引用来提高效率，在比较类的参数中加上const和&，e.g.
		bool operator () (const fruit &f1, const fruit &f2){
			return f1.price>f2.price;
		}
```

### stack

```c++
// 1. 定义
stack<type> s;
// 2. 操作
s.top(); // 访问栈顶元素
s.push(x); // 令x入栈
s.pop();  // 弹出栈顶元素
s.empty();
s.size();
// 清空：
s = stack<int>();
```

### pair

当想要将两个元素绑在一起作为一个合成元素，又不想定义结构体时，可以使用 pair 作为一个替代品。

```c++
pair位于头文件<utility>中，但是map内部实现涉及pair，因此添加<map>头文件时，会自动添加<utility>头文件
// 1. 定义
pair<type1, type2> p;
pair<string, int> p("haha", 3); // 定义同时初始化
// 2. 访问/赋值
p.first;
p.second = 4;
p = make_pair("xixi", 4);
p = pair<string, int>("hehe", 3);
// 3. 操作
bool res = p1 > p2; // 先比较first，若first相等再比较second
```

pair 的常见用途：

1. 代替二元结构体，节省编码时间

2. 作为 map 的键值对来进行插入

   ```c++
   map<string, int> mp;
   mp.insert(make_pair("hehe",3));
   for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
       cout<<it->first<<" "<<it->second<<endl;
   ```

## 常用库

### \<cstdint>

```cpp
typedef signed char             int8_t;
typedef short int               int16_t;
typedef int                     int32_t;
typedef long int                int64_t;
typedef long long int           int64_t;

typedef unsigned char           uint8_t;
typedef unsigned short int      uint16_t;
typedef unsigned int            uint32_t;
typedef unsigned long int       uint64_t;
typedef unsigned long long int  uint64_t;
// 格式化输出
uint16_t %hu
uint32_t %u
uint64_t %llu
```

### \<algorithm>

```c++
#include <algorithm>
--------------------------------------
max(x, y);
min(x, y);
abs(x); // x必须是整数
fabs(y); // x是浮点数
--------------------------------------
swap(x, y); // 交换x和y的值
reverse(it1, it2); // 将数组指针在[it1, it2)之间的元素，或者容器的迭代器在此范围内的元素进行翻转
--------------------------------------
next_permutation(); // 给出一个排列在全排列中的下一个序列，当到达最后一个时会返回false
	int a[]={1,2,3};
	do{
        cout<<a[0]<<a[1]<<a[2];
    }while(next_permutaion(a, a+3))
--------------------------------------
fill(it1, it2, value); // 把数组或容器中的[it1,it2)区间赋值为value
--------------------------------------
sort(p1, p2, cmp);
	// p1:首元素地址，p2:尾元素地址的下一个地址
	// cmp:比较函数（可不填，不填时默认递增排序）
实现cmp：
// 1. 基本数据类型数组的排序：若不填比较函数，默认从小到大排序。若要实现从大到小排序：
    bool cmp(int a, int b){
    	return a > b;
	}
	sort(a, a+4, cmp);
// 2. 结构体数组的排序
	struct node{
        int x, y;
    }ssd[10];
	bool cmp(node a, node b){
        return a.x > b.x; // 按照x从大到小排序
    }
	sort(ssd, ssd+3, cmp);
// 3. 容器的排序：只有vector、string、deque可以使用sort。set、map内部用红黑树实现，本身有序，不允许使用sort排序
	bool cmp(int a, int b){
    	return a > b;
	}
	vector<int> vi;
	sort(vi.begin(), vi.end(), cmp);

	bool cmp(string a, string b){
        return a.length()<b.length();
    }
	string arr[];
	sort(arr, arr+2, cmp);
--------------------------------------
// 用于有序数组或容器中
lower_bound(first, last, val);  // 返回[first, last)范围内第一个值大于等于val的元素的位置(指针/迭代器)，若不存在则返回可以插入该元素的位置
upper_bound();  // 返回[first, last)范围内第一个值大于val的元素的位置(指针/迭代器)，若不存在则返回可以插入该元素的位置
若只想获得元素的下标，可以直接令返回值剪去数组首地址

--------------------------------------
max_element(arr,arr+n); // 返回最大元素位置迭代器
*max_element(arr,arr+n); // 得到最大元素值
max_element(arr,arr+n)-arr; // 剪去初始地址得到下标

min_element(arr,arr+n); // 返回最小元素位置迭代器
*min_element(arr,arr+n); // 得到最小元素值
// 存在多个相同大小的元素的时候找到的是第一个
```

### \<cstring>

string.h 头文件：包含了许多用于字符数组的函数。

1. `strlen(char[] str)`：得到字符数组中字符的个数
2. `strcmp(char[] str1, char[] str2)`：返回两个字符串大小的比较结果
3. `strcpy(char[] str1, char[] str2)`：把 str2 复制给 str1
4. `strcat(char[] str1, char[] str2)`：吧 str2 接到 str1 后面

