#pragma once
#include <memory>
#include "Fan.hpp"
#include "IThermometer.hpp"

class LcdDisplay;

class Controller {
public:
    Controller(IThermometer& t, Fan& f, double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();

private:
    IThermometer& thermometer_;
    Fan& fan_;
};
