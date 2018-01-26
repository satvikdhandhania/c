#include <stdio.h>
#include <assert.h>

int strcmp(char *p, char *q);

/*
 * Compares two strings as a dictionary would.
 * Returns:
 *  n < 0 if 'q' would come after 'p' in the dictionary
 *  n > 0 if 'q' would come before 'p' in the dictionary
 *  0 if 'p' and 'q' are identical
 */

/*
   int strcmp(char *p, char *q)
   {
   int i;

   if((p == NULL)|| (q == NULL))
   return 1;

   for(i=0; ;i++){
   if((p[i] == NULL) || (q[i] == NULL)){
   return 1; 
   }

   if(p[i] == q[i])
   continue;  
   else 
   break;
   }

   if(p[i] == q[i])
   return 0;

   if(p[i]<q[i])
   return -1;

   return 1;
   }
   */

int strcmp(char *p, char *q)
{
    while (*p && *q && (*p == *q) ) {
        p++;
        q++;
    }
    return *p - *q;
}
int main() {

    assert(strcmp("aa", "ab") < 0);
    assert(strcmp("aa", "aa") == 0);
    assert(strcmp("ab", "aa") > 0); 
    assert(strcmp("aa", "a")== 1);
    //sert(strcmp(NULL, "aa")== 1);
    //sert(strcmp(NULL, NULL)== 1);

    return 0;
}
