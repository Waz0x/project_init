if [ $UID -eq "0" ]; then
    SUDO=""
    echo "[no sudo for root]"
fi

sudo cp ./project /bin/project
echo "Bin installed."
echo ""
echo "project [name] to start all projects"
echo "project -h for help"
echo ""
mkdir ~/init
mkdir ~/init/include
mkdir ~/init/lib
mkdir ~/init/source
touch ~/init/include/project.h
echo "Put your files in the file ~/init."