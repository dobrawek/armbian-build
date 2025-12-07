#
# SPDX-License-Identifier: GPL-2.0
#
# Copyright (c) 2024 Armbian community
#
# This file is a part of the Armbian Build Framework
# https://github.com/armbian/build/
#
# Common configuration for NXP i.MX93 SoCs
#

ARCH="arm64"
KERNEL_IMAGE_TYPE="Image"
OVERLAY_DIR="/boot/dtb/freescale/overlay"
SRC_EXTLINUX="yes"

# iMX93 requires ELE firmware (EdgeLock Enclave) instead of HDMI firmware
# firmware-imx for DDR training
IMX_FIRMWARE="${IMX_FIRMWARE:-"firmware-imx-8.26-d4c33ab"}"
IMX_ELE_FIRMWARE="${IMX_ELE_FIRMWARE:-"firmware-ele-imx-1.3.0-17945fc"}"

# imx_mkimage for creating flash.bin (same as flexbuild uses)
IMX_MKIMAGE_GIT="https://github.com/nxp-imx/imx-mkimage.git"
IMX_MKIMAGE_COMMIT="71b3e6f96de5f02b2d1f5e33b6b4908ef3d2b57c"

# ATF settings - must be set per board
# ATF_PLAT must be set in board config
# ATF_UART_BASE must be set in board config
ATFPATCHDIR='atf-imx93'
# ATF_TARGET_MAP is set in family config after ATF_PLAT is defined

# Build u-boot.bin and spl/u-boot-spl.bin, flash.bin is created by uboot_custom_postprocess() using imx_mkimage
UBOOT_TARGET_MAP="u-boot.bin spl/u-boot-spl.bin;;flash.bin"

# Bootloader offset for iMX93 - 32KB
OFFSET=32
