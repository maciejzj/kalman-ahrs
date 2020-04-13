#include "ahrs/kalman.h"

#include <gtest/gtest.h>

#include <memory>

using namespace ::testing;
using namespace ahrs;

class KalmanFilterTest : public Test {
   protected:
    std::unique_ptr<ahrs::Kalman> kalman = nullptr;

    void SetUp() override {
        /* The system matrices for this test come from AHRS systems */
        double dt = 0.1;
        ahrs::array_2d<double, 4, 4> A = {
            {{1, -dt, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, -dt}, {0, 0, 0, 1}}};
        ahrs::array_2d<double, 4, 2> B = {{{dt, 0}, {0, 0}, {0, dt}, {0, 0}}};
        ahrs::array_2d<double, 2, 4> H = {{{1, 0, 0, 0}, {0, 0, 1, 0}}};

        kalman = std::make_unique<ahrs::Kalman>(A, B, H);
    }
};

/* TODO: Due to the complex nature of the filter the testing
 * requires much thought and is delegated to the issue #26.
 */
TEST_F(KalmanFilterTest, AnyTest) {}
