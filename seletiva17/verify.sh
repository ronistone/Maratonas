P="I"
max=33

#g++ $P.cpp -o main
for i in `seq 1 $max`
do
	./main < $P/input/$P\_$i > out_$i
done

for i in `seq 1 33`
do
	diff $P/output/$P\_$i out_$i
done
rm out_*
