
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

if [ -z "$(command -v python)" ]
then
    echo -e "G++ not installed. Please install g++ and run this script again."

fi

chmod +x "./fast-find_/exec"
chmod +x "./src/fast-find.desktop"
chmod +x "./uninstall.sh"

echo -e "COPYING HELPER FILES..."
sudo rm -rf "/usr/share/fast-find_"
sudo cp -r -T "./fast-find_/" "/usr/share/fast-find_"
sudo chown -R "${SUDO_USER}" "/usr/share/fast-find_"

echo -e "COMPILING THE EXECUTABLE..."
g++ -std=c++20 -static-libgcc -static-libstdc++ src/main.cc src/utils.cc -o ./fast-find_/exec

echo -e "COPYING THE EXECUTABLE..."
sudo cp "./ff" "/usr/bin/ff"

echo -e "COPYING THE .DESKTOP FILE..."
sudo cp -r "./src/fast-find.desktop" "/usr/share/applications/fast-find.desktop"


# ALIAS INSERTION FUNCTIONALITY

alias(){

    
    file=""
    if [ -e "$home_dir/.bash_aliases" ]
    then    
        file="$home_dir/.bash_aliases"
    elif [ -e "$home_dir/.bashrc" ]
    then
        file="$home_dir/.bashrc"
    elif [ -e "$home_dir/.zshrc" ]
    then
        file="$home_dir/.xshrc"
    elif [ -e "$home_dir/.config/fish/config.fish" ]
    then
        file="$home_dir/.config/fish/config.fish"
    else 
        echo -e "  Could not find a shell configuration file."
        exit 1
    fi

    if grep -q "alias ff=\". ff\"" "$file" ; then
        echo -e "Alias already exists."
    else 
        echo -e "alias ff=\". ff\"" >> "$file"
        echo -e "Alias inserted. Run 'cat $file' to confirm changes. Please restart your shell session for the changes to take effect."
    fi
}

read -p "Insert 'alias ff=\". ff\"' into your shell configuration file? [Yes / No / Why]?:  " insert

case "$(echo $insert | tr A-Z a-z)" in 
    "yes" | "ye" | "y" | "")
        alias
    ;;
    "no" | "n" ) 
        echo -e "Run \". ff <arguments>\" (as source in the shell) to use the cd functionality."
        exit 1
    ;;
    "why" | "wh" | "w" )
        echo -e "Fast-find needs to prefix the \"source\" or \".\" command to be able to cd in the currently open shell. Without the command, your shell (and .desktop file) creates a subshell for the executable, making cd within the executed shell impossible. Only solution is to put an alias in your shell configuration file."

        read -p "[Yes / No]?:  " insert
        case "$(echo $insert | tr A-Z a-z)" in 
            "yes" | "ye" | "y" )
            alias
            ;;
            "no" | "n" ) 
                echo -e "Run \". ff <arguments>\" (as source in the shell) to use the cd functionality."
                exit 1
            ;;
        esac
    ;;
    *)
esac

