echo "Enter numbers : "
read num1 num2 num3

max=0;
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then 
	echo -en "num1 is greater\n"
	max=$num1;

elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
	echo -en "num2 is greater\n"
	max=$num2;

else
	echo -en "num3 is greater\n"
	max=$num3;

fi

echo -en "maximum value =$max\n"



