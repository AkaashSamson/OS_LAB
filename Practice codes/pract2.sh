echo "Enter number a: "
read a
echo "Enter number b: "
read b

echo "Addition: "
res=`expr $a + $b`
echo $res

echo "Subtraction: "
res=`expr $a - $b`
echo $res

echo "multiplication: "
res=`expr $a \* $b`
echo $res

echo "divison: "
res=`expr $a / $b`
echo $res
