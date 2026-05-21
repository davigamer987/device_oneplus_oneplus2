/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <android/hardware/radio/config/1.1/IRadioConfigResponse.h>
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

struct RadioConfigResponse : public V1_1::IRadioConfigResponse {
    Return<void> getSimSlotsStatusResponse(
        const ::android::hardware::radio::V1_0::RadioResponseInfo& info,
        const hidl_vec<V1_0::SimSlotStatus>& slotStatus) override;
    Return<void> setSimSlotsMappingResponse(
        const ::android::hardware::radio::V1_0::RadioResponseInfo& info) override;

    Return<void> getPhoneCapabilityResponse(
        const ::android::hardware::radio::V1_0::RadioResponseInfo& info,
        const V1_1::PhoneCapability& phoneCapability) override;
    Return<void> setPreferredDataModemResponse(
        const ::android::hardware::radio::V1_0::RadioResponseInfo& info) override;
    Return<void> setModemsConfigResponse(
        const ::android::hardware::radio::V1_0::RadioResponseInfo& info) override;
    Return<void> getModemsConfigResponse(
        const ::android::hardware::radio::V1_0::RadioResponseInfo& info,
        const V1_1::ModemsConfig& modemsConfig) override;
};

}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android
