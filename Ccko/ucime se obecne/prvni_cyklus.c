//prvni_cyklus
#include <stdio.h>


/*
int main() {
    for (char i = 1; i >= 0; ++i)
        printf("%d", i);
    return 0;



}
*/

/*
int main() { 
    char i = 1;
    do { 
        printf("%d, i");
        ++i; 
        if (i < 0)
            break;
    }

    return 0;

}
*/

int main() {
    char i = 1;
    while(1) {
        printf("%d", i);
        ++i;
        if (i < 0)
        break;
    }
    return 0;
}