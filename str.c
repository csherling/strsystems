#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strlen1(char *arr){
  int i = 0;
  while(arr[i] != 0){
    i++;
  }
  return i;
}

char * strcpy1( char *dest, char *source ){
  int i = 0;
  while(source[i] != 0){
    dest[i] = source[i];
    i++;
  }

  return dest;
}

char * strncpy1( char *dest, char *source, int n){
  int i = 0;
  for(; i < n; i++){
    dest[i] = source[i];
  }
  return dest;
}

char * strcat1( char *dest, char *source ){

  int l = strlen1(dest);
  int i = 0;
  while(source[i] != 0){
    dest[i + l] = source[i];
    i++;
  }
  dest[strlen1(source) + l] = 0;

  return dest;

}

char * strncat1( char *dest, char *source, int n){

  int l = strlen1(dest);
  int i = 0;
  for(; i < n; i++){
    dest[i + l] = source[i];
  }
  dest[strlen1(source) + l] = 0;

  return dest;

}

int strcmp1( char *s1, char *s2 ){
  int i = 0;
  while(s1[i] == s2[i]){
    i++;
  }
  return s1[i] - s2[i];
}

int strncmp1( char *s1, char *s2, int n ){
  int i = 0;
  for(; i < n; i++){
    if(s1[i] != s2[i]){
      return s1[i] - s2[i];
    }
  }
  return 0;
}

char * strchr1( char *s, char c ){

  int i = 0;

  for(; i < strlen1(s); i++){
    if(s[i] == c){
      return &s[i];
    }
    if(s[i] == 0){
      return &s[i];
    }
  }

}

char * strstr1( char *s1, char *s2 ){

  int i = 0;
  int l = strlen1(s1) - strlen1(s2);
  int j = 0;

  for(; i < l; i++){
    for(j = i; j < i + strlen1(s2); j++){
      if(j == i + strlen1(s2) - 1 && s1[j] == s2[j]){
	return &s1[i];
      }
    }
  }
  return &s1[i];
}


int main(){
  char arr[20] = "rainbow";

  printf("Length of %s: %lu \n", arr, strlen(arr));//7
  printf("Length of %s mine: %d \n\n", arr, strlen1(arr));//7

  char dest[10];
  char dest1[10];
  char destn[10];
  char destn1[10];

  printf("cpy %s into %s: \n", arr, dest);
  printf("strcpy: %s \n", strcpy(dest, arr)); 
  printf("strcoy: %s \n", dest); 
  printf("strcpy mine: %s \n", strcpy1(dest1, arr)); 
  printf("strcpy mine: %s \n\n", dest1); 

  printf("cpy 2 bytes of %s into %s: \n", arr, destn);
  printf("strncpy: %s \n", strncpy(destn, arr, 2)); 
  printf("strncpy: %s \n", destn); 
  printf("strncpy mine: %s \n", strncpy1(destn1, arr, 2)); 
  printf("strncpy mine: %s \n\n", destn1); 

  char kitten[10] = "hi";
  char kitten1[10] = "hi";
  char kittenn[10] = "hi";
  char kittenn1[10] = "hi";

  printf("cat %s on to %s: \n", arr, kitten);
  printf("strcat: %s \n", strcat(kitten, arr)); 
  printf("strcat: %s \n", kitten); 
  printf("strcat mine: %s \n", strcat1(kitten1, arr)); 
  printf("strcat mine: %s \n\n", kitten1); 

  printf("cat 2 bytes of %s on to %s: \n", arr, kittenn);
  printf("strncat: %s \n", strncat(kittenn, arr, 2)); 
  printf("strncat: %s \n", kittenn); 
  printf("strncat mine: %s \n", strncat1(kittenn1, arr, 2)); 
  printf("strncat mine: %s \n\n", kittenn1); 

  char grt[5] = "abc";
  char lss[5] = "abcd";

  printf("compare %s and %s: \n", grt, lss);
  printf("strcmp: %d \n", strcmp(grt, lss)); 
  printf("strcmp mine: %d \n", strcmp1(grt, lss));
  printf("compare first n bytes of %s and %s: \n", grt, lss); 
  printf("strncmp: %d \n", strncmp(grt, lss, 4)); 
  printf("strncmp mine: %d \n\n", strncmp1(grt, lss, 4)); 

  printf("find %s in %s: \n", "c", lss);
  printf("strchr: %s \n", strchr(lss, 'c')); 
  printf("strchr mine: %s \n", strchr1(lss, 'c')); 
  printf("find %s in %s: \n", grt, lss);
  printf("strstr: %s \n", strstr(lss, grt)); 
  printf("strstr mine n: %s \n", strstr1(lss, grt)); 

  return 0;
}
