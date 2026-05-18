#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    
    //a need to explain const ptr and ptr const a
    
    // In C, a "const pointer" (ptr const) is a pointer that cannot change the address it points to, but the value at that address can be modified. For example:
    int hodnota = 10;
    int *const pojntr = &hodnota; // ptr is a const pointer to an int
    *pojntr = 20; // This is allowed, we can change the value at the address
    // ptr = &anotherValue; // This would be an error, we cannot change the pointer
    
    // On the other hand, a "pointer to const" (const ptr) is a pointer that can point to different addresses, but the value at those addresses cannot be modified through that pointer. For example:
    int value1 = 10;
    int value2 = 20;
    const int *ptr = &value1; // ptr is a pointer to a const int
    // *ptr = 30; // This would be an error, we cannot change the value
    ptr = &value2; // This is allowed, we can change where the pointer points
    *ptr = 40; // This would be an error, we cannot change the value through this pointer
    
    return 0;
}

