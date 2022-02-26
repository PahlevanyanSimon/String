#include "gorc3.h"
#include <iostream>
#include <ostream>


int main()
{
  String s;
  s.push_back('h');
  s.push_back('e');
  s.push_back('l');
  s.push_back('l'); 
  s.push_back('o');
  
  String st;
  st.push_back('w');
  st.push_back('o');
  st.push_back('r');
  st.push_back('l');
  st.push_back('d');
  
  std::cout << s + st <<std::endl;
 
}