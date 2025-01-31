read num
iter=1
while [ $iter -le $num ]
do
    str=""
    temp=0
    while [ $temp -lt $iter ]
    do
        str+="*"
        temp=$((temp+1))
    done
    set -f
    echo $str
    iter=$((iter + 1))
done
