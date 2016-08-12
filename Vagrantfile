# -*- mode: ruby -*-
# vi: set ft=ruby :

$script = <<SCRIPT
set -x
sudo apt-get update
sudo apt-get install -y linux-headers-$(uname -r)
SCRIPT

Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu/trusty64"
  config.vm.provision 'shell', inline: $script
end
