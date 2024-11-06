#pragma once

#include "common.h"
#include "hal.h"

#define SD_LOG_PREFIX  "SD Card Driver: "
#define SD_DUMMY_BYTE  (0xff)
#define SD_ACMD_FAIL   (0x39)
#define SD_SECTOR_SIZE (512)

void sd_init(void);

/**
 * @brief Single block read
 *
 * @param lba Logical block address
 * @param off block offset, less than sector size, i.e. 512 bytes
 * @param buf result, as large as (sector size - off) bytes
 * @return true if I/O was ok!
 */
bool sd_read_sector(uint32_t lba, uint16_t off, void* buf);

/**
 * @brief Single block write
 *
 * @param lba Logical block address
 * @param buf result (at least 512 bytes long)
 * @return true if I/O was ok!
 */
bool sd_write_sector(uint32_t lba, void* buf);