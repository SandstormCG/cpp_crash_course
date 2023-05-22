#include <sys/time.h>
#include <cstring>

struct TimerClass {
    TimerClass(const char* name): timestamp {(int*) malloc(sizeof(int))} {
         this->name = new char [strlen(name) + 1];
         std::strcpy(this->name, name);
         init();
    }

    // Not shared pointer
    /*~TimerClass(){
         struct timeval tv;
         gettimeofday(&tv, NULL);
         cout << "Substract: " << (tv.tv_sec + ( tv.tv_usec / 1000000.0 ) ) - *timestamp << std::endl ;
         // cout << "Substract: " << (tv.tv_sec + ( tv.tv_usec / 1000000.0 ) ) - timestamp << std::endl ;
         delete timestamp;
         timestamp = nullptr;
    }*/

    // Shared pointer
    ~TimerClass(){
         struct timeval tv;
         gettimeofday(&tv, NULL);
         // avoid move issues
         if (timestamp != 0)    cout << "Substract: " << (tv.tv_sec + ( tv.tv_usec / 1000000.0 ) ) - *timestamp << std::endl ;
         // cout << "Substract: " << (tv.tv_sec + ( tv.tv_usec / 1000000.0 ) ) - timestamp << std::endl ;
         cout << "delete " << this->name << " timer." << std::endl;
    }

    // Not shared pointer
    /*TimerClass(const TimerClass& source){
        *timestamp = *source.timestamp;
        init();
    }*/

    // Shared pointer
    TimerClass(const TimerClass& source){
        this->name = new char [strlen(source.name) + 1];
        std::strcpy(this->name, source.name);
        timestamp = source.timestamp;
        init();
    }

    // Not shared pointer
    /*TimerClass& operator=(const TimerClass& source){
        if (this == &source ) return *this;
        //timestamp = source.timestamp;
        timestamp = new int;
        *timestamp = *source.timestamp;
        return *this;
    }*/
    // Shared pointer
    TimerClass& operator=(const TimerClass& source){
        if (this == &source ) return *this;
        timestamp = source.timestamp;
        this->name = new char [strlen(source.name) + 1];
        std::strcpy(this->name, source.name);
        return *this;
    }

    //TimerClass(const  TimerClass&) = default;
    //TimerClass& operator=(const TimerClass&) = default;

    TimerClass(TimerClass&& source) noexcept {
        timestamp = new int;
        *timestamp = *source.timestamp;
        delete source.timestamp;
        source.timestamp = nullptr;
        this->name = new char [strlen(source.name) + 1];
        std::strcpy(this->name, source.name);
        delete source.name;
        source.name=nullptr;
    }

    TimerClass& operator=(TimerClass&& source) noexcept{
        if (this == &source) return *this;
        delete timestamp;
        timestamp = source.timestamp;
        delete source.timestamp;
        source.timestamp = nullptr;
        this->name = new char [strlen(source.name) + 1];
        std::strcpy(this->name, source.name);
        delete source.name;
        source.name=nullptr;
        return *this;
    }

    double const getTimestamp(){
        return *timestamp;
    }

    void setTimestamp(double timestamp){
        *this->timestamp = timestamp;
    }
private:
    void init(){
         struct timeval tv;
         gettimeofday(&tv, NULL);
         *timestamp = (int)  ( tv.tv_sec + ( tv.tv_usec / 1000000.0 ) );
         //timestamp = tv.tv_sec + ( tv.tv_usec / 1000000.0 );
    }

    int *timestamp = (int*) malloc(sizeof(int));
    char *name;
};


void TimerFunction() {
    auto timer = new TimerClass{"Counter"}; // auto = TimerClass*
    cout << "1.Timestamp: " << timer->getTimestamp() << std::endl;
    auto timer2 = new TimerClass{*timer};
    cout << "1.Timestamp2: " << timer2->getTimestamp() << std::endl;
    timer->setTimestamp(332211);
    cout << "2.Timestamp: " << timer->getTimestamp() << std::endl;
    cout << "2.Timestamp2: " << timer2->getTimestamp() << std::endl;

    // Move constructr
    auto timer3 = new TimerClass(std::move(*timer));
    cout << "3. Move timestamp: " << timer3->getTimestamp() << std::endl;

    cout << "2" << std::endl;
    delete timer2;
    cout << "3" << std::endl;
    delete timer3;
    cout << "1" << std::endl;
    delete timer;


}
