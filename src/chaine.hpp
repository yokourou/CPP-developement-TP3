#ifndef _CHAINE_HPP__
#define _CHAINE_HPP__
#include <string>
#include <iostream>
#include <exception.hpp>
#include <sstream>


using namespace std;

// Exception 
template <typename T>
inline string chaine(const T &); // pour quoi pas : inline string

inline const string & chaine(const string &);
inline string chaine(const int &);
inline string  chaine(const double &);
// ********* prof 
template <typename T,size_t... Is> string chaine_bis(const T & ,index_sequence<Is...>);
template <typename... ARGS> string chaine(const tuple<ARGS...> & t);
// ********* prof 


template <typename T> inline string  chaine(const T & x){
   
    throw ExceptionChaine(typeid(x).name()); // 
    
} 

inline const string & chaine(const string & c){
    return c;
} 

inline string chaine(const int & entier){
    stringstream ss;
    ss << entier ;
    return ss.str();
} 

inline string chaine(const double & reel){
    return to_string(reel);
} 

// Variadic template

/* surchage de la fonction chaine sous la forme d'un template avec un nombre variable de paramètres */

// specialisation n**1 = recursion
template <typename PRIM, typename... REST>
inline string chaine(const PRIM & arg1, const REST &...args){
    return chaine(arg1) + ((string(" ")+chaine(args))+...);
} 

/* fonction chaine pour les tuple */
 

template <typename T,size_t... Is>
string chaine_bis(const T & t,index_sequence<Is...>)
{ 
    return chaine(get<Is>(t)...);
}

template <typename... ARGS>
string chaine(const tuple<ARGS...> & t){
    return chaine_bis(t, make_index_sequence<sizeof... (ARGS)>());
}

#endif 

