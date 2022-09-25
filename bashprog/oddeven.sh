echo "Enter the number:"
read NUMBER
#res = "$(expr $NUMBER % 2)"
#echo "$res"

if [ $(($NUMBER%2)) == 0 ];
then
    echo "$NUMBER is even!"
else
    echo "$NUMBER is odd!"
fi