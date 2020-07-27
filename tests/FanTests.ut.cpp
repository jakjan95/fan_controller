#include "Fan.hpp"
#include "gtest/gtest.h"

namespace Speeds {
constexpr int disabledRpm = 0;
constexpr int minRpm = 1000;
constexpr int maxRpm = 3000;
}  // namespace FanSpeeds



TEST(Fan, CreatedFanIsDisabled) {
    Fan f{};
    EXPECT_EQ(f.getSpeed(), Speeds::disabledRpm);
}

TEST(Fan, SettingProperValues) {
    Fan f{};

    f.setSpeed(Speeds::minRpm);
    EXPECT_EQ(f.getSpeed(), Speeds::minRpm);

    f.setSpeed(Speeds::maxRpm);
    EXPECT_EQ(f.getSpeed(), FanSpeeds::maxRpm);

    f.setSpeed(Speeds::disabledRpm);
    EXPECT_EQ(f.getSpeed(), Speeds::disabledRpm);
}

TEST(Fan, SettingInvalidArguments) {
    Fan f{};
    auto before = f.getSpeed();

    ASSERT_THROW(f.setSpeed(Speeds::minRpm - 1), std::invalid_argument);
    EXPECT_EQ(f.getSpeed(), before);

    ASSERT_THROW(f.setSpeed(Speeds::maxRpm + 1), std::invalid_argument);
    EXPECT_EQ(f.getSpeed(), before);
}
