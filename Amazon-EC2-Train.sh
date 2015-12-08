#!/bin/bash

# Connect
chmod 400 ./TestInstance2.pem
ssh -i ./TestInstance2.pem ubuntu@ec2-52-24-120-173.us-west-2.compute.amazonaws.com

# Prepare the environment
sudo apt-get update -qq -y
sudo apt-get install -qq git cmake opencl-headers build-essential unzip

# Install Catalyst dependencies
sudo apt-get install -qq -y cdbs dh-make dkms execstack dh-modaliases linux-headers-generic libqtgui4 xserver-xorg-dev-lts-trusty lib32gcc1 libxrandr2 libxcursor1 libgl1-mesa-glx libxinerama1

# From the http://wiki.cchtml.com/index.php/Ubuntu_Trusty_Installation_Guide#Installing_Proprietary_Drivers_a.k.a._Catalyst.2Ffglrx
# Download the latest Catalyst package
mkdir catalyst-14.6beta1.0jul11
pushd catalyst-14.6beta1.0jul11
    wget --referer='http://support.amd.com/en-us/download/desktop?os=Linux+x86' http://www2.ati.com/drivers/beta/linux-amd-catalyst-14.6-beta-v1.0-jul11.zip
    unzip linux-amd-catalyst-14.6-beta-v1.0-jul11.zip
    # Create and install .deb packages
    pushd fglrx-14.20
        sudo ./amd-driver-installer-14.20-x86.x86_64.run --buildpkg Ubuntu/trusty
        sudo apt-get -f install
        sudo dpkg -i fglrx*.deb
    popd
popd

# Build and test TinyRNN
git clone https://github.com/peterrudenko/TinyRNN.git
pushd TinyRNN
    git submodule init && git submodule update && git submodule status

    # Fetch OpenCL C++ binding
    mkdir -p ./Source/OpenCL
    pushd ./Source/OpenCL
        wget -w 1 -r -np -nd -nv -A h,hpp https://www.khronos.org/registry/cl/api/2.1/cl.hpp
    popd

    #cmake -HProjects/CMake -BBuild -DCMAKE_BUILD_TYPE=Release -DTINYRNN_OPENCL_ACCELERATION=0
    cmake -HProjects/CMake -BBuild -DCMAKE_BUILD_TYPE=Release
    pushd Build
        make
        ctest -V
    popd
popd

# JUCE modules' dependencies
sudo apt-get install libfreetype6-dev libxrandr-dev libxinerama-dev libasound-dev

# Build GoDeeper trainer
git clone https://github.com/peterrudenko/GoDeeper.git
pushd GoDeeper
    git submodule init && git submodule update && git submodule status
    git checkout develop

    # Fetch OpenCL C++ binding
    mkdir -p ./Source/Playground/OpenCL
    pushd ./Source/Playground/OpenCL
        wget -w 1 -r -np -nd -nv -A h,hpp https://www.khronos.org/registry/cl/api/2.1/cl.hpp
    popd

    pushd Projects/LinuxMakefile/GoDeeper
        export CONFIG=Release && make clean && make
        sudo rm -r /usr/bin/deeper
        sudo ln -s $PWD/build/GoDeeper /usr/bin/deeper
    popd
popd

# Train!
deeper init MyLSTM 256 128 128 128 256
deeper train MyLSTM targets="Targets"
