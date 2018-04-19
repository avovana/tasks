// Task - http://acm.timus.ru/problem.aspx?space=1&num=2001&locale=en

#include <stdio.h>

int main()
{
    int bucket1berry1;
    int bucket2berry2;
    
    scanf("%d", &bucket1berry1);
    scanf("%d", &bucket2berry2);
    
    int bucket1berry1berry2;
    int bucket2;

    scanf("%d", &bucket1berry1berry2);
    scanf("%d", &bucket2);
    
    int bucket1;
    int bucket2berry2berry1;

    scanf("%d", &bucket1);
    scanf("%d", &bucket2berry2berry1);
    
    int berry1 = bucket1berry1 - bucket1;
    int berry2 = bucket2berry2 - bucket2;
    
    printf("%d %d", berry1, berry2);
}