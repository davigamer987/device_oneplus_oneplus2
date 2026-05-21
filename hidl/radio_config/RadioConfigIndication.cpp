/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "RadioConfigIndication.h"

namespace android {
namespace hardware {
namespace radio {
namespace config {
namespace V1_0 {
namespace implementation {

using namespace ::android::hardware::radio::V1_0;

Return<void> RadioConfigIndication::simSlotsStatusChanged(
        RadioIndicationType /* type */,
        const hidl_vec<SimSlotStatus>& /* slotStatus */) {
    return Void();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android
