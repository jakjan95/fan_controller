#include "Controller.hpp"
#include "StubThermometer.hpp"
#include "external/catch.hpp"
#include "external/hippomocks.h"

SCENARIO("Controller can control Fan") {
    GIVEN("Controller, Thermometer, Fan, target temperature=36.6, tolerance=0.5 and updateRpm is called") {
        StubThermometer thermometer;
        Fan fan;
        double targetTemperature = 36.6;
        double tolerance = .5;
        Controller cut{thermometer, fan, targetTemperature, tolerance, nullptr};  //class under test

        WHEN("Temperature drops below 0") {
            thermometer.temperature = -1;
            cut.updateRpm();

            THEN("Fan should be disabled") {
                REQUIRE(fan.getSpeed() == disabledSpeed);
            }
        }

        WHEN("Temperature raise above 100 and updateRpm is called") {
            thermometer.temperature = 101;
            cut.updateRpm();
            THEN("Fan should work at max speed") {
                REQUIRE(fan.getSpeed() == maxSpeed);
            }
        }
    }
}
