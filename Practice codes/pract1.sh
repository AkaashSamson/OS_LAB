echo "Enter number a: "
read a
echo "Enter number b: "
read b
echo "Enter number c: "
read c

if [ $a -gt $b ];
	then 
		if [ $c -gt $a ];
		then echo "largest number is $c"
		else
		 	echo "largest number is $a"
		fi
	else
		if [ $c -gt $b ];
		then echo "largest number is $c"
		else
		 	echo "largest number is $b"
		fi
fi
