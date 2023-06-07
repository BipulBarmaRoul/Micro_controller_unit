#include <stdio.h>
#include <string.h>

int main()
{
    int a=11, b=22;
    printf("Before=%d %d, ", a, b);
    fn(&a, &b);
    printf("After=%d %d", a, b);
    
    return 0;
}
void fn(int *i, int *j)
{
    *i = 55;
    *j = 65;
}