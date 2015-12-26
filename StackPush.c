/*
#include<iostream>

struct Stack_element{
  int data;
  Stack_element*next;
};   

class Stack{
private:
  Stack_element*last_data, *first_data;

public:
  Stack():last_data(NULL), first_data(NULL){}  
  void push(int data);
  void print() const;  
};

void Stack::push(int data)
{
  Stack_element*p=new Stack_element();
  p->data=data;
  p->next=NULL;
  if(last_data)
    last_data->next=p;
  else // empty stack
    first_data=p;
  last_data=p;
}

void Stack::print() const
{
  for(Stack_element*p=first_data;p;p=p->next)
    std::cout << p->data << std::endl; // ** Do not use printf in c++. Ever. **
}    
*/ 
#include <stdio.h>

int main(){
	 
	char *s = "12345";
	printf("%lu \n", sizeof(s)+1);

}