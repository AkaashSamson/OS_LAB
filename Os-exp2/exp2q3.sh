echo "Enter the directory: "
read d

if [ $d == $(pwd) ]
	then
		echo "It's the Same directory"
	else
		echo "It's not the Same directory"
fi
