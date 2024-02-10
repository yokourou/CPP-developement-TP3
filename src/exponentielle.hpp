#ifdef FACTORIELLE__HPP__
#define FACTORIELLE__HPP__
#include <iostream>


#include <factorielle.hpp>
#include <puissance.hpp>

/* 
//-----------------------exponentielle

template <unsigned long N> struct Exponentielle{
    static double valeur(double x) {
        return Exponentielle<N-1>::valeur(x) + Puissance<N>::valeur(x) / Factorielle<N>::valeur;
    }
};

template<> struct Exponentielle<0>{
    static double valeur(double ) {
        return 1.0;
    }
} ;

*/
#endif