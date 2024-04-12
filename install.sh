
: '
INSTALL SCRIPT FOR FAST FIND
'


[ "$UID" -eq 0 ] || exec sudo bash "$0" "$@"

home_dir="$HOME"

# for linux
# find user home dir
if [ ! "$os" == "Darwin" ]
then
home_dir="/home/${SUDO_USER}"
fi


chmod +x "./fast-find_/exec"
chmod +x "./src/fast-find.desktop"
chmod +x "./uninstall.sh"

echo -e "COPYING HELPER FILES..."
sudo rm -rf "/usr/share/fast-find_"
sudo cp -r -T "./fast-find_/" "/usr/share/fast-find_"
sudo chown -R "${SUDO_USER}" "/usr/share/fast-find_"

echo -e "COPYING THE EXECUTABLE..."
sudo cp "./ff" "/usr/bin/ff"

echo -e "COPYING THE .DESKTOP FILE..."
sudo cp -r "./src/fast-find.desktop" "/usr/share/applications/fast-find.desktop"