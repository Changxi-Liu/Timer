#include "Timers.hpp"
#include <iostream>
#define COUT cout

//#define COUT Info
using namespace std;
    map<string,double> Timer::timeSum ;
    map<string,double> Timer::timeStart;
    map<string,double> Timer::timeEnd;
    map<string,int> Timer::count;
    map<string,unsigned long> Timer::timeSum_asm ;
    map<string,unsigned long> Timer::timeStart_asm;
    map<string,unsigned long> Timer::timeEnd_asm;

    inline double getSystemTime()
    {
        struct timeval timer;
        gettimeofday(&timer, 0);
        return ((double)(timer.tv_sec) + (double)(timer.tv_usec)*1.0e-6);
    }


    inline unsigned long rpcc()
    {
            unsigned long time;
            asm("rtc %0": "=r" (time) : );
            return time;
    }
    void Timer::startTimer(string in) {
            
            timeStart[in] = getSystemTime();
    }
    void Timer::endTimer(string in) {
            timeEnd[in] = getSystemTime();
            map<string,double>::iterator it = timeSum.find(in);
            if(it==timeSum.end()) {
                timeSum[in] = 0 ;
                count[in] = 0 ;
            }
            timeSum[in] += timeEnd[in] - timeStart[in] ;
            count[in]++;
    }
    void Timer::startTimer_asm(string in) {
            
            timeStart_asm[in] = rpcc();
    }
    void Timer::endTimer_asm(string in) {
            timeEnd_asm[in] = rpcc();
            map<string,unsigned long>::iterator it = timeSum_asm.find(in);
            if(it==timeSum_asm.end()) {
                timeSum_asm[in] = 0 ;
                count[in] = 0 ;
            }
            timeSum_asm[in] += timeEnd_asm[in] - timeStart_asm[in] ;
            count[in]++;
    }

    void Timer::printTimer(string in) {
         map<string,double>::iterator it = timeSum.find(in);

        if(it==timeEnd.end()) {
            COUT<<"there is no Timer \""<<in<<endl;
        }
        else{
            COUT<< it->first <<" Time: "<<it->second
                <<" count: "<<count[it->first]<<endl;
        }
    }
    void Timer::printTimer_asm(string in) {
         map<string,unsigned long>::iterator it = timeSum_asm.find(in);

        if(it==timeEnd_asm.end()) {
            COUT<<"there is no Timer \""<<in<<endl;
        }
        else{
            COUT<< it->first <<" Time: "<<it->second
                <<" count: "<<count[it->first]<<endl;
        }
    }


    void Timer::printTimer_asm() {
            map<string,unsigned long>::iterator it;
            for(it=timeSum_asm.begin();it!=timeSum_asm.end();++it)
                COUT<< it->first <<" Time: "<<it->second<<" count: "
                    <<count[it->first]<<endl;
    }
    Timer::~Timer() {
            map<string,double>::iterator it;
            COUT<<"Timer ~~~"<<endl;

            for(it=timeSum.begin();it!=timeSum.end();++it)
                COUT<< it->first <<" Time: "<<it->second
                    <<" count: "<<count[it->first]<<endl;

    }
//}
