for ((i=2;i<=64;i*=2)); 
do
    for ((j=0;j<10;j+=1)); 
    do
        ./obj32/p1 -n batch_test -i 1000 -t $i -s -k 1000
    done
done
