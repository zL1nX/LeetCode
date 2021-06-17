/*
有效数字（按顺序）可以分成以下几个部分：

一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分有效数字列举如下：

["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
部分无效数字列举如下：

["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。

 

示例 1：

输入：s = "0"
输出：true
示例 2：

输入：s = "e"
输出：false
示例 3：

输入：s = "."
输出：false
示例 4：

输入：s = ".1"
输出：true
 

提示：

1 <= s.length <= 20
s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，或者点 '.' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <unordered_map>
using namespace std;

enum State{
    STATE_INITIAL,
    STATE_INT_SIGN,
    STATE_INTEGER,
    STATE_POINT,
    STATE_POINT_WITHOUT_INT,
    STATE_FLOAT,
    STATE_EXP,
    STATE_EXP_SIGN,
    STATE_EXP_INT,
    STATE_END

};

enum CharType{
    CHAR_NUMBER,
    CHAR_POINT,
    CHAR_SIGN,
    CHAR_EXP,
    CHAR_ILLEGAL
};

CharType convert(char s)
{
    if(s >= '0' && s <= '9')
    {
        return CHAR_NUMBER;
    }
    else if(s == '.')
    {
        return CHAR_POINT;
    }
    else if(s == '+' || s == '-')
    {
        return CHAR_SIGN;
    }
    else if(s == 'e' || s == 'E')
    {
        return CHAR_EXP;
    }
    else
    {
        return CHAR_ILLEGAL;
    }  
}

bool isNumber(string s) 
{
    int n = s.length();
    unordered_map<State, unordered_map<CharType, State>> transfer = {
        {
            STATE_INITIAL,{
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                {CHAR_SIGN, STATE_INT_SIGN}
            }
        },
        {
            STATE_INT_SIGN,{
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT_WITHOUT_INT}
            }
        },
        {
            STATE_INTEGER,{
                {CHAR_NUMBER, STATE_INTEGER},
                {CHAR_POINT, STATE_POINT},
                {CHAR_EXP, STATE_EXP},
            }
        },
        {
            STATE_POINT,{
                {CHAR_NUMBER, STATE_FLOAT},
                {CHAR_EXP, STATE_EXP},
            }
        },
        {
            STATE_POINT_WITHOUT_INT,{
                {CHAR_NUMBER, STATE_FLOAT},
            }
        },
        {
            STATE_EXP,{
                {CHAR_SIGN, STATE_EXP_SIGN},
                {CHAR_NUMBER, STATE_EXP_INT}
            }
        },
        {
            STATE_FLOAT,{
                {CHAR_EXP, STATE_EXP},
                {CHAR_NUMBER, STATE_FLOAT}
            }
        },
        {
            STATE_EXP_SIGN,{
                {CHAR_NUMBER, STATE_EXP_INT},
            }
        },
        {
            STATE_EXP_INT,{
                {CHAR_NUMBER, STATE_EXP_INT},
            }
        }
        
    };
    State st = STATE_INITIAL;
    for(int i = 0; i < n; i++)
    {
        CharType ct = convert(s[i]);
        if(transfer[st].find(ct) == transfer[st].end())
        {
            return false;
        }
        st = transfer[st][ct];
    }
    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FLOAT || st == STATE_EXP_INT || st == STATE_END;

}

// 状态机牛逼

// 无所谓也有点累

// enum + unordered map写状态机这个写法学习了