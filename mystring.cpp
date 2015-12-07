#include "mystring.h"
#include <iostream>
#include <cstring>

using namespace std ;
using namespace mystr ;

namespace mystr
{
    ostream& operator <<( ostream& os , const String& str ) {
        for( int i = 0 ; i < str.size() ; ++i )
            cout << str[i];
        return os ;
    }
    /*
        istream
    */
    char& String::operator []( size_t idx ) {
        return const_cast<char&>( static_cast<const String&>(*this)[idx] ) ;
    }
    const char& String::operator []( size_t idx ) const{
        return str_[idx] ;
    }
    String& String::operator += ( const char* str ) {
        int length = strlen( str ) ;
        if( size_ + length >= capacity_ ){
            char* newstr = new char[size_+length+1]() ;
            size_ = size_+length ;
            capacity_ = size_+1 ;
            strcpy( newstr , str_ ) ;
            delete[] this->str_ ;
            str_ = newstr ;
        }
        strcat( str_ , str ) ;
        return *this ;
    }
    String& String::operator += ( const String& str ){
        (*this) += str.c_str() ;
        return *this ;
    }
    String& String::operator += ( const char c ) {
        char tmp[] = { c , '\0' } ;
        (*this) += tmp ;
        return *this ;
    }

}