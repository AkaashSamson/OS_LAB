
for i in {2..50}
do
	p=0
	j=$i

	while [ $j -ne 0 ]
		do
			a=$(($i%$j))
			if [ $a -eq 0 ]
				then	
					p=$(($p+1))
			fi
		j=$(($j-1))
		done
	if [ $p -eq 2 ]
		then
			echo $i
	fi
done
