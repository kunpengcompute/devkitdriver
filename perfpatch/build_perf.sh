#!/bin/bash
# Copyright (C) 2016. Huawei Technologies Co., Ltd. All rights reserved.

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 and
# only version 2 as published by the Free Software Foundation.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.

# description: build perf

umask 0027

CUR_PATH=$(dirname "$0")
SPE_DIR=$(readlink -e "${CUR_PATH}")
PERF_SOURCE_DIR="${SPE_DIR}/linux-4.14.0-115.el7a"
PERF_FILE_DIR="${PERF_SOURCE_DIR}/tools/perf"
SPE_PATCH="${SPE_DIR}/spe_4.14_v4"
SUCCESS=0
ERROR=1

function build_perf() {
    [[ ! -d "${SPE_PATCH}" ]] && echo "The directory ${SPE_PATCH} does not exist." && exit "${ERROR}"
    [[ ! -d "${PERF_SOURCE_DIR}" ]] && echo "The directory ${PERF_SOURCE_DIR} does not exist." && exit "${ERROR}"
    [[ ! -d "${PERF_FILE_DIR}" ]] && echo "The directory ${PERF_FILE_DIR} does not exist." && exit "${ERROR}"
    cp -r "${SPE_DIR}/spe_4.14_v4" "${PERF_SOURCE_DIR}/"
    cd "${PERF_SOURCE_DIR}"
    git apply spe_4.14_v4/*.patch
    [[ "$?" -ne "${SUCCESS}" ]] && echo "Patch installation failed." && exit "${ERROR}"
    cd "${PERF_FILE_DIR}"
    make -j
    [[ "$?" -ne "${SUCCESS}" ]] && exit "${ERROR}"
    exit "${SUCCESS}"
}

function main() {
    build_perf
    [[ "$?" -ne "${SUCCESS}" ]] && echo "Compilation failed." || echo "Compilation succeeded."
}

main