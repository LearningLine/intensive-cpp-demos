#include "Time.h"

Time add(Time const& a, Time const& b) {
    return Time(a.ticks_ + b.ticks_);
}
