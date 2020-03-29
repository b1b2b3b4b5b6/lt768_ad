#!/bin/bash
#$IDF_PATH/components/esptool_py/esptool/esptool.py --chip esp32 --port /dev/ttyS$1 erase_flash
cat /proc/version | grep Microsoft 
if [ $? -ne 0 ];then
    device=/dev/ttyUSB$1
else
    device=/dev/ttyS$1
fi
$IDF_PATH/tools/idf_monitor.py --port $device --baud 115200 build/app.elf
