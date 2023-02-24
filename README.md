# Calculator

:star2:大三上期面向对象期末大作业，以下是最后实现的效果图:star2:：

<img src="C:\Users\20826\Documents\GitHub\Calculator\img\image-20230224153506975.png" alt="image-20230224153506975" style="zoom: 50%;" />

## 作业内容

**简单的科学计算器**

**难度权重：**70%

**设计目的：**

1.熟悉MFC图形界面设计流程；

2.熟悉MFC主要控件（按钮、编辑框、菜单等）的使用方法

**设计要求：**

1.利用MFC实现一个类似Windows附件计算器的图形用户界面的科学计算器程序；

2.实现基本的加、减、乘、除算术运算；

3.实现包括正弦（sin）、余弦（cos）、正切（tan）、开方、乘方、指数（ex）、对数（ln）等科学计算；

4.实现阶乘计算（n！）；

5.实现数据的存储和统计功能，即通过类似Windows计算器中的MS按钮将当前计算结果保存、MC按钮清除存储数据，保存多个结果后，可以计算最大值、最小值、中值、平均值、标准差、累加、累乘等；

6.有一个清除按钮可以清除当前输入；

7.输入算式的时候可以带括号。

**参考与提示：**

1.关于计算器的数据存储与统计功能，可以使用MFC或C++STL的向量或列表来保存数据。

**一点也不简单**:dizzy_face:

## 实现流程

### 界面重构

这里原来的界面太丑了:sweat:，这里仿了一个IOS风格的计算器出来。主要是改了按钮的样子

<img src="C:\Users\20826\Documents\GitHub\Calculator\img\image-20230224154238773.png" alt="image-20230224154238773" style="zoom:50%;" />

原理是继承`CButton`类然后对窗口，字体，有效范围，背景根据不同的按钮类型自定义新的（搜了好久，具体怎么操作的最后也忘了:yum:）。就是添加了下面的内容。主要是在`DrawItem`函数中添加各种规则。

```c++
#pragma once
#include "afxwin.h"
class CRoundButton :
	public CButton
{
public:
	CRoundButton(const char a);
	~CRoundButton();
	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
private:
	char kind;
};
```

### 计算器算法

这里最后被现实打败，我还是太菜了:frowning:。主要是太久没写过这些东西了。我大概构思了流程，一个是高精度的四则运算，不仅要满足整形还有浮点型！！！一个就是用栈去实现中缀表达式转后缀表达式。这里还有个很大问题就是其中还包括三角函数等科学计算，这对转换的规则影响很大。具体怎么实现，反正我连四则运算写出来都是bug:shit:。

<img src="C:\Users\20826\Documents\GitHub\Calculator\img\image-20230224155419540.png" alt="image-20230224155419540" style="zoom: 25%;" />

这依托答辩就看个乐就行了。这里主要是重构各种运算符，但是还有考虑到小数点对齐，进位之类的，折腾了半天，加法都还有bug:shit:。

最后只能从python方面解决问题。。。。

首先python这个加减乘除都不要考虑数据类型，这就完胜c++其次在math库中有一个`eval`函数传入str类型参数，直接返回表达式结果？？？？一个字6，这一刻还说什么Python效率低，再怎么样效率也比我写的答辩效率高。一次，只要对传入的数据简单处理一下就行。

```Python
def Calculate(expression):
    try:
        substring = 'sin'
        newstring = 'math.sin'
        expression = expression.replace(substring, newstring)
        substring = 'cos'
        newstring = 'math.cos'
        expression = expression.replace(substring, newstring)
        substring = 'tan'
        newstring = 'math.tan'
        expression = expression.replace(substring, newstring)
        substring = 'pi'
        newstring = 'math.pi'
        expression = expression.replace(substring, newstring)
        substring = '#2'
        newstring = '**0.5'
        expression = expression.replace(substring, newstring)
        substring = '^2'
        newstring = '**2'
        expression = expression.replace(substring, newstring)
        substring = 'ln'
        newstring = 'math.log'
        expression = expression.replace(substring, newstring)
        substring = 'e^'
        newstring = 'math.exp'
        expression = expression.replace(substring, newstring)
        expression=process_factorial(expression)
        #print(expression)
        substring = '!'
        newstring = 'math.factorial('
        expression = expression.replace(substring, newstring)
        
        result = eval(expression)
        return  str(result)

    except:
        return "Expression Error"
```

真就是简单处理一下就行:pray:。。。。

这里我发现python算999的阶乘也能秒出答案，而且也不会有溢出。只能说Python yyds:thumbsup:

这里可能就有个问题，这不是C++开发吗。引用老师的话，我们学的是面向对象什么语音都无所谓:satisfied:。凭借我一坤年的openCV开发经验。这里只要在项目属性里添加库目录，包含目录，附加依赖项，我就能调用Python.h。首先就conda创建一个Python环境,然后把这个环境的文件夹的include和lib添加进来，然后再把它添加到系统环境变量下。折腾了半天，这不是简简单单。

一顿操作之后我就能使用c++调用python的函数了。

这里是python环境的初始化，如果在别的电脑上应该改成对应的即可,在CalculatorDlg.cpp的160行

```c++
Py_SetPythonHome((wchar_t*)L"C:\\Users\\20826\\.conda\\envs\\cplusplus");
Py_Initialize();
PyRun_SimpleString("import sys");	PyRun_SimpleString("sys.path.append(r'C:\\Users\\20826\\Documents\\GitHub\\Calculator')");
pModule = PyImport_ImportModule("src");
pFunc = PyObject_GetAttrString(pModule, "Calculate");
```

然后还有个点就是python和c++的数据类型转换。这里这个函数不接受string类型，只有char*才能生效。所以这样来回总共转了4次

```c++
void CCalculatorDlg::OnBnClickedButton20()
{
	char* p = (char*)nowstr.data();
	pParams = Py_BuildValue("(s)",p);
	pResult = PyObject_CallObject(pFunc, pParams);
	char *res= NULL;
	PyArg_Parse(pResult, "s", &res);
	nowstr =res;
	CString str(nowstr.c_str());
	outEDIT.SetWindowText(str);
}
```

其他就是为了让计算器能给人用，还要添加亿点点细节。

## 总结

求求老师给个高分吧，我已经尽力了。

<video src="C:\Users\20826\Documents\WeChat Files\wxid_nxjnrzh6781g22\FileStorage\Video\2023-02\5a5c2d59a660ccc7fc3bfe2c4bd942e1.mp4"></video>

<video src="C:\Users\20826\Documents\WeChat Files\wxid_nxjnrzh6781g22\FileStorage\Video\2023-02\7f3281808246f375877d0bb32d044e6b.mp4"></video>

<video src="C:\Users\20826\Documents\WeChat Files\wxid_nxjnrzh6781g22\FileStorage\Video\2023-02\206c3aa76616605e1cf81ed90c9b1bd7.mp4"></video>

