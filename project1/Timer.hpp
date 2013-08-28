#include <chrono>


class Timer {
    private:
        std::chrono::high_resolution_clock::time_point t1, t2;
    public:
    void start() { t1 = std::chrono::high_resolution_clock::now(); }
    void stop() { t2 = std::chrono::high_resolution_clock::now(); };
    std::chrono::milliseconds duration() { return std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1); }

};

