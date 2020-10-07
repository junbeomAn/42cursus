#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
  char *new_str;
  size_t i;
  
  if (s1 && s2)
  {
    if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
      return (NULL);
    i = 0;
    while (*s1)
      new_str[i++] = *s1++;
    while (*s2)
      new_str[i++] = *s2++;
    new_str[i] = '\0';
    return (new_str);
  }
  return (NULL);  
}
// 처음엔 strlcat 두번으로 하려 했으나, strlcat은 new_str의 끝을 알아야하는데
// malloc으로 할당한 메모리공간인 new_str은 처음에 어떻게 초기화 될지 보장할 수 없다. 
// 그러므로 그냥 str값을 복사하는 strlcpy와 그 뒤를 이어주는 strlcat을 쓸수도 있을것으로 보인다.