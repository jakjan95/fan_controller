#include "Fan.hpp"
#include <cmath>
#include <stdexcept>

void Fan::setSpeed(int newRpm) {
    if ((newRpm < 1000 and newRpm != 0) or newRpm > 3000) {
        throw std::invalid_argument("Invalid speed");
    }
    rpm = newRpm;
}

int Fan::getSpeed() const {
    return rpm;
}
