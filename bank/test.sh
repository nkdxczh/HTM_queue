END=24
for ((i=4;i<=END;i+=4)); do
    ./obj32/p1 -n batch_test -i 5000 -t 8 -s -k 100
done
