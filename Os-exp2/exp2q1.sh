echo "Enter the Principle: "
read p
echo "Enter the Rate of Interest: "
read r
echo "Enter Time period: "
read t

si=$(($p*$r*$t/100)) 
echo "Simple Interest: $si"
