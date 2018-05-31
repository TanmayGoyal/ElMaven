


# cd bin/;
# ls;

echo "start run tests"



if [ -f tests/MavenTests/test.xml ]; then
	echi "inside if 1"
	rm test*.xml
fi

if [ -d bin/MavenTests* ]; then
	echo "This is a directory!"


fi

cd bin/MavenTests*
ls
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
