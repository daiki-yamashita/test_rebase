# SPP_VF Sample Usage

This sample demonstrates an use-case of MAC address classification of
spp_vf.
It enables to access to VMs with ssh from a remote node.

Before trying this sample, install SPP by following
[setup guide](setup_guide.md).

![spp_sample_usage](spp_sample_usage.svg)

## Testing Steps

In this section, you configure spp_vf and client applications for
this use-case.


### Setup SPP

First, launch spp controller and primary process.

  ```sh
  $ pwd
  /path/to/Soft-Patch-Panel

  # SPP controller
  $ python ./src/spp_vf.py -p 5555 -s 6666

  # SPP primary
  $ sudo ./src/primary/x86_64-native-linuxapp-gcc/spp_primary \
  -c 0x02 -n 4 --socket-mem 512,512 --huge-dir=/run/hugepages/kvm \
  --proc-type=primary \
  -- \
  -p 0x03 -n 8 -s 127.0.0.1:5555
  ```

launch secondary process after launch primary process.

  ```sh
  # start secondary 1
  $ sudo ./src/vf/x86_64-native-linuxapp-gcc/spp_vf \
  -c 0x00fd -n 4 --proc-type=secondary \
  -- \
  --client-id 1 \
  --config /path/to/spp_vf1_without_cmtab.json \
  -s 127.0.0.1:11111 \
  --vhost-client

  # start secondary 2
  $ sudo ./src/vf/x86_64-native-linuxapp-gcc/spp_vf \
  -c 0x3f01 -n 4 --proc-type=secondary \
  -- \
  --client-id 2 \
  --config /path/to/spp_vf2_without_cmtab.json \
  -s 127.0.0.1:11112 \
  --vhost-client
  ```

### Setup network configuration for VMs

Start two VMs.

  ```sh
  $ virsh start spp-vm1
  $ virsh start spp-vm2
  ```

Login to spp-vm1 for network configuration.
To not ask for unknown keys while login VMs,
set `-oStrictHostKeyChecking=no` option for ssh.

  ```sh
  $ ssh -oStrictHostKeyChecking=no sppuser@192.168.122.31
  ```

Up interfaces for vhost inside spp-vm1.
In addition, you have to disable TCP offload function, or ssh is faled
after configuration is done.

  ```sh
  # up interfaces
  $ sudo ifconfig ens4 inet 192.168.140.21 netmask 255.255.255.0 up
  $ sudo ifconfig ens5 inet 192.168.150.22 netmask 255.255.255.0 up

  # diable TCP offload
  $ sudo ethtool -K ens4 tx off
  $ sudo ethtool -K ens5 tx off
  ```

Configurations for spp-vm2 is same as spp-vm1.

  ```sh
  $ ssh -oStrictHostKeyChecking=no sppuser@192.168.122.32

  # up interfaces
  $ sudo ifconfig ens4 inet 192.168.140.31 netmask 255.255.255.0 up
  $ sudo ifconfig ens5 inet 192.168.150.32 netmask 255.255.255.0 up

  # diable TCP offload
  $ sudo ethtool -K ens4 tx off
  $ sudo ethtool -K ens5 tx off
  ```

## Test Application

### Register MAC address to Classifier

Register MAC addresses to classifier.

  ```sh
  spp > classifier_table mac 52:54:00:12:34:56 ring:0
  spp > classifier_table mac 52:54:00:12:34:58 ring:1
  spp > flush
  ```

  ```sh
  spp > classifier_table mac 52:54:00:12:34:57 ring:4
  spp > classifier_table mac 52:54:00:12:34:59 ring:5
  spp > flush
  ```

### Login to VMs

Now, you can login VMs.

  ```sh
  # spp-vm1 via NIC0
  $ ssh sppuser@192.168.140.21

  # spp-vm1 via NIC1
  $ ssh sppuser@192.168.150.22

  # spp-vm2 via NIC0
  $ ssh sppuser@192.168.140.31

  # spp-vm2 via NIC1
  $ ssh sppuser@192.168.150.32
  ```

## End Application

Describe the procedure to end the application.

### Remove MAC address from Classifier

It is possible to remove the MAC address set by inputting the following
command from `spp_vf.py` which was started with `Setup SPP`.
The flush command is required to reflect the setting.

  ```sh
  spp > classifier_table mac 52:54:00:12:34:56 unuse
  spp > classifier_table mac 52:54:00:12:34:58 unuse

  spp > classifier_table mac 52:54:00:12:34:57 unuse
  spp > classifier_table mac 52:54:00:12:34:59 unuse

  spp > flush
  ```

### Teardown SPP

Tear down SPP in the reverse order of Setup.
To stop other than spp_vf.py, press Ctrl + C on the launched screen.
spp_vf.py can be stopped by the bye command.

  ```sh
  # stop secondary 2
  Ctrl + C

  # stop secondary 1
  Ctrl + C

  # stop primary
  Ctrl + C

  # stop controller
  spp > bye
  ```
