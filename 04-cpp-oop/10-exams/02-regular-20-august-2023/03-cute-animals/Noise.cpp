#include "Noise.h"
#include <sstream>
using namespace std;

auto Noise::newNoise(size_t time) -> void {
    if (this->number == 0) {
        this->first = this->last = time;
        this->number = 1;
        this->each = 1;
        return;
    }

    this->number++;
    this->last = time;
    this->each = (this->last - this->first) / this->number;
    if (this->each == 0)
        this->each = 1;
}

auto Noise::getNewNoiseStatistics() const -> string {
    std::ostringstream oss;
    if (this->number == 1) {
        oss << this->number;
    } else {
        oss << this->number << ", each " << (this->each > 1 ? std::to_string(this->each) + " " : "") << "minute";
        if (this->each != 1)
            oss << "s";
    }
    return oss.str();
}

auto Noise::getFinalStatistics() const -> string {
    std::ostringstream oss;
    if (number == 1) {
        oss << "1 at " << first;
    } else {
        oss << number << ", from " << first << " till " << last << ", each "
            << (each > 1 ? std::to_string(each) + " " : "") << "minute";
        if (each != 1)
            oss << "s";
    }
    return oss.str();
}
