#ifndef __gorc3__
#define __gorc3__
#include <ostream>



class String 
{
public:
     String();
     String(const String&);
     String(String&&);
     String( const char*);
     String& operator=(const String&);
     String& operator=(String&&);
     char& operator[](int );
     String operator+(const String&);
     friend std::ostream& operator<<(std::ostream& cout, const String& oth)
     {
         cout << oth.arr;
         return cout; 
     }
    ~String();
     void push_back( char );
     void pop_back();
     void insert(int pos, const char*);
     char& at(int pos);
     int  find(char);

private:
    unsigned int m_cup;
    unsigned int m_size;
    char * arr;


};

#endif