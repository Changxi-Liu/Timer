/*---------------------------------------------------------------------------*\
Class: Timer
Author: Changxi.Liu
Copyright
-------------------------------------------------------------------------------

\*---------------------------------------------------------------------------*/

#ifndef TIMER_H
#define TIMER_H
#include "lduMatrix.hpp"

#include <sys/time.h>
//#include <iostream.h>
#include <map>
#include <string>
using namespace std;
namespace CML
{
class Timer
{
    public:    //get time
//        inline double getSystemTime();
        static map<string,double> timeSum ;
        static map<string,double> timeStart;
        static map<string,double> timeEnd;
        static map<string,int> count;
        void static startTimer(string in) ;
        static void endTimer(string in);
        ~Timer();
        static void printTimer();
        static void printTimer(string in) ;


};

//extern map<string,double> Timer::timeSum ;
//extern map<string,double> Timer::timeStart;
//extern map<string,double> Timer::timeEnd;
//extern map<string,int> Timer::count;
}
#endif

