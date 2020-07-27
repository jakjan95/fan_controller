#include "Controller.hpp"

Controller::Controller(std::shared_ptr<SlowThermometer> termomether,
                       std::shared_ptr<Fan> fan,
                       double targetTemperature,
                       double tolerance,
                       std::shared_ptr<LcdDisplay> lcdDisplay)
    : termomether_{std::move(termomether)}, fan_{std::move(fan)}, targetTemperature_{targetTemperature}, tolerance_{tolerance}, lcdDisplay_{std::move(lcdDisplay)} {}

void Controller::updateRpm() {}

void Controller::displayInfo() {}
