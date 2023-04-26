#include <sys/time.h>

struct TimerClass {
    TimerClass(){
         struct timeval tv;
         gettimeofday(&tv, NULL);
         timestamp = tv.tv_sec + ( tv.tv_usec / 1000000.0 );
    }

    ~TimerClass(){
         struct timeval tv;
         gettimeofday(&tv, NULL);
         cout << "Substract: " << (tv.tv_sec + ( tv.tv_usec / 1000000.0 ) ) - timestamp << std::endl ;
    }

    int getTimestamp(){
        return timestamp;
    }
private:
    int timestamp;
};


void TimerFunction() {
    auto timer = new TimerClass{}; // auto = TimerClass*
    cout << "Timestamp: " << timer->getTimestamp() << std::endl;
    delete timer;
}
