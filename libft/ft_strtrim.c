#include "libft.h"

#include <stdio.h>

char *ft_strtrim(char const *s1, char const *set)
{
    char *new_str;
    size_t left;
    size_t right;
    size_t len;

    if (!s1)
        return (NULL);
    len = ft_strlen(s1);
    left = 0;
    right = len - 1;
    while (left <= right && s1[left] && ft_strchr(set, s1[left]))
        left++;
    while (left <= right && s1[right] && ft_strchr(set, s1[right]))
        right--;
    if (!(new_str = ft_substr(s1, left, right - left + 1)))
       return (NULL);
    return (new_str);
}
// substr으로 부분문자열을 추출 했다. 왼쪽에서부터 시작 인덱스, 오른쪽부터 끝 인덱스를 구해서
// trim을 수행하는 방법으로 구현함. trim은 일반적으로 단순히 양끝을 의미하는게 아닌, 양끝을 trim하고 
// 새로운 양끝이 또 조건에 부합한다면 trim을 계속 이어서 한다. 