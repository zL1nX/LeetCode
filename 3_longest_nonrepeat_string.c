#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lengthOfLongestSubstring(char *s)
{
    if(strlen(s)==0)
        return 0;
    int show[128]={ 0 };
    int i=0,start = 0,current_len,m=0;
    int slen = strlen(s);
    while (i < slen && start < slen)
    {
        if(show[s[start]] == 1)
        {
            show[s[i]] = 0;
            i++;
        }
        else
        {
            show[s[start++]] = 1;
            current_len = start - i;
            m = current_len > m ? current_len : m;
        }
    }
    return m;
}
/*int lengthOfLongestSubstring(char* s)
	{
		int Hash[128] = { 0 }; //因为不知道字符串李哪种符号（有可能不是字母），ASCII使用128
		int max = 0;
		int start = 0;
		int i = 0;
		int length = strlen(s);
		while (i < length && start < length)
		{
		    printf("%d %d %d %d\n",i,start,Hash[start],Hash[i]);
			if (Hash[s[start]] == 0) {
				Hash[s[start]] = 1;
				start++;
				max = (start - i) > max ? (start - i) : max;
			}
			else {
				Hash[s[i]] = 0;
				i++;
			}

		}
		return max;
	}*/
/*int lengthOfLongestSubstring(char *s)
{
    if(strlen(s)==0)
        return 0;
    int len_res[strlen(s)];
    int show[strlen(s)];
    int i,j=0,m=0;
    memset(len_res,0,strlen(s)*sizeof(int));//,show[i] = 0;
    for(i=0;i<strlen(s);s++)
    {
        if(show[s[i]]==1)
        {
            memset(show,0,strlen(s)*sizeof(int));
            len_res[++j]=1;
            continue;
        }
        else
        {
            show[s[i]] = 1;
            len_res[j]++;
        }
    }
    printf("%d %d",j,strlen(j));
    for(i=0;i<j;i++)
    {
        if(m < len_res[i])
            m = len_res[i];
    }
    return m;
}*/
/*int main()
{
    char str[1000];
    int res;
    scanf("%s",str);
    res = lengthOfLongestSubstring(str);
    printf("%d\n",res);
    return 0;
}*/
