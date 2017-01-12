echo "# sshared tests\n"

echo "# [CALL] incorrect filter message..."
./stest -in my.file -n  > output 2> errout
echo "### output ###"
cat output
echo "### error output ###"
cat errout

echo "\n# [CALL] correct filter message..."
./stest -in my.file -t 3 -n 5 > output 2> errout
echo "### output ###"
cat output
echo "### error output ###"
cat errout

echo "# clean the test file to read/write"
rm test.txt
