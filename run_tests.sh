echo "# sshared tests\n"

echo "# [CALL] incorrect filter message..."
./stest -in my.file -n  > output
cat output

echo "\n# [CALL] correct filter message..."
./stest -in my.file -n 5 -t 3 > output
cat output

echo "# clean the test file to read/write"
rm test.txt
