# mahiwa-backend

## environment

- ESP-IDF : esp-idf:v5.x
- C++ : c++23

## getting started

### Install esp-idf

Install esp-idf v5.x

See here : https://docs.espressif.com/projects/esp-idf/en/v5.1.1/esp32c3/get-started/linux-macos-setup.html

```
mkdir -p ~/esp
cd ~/esp
git clone -b v5.1.1 --recursive https://github.com/espressif/esp-idf.git
cd ~/esp/esp-idf
./install.sh esp32c3
```

### Install repository

```
git clone --recursive https://github.com/project-mahiwa/mahiwa-backend
```

### build and flash

```
cd mahiwa-backend
. ~/esp/esp-idf/export.sh
idf.py set-target esp32c3
idf.py build
idf.py flash
idf.py monitor
```

result example

```
❯ idf.py monitor
Executing action: monitor
Serial port /dev/ttyACM0
Connecting...
Detecting chip type... ESP32-C3
Running idf_monitor in directory /opt/usuyuki/project-mahiwa/mahiwa-backend
Executing "/home/fss3/usuyuki/.espressif/python_env/idf5.1_py3.10_env/bin/python /opt/usuyuki/esp/esp-idf-511/tools/idf_monitor.py -p /dev/ttyACM0 -b 115200 --toolchain-prefix riscv32-esp-elf- --target esp32c3 --revision 3 --deco
de-panic backtrace /opt/usuyuki/project-mahiwa/mahiwa-backend/build/mahiwa-backend.elf -m '/home/fss3/usuyuki/.espressif/python_env/idf5.1_py3.10_env/bin/python' '/opt/usuyuki/esp/esp-idf-511/tools/idf.py'"...
--- esp-idf-monitor 1.3.1 on /dev/ttyACM0 115200 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
ESP-ROM:esp32c3-api1-20210207
Build:Feb  7 2021
rst:0x15 (USB_UART_CHIP_RESET),boot:0xc (SPI_FAST_FLASH_BOOT)
Saved PC:0x4004c516
0x4004c516: uart_rx_one_char in ROM

SPIWP:0xee
mode:DIO, clock div:1
load:0x3fcd5820,len:0x1704
load:0x403cc710,len:0x968
load:0x403ce710,len:0x2f68
entry 0x403cc710
I (24) boot: ESP-IDF v5.1.1 2nd stage bootloader
I (24) boot: compile time Oct 12 2023 16:28:28
I (25) boot: chip revision: v0.3
I (27) boot.esp32c3: SPI Speed      : 80MHz
I (32) boot.esp32c3: SPI Mode       : DIO
I (37) boot.esp32c3: SPI Flash Size : 2MB
I (42) boot: Enabling RNG early entropy source...
I (47) boot: Partition Table:
I (51) boot: ## Label            Usage          Type ST Offset   Length
I (58) boot:  0 nvs              WiFi data        01 02 00009000 00006000
I (65) boot:  1 phy_init         RF data          01 01 0000f000 00001000
I (73) boot:  2 factory          factory app      00 00 00010000 00100000
I (80) boot: End of partition table
I (84) esp_image: segment 0: paddr=00010020 vaddr=3c020020 size=06e78h ( 28280) map
I (97) esp_image: segment 1: paddr=00016ea0 vaddr=3fc8a600 size=01120h (  4384) load
I (102) esp_image: segment 2: paddr=00017fc8 vaddr=40380000 size=08050h ( 32848) load
I (116) esp_image: segment 3: paddr=00020020 vaddr=42000020 size=15398h ( 86936) map
I (132) esp_image: segment 4: paddr=000353c0 vaddr=40388050 size=02520h (  9504) load
I (137) boot: Loaded app from partition at offset 0x10000
I (137) boot: Disabling RNG early entropy source...
I (152) cpu_start: Unicore app
I (152) cpu_start: Pro cpu up.
I (161) cpu_start: Pro cpu start user code
I (161) cpu_start: cpu freq: 160000000 Hz
I (161) cpu_start: Application information:
I (164) cpu_start: Project name:     mahiwa-backend
I (169) cpu_start: App version:      d4422db-dirty
I (175) cpu_start: Compile time:     Oct 12 2023 16:28:24
I (181) cpu_start: ELF file SHA256:  95b02f96b7d8ee3e...
I (187) cpu_start: ESP-IDF:          v5.1.1
I (192) cpu_start: Min chip rev:     v0.3
I (196) cpu_start: Max chip rev:     v0.99
I (201) cpu_start: Chip rev:         v0.3
I (206) heap_init: Initializing. RAM available for dynamic allocation:
I (213) heap_init: At 3FC8C560 len 000501B0 (320 KiB): DRAM
I (219) heap_init: At 3FCDC710 len 00002950 (10 KiB): STACK/DRAM
I (226) heap_init: At 50000010 len 00001FD8 (7 KiB): RTCRAM
I (233) spi_flash: detected chip: generic
I (237) spi_flash: flash io: dio
W (241) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (254) sleep: Configure to isolate all GPIO pins in sleep state
I (261) sleep: Enable automatic switching of GPIO sleep configuration
I (268) app_start: Starting scheduler on CPU0
I (273) main_task: Started on CPU0
I (273) main_task: Calling app_main()
I (273) main_task: Returned from app_main()
```
