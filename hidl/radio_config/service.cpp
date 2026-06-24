/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "android.hardware.radio.config@1.1-service.msm8994"

#include <android/hardware/radio/config/1.1/IRadioConfig.h>
#include <hidl/HidlTransportSupport.h>

#include "RadioConfig.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using namespace android::hardware::radio::config;

using android::sp;
using android::status_t;
using android::OK;

int main() {
    configureRpcThreadpool(1, true);

    sp<V1_1::IRadioConfig> radioConfig = new RadioConfig;
    status_t status = radioConfig->registerAsService();
    ALOGW_IF(status != OK, "Could not register IRadioConfig");
    ALOGD("Default service is ready.");

    joinRpcThreadpool();
    return 0;
}
