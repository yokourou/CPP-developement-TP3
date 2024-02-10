#ifndef EXCEPTION_HPP__
#define EXCEPTION_HPP__
#include <iostream>
#include <string>
#include <exception>
#include <demangle.hpp>



using namespace std;


class ExceptionChaine: public exception{
    public:
        string err;
    public :
        ExceptionChaine(const string & type):err("Conversion en chaine impossible pour '"+ demangle(type)+"'"){}
        ~ExceptionChaine(){} 
        const char * what() const noexcept override{ return err.c_str(); } 
} ;



#endif


