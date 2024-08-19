echo "Enter the limit: "
read n
i=0
echo "Multiplication table of 6: "
n=$(($n+1))
while [ $i -ne $n ]
	do
		m=$(($i*6))
		echo "6 x $i = $m"
		i=$(($i+1))
	done
