choice=1
while [ $choice -eq 1 ]
do 
	echo "1.Display calendar"
	echo "2.Display Users"
	echo "3.Display Current Directory"
	echo "Enter your choice"
	read choice
	case $choice in
	1)cal
	  ;;
	2)who
	  ;;
	3)pwd
	  ;;
	*)echo "Invalid Choice"
	 esac
	 echo "(1 to continue/ 0 to exit)"
	 read choice
	 done
