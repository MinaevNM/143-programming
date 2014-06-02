// ----------------------------------------------------------------------------
/*
File: gauss.cpp
Description: Решение СЛАУ методом Гаусса
Language: C++
Author: Минаев Никита
Reviewer: Анкаренко Сергей
Co-autors: С_имя С_фамилия
(c) Copyright group 143 2014
*/
// ----------------------------------------------------------------------------

#include <iostream>
#include "fraction.h"
#pragma once
#pragma warning(disable: 4996)

class matrix
{
    //    TODO: [A]
    //    Интерфейс класса должен быть понятен.
    //    Непосвещенному придется лезть в cpp-шник, чтобы разобраться со смыслом этих переменных.
    //    DONE
    //    Matrix dimensions
    int n, m;
    //    Matrix itself
    Fraction ** a;

public:
    // constructors
    matrix( int _n, int _m );
    matrix( char * fileName );
    //destructor
    ~matrix();

    // print matrix
    void print();
    // substract one string from another with coeff
    //    TODO: [A] Раз уж эта фукнция составляет интерфейс, она должна быть понятной.
    //    Неясно, что из чего вычитается и к чему применяется умножение на 'с'.
    //    Чтобы разобраться, придется лезть в cpp-ник. Что не есть хорошо.
    //    Функция вычитания выполняет работу функции mult (которая никак не используется)
    //    Нужно разделить умножение и вычитание
    // substract one string from another
    void subst(int s1, int s2, Fraction c );
    // multiply string on non-zero coeff
    void mult( int s, Fraction c );
    // swap two strings
    void Swap( int s1, int s2 );
    // swap two strings with the biggest base element
    void swapBiggest( int from, int column );
    // substract string #num from all strings from 'from'
    // to n. base element - column
    void substFromAll( int num, int from, int column );
    // Gauss
    void Gauss();
    // Check matrix after Gauss transformation
    void checkResult( char * fileName);
    // Find basis
    void findBasis( int freeVar, FILE * _f );
	// Check if downloading from file failed 
	bool matrix::isEmpty();
};
