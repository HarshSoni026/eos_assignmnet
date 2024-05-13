echo -n "Enter Number : "
read num

isPrime=0

for (( i=2; i<$num; i++ ))
do 
	if [ $((num%i)) -eq 0 ]
	then
		isPrime=1
	fi
done

if [ $isPrime -eq 0 ]
then
	echo "num is prime"
else
	echo "num is not prime"
fi;
