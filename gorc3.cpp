#include "gorc3.h"
#include <cstring>
#include <stdexcept>

String::String() 
{
    this-> m_size = 0;
    this-> m_cup = 1;
    arr = new char[m_cup];
}
String::String(const char * str) : m_size(strlen(str)), m_cup(m_size)
{
    arr = new char[m_cup];
    std::strcpy(arr, str);
}
String::String(const String& obj)
{    
    m_size = obj.m_size;
    m_cup = obj.m_cup;
    arr = new char[m_cup];
    for(int i = 0; i< m_size; ++i)
    {
        arr[i] = obj.arr[i];
    }
   
}
String::String(String&& obj)
{
    m_size = obj.m_size;
    m_cup = obj.m_cup;
    arr = obj.arr;
    obj.arr = nullptr;

}

String& String::operator=(const String& obj)
{
    this-> m_size = obj.m_size;
    this-> m_cup = obj.m_cup;
    arr = new char[m_cup];
    for(int i = 0; i< m_size; ++i)
    {
        arr[i] = obj.arr[i];
    }
    return *this;
}
String& String::operator=(String&& obj)
{
     
    this-> m_size = m_size;
    this-> m_cup = m_cup;
    arr = new char[m_cup];
    for(int i = 0; i< m_size; ++i)
    {
        arr[i] = obj.arr[i];
    }

    return *this;
}

String::~String()
{
    delete [] arr;
}

String String::operator+(const String& obj2)
{ 
   String tmp(*this);
   for( int i = 0; i < obj2.m_size; ++i)
   {
       tmp.push_back(obj2.arr[i]);
   }

  return tmp;
}

char& String::operator[](int pos)
{
    return arr[pos];
}


void String::push_back(char elem)
{
    if(m_size == m_cup)
    {   m_cup = (m_cup * 2);
       char* arr1 = new char[m_cup];
    for( int i = 0; i < m_size; ++i)
    {
        arr1[i] = arr[i];
    } 
    arr1[m_size] = elem;
    delete [] arr;
    arr = arr1;
    arr1 = nullptr;
    ++m_size;
    }
    else{
        arr[m_size] = elem;
        ++m_size;
    }

}

void String::pop_back()
{
    arr[--m_size] = '\0';
}
void String::insert(int pos, const char* rhs)
{   
    int size = m_size + strlen(rhs);
    char* arr1 = new char[m_size+1];
    for( int i = 0; i < pos; ++i)
    {
        arr1[i] = arr[i];
    }
    for( int i = 0; i < strlen(rhs); ++i)
    {
        arr1[pos+i] = rhs[i]; 
    }
    for( int i = pos; i < m_size; ++i)
     { 
           arr1[strlen(arr1)] = arr[i];
     }

     arr1[strlen(arr1)] = '\0';
    
    delete [] arr;
    arr = arr1;
    arr1 = nullptr;
    
    
}

char& String::at(int pos)
{  if(pos >= m_size) throw std::invalid_argument(" out of borders");
    return arr[pos];

}

int String::find(char ch)
{
    for( int i = 0; i < m_size; ++i)
    {
          if(arr[i] == ch)
            return i;
    }

   return -1; 
}


