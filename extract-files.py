#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: 2024 The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

from extract_utils.file import File
from extract_utils.fixups_blob import (
    BlobFixupCtx,
    blob_fixup,
    blob_fixups_user_type,
)
from extract_utils.fixups_lib import (
    lib_fixup_remove,
    lib_fixups,
    lib_fixups_user_type,
)
from extract_utils.main import (
    ExtractUtils,
    ExtractUtilsModule,
)

namespace_imports = [
    'device/oneplus/oneplus2',
    'vendor/qcom/opensource/commonsys-intf/display',
    'vendor/qcom/opensource/dataservices',
    'hardware/qcom-caf/wlan',
]

def lib_fixup_vendor_suffix(lib: str, partition: str, *args, **kwargs):
    return f'{lib}_{partition}' if partition == 'vendor' else None

lib_fixups: lib_fixups_user_type = {
    **lib_fixups,
    (
        'libqdutils',
        'libqservice',
        'libgps.utils',
        'libloc_core',
        'libCB',
        'libloc_api_v02',
        'libloc_eng',
        'liblocationservice',
        'libnetmgr',
        'libconfigdb',
        'libmmcamera_interface',
        'libqdMetaData',
    ): lib_fixup_remove,
}


blob_fixups: blob_fixups_user_type = {
    'vendor/lib/mediadrm/libwvdrmengine.so': blob_fixup()
        .add_needed('libcrypto_shim.so')
        .replace_needed('libprotobuf-cpp-lite.so', 'libprotobuf-cpp-lite-v28.so'),
    'vendor/lib64/libsettings.so': blob_fixup()
        .replace_needed('libprotobuf-cpp-full.so', 'libprotobuf-cpp-full-v28.so'),
    'vendor/bin/pm-service': blob_fixup()
        .add_needed('libutils-v33.so'),
    'vendor/lib64/com.quicinc.cne.api@1.0.so': blob_fixup()
        .replace_needed('libhidlbase.so', 'libhidlbase-v32.so'),
    'vendor/lib/libmmcamera2_stats_algorithm.so': blob_fixup()
        .add_needed('libshim_atomic.so'),
    'vendor/lib64/libcrypto_keystore.so': blob_fixup()
        .add_needed('libcrypto_shim.so'),
    'vendor/lib64/lib-imsvt.so': blob_fixup()
        .add_needed('libshims_ims.so')
        .add_needed('lib-imsvtshim.so'),
    'vendor/lib64/libmm-abl.so': blob_fixup()
        .add_needed('libshims_postproc.so'),
    'vendor/lib64/libril-qc-qmi-1.so': blob_fixup()
        .add_needed('libaudioclient_shim.msm8994.so')
        .add_needed('rild_socket.so'),
    'vendor/lib64/libimsmedia_jni.so': blob_fixup()
        .add_needed('lib-imsvtshim.so'),
    (
        'lib/libmorpho_video_refiner.so',
        'lib/libFNVfbEngineLib.so',
        'vendor/lib/libmmcamera_tintless_bg_pca_algo.so',
        'vendor/lib/libmmcamera2_is.so',
        'vendor/lib/libmmcamera_faceproc.so',
        'vendor/lib/libmmcamera2_frame_algorithm.so',
        'vendor/lib/libmmcamera_tintless_algo.so',
        'vendor/lib/libmmcamera_hdr_gb_lib.so',
        'vendor/lib/libmmcamera2_q3a_core.so',
        'vendor/lib/libmmcamera_cac2_lib.so',
        'vendor/lib/libmmcamera_pdaf.so',
        'vendor/lib/libmmcamera2_stats_algorithm.so',
        'vendor/lib/libmmcamera_pdafcamif.so',
        'vendor/lib64/libmmcamera2_q3a_core.so',
        'vendor/lib64/libmmcamera2_stats_algorithm.so',
        'vendor/lib64/libcrypto_keystore.so',
        'lib64/libopcamera.so',
        'lib64/libopcameralib.so',
    ): blob_fixup()
        .replace_needed('libstdc++.so', 'libstdc++_vendor.so'),

    # GnssSvStatus -> QcomSvStatus replacement
    (
        'vendor/lib64/liblocationservice.so',
        'vendor/lib64/liblbs_core.so',
        'system/lib64/libloc_api_v02.so',
    ): blob_fixup()
        .binary_regex_replace(b'GnssSvStatus', b'QcomSvStatus'),

} # fmt: skip

module = ExtractUtilsModule(
    'oneplus2',
    'oneplus',
    blob_fixups=blob_fixups,
    lib_fixups=lib_fixups,
    namespace_imports=namespace_imports,
)

if __name__ == '__main__':
    utils = ExtractUtils.device(module)
    utils.run()
