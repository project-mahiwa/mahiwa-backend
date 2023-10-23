# mahiwa-backend

## environment

```
❯ pio --version
PlatformIO Core, version 6.1.11
```

ESP系であればframeworkにESP-IDFも指定できるが，今回は他のマイコンも対象としたいのでframeworkはArduinoとする．

- https://docs.platformio.org/en/stable/tutorials/espressif32/espidf_debugging_unit_testing_analysis.html
- https://docs.platformio.org/en/stable/tutorials/espressif32/arduino_debugging_unit_testing.html

## getting started

### Install platformio

See here : https://docs.platformio.org/en/latest/core/installation/index.html

brew

```
brew install platformio
```

Arch Linux

```
yay -S platformio-git
```

### Install repository

```
git clone --recursive https://github.com/project-mahiwa/mahiwa-backend
cd mahiwa-backend
pip run -t m5stack-atoms3
```

## development

### GUI

https://docs.platformio.org/en/stable/core/userguide/cmd_home.html

```
pio home
```

### static analysis

https://docs.platformio.org/en/stable/core/userguide/cmd_check.html

```
pio check
```

### test

https://docs.platformio.org/en/stable/core/userguide/cmd_test.html

```
pio test
```

### update

update libraries https://docs.platformio.org/en/stable/core/userguide/cmd_update.html

```
pio update
```

update pip core https://docs.platformio.org/en/stable/core/userguide/cmd_upgrade.html

```
pio upgrade
```

### check USB devices

https://docs.platformio.org/en/stable/core/userguide/device/cmd_list.html

```
pio device list
```

### serial monitor

https://docs.platformio.org/en/stable/core/userguide/device/cmd_monitor.html

```
pio device monitor
```

- -p select a device

### debug

https://docs.platformio.org/en/stable/core/userguide/cmd_debug.html

```
pio debug
```
