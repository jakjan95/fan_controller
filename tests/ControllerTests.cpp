#include "Controller.hpp"
#include "StubThermometer.hpp"
#include "external/catch.hpp"
#include "external/hippomocks.h"


SCENARIO("Controller can control Fan") {
    GIVEN("Controller, Thermometer, Fan, target temperature=36.6, tolerance=0.5") {
        StubThermometer thermometer;
        Fan fan;
        double targetTemperature = 36.6;
        double tolerance = .5;
        Controller cut{thermometer, fan, targetTemperature, tolerance, nullptr};  //class under test
        
        WHEN("Temperature drops below 0") {
            thermometer.temperature = -1;
            auto temperature = thermometer.getTemperature();
            REQUIRE(temperature < 0);

            THEN("Fan should be disabled") {
                REQUIRE(fan.getSpeed() == 0);
            }
        }

         WHEN("Temperature raise above 100") {
            thermometer.temperature = 101;
            auto temperature = thermometer.getTemperature();
            REQUIRE(temperature > 100);

            THEN("Fan should work at max speed") {
                constexpr int maxSpeed = 3000;
                REQUIRE(fan.getSpeed() == maxSpeed);
            }
        }
    }
}
