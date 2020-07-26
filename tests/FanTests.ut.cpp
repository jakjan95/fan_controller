#include "Fan.hpp"
#include "gtest/gtest.h"

TEST(Fan, CreatedFanIsDisabled) {
    Fan f{};
    EXPECT_EQ(f.getSpeed(), 0);
}

TEST(Fan, SettingProperValues) {
    Fan f{};

    const auto disabledRpm = 0;
    const auto minRpm = 1000;
    const auto maxRpm = 3000;

    f.setSpeed(minRpm);
    EXPECT_EQ(f.getSpeed(), minRpm);

    f.setSpeed(maxRpm);
    EXPECT_EQ(f.getSpeed(), maxRpm);

    f.setSpeed(disabledRpm);
    EXPECT_EQ(f.getSpeed(), disabledRpm);
}

TEST(Fan, SettingInvalidArguments) {
    Fan f{};
    const auto minRpm = 1000;
    auto before = f.getSpeed();

    ASSERT_THROW(f.setSpeed(minRpm - 1), std::invalid_argument);
    EXPECT_EQ(f.getSpeed(), before);

    ASSERT_THROW(f.setSpeed(minRpm + 1), std::invalid_argument);
    EXPECT_EQ(f.getSpeed(), before);
}
