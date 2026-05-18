#include <stdio.h>
#include <stdlib.h>

void print_array(char arr[], int size);
void load_pattern(void);

char arr_input[100];
int i = 0;

/* The main program */
int main(int argc, char *argv[])
{
  int arr_quantity[26] = {0};
   //char arr_pattern[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  printf("Hello, World!\n");
  load_pattern();
  for (int j = 0; j < i; j++) {
    switch (arr_input[j])
    {
    case 'a':
      arr_quantity[0]++;
      break;
    case 'b':
      arr_quantity[1]++;
      break;
    case 'c':
      arr_quantity[2]++;
      break;
    case 'd':
      arr_quantity[3]++;
      break;
    
    default:
      break;
    }
  }
  //print arr_input
  print_array(arr_input, i);
  
  return 0;
}

void print_array(char arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");
}


void load_pattern(void) {
  int c;
  while ((c = getchar()) != '\n')
  {
    arr_input[i] = c;
    i++;
    //putchar(c);
  }
}




