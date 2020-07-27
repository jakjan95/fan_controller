#pragma once

namespace FanSpeeds {
constexpr int disabledRpm = 0;
constexpr int minRpm = 1000;
constexpr int maxRpm = 3000;
}  // namespace FanSpeeds

class Fan {
    int rpm = 0;

public:
    Fan();
    Fan(const Fan&);
    Fan(Fan&&);

    void setSpeed(int newRpm);
    int getSpeed();
    bool disable();
    bool enable();
};
