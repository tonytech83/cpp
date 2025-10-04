//
// Created by tonytech on 04.10.2025.
//

#include <string>


#include "Noises.h"


auto Noises::registerNoise(const std::string &time_, const std::string &noise_) -> std::string {
    const size_t time = stringToTime(time_);

    auto it = noises.find(noise_);
    if (it == noises.end()) {
        it = noises.emplace(noise_, Noise(time)).first;
    } else {
        it->second.newNoise(time);
    }

    // print statistics for this noise
    std::cout << noise_ << ": " << it->second.getNewNoiseStatistics() << std::endl;
    return noise_;
}

auto Noises::printStatistics(std::ostream &ostr) const -> void {
    if (noises.empty()) {
        ostr << "No noises." << std::endl;
        return;
    }

    for (const auto &entry: noises) {
        const auto &noiseName = entry.first;
        const auto &noiseObj = entry.second;
        ostr << noiseName << ": " << noiseObj.getFinalStatistics() << std::endl;
    }
}
