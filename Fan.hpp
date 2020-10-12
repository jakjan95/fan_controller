#pragma once

class Fan {
private:
    int rpm = 0;

public:
    void setSpeed(int newRpm);
    int getSpeed() const;
};
