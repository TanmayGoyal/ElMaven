OMP_CANCELLATION=true
export QT_SELECT=qt5 
flag=100   #this flag check wether qt running in debug mode or not
while true; do
    read -p "Do you wish to install this program in release mode? " yn
    case $yn in
        [Yy]* ) qmake CONFIG+=release -o Makefile build.pro; break;;
        [Nn]* ) qmake CONFIG+=debug -o Makefile build.pro; flag=10; break;;
        * ) echo "Please answer yes or no.";;
    esac
done
make -j $(nproc)

echo "HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII 1"

# if [ -f tests/MavenTests/test.xml ]; then
# 	rm test*.xml
# fi

# echo "HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII 2"

# if [ -f ./bin/MavenTests ]; then
# 	./bin/MavenTests -xml

#     MY_VAR=$?

#     echo $MY_VAR

#     if [ $MY_VAR != 0 ]; then
#         exit 1
#         # knsdlgdslfsdkf
#     fi

# fi



echo "HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII 3"


type="$(uname)"
systemType="$(echo "$type"  |  tr '[:upper:]'  '[:lower:]')"
if [ $systemType == "linux" ] && [ $flag == 10 ]; then
    lcov --capture --directory ./ --output-file ../coverage.info --no-external
    genhtml ../coverage.info --output-directory ../coverage
fi

echo "HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII 4"
