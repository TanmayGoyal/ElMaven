


# cd bin/;
# ls;

echo "start run tests"

if [ -f tests/MavenTests/test.xml ]; then
	echi "inside if 1"
	rm test*.xml
fi


if [ -f ./bin/MavenTests* ]; then
	echo "inside if 2"

	./bin/MavenTests* -xml

    MY_VAR=$?

    echo $MY_VAR

    if [ $MY_VAR != 0 ]; then
        exit 1
        # knsdlgdslfsdkf
    fi

fi

echo "end run tests"
