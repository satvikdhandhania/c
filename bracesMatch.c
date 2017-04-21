
/*
 * (Find whether a given input string contains matching brackets
 * face
 * 1. Brackets can be of form { }, or ( ), or [ ]
 * 2. Input string contains either above brackets or lower case english alphabets
 *
 * Ex: 
 * 1. Input string: [abcd]
 * Output: Yes
 *
 * 2. Input string: [ aa { asda (rew ) } we]
 * Output: Yes
 *
 * 3. Input string: [ asdfbas} ]
 * Output: No
 *
 * 4. Input string: [ ( asdf)
 * Output: No
 *
 * 5. Input string:  [aw { } ) ]
 * Output: No
 *
 * 6. Input: [(abc])
 * Output: No
 *
 * 7. abcd[abcd]def[abcd]abde
 * Output: Yes
 *
 * Type Here: 
 *
 * */

/* This adds a character to the top of the stack */
boolean stack.insert(char c);
/* This returns the top of the stack */
char stack.pop(); 
/* Assuming these interfaces are there. Which describe whether stack is empty or
 * not by returning a value. */
boolean stack.check();

boolean checkBrackets(char* string)
{   
    if(string == NULL)
    {
        return false;
    }
    stack.empty();
    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i] == '(') || (string[i] == '{') || (string[i] =='['))
        {   
            if(!stack.insert(string[i]))
            {
                printf("\n Stack is full! Need a bigger stack!! ");
                return false;
            }
        }
        if((string[i] == ')') || (string[i] == '}') || (string[i] ==']'))
        {
            if(!stack.check())
            {
                return false;
            }
            char c = stack.pop();
            if( (c == '(') && (string[i] != ')') )
            {
                return false;
            } else if ( (c == '{') && (string[i] != '}') )
            {
                return false;
            }else if ((c == '[') && (string[i] != ']'))
            {
                return false;
            }

        }
    }
    if(!stack.check())
    {
        return true;
    }
    return false;
}

