/*
 *  Author Satvik Dhandhania Date: 10th May 2017
 *  Qventus Telephonic
 */
/* 
Your previous Plain Text content is preserved below:

Write a function that when given a string made up of parenthesis, and
whitespace, returns whether pairs of parenthesis are balanced.

Examples: 

input: "()"
output: true

input: "(( ))"
output: true

input: "())"
output: false


 */

// To execute C, please define "int main()"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
  char ch;
  struct node* next;
}*s;

char topElem(){
  //Check for uninitialized
  if(s != NULL){
   return s->ch; 
  }
  // Default garbage value that will fail any condition
  return 'a';
}


void pop(){ 
  if(s != NULL){
   struct node *s2 = s;
   s = s-> next;
   free(s2);
  }
}  

int push( char ch){
  struct node *newElem = (struct node*) malloc(sizeof(struct node));
  if(s == NULL){
    if(newElem == NULL){
      return 0;
    }
    newElem -> ch = ch;
    newElem->next = NULL; 
  } else {
    if(newElem == NULL){
      return 0;
    }
    newElem -> ch = ch;
    newElem->next = s;
  }
  s = newElem; 
  return 1;
}


int checkParanthesis(char *string){
  int len = strlen(string);
  for(int i=0;i<len;i++){
    if((string[i] == '(') ||(string[i] == '{') ||(string[i] == '[')){    
      push(string[i]);
    }
    if((string[i] == '}') ||(string[i] == ']') ||(string[i] == ')')){  
     char c = topElem();
     if(c == '(' && string[i] != ')'){
       return 0;
     } else if(c == '{' && string[i] != '}'){
       return 0;
     } else if(c == '[' && string[i] != ']'){
       return 0;
     } else {
       if(c == 'a'){
        return 0; 
       }
      pop();
     }
    }
  }
  
  if(s == NULL){
     return 1;
  }
  return 0;
}


int main() {
  char string[1000];
  scanf("%s",string);
  
  s = NULL;
  if(checkParanthesis(string)){
    printf("Balanced");
  } 
  else {
    printf("Unbalanced");
  }
  return 0;
}


