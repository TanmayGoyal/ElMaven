


# cd bin/;
# ls;

echo "start run tests"



if [ -f tests/MavenTests/test.xml ]; then
	echo "inside if 1"
	rm test*.xml
fi

if [ -d bin/MavenTests.app ]; then
	echo "This is a directory!"
	./bin/MavenTests.app/Contents/MacOS/MavenTests

	echo $?
	
	VAR=$?

	echo $VAR

	if [ $VAR != 0 ]; then
		echo "yayy!!"
		exit 1
	fi

fi

# cd bin/MavenTests*/Contents
# ls -R
# ls
# cd ..

# ./MavenTests.app

if [ -f ./bin/MavenTests* ]; then
	echo "inside if 2"

	./bin/MavenTests* -xml

    VAR=$?

    echo $VAR

    if [ $VAR != 0 ]; then
        exit 1
        # knsdlgdslfsdkf
    fi
fi

echo "end run tests"