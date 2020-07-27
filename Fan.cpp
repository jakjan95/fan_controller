#include "Fan.hpp"
#include <cmath>
#include <stdexcept>

Fan::Fan()
    : rpm{0} {}

Fan::Fan(Fan&& other)
    : rpm(std::move(other.rpm)) {}

Fan::Fan(const Fan& other)
    : rpm(other.rpm) {}

void Fan::setSpeed(int newRpm) {
    if ((newRpm < FanSpeeds::minRpm && newRpm != FanSpeeds::disabledRpm) || newRpm > FanSpeeds::maxRpm) {
        throw std::invalid_argument("Invalid speed");
    }
    auto difference = std::abs(newRpm - rpm);
    for (auto i = 0; i < difference; ++i) {
        if (newRpm - rpm > 0) {
            rpm++;
        } else {
            rpm--;
        }
    }
}

int Fan::getSpeed() {
    return rpm;
}

bool Fan::disable() {
    rpm = FanSpeeds::disabledRpm;
    return true;
}

bool Fan::enable() {
    rpm = FanSpeeds::minRpm;
    return true;
}
