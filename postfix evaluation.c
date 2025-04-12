//program to Postfix Expression Evaluation
#include<stdio.h>
#include<string.h>
#include<math.h>
struct stack
{
    char a[50];
    int top;
};
struct stack s={{' '},-1};
void push(char);
char pop();
long int eval_post();
char postfix[40];
int main()
{
    int n;
    scanf("%s",postfix);
    n=eval_post();
    printf("%d",n);
    return 0;
}
void push(char symb)
{
    if(s.top>=49)
      return;
    else
    {
         s.top=s.top+1;
         s.a[s.top]=symb;
    }
}
char pop()
{
     char item;
     if(s.top==-1)
         return(0);
     else
     {
            item=s.a[s.top];
            s.top--;
     }
     return(item);
}
long int eval_post()
{
 long int a,b,temp,result,len;
 int i;
 len=strlen(postfix);
 postfix[len]='\0';  

 for(i=0;postfix[i]!='\0';i++)
 {
  if(postfix[i]>='0' && postfix[i]<='9' )
  //type your code here
  push( postfix[i]-48);
  else
  {
  //type your code here
  a=pop();
   b=pop();
   switch(postfix[i])
   {
    case '+':temp=b+a; break;
    case '-':temp=b-a;break;
    case '*':temp=b*a;break;
    case '/':temp=b/a;break;
    case '%':temp=b%a;break;
    case '^':temp=pow(b,a);
   }
   push(temp);
  }
 }
 result=pop();
 return result;
}