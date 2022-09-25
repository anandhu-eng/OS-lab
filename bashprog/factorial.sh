echo "Enter the number you want to find factorial:"
read number
a=1
for((i=1;i<=number;i++))
do
    a= expr $a \* $i
    echo "hello"
done

echo "$a"