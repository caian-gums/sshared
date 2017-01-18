echo "# sshared tests\n"

echo "\n# [RUN] help information..."
./stest -h > output 2> errout
echo "### output ###"
cat output
echo "### error output ###"
cat errout

echo "\n# [CALL] incorrect filter message..."
./stest split -in my.file -n  > output 2> errout
echo "### output ###"
cat output
echo "### error output ###"
cat errout

echo "\n# [CALL] correct filter message..."
./stest split -in my.file -t 3 -n 5 > output 2> errout
echo "### output ###"
cat output
echo "### error output ###"
cat errout

echo "# clean the test file to read/write"
rm test.txt
