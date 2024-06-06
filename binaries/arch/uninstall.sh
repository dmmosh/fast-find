#!/bin/bash

# UNINSTALLER 

# ask for sudo permissions

# ROOT PERMISSIONS

if [ ! "$UID" -eq 0 ] 
then
    echo -e "FATAL ERROR:"
    echo -e "   Can't uninstall without root permissions."
    echo -e "   Please run 'sudo ./$(basename "$0")'."
    exit 1
fi



os="$(uname)"

home_dir="$HOME"




echo -e "DELETING EXECUTABLE..." 
rm "/usr/bin/ff"



sudo rm /usr/share/applications/fast-find.desktop


echo -e "NOTE: alias 'alias ff=\". ff\"' is still present in your shell configuration file. Please remove it if you want a full uninstall of the program."
echo -e "Thank you for using the search tool. -Dmytro" 