#!/bin/bash
cat /proc/version | grep Microsoft 
if [ $? -ne 0 ];then
    device=/dev/ttyUSB$1
else
    device=/dev/ttyS$1
fi
$IDF_PATH/components/esptool_py/esptool/esptool.py --chip esp32 --port $device erase_flash

