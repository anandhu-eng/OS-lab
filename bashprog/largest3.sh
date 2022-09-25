echo "Enter number1:"
read NUMBER1
echo "Enter number2:"
read NUMBER2
echo "Enter number3:"
read NUMBER3
if [ $NUMBER1 -ge $NUMBER2 ];
then
    if [ $NUMBER1 -gt $NUMBER3 ];
    then
        echo "$NUMBER1 is largest!"
    else
        echo "$NUMBER3 is largest!"
    fi
elif [ $NUMBER2 -gt $NUMBER1 ];
then
    if [ $NUMBER2 -gt $NUMBER3 ];
    then
        echo "here"
        echo "$NUMBER2 is largest!"
    else
        echo "$NUMBER3 is largest!"
    fi
fi