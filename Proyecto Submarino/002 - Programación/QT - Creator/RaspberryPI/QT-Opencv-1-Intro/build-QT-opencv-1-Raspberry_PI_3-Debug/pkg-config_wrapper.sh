#!/bin/sh
PKG_CONFIG_SYSROOT_DIR=/home/aldo/raspi/sysroot
export PKG_CONFIG_SYSROOT_DIR
PKG_CONFIG_LIBDIR=/home/aldo/raspi/sysroot/usr/lib/pkgconfig:/home/aldo/raspi/sysroot/usr/share/pkgconfig:/home/aldo/raspi/sysroot/usr/lib/arm-linux-gnueabihf/pkgconfig
export PKG_CONFIG_LIBDIR
exec pkg-config "$@"
