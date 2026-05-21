/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <android/hardware/radio/config/1.1/IRadioConfig.h>
#include <android/hardware/radio/config/1.1/IRadioConfigResponse.h>
#include <android/hardware/radio/config/1.0/IRadioConfigIndication.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace radio {
namespace config {

using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct RadioConfig : public V1_1::IRadioConfig {
    sp<V1_1::IRadioConfigResponse> mRadioConfigResponse;
    sp<V1_0::IRadioConfigIndication> mRadioConfigIndication;

    Return<void> setResponseFunctions(
        const sp<V1_0::IRadioConfigResponse>& radioConfigResponse,
        const sp<V1_0::IRadioConfigIndication>& radioConfigIndication) override;
    Return<void> getSimSlotsStatus(int32_t serial) override;
    Return<void> setSimSlotsMapping(int32_t serial, const hidl_vec<uint32_t>& slotMap) override;

    Return<void> getPhoneCapability(int32_t serial) override;
    Return<void> setPreferredDataModem(int32_t serial, uint8_t modemId) override;
    Return<void> setModemsConfig(int32_t serial,
        const V1_1::ModemsConfig& modemsConfig) override;
    Return<void> getModemsConfig(int32_t serial) override;
};

}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android
