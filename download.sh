#!/bin/bash
#make all -j4
cat /proc/version | grep Microsoft 
if [ $? -ne 0 ];then
    device=/dev/ttyUSB$1
else
    device=/dev/ttyS$1
fi
while true
do
$IDF_PATH/components/esptool_py/esptool/esptool.py --chip esp32 --port $device erase_flash
$IDF_PATH/components/esptool_py/esptool/esptool.py --chip esp32 --port $device --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 40m --flash_size detect 0x1000 build/bootloader/bootloader.bin 0x10000 build/app.bin 0x8000 build/partitions.bin
echo "getout"
sleep 3s
done

