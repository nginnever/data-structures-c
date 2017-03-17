// a templated stack implementation

#include <iostream>

using std::cout;
using std::endl;

#define MAX 10 // max stack height

template <class T> // template so any data type can be stored

class Stack
{
  protected:
    T arr[MAX]; // contains all the data
  public:
    T item;
    T r;
    int top; // contains info about top most stack

    Stack() // constructor
    {
      for(int i = 0; i < MAX; i++)
      {
        arr[i] = NULL; // init stack elems to null
      }
      top = -1; // indicates an empty stack
    }

    void push(T a) // Add value to stack
    {
      top++;
      if(top < MAX)
      {
        arr[top] = a;
      } else
      {
        cout << "STACK IS FULL STACK WARNING!" << endl;
        top--;
      }
    }

    T pop()
    {
      if(top == -1)
      {
        cout << "STACK IS EMPTY" << endl;
        return NULL;
      } else {
        T data = arr[top];
        arr[top] = NULL;
        top--;
        return data;
      }
    }
};

int main()
{
  Stack <int> s;
  int opt = 1;
  
  s.push(10);
  cout << s.top << endl;
  cout << s.pop() << endl;
  return 0;
}