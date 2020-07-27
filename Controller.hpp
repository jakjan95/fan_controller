#pragma once
#include <memory>
#include "Fan.hpp"
#include "SlowThermometer/SlowThermometer.hpp"

class LcdDisplay;

class Controller {
public:
    Controller(std::shared_ptr<SlowThermometer> termomether,
               std::shared_ptr<Fan> fan,
               double targetTemperature,
               double tolerance,
               std::shared_ptr<LcdDisplay> lcdDisplay);

    void updateRpm();
    void displayInfo();

private:
    std::shared_ptr<SlowThermometer> termomether_;
    std::shared_ptr<Fan> fan_;
    double targetTemperature_;
    double tolerance_;
    std::shared_ptr<LcdDisplay> lcdDisplay_;
};
