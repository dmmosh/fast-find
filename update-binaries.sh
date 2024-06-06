#!/bin/bash


# UPDATES THE BINARIES
# for development use only

# compile on vms
#g++ -std=c++20 -static-libgcc -static-libstdc++ src/main.cc src/utils.cc -o ./fast-find_/exec

cd ./binaries
for dir in */     # list directories in the form "/tmp/dirname/"
do
    cd $dir 

    # copies the scripts
    rm ./install.sh
    rm ./uninstall.sh
    cp ../../install.sh .
    cp ../../uninstall.sh .
    rm ./fast-find.desktop
    cp ../../src/fast-find.desktop .
    rm ./ff 
    cp ../../ff .

    cd ..
    tar -czvf "${dir::-1}.tar.gz" $dir

done
