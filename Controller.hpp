#pragma once
#include <memory>
#include "Fan.hpp"
#include "IThermometer.hpp"

class LcdDisplay;

class Controller {
public:
    Controller(IThermometer& t, Fan, double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();

private:
    IThermometer& thermometer_;
};
