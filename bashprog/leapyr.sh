echo "Enter the year you want to check:"
read year
if [ $(($year%100)) -eq 0 ] || [ $(($year%4)) -ne 0 ]
then
    echo "The year is not a leap year!"
else
    echo "The year is a leap year!"
fi