ch=1
while [ $ch -eq 1 ]
	do 
		echo "1.Area and Circumference of Circle"
		echo "2.Area of Triangle"
		echo "3.Area of Square"
		echo "Enter your choice: "
		read choice
		case $choice in
		1) echo "Enter the Radius of Circle: "
		   read rad
		   area=$((22*$rad*$rad/7))
		   echo "Area: $area"
		   circum=$((2*22*$rad/7))
		   echo "Circumference: $circum"
		;;
	    2)echo "Enter the height of Triangle: "
		  read ht
		  echo "Enter the base of Triangle: "
		  read bs
		  area=$(($ht*$bs/2))
		  echo "Area: $area"
		;;
		3)echo "Enter the side of Square: "
		  read sd
		  area=$(($sd*$sd))
		  echo "Area: $area"
		;;
		*)echo "Invalid Choice"
	 	  esac
	 	  echo "(1 to continue/ 0 to exit)"
	      read ch
	done

