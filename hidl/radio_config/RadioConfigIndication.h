/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <android/hardware/radio/config/1.0/IRadioConfigIndication.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace radio {
namespace config {
namespace V1_0 {
namespace implementation {

using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct RadioConfigIndication : public IRadioConfigIndication {
    Return<void> simSlotsStatusChanged(
        ::android::hardware::radio::V1_0::RadioIndicationType type,
        const hidl_vec<::android::hardware::radio::config::V1_0::SimSlotStatus>& slotStatus)
        override;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android
