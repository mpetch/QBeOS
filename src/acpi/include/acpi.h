#ifndef ACPI_H
#define ACPI_H

#include "include/configs.h"
#include "acpi/include/rsdt.h"
#include "arch/include/vmm.h"
#include "include/common.h"
#include "include/logger.h"
#include "include/strings.h"
#include "kstdlib/include/global_operators.h"

#define ACPI_EBDA_REG_START 0x40e /* Physical Address */
#define ACPI_EBDA_REG_END 0x80e
#define ACPI_HI_RSDP_REG_START 0xe0000 /* Physical Address */
#define ACPI_HI_RSDP_REG_END 0x100000

struct ACPIRSDP {
  char signature[8];
  uint8_t checksum;
  char oemid[6];
  uint8_t rev;
  uint32_t rsdtAddr;
  uint32_t lengthBytes;
  uint64_t xsdtAddr;
  uint8_t extChecksum;
  uint8_t reserved[3];
} __attribute__((packed));

/**
 * this is the APCI Manager. this should expose all required functionalities
 * to other components in the kernel.
 */
class ACPIM {
private:
  uint8_t acpiver;
  struct ACPIRSDP rsdp;
  RSDTM *rsdt; 

  void parseRSDP(uintptr_t p);
  void parseRSDPV1();
  void parseRSDPV2();
  void printTableInfo();

public:
  ACPIM();

  bool IsPS2Supported();
};

inline ACPIM acpi;
#endif /* ACPI_H */
