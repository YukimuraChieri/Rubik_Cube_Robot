#!/bin/bash

echo  'KERNEL=="video*", KERNELS=="1-1.1", ATTRS{idVendor}=="058f", ATTRS{idProduct}=="0362", ATTR{index}=="0" , MODE:="0777", SYMLINK+="left_camera"' >/etc/udev/rules.d/left_camera.rules
# echo  'KERNEL=="video*",KERNELS=="1-1.1", ATTRS{idVendor}=="058f", ATTRS{idProduct}=="0362",ATTR{index}=="1" , MODE:="0777", SYMLINK+="left_camera-1"' >>/etc/udev/rules.d/left_camera.rules

echo  'KERNEL=="video*", KERNELS=="1-1.2", ATTRS{idVendor}=="058f", ATTRS{idProduct}=="0362", ATTR{index}=="0", MODE:="0777", SYMLINK+="right_camera"' >/etc/udev/rules.d/right_camera.rules
# echo  'KERNEL=="video*",KERNELS=="1-1.2",ATTRS{idVendor}=="058f", ATTRS{idProduct}=="0362",ATTR{index}=="1", MODE:="0777", SYMLINK+="right_camera-1"' >>/etc/udev/rules.d/right_camera.rules

service udev reload

sleep 2

service udev restart

