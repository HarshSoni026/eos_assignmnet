echo -n "Enter the name : "
read name

echo -e "name : $name\n"

if [ -f "$name" ]
then 
	echo "$name is file"

elif [ -d "$name" ]
then 
	echo "$name is directory"

else 
	echo "$name not a file nor a directory"

fi
