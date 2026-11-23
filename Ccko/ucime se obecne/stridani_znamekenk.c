//stridani_znamenek




#include <stdio.h>
#include <string.h>

#define OPPOSITE(i) pow( -1, i)
#define OPPOSITE1(a) (-1) * a
#define OPPOSITE2(a) a== 1 ? -1 : 1      // ? znamena then
#define OPPOSITE3(a) 

int main(){
    int a = 1;
    for (int i = 0; i < 1000; ++i) {
        printf("%d", a);
        a = OPPOSITE3(a);
    }
}