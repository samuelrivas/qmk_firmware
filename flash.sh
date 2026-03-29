#!/usr/bin/env bash

udisksctl mount -b /dev/sda1
cp .build/crkbd_rev4_1_standard_samuelrivas.uf2 /run/media/samuel/RPI-RP2/
