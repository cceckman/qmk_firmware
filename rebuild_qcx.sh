#!/bin/sh

set -eux

# From holykeebs commands.txt:
# https://docs.holykeebs.com/firmware/

. ./.venv/bin/activate

make lily58/rev1:qcx \
    -e USER_NAME=holykeebs \
    -e CONSOLE=yes \
    -e POINTING_DEVICE=trackpoint \
    -e POINTING_DEVICE_POSITION=left \
    -j$(nproc) \
    -e OLED=yes \
    # -e OLED_FLIP=yes \
    # -e TARGET=debug_lily58_rev1_hk_trackpoint_oled \

