#!/bin/bash
echo  'KERNEL=="ttyACM*", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="5740", MODE:="0666", GROUP:="dialout",  SYMLINK+="stm32_serial"' >/etc/udev/rules.d/stm32_serial.rules

service udev reload

sleep 2

service udev restart

