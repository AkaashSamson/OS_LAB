echo "Enter the year : "
read y
a=$(($y % 4))
b=$(($y % 100))
c=$(($y % 400))

if [ $a -eq 0 ];
	then 
		if [ $b -eq 0 ];
			then 
				if [ $c -eq 0 ];
					then 
						echo "It's a Leap year"
					else
						echo "It's not a Leap year"
				fi
			else
				echo "It's a Leap year"
		fi
	else
		echo "It's not a Leap year"
fi
