#!/bin/bash
  
  qemu-system-x86_64 \
  -enable-kvm \
  -smp 1 \
  -m 1024 \
  -hda born2beroot.qcow2 \
  -netdev user,id=net0,hostfwd=tcp::2222-:4242 \
  -device e1000,netdev=net0 \
  -vga virtio