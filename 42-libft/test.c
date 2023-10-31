#include <string.h>
#include <stdio.h>




size_t ft_strlcat2(char *dst, const char *src, size_t dstsize)
{
    int i;
    size_t dstlen;
    size_t srclen;
    
    i = 0;
    dstlen = strlen(dst);
    srclen = strlen(src);
    if (dstsize == 0 || dstlen > dstsize)
        return (dstsize + srclen);
    while (*dst)
        dst++;
    while ((i < (int) (dstsize - dstlen - 1)) && (*dst++ = *src++))
        i++;
    return (dstlen + srclen);
}

int main(void)
{
    char dst[20] = "Hello";
    char dst2[20] = "Hello";
    const char *src = " , world";
    // int nb = ft_strlcat(dst, src, 20);
    // printf("%s\n", dst);
    // printf("%d\n", nb);

    int nb2 = ft_strlcat2(dst, src, 4);
    printf("%s\n", dst);
    printf("%d\n", nb2);
}
