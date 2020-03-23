#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

    struct s_type {
        int i;
        char str[80];
    } s,*p;

    struct tm *systime;
    time_t t;

    p = &s;
    s.i = 11;
    p->i = 1;
    strcpy(p->str,"I like structures");

    printf("%d %s",s.i,s.str);

     t = time(NULL);
     systime = localtime(&t);

     printf("Time is %.2d:%.2d:%.2d\n",
            systime->tm_hour,systime->tm_min,
            systime->tm_sec);
     printf("Date: %.2d/%.2d/%.2d",
            systime->tm_mon+1,systime->tm_mday,
            systime->tm_year);


    return 0;
}
