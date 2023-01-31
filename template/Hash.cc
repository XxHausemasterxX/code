#include <iostream>
#include <string>
#include <algorithm>
#define MOD 1073807359ll
#define BASE 257ll
#define N 10005ull

typedef long long ll;
using namespace std;
string s[N]; unsigned long long Hash[N];


unsigned long long get_hash(const string& s)
{
    unsigned long long res = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        res = (ll)(res * BASE + s[i]) % MOD;
    }
    return res;
}

bool isequal(const string &s, const string &t)
{
    return get_hash(s) == get_hash(t);
}

int main()
{
    int n; int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        Hash[i] = get_hash(s[i]);
    }
    sort(Hash, Hash + n);
    for (int i = 0; i < n; i++)
    {
        if (Hash[i] != Hash[i+1])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}

// https://www.luogu.com.cn/training/list

// # 【模板】字符串哈希

// ## 题目描述

// 如题，给定 $N$ 个字符串（第 $i$ 个字符串长度为 $M_i$，字符串内包含数字、大小写字母，大小写敏感），请求出 $N$ 个字符串中共有多少个不同的字符串。


// **友情提醒：如果真的想好好练习哈希的话，请自觉。**

// ## 输入格式

// 第一行包含一个整数 $N$，为字符串的个数。

// 接下来 $N$ 行每行包含一个字符串，为所提供的字符串。

// ## 输出格式

// 输出包含一行，包含一个整数，为不同的字符串个数。

// ## 样例 #1

// ### 样例输入 #1

// ```
// 5
// abc
// aaaa
// abc
// abcc
// 12345
// ```

// ### 样例输出 #1

// ```
// 4
// ```

// ## 提示

// 对于 $30\%$ 的数据：$N\leq 10$，$M_i≈6$，$Mmax\leq 15$。

// 对于 $70\%$ 的数据：$N\leq 1000$，$M_i≈100$，$Mmax\leq 150$。

// 对于 $100\%$ 的数据：$N\leq 10000$，$M_i≈1000$，$Mmax\leq 1500$。


// 样例说明：

// 样例中第一个字符串(abc)和第三个字符串(abc)是一样的，所以所提供字符串的集合为{aaaa,abc,abcc,12345}，故共计4个不同的字符串。


// Tip：
// 感兴趣的话，你们可以先看一看以下三题：

// BZOJ3097：http://www.lydsy.com/JudgeOnline/problem.php?id=3097

// BZOJ3098：http://www.lydsy.com/JudgeOnline/problem.php?id=3098

// BZOJ3099：http://www.lydsy.com/JudgeOnline/problem.php?id=3099

// 如果你仔细研究过了（或者至少仔细看过AC人数的话），我想你一定会明白字符串哈希的正确姿势的^\_^