echo "# sshared tests\n"

echo "# [CALL] incorrect filter message..."
./stest -in my.file -n  > output
cat output

echo "\n# [CALL] correct filter message..."
./stest -in my.file -t 3 -n 5 > output
cat output

echo "# clean the test file to read/write"
rm test.txt
