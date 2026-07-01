/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "RadioConfig.h"
#include <android/hardware/radio/1.0/types.h>
#include <cutils/properties.h>

namespace android {
namespace hardware {
namespace radio {
namespace config {

using namespace ::android::hardware::radio::config::V1_1;

Return<void> RadioConfig::setResponseFunctions(
    const sp<V1_0::IRadioConfigResponse>& radioConfigResponse,
    const sp<V1_0::IRadioConfigIndication>& radioConfigIndication) {
    mRadioConfigResponse = V1_1::IRadioConfigResponse::castFrom(radioConfigResponse);
    mRadioConfigIndication = radioConfigIndication;
    return Void();
}

Return<void> RadioConfig::getSimSlotsStatus(int32_t /* serial */) {
    hidl_vec<V1_0::SimSlotStatus> slotStatus(2);
    for (uint32_t i = 0; i < 2; ++i) {
        char prop[PROPERTY_VALUE_MAX];
        char key[PROPERTY_KEY_MAX];

        snprintf(key, sizeof(key), "vendor.radio.cardstate.slot%d", i + 1);
        property_get(key, prop, "0" /* ABSENT */);
        int cardState = atoi(prop);

        slotStatus[i].cardState = static_cast<::android::hardware::radio::V1_0::CardState>(cardState);
        slotStatus[i].slotState = V1_0::SlotState::ACTIVE;
        slotStatus[i].logicalSlotId = i;
        slotStatus[i].atr = "";

        if (slotStatus[i].cardState == ::android::hardware::radio::V1_0::CardState::PRESENT) {
            snprintf(key, sizeof(key), "vendor.radio.iccid.slot%d", i + 1);
            property_get(key, prop, "");
            slotStatus[i].iccid = prop;
        }
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo info;
    info.error = ::android::hardware::radio::V1_0::RadioError::NONE;
    mRadioConfigResponse->getSimSlotsStatusResponse(info, slotStatus);
    return Void();
}

Return<void> RadioConfig::setSimSlotsMapping(int32_t /* serial */,
                                             const hidl_vec<uint32_t>& /* slotMap */) {
    ::android::hardware::radio::V1_0::RadioResponseInfo info;
    mRadioConfigResponse->setSimSlotsMappingResponse(info);
    return Void();
}

Return<void> RadioConfig::getPhoneCapability(int32_t /* serial */) {
    ::android::hardware::radio::V1_0::RadioResponseInfo info;
    V1_1::PhoneCapability capability;
    mRadioConfigResponse->getPhoneCapabilityResponse(info, capability);
    return Void();
}

Return<void> RadioConfig::setPreferredDataModem(int32_t /* serial */, uint8_t /* modemId */) {
    ::android::hardware::radio::V1_0::RadioResponseInfo info;
    mRadioConfigResponse->setPreferredDataModemResponse(info);
    return Void();
}

Return<void> RadioConfig::setModemsConfig(int32_t /* serial */,
                                          const V1_1::ModemsConfig& /* modemsConfig */) {
    ::android::hardware::radio::V1_0::RadioResponseInfo info;
    mRadioConfigResponse->setModemsConfigResponse(info);
    return Void();
}

Return<void> RadioConfig::getModemsConfig(int32_t /* serial */) {
    ::android::hardware::radio::V1_0::RadioResponseInfo info;
    const V1_1::ModemsConfig config = {};
    mRadioConfigResponse->getModemsConfigResponse(info, config);
    return Void();
}

}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android
