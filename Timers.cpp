#include "Timers.hpp"
namespace CML{
    map<string,double> Timer::timeSum ;
    map<string,double> Timer::timeStart;
    map<string,double> Timer::timeEnd;
    map<string,int> Timer::count;

    inline double getSystemTime()
    {
        struct timeval timer;
        gettimeofday(&timer, 0);
        return ((double)(timer.tv_sec) + (double)(timer.tv_usec)*1.0e-6);
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
    void Timer::printTimer(string in) {
         map<string,double>::iterator it = timeSum.find(in);

        if(it==timeEnd.end()) {
            Info<<"there is no Timer \""<<in<<endl;
        }
        else{
            Info<< it->first <<" Time: "<<it->second
                <<" count: "<<count[it->first]<<endl;
        }
    }

    void Timer::printTimer() {
            map<string,double>::iterator it;
            for(it=timeSum.begin();it!=timeSum.end();++it)
                Info<< it->first <<" Time: "<<it->second<<" count: "
                    <<count[it->first]<<endl;
    }
    Timer::~Timer() {
            map<string,double>::iterator it;
            Info<<"Timer ~~~"<<endl;

            for(it=timeSum.begin();it!=timeSum.end();++it)
                Info<< it->first <<" Time: "<<it->second
                    <<" count: "<<count[it->first]<<endl;

    }
}
//}
