/* ESP32 Linker Script Memory Layout

   This file describes the memory layout (memory blocks) as virtual
   memory addresses.

   esp32.common.ld contains output sections to link compiler output
   into these memory blocks.

   ***

   This linker script is passed through the C preprocessor to include
   configuration options.

   Please use preprocessor features sparingly! Restrict
   to simple macros with numeric values, and/or #if/#endif blocks.
*/
/* Bootloader configv */
/* Security features */
/* Serial flasher config */
/* Partition Table */
/* Compiler options */
/* Component config */
/* Application Level Tracing */
/* FreeRTOS SystemView Tracing */
/* Bluetooth */
/* ESP32-specific */
/* SPI RAM config */
/* #define CONFIG_SPIRAM_SUPPORT 1 */
/* #define CONFIG_SPIRAM_BOOT_INIT 1 */
/* #define CONFIG_SPIRAM_IGNORE_NOTFOUND 1 */
/* #define CONFIG_SPIRAM_USE_CAPS_ALLOC 1 */
/* #define CONFIG_SPIRAM_TYPE_ESPPSRAM32 1 */
/* #define CONFIG_SPIRAM_SIZE 4194304 */
/* #define CONFIG_SPIRAM_SPEED_40M 1 */
/* #define CONFIG_SPIRAM_MEMTEST 1 */
/* #define CONFIG_SPIRAM_CACHE_WORKAROUND 1 */
/* #define CONFIG_WIFI_LWIP_ALLOCATION_FROM_SPIRAM_FIRST 1 */
/* #define CONFIG_SPIRAM_ALLOW_STACK_EXTERNAL_MEMORY 1 */
/* Wi-Fi */
/* PHY */
/* Power Management */
/* Ethernet */
/* FAT Filesystem support */
/* FreeRTOS */
/* Heap memory debugging */
/* libsodium */
/* Log output */
/* LWIP */
/* DHCP server */
/* TCP */
/* UDP */
/* ICMP */
/* LWIP RAW API */
/* mbedTLS */
/* TLS Key Exchange Methods */
/* Symmetric Ciphers */
/* Certificates */
/* OpenSSL */
/* PThreads */
/* SPI Flash driver */
/* SPIFFS Configuration */
/* SPIFFS Cache Configuration */
/* Debug Configuration */
/* tcpip adapter */
/* Wear Levelling */
/* SDK tool configuration */
/* Others */
/* If BT is not built at all */
MEMORY
{
  /* All these values assume the flash cache is on, and have the blocks this uses subtracted from the length
  of the various regions. The 'data access port' dram/drom regions map to the same iram/irom regions but
  are connected to the data port of the CPU and eg allow bytewise access. */
  /* IRAM for PRO cpu. Not sure if happy with this, this is MMU area... */
  iram0_0_seg (RX) : org = 0x40080000, len = 0x20000
  /* Even though the segment name is iram, it is actually mapped to flash
  */
  iram0_2_seg (RX) : org = 0x400D0018, len = 0x330000-0x18
  /*
    (0x18 offset above is a convenience for the app binary image generation. Flash cache has 64KB pages. The .bin file
    which is flashed to the chip has a 0x18 byte file header. Setting this offset makes it simple to meet the flash
    cache MMU's constraint that (paddr % 64KB == vaddr % 64KB).)
  */
  /* Shared data RAM, excluding memory reserved for ROM bss/data/stack.

     Enabling Bluetooth & Trace Memory features in menuconfig will decrease
     the amount of RAM available.

     Note: Length of this section *should* be 0x50000, and this extra DRAM is available
     in heap at runtime. However due to static ROM memory usage at this 176KB mark, the
     additional static memory temporarily cannot be used.
  */
  dram0_0_seg (RW) : org = 0x3FFB0000 + 0x10000,
                                     len = 0x2c200 - 0x10000
  /* Flash mapped constant data */
  drom0_0_seg (R) : org = 0x3F400018, len = 0x400000-0x18
  /* (See iram0_2_seg for meaning of 0x18 offset in the above.) */
  /* RTC fast memory (executable). Persists over deep sleep.
   */
  rtc_iram_seg(RWX) : org = 0x400C0000, len = 0x2000
  /* RTC slow memory (data accessible). Persists over deep sleep.

     Start of RTC slow memory is reserved for ULP co-processor code + data, if enabled.
  */
  rtc_slow_seg(RW) : org = 0x50000000 + 0,
                                     len = 0x1000 - 0
}
/* Heap ends at top of dram0_0_seg */
_heap_end = 0x40000000 - 0x0;
