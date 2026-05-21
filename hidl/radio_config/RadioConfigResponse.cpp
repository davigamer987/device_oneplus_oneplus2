/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "RadioConfigResponse.h"

namespace android {
namespace hardware {
namespace radio {
namespace config {

using namespace ::android::hardware::radio::V1_0;
using namespace ::android::hardware::radio::config::V1_1;

Return<void> RadioConfigResponse::getSimSlotsStatusResponse(
        const RadioResponseInfo& /* info */,
        const hidl_vec<V1_0::SimSlotStatus>& /* slotStatus */) {
    return Void();
}

Return<void> RadioConfigResponse::setSimSlotsMappingResponse(
        const RadioResponseInfo& /* info */) {
    return Void();
}

Return<void> RadioConfigResponse::getPhoneCapabilityResponse(
        const RadioResponseInfo& /* info */,
        const V1_1::PhoneCapability& /* phoneCapability */) {
    return Void();
}

Return<void> RadioConfigResponse::setPreferredDataModemResponse(
        const RadioResponseInfo& /* info */) {
    return Void();
}

Return<void> RadioConfigResponse::setModemsConfigResponse(
        const RadioResponseInfo& /* info */) {
    return Void();
}

Return<void> RadioConfigResponse::getModemsConfigResponse(
        const RadioResponseInfo& /* info */,
        const V1_1::ModemsConfig& /* modemsConfig */) {
    return Void();
}

}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android
